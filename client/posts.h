#ifndef POSTS_H
#define POSTS_H

#include <QDialog>

namespace Ui {
class posts;
}

class posts : public QDialog
{
    Q_OBJECT

public:
    explicit posts(QWidget *parent = nullptr);
    ~posts();
    void posts::addtoTable(QString data);
private slots:
    void on_pushButton_clicked();

private:
    Ui::posts *ui;
};

#endif // POSTS_H
