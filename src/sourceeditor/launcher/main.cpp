#include "appframework/AppFramework.h"
#include "tier0/icommandline.h"

// Qt includes
#include <QtGui/qapplication.h>
#include <QtCore/qdebug.h>
#include "windows/dialog.h"

/*
Todo: fix stylesheet not loading from file.
Todo: fix Qt not working well with Source files, to do with runtime library
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

	if (!CommandLine()->CheckParm("-nop4"))
	{
		qDebug() << "Launching with p4 source control";
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