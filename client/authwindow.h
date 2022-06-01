#ifndef AUTHWINDOW_H
#define AUTHWINDOW_H

#include <QDialog>
#include "QString"
#include "QMessageBox"
#include "functions_for_client.h"

namespace Ui {
class AuthWindow;
}

class AuthWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AuthWindow(QWidget *parent = nullptr);
    ~AuthWindow();



private slots:
    void on_authRegButton_clicked();

    void on_regLoginButton_clicked();

    void on_authEnterButton_clicked();

    void on_regEnterButton_clicked();

signals:
    void send_data (QString log);

private:
    Ui::AuthWindow *ui;

};

#endif // AUTHWINDOW_H
