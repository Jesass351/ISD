#ifndef SPLIT_H
#define SPLIT_H

#include <QDialog>

namespace Ui {
class split;
}

class split : public QDialog
{
    Q_OBJECT

public:
    explicit split(QWidget *parent = nullptr);
    ~split();
    inline static QString splitNum;
    static QString getSplitNum(){
        return splitNum;
    }
private slots:
    void on_refresh_clicked();

    void on_detailed_clicked();


    void on_addPilot_clicked();

    void on_addSplit_clicked();

private:
    Ui::split *ui;
};

#endif // SPLIT_H
