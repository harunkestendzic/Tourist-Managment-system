#include "findpackage.h"
#include "ui_findpackage.h"

FindPackage::FindPackage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindPackage)
{
    ui->setupUi(this);
    model=NULL;
}

FindPackage::~FindPackage()
{
    delete ui;
    delete model;

}

void FindPackage::on_btnFindPackage_clicked()
{
    QString packageName=ui->txtfName->text();


    qDebug()<<"Package Name: "<<packageName;

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

    query.prepare("select * from Package where PackageName like '%"+ packageName+ "%'");

    query.exec();
    qDebug()<< "Last error: "<<query.lastError().text();

    if(model==NULL)
    {
        model= new QSqlQueryModel();
    }

    model->setQuery(std::move(query));
    ui->tableView->setModel(model);

    database.close();
}

