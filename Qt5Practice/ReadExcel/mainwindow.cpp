#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"excelbase.h"
#include"cinputlinestandard.h"
#include<QFile>
#include<QFileDialog>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QString S="..\444.xlsx";
    //QFile file("444.xlsx");

        ExcelBase excel;
       // ui->label->setText(excel.m_datas[38].at(5).toString());
        QString S1=excel.m_datas[11].at(2).toString();
        QStringList list=S1.split(" ");
       qDebug()<< list.at(1);
       //ui->label->setText(list.at(3));

       m_Groupbutton.addButton(ui->Yes_checkBox,1);
       m_Groupbutton.addButton(ui->No_checkBox,2);

       ui->TwistedPair_comboBox->addItem(QWidget::tr("8芯双绞线"));
       ui->TwistedPair_comboBox->addItem(QWidget::tr("8芯双绞线灰"));
        connect(ui->TwistedPair_comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(getTwistedPairType(QString)));

       ui->BothPort_comboBox->addItem(QWidget::tr("RJ45"));

       CInPutLineStandard *Input=new CInPutLineStandard;
       Input->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::getTwistedPairType(QString S)
{
    qDebug()<<S;
}
