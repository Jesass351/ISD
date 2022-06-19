#ifndef ABOUTSPLIT_H
#define ABOUTSPLIT_H

#include <QDialog>

namespace Ui {
class AboutSplit;
}

class AboutSplit : public QDialog
{
    Q_OBJECT

public:
    explicit AboutSplit(QWidget *parent = nullptr);
    ~AboutSplit();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_addClient_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::AboutSplit *ui;
};

#endif // ABOUTSPLIT_H
