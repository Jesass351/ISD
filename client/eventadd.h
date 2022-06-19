#ifndef EVENTADD_H
#define EVENTADD_H

#include <QDialog>
#include "client.h"
#include "functions_for_client.h"
namespace Ui {
class eventAdd;
}

class eventAdd : public QDialog
{
    Q_OBJECT

public:
    explicit eventAdd(QWidget *parent = nullptr);
    ~eventAdd();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::eventAdd *ui;
};

#endif // EVENTADD_H
