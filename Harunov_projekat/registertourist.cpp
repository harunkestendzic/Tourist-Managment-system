#include "registertourist.h"
#include "ui_registertourist.h"

RegisterTourist::RegisterTourist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterTourist)
{
    ui->setupUi(this);
}

RegisterTourist::~RegisterTourist()
{
    delete ui;
}

void RegisterTourist::on_btnSave_clicked()
{
    QString firstName=ui->txtFirstName->text();
    QString middleName= ui->txtMiddleName->text();
    QString lastName =ui->txtLastName->text();
    QString passportNo =ui->txtPassportNo->text();
    QString contactNo =ui->txtContactNo->text();
    QString permanentAddress =ui->txtPermanentAddress->text();
    QString packageName =ui->cmbChoosePackage->currentText();



    QSqlDatabase database= QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("S:/database/MyTouristManager.db");

    if(QFile::exists("S:/database/MyTouristManager.db")){
        qDebug()<<"Database file exists";
    }
    else{
        qDebug()<<"Database file does not exist";
    }

    if(!database.open())
    {
    qDebug()<<"Error: Unable to open Database";
    return;
    }
    else
{
        qDebug()<<"Database open successfully..";
    }
    QSqlQuery query(database);

    query.prepare("Insert into Tourist(FirstName,MiddleName,LastName,PassportNo,ContactNo,PermanentAddress,PackageName) "
                  "values('"+ firstName+  "','"+middleName + "','"+lastName+ "', '"+passportNo+"','"+contactNo+"','"+permanentAddress+"','"+packageName+"')");

    query.exec();
    qDebug()<< "Last error: "<<query.lastError().text();
    database.close();
}

