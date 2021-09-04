#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/qmainwindow.h>

namespace Ui
{
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow();
	~MainWindow();

private slots:
	void on_AboutQt_triggered();

private:
	Ui::MainWindow *ui;
};

#endif // !MAINWINDOW_H