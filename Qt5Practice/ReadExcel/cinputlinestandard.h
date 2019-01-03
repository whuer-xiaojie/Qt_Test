#ifndef CINPUTLINESTANDARD_H
#define CINPUTLINESTANDARD_H

#include <QMainWindow>

namespace Ui {
class CInPutLineStandard;
}

class CInPutLineStandard : public QMainWindow
{
    Q_OBJECT

public:
    explicit CInPutLineStandard(QWidget *parent = 0);
    ~CInPutLineStandard();

private:
    Ui::CInPutLineStandard *ui;
};

#endif // CINPUTLINESTANDARD_H
