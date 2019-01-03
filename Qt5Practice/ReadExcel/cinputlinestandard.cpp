#include "cinputlinestandard.h"
#include "ui_cinputlinestandard.h"

CInPutLineStandard::CInPutLineStandard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CInPutLineStandard)
{
    ui->setupUi(this);
}

CInPutLineStandard::~CInPutLineStandard()
{
    delete ui;
}
