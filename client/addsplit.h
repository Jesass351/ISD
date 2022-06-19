#ifndef ADDSPLIT_H
#define ADDSPLIT_H

#include <QDialog>

namespace Ui {
class addSplit;
}

class addSplit : public QDialog
{
    Q_OBJECT

public:
    explicit addSplit(QWidget *parent = nullptr);
    ~addSplit();

private slots:
    void on_pushButton_clicked();

private:
    Ui::addSplit *ui;
};

#endif // ADDSPLIT_H
