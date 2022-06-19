#ifndef ADDCLIENT_H
#define ADDCLIENT_H

#include <QDialog>

namespace Ui {
class addClient;
}

class addClient : public QDialog
{
    Q_OBJECT

public:
    explicit addClient(QWidget *parent = nullptr);
    ~addClient();

private:
    Ui::addClient *ui;
};

#endif // ADDCLIENT_H
