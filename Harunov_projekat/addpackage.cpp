#include "addpackage.h"
#include "ui_addpackage.h"

Addpackage::Addpackage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Addpackage)
{
    ui->setupUi(this);
}

Addpackage::~Addpackage()
{
    delete ui;
}

void Addpackage::on_btnSave_clicked()
{
    QString packageName=ui->txtPackageName->text();
    QString packageDescription= ui->txtDescription->text();
    QString amount =ui->txtAmount->text();

    qDebug()<<"Package Name: "<<packageName<<" Package Desc: "<<packageDescription<<"Amount: "<<amount;

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

    query.prepare("Insert into Package(PackageName, PackageDescription, Amount) values('"+ packageName+  "','"+packageDescription + "','"+amount+ "')");

    query.exec();
    qDebug()<< "Last error: "<<query.lastError().text();
    database.close();
}

