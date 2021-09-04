// Source Includes
#include "appframework/AppFramework.h"
#include "tier0/icommandline.h"
#include "tier1/tier1.h"
#include "tier2/tier2.h"

#include "filesystem.h"
#include "materialsystem/imaterialsystem.h"
#include "istudiorender.h"
#include "Datacache/imdlcache.h"
#include "datacache/idatacache.h"

// Qt includes
#include <QtGui/qapplication.h>
#include <Qt/qicon.h>
#include <Qt/qlabel.h>
#include <Qt/qfile.h>
#include <Qt/qdir.h>
#include <QtCore/qdebug.h>

// Windows
#include "windows/mainwindow.h"

// memdbgon must be the last include file in a .cpp file!!!
#include <tier0/memdbgon.h>

// Globals
IFileSystem *g_pFileSystem;
CreateInterfaceFn g_Factory;
IStudioRender	*g_pStudioRender;
IMDLCache *g_pMDLCache;
//IMaterialSystem *g_pMaterialSystem;

class CHammerApp : public CSteamAppSystemGroup
{
public:
	// Methods of IApplication
	virtual bool Create();
	virtual bool PreInit();
	virtual int Main();
	virtual void PostShutdown();
	virtual void Destroy();
};

int main( int argc, char *argv[] )
{
	CommandLine()->CreateCmdLine( argc, argv );
	QApplication app( argc, argv );

	// Setup resource paths
	QDir::setSearchPaths( "resources", QStringList( "./resources" ) );
	QDir::setSearchPaths( "toolimages", QStringList( "resources:/images" ) );

	// Set app icon
	QApplication::setWindowIcon( QIcon( "toolimages:/hammer/appicon.ico" ) );

	// Setup stylesheet
	QFile file( "resources:/stylesheets/valve.qss" );
	file.open( QFile::ReadOnly );
	QString styleSheet = QLatin1String( file.readAll() );
	qApp->setStyleSheet( styleSheet );

	// Set the color across the entire application we may
	// be missing some, but that doesn't matter for now.
	QPalette p = QApplication::palette();
	p.setColor( QPalette::Text, Qt::gray );
	p.setColor( QPalette::WindowText, Qt::gray );
	p.setColor( QPalette::ButtonText, Qt::gray );
	p.setColor( QPalette::BrightText, Qt::gray );
	p.setColor( QPalette::Link, QColor( 103, 138, 244 ) );
	QApplication::setPalette( p );

	// Run AppSystem app
	CHammerApp hammerApp;
	CSteamApplication steamApplication( &hammerApp );

	return steamApplication.Run();
}

bool CHammerApp::Create()
{
	// Load all our dependencies
	AppSystemInfo_t appSystems[] = 
	{
		{ "materialsystem.dll",		MATERIAL_SYSTEM_INTERFACE_VERSION },
		{ "studiorender.dll",		STUDIO_RENDER_INTERFACE_VERSION },
		{ "datacache.dll",			DATACACHE_INTERFACE_VERSION },
		{ "datacache.dll",			MDLCACHE_INTERFACE_VERSION },

		{ "", "" }	// Required to terminate the list
	};

	if ( !AddSystems( appSystems ) )
	{
		Error( "App systems failed to load\n" );
		return false;
	}

	g_Factory = GetFactory();
	ConnectTier1Libraries( &g_Factory, 1 );
	ConnectTier2Libraries( &g_Factory, 1 );

	g_pFileSystem = (IFileSystem *)FindSystem( FILESYSTEM_INTERFACE_VERSION );
	g_pMaterialSystem = (IMaterialSystem *)FindSystem( MATERIAL_SYSTEM_INTERFACE_VERSION );
	g_pStudioRender = (IStudioRender *)FindSystem( STUDIO_RENDER_INTERFACE_VERSION );
	g_pMDLCache = (IMDLCache *)FindSystem( MDLCACHE_INTERFACE_VERSION );

	if ( !g_pFileSystem || !g_pMaterialSystem || !g_pStudioRender || !g_pMDLCache )
	{
		Warning( "Failed to load required systems\n" );
		return false;
	}

	//const char *pShaderDLL = CommandLine()->ParmValue( "-shaderdll" );
	//const char *pArg;
	//if ( CommandLine()->CheckParm( "-shaderapi", &pArg ) )
	//{
	//	pShaderDLL = pArg;
	//}

	//if ( !pShaderDLL )
	//{
	//	pShaderDLL = "shaderapidx9.dll";
	//}

	//g_pMaterialSystem->SetShaderAPI( pShaderDLL );

	//g_Factory = GetFactory();

	g_pMaterialSystem->SetShaderAPI( "shaderapidx9" );
	g_pMaterialSystem->Connect( g_Factory );

	// Must be done after material system is connected up!
	g_pMaterialSystemHardwareConfig = (IMaterialSystemHardwareConfig *)FindSystem( MATERIALSYSTEM_HARDWARECONFIG_INTERFACE_VERSION );

	return true;
}

bool CHammerApp::PreInit()
{
	MathLib_Init();

	g_pMaterialSystem->SetAdapter( 0, 0 );

	return true;
}

void CHammerApp::PostShutdown()
{
	DisconnectTier1Libraries();
}

int CHammerApp::Main()
{
	MainWindow window;
	window.show();

	int nRetValue = qApp->exec();

	return nRetValue;
}

void CHammerApp::Destroy()
{
	DisconnectTier1Libraries();
	DisconnectTier2Libraries();

	g_pFileSystem = NULL;
	g_pMaterialSystem = NULL;
	g_pStudioRender = NULL;
}
