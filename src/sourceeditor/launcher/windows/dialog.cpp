#include "dialog.h"
#include <QtCore/qstring.h>
#include <QtGui/qmessagebox.h>

// Generated files
#include "dialog.moc"
#include "generated_code_DO_NOT_CHECK_THESE_IN/ui_dialog.h"


Dialog::Dialog(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //ui->comboBox->addItem("Hello");
    //ui->comboBox->addItem("World");

    for (int var = 1; var <= 9; ++var) {
        ui->comboBox->addItem(QString::number(var) + " item");
    }
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QMessageBox::information(this, "Title", ui->comboBox->currentText());
}