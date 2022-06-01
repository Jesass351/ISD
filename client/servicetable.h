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

private slots:
    void on_pushButton_clicked();

private:
    Ui::serviceTable *ui;
};

#endif // SERVICETABLE_H
