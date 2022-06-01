#ifndef CONTROLTABLE_H
#define CONTROLTABLE_H

#include <QDialog>

namespace Ui {
class controltable;
}

class controltable : public QDialog
{
    Q_OBJECT

public:
    explicit controltable(QWidget *parent = nullptr);
    ~controltable();

private slots:
    void on_pushButton_clicked();

private:
    Ui::controltable *ui;
};

#endif // CONTROLTABLE_H
