#ifndef CONTROLTABLE_H
#define CONTROLTABLE_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class controltable; }
QT_END_NAMESPACE


class controltable : public QDialog
{
    Q_OBJECT

public:
    explicit controltable(QWidget *parent = nullptr);
    ~controltable();
    void addtoTable(QString data);
    inline static QString dataCon;
    static QString getDataCon(){
        return dataCon;
    }
private slots:
    void on_pushButton_clicked();

    void on_add_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::controltable *ui;
};

#endif // CONTROLTABLE_H
