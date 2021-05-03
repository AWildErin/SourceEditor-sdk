#include "appframework/AppFramework.h"
#include "tier0/icommandline.h"
#include "editortoolframework/ieditortoolframework.h"
#include "scriptsystem/iscriptsystem.h"

// Qt includes
#include <QtGui/qapplication.h>
#include <Qt/qlabel.h>
#include <Qt/qfile.h>
#include <Qt/qdir.h>
#include <QtCore/qdebug.h>
#include "windows/dialog.h"

/*
Todo: fix stylesheet not loading from file.
*/
class CSourceEditorApp : public CSteamAppSystemGroup
{
public:
	// Methods of IApplication
	virtual bool Create();
	virtual bool PreInit();
	virtual int Main();
	virtual void PostShutdown();
	virtual void Destroy();
};

bool CSourceEditorApp::Create()
{
	qDebug() << "Running Create()";

	AppSystemInfo_t appSystems[] =
	{
		{"toolframework.dll",	EDTIORTOOLFRAMEWORK_INTERFACE_VERSION},
		{"scriptsystem.dll",	SCRIPTSYSTEM_INTERFACE_VERSION},
		{ "", "" }	// Required to terminate the list
	};

	if (!AddSystems(appSystems))
	{
		Warning("App systems failed to load\n");
		return false;
	}

	return true;
}

bool CSourceEditorApp::PreInit()
{
	qDebug() << "Running PreInit()";

	return true;
}

int CSourceEditorApp::Main()
{
	QFile file("resources:/stylesheets/sourceeditor.qss");
	file.open(QFile::ReadOnly);
	QString styleSheet = QLatin1String(file.readAll());
	qApp->setStyleSheet(styleSheet);

	Dialog w;
	w.show();
	
	qApp->exec();

	return 1;
}

void CSourceEditorApp::PostShutdown()
{

}

void CSourceEditorApp::Destroy()
{
}


int main(int argc, char* argv[])
{
	CommandLine()->CreateCmdLine(argc, argv);
	QApplication app(argc, argv);

	// Set our search paths so tools have a general way
	// to search for resources
	QDir::setSearchPaths("resources", QStringList("./resources"));
	QDir::setSearchPaths("toolimages", QStringList("resources:/images"));

	CSourceEditorApp editorApp;
	CSteamApplication steamApplication(&editorApp);
	int nRetValue = steamApplication.Run();

	return nRetValue;

	/*
	QApplication app(argc, argv);

	QFile styleSheetFile("resources/stylesheets/sourceeditor.qss");
	styleSheetFile.open(QFile::ReadOnly);
	QString style(styleSheetFile.readAll());
	app.setStyleSheet(style);

	Dialog w;
	w.show();

	return app.exec();
	*/
}