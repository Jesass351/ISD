#ifndef SERVICETABLE_H
#define SERVICETABLE_H

#include <QDialog>

namespace Ui {
class serviceTable;
}

class serviceTable : public QDialog
{
    Q_OBJECT

public:
    explicit serviceTable(QWidget *parent = nullptr);
    ~serviceTable();
    void addtoTable(QString data);
    inline static QString dataP;
    static QString getData(){
        return dataP;
    }
    static void setData(QString d){
        dataP = d;
    }
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::serviceTable *ui;
};

#endif // SERVICETABLE_H
