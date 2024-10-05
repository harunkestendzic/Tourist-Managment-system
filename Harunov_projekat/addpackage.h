#ifndef ADDPACKAGE_H
#define ADDPACKAGE_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class Addpackage;
}

class Addpackage : public QDialog
{
    Q_OBJECT

public:
    explicit Addpackage(QWidget *parent = nullptr);
    ~Addpackage();

private slots:
    void on_btnSave_clicked();

private:
    Ui::Addpackage *ui;
};

#endif // ADDPACKAGE_H
