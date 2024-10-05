#include "findtourist.h"
#include "ui_findtourist.h"

FindTourist::FindTourist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindTourist)
{
    ui->setupUi(this);
    model=NULL;
}

FindTourist::~FindTourist()
{
    delete ui;
    delete model;
}

void FindTourist::on_btnFind_clicked()
{
    QString touristName=ui->txtTouristName->text();


    qDebug()<<"Tourist  Name: "<<touristName;

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

    query.prepare("select * from Tourist where FirstName like '%"+ touristName+ "%'");

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

