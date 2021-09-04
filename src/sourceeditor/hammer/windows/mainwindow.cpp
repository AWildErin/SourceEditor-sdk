#include "mainwindow.h"

// Qt Includes
#include <Qt/qmessagebox.h>
#include <Qt/qlabel.h>
#include <Qt/qpixmap.h>

// Generated files
#include "mainwindow.moc"
#include "generated_code_DO_NOT_CHECK_THESE_IN/ui_mainwindow.h"

MainWindow::MainWindow() : ui( new Ui::MainWindow )
{
	ui->setupUi( this );

	// Example of an action. Moc MUST be deleted before this, it doesn't get
	// autogenerated for some reason.
	connect( ui->actionAbout_Qt, SIGNAL( triggered() ), this, SLOT( on_AboutQt_triggered() ) );

	/*
	QLabel *label = new QLabel( this );
	label->setAlignment( Qt::AlignCenter );
	QPixmap pix;
	pix.load( "toolimages:/hammer/appicon.ico" );
	label->setPixmap( pix );
	*/
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_AboutQt_triggered()
{
	QMessageBox::aboutQt( this, "About Qt" );
}