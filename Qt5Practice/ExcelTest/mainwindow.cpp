#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QAxObject>
#include<QFileDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString fileName=QFileDialog::getSaveFileName(this,tr("open"),QDir::currentPath());
    if(!fileName.isEmpty())
    {
       //QAxObject *excel=new QAxObject(this);
       //excel->setControl("Excel.Application");
       //excel->dynamicCall("SetVisible(bool Visible)","false");
       //excel->setProperty("DisplayAlerts",false);
           QAxObject *work_book = NULL;
           QAxObject excel("Excel.Application");
           excel.setProperty("Visible", true);
           excel.setProperty("DisplayAlerts", false);//不显示任何警告信息
           QAxObject *work_books = excel.querySubObject("WorkBooks");
           QFile xlsFile(fileName);
           if (xlsFile.exists()) {
               work_book = work_books->querySubObject("Open(const QString &)",  fileName);
           }
           else {
               work_books->dynamicCall("Add");
               work_book = excel.querySubObject("ActiveWorkBook");
           }
           QAxObject *work_sheets = work_book->querySubObject("Sheets");
           QAxObject *first_sheet = work_sheets->querySubObject("Item(int)", 1);
           QAxObject *cell = first_sheet->querySubObject("Cells(int,int)", 1, 1);
         // cell=first_sheet->querySubObject("Cells(int,int)", 2,1);
           // cell->dynamicCall("Value","测试第一行第三列");

           /*
           QString merge_cell;
           merge_cell.append(QChar(1-1 + 'A'));  //初始列第3列
           merge_cell.append(QString::number(1));  //初始行第6行
           merge_cell.append(":");
           merge_cell.append(QChar(9 + 'A'));  //终止列第5列
           merge_cell.append(QString::number(2));  //终止行第八行
           QAxObject *merge_range = first_sheet->querySubObject("Range(const QString&)", merge_cell);
           merge_range->setProperty("HorizontalAlignment", -4108);
           merge_range->setProperty("VerticalAlignment", -4108);
           merge_range->setProperty("WrapText", true);
           merge_range->setProperty("MergeCells", true);  //合并单元格


           cell->setProperty("Value", "test");
           cell=first_sheet->querySubObject("Cells(int,int)",1,3);
           cell->dynamicCall("Value","测试第一行第三列");
           cell->setProperty("WrapText", true);

           cell=first_sheet->querySubObject("Cells(int,int)",3,1);
           cell->dynamicCall("Value","5*4");
           */

           /*
           QString merge_cell;
           merge_cell.append(QChar(3 + 'A'));  //初始列第3列
           merge_cell.append(QString::number(6));  //初始行第6行
           merge_cell.append(":");
           merge_cell.append(QChar(5 + 'A'));  //终止列第5列
           merge_cell.append(QString::number(8));  //终止行第八行
           QAxObject *merge_range = first_sheet->querySubObject("Range(const QString&)", merge_cell);
           merge_range->setProperty("HorizontalAlignment", -4108);
           merge_range->setProperty("VerticalAlignment", -4108);
           merge_range->setProperty("WrapText", true);
           merge_range->setProperty("MergeCells", true);  //合并单元格
           //merge_range->setProperty("MergeCells", false);  //拆分单元格
           */
           for(int i=1;i<10;i++)
           {
               cell=first_sheet->querySubObject("Cells(int,int)",3,i);
               QAxObject* interior = cell->querySubObject("Interior");
              // interior->setProperty("Color", QColor(0, 255, 0));
               interior->setProperty("Color",QColor(173,171,168));//背景颜色设置
               cell->setProperty("HorizontalAlignment", -4108);   //居中
               cell->setProperty ("VerticalAlignment", -4108);
               QAxObject *font = cell->querySubObject("Font");
               font->setProperty("Name",QStringLiteral("宋体"));//字体
               font->setProperty("Bold",true);//加粗
           }

           cell=first_sheet->querySubObject("Cells(int,int)",3,1);
           cell->dynamicCall("Value","导线名称");
           cell->setProperty("RowHeight",20);
           cell->setProperty("ColumnWidth",8);
           cell->setProperty("Color",QColor(173,171,168));//背景颜色设置
           cell->setProperty("HorizontalAlignment", -4108);   //居中
           cell->setProperty ("VerticalAlignment", -4108);
           cell->setProperty("Name",QStringLiteral("宋体"));//字体
           cell->setProperty("Bold",true);//加粗

           cell=first_sheet->querySubObject("Cells(int,int)",3,2);
           cell->dynamicCall("Value","物料代码");
           cell->setProperty("RowHeight",20);
           cell->setProperty("ColumnWidth",10);

           cell=first_sheet->querySubObject("Cells(int,int)",3,3);
           cell->dynamicCall("Value","名称");
           cell->setProperty("RowHeight",20);
           cell->setProperty("ColumnWidth",6);

           cell=first_sheet->querySubObject("Cells(int,int)",3,4);
           cell->dynamicCall("Value","线号");
           cell->setProperty("RowHeight",20);
           cell->setProperty("ColumnWidth",4);

           cell=first_sheet->querySubObject("Cells(int,int)",3,5);
           cell->dynamicCall("Value","规格型号");
           cell->setProperty("RowHeight",20);
           cell->setProperty("ColumnWidth",24);

           cell=first_sheet->querySubObject("Cells(int,int)",3,6);
           cell->dynamicCall("Value","基数");
           cell->setProperty("RowHeight",20);
           cell->setProperty("ColumnWidth",5);

           cell=first_sheet->querySubObject("Cells(int,int)",3,7);
           cell->dynamicCall("Value","单位");
           cell->setProperty("RowHeight",20);
           cell->setProperty("ColumnWidth",5);

           cell=first_sheet->querySubObject("Cells(int,int)",3,8);
           cell->dynamicCall("Value","合计");
           cell->setProperty("RowHeight",20);
           cell->setProperty("ColumnWidth",5);

           cell=first_sheet->querySubObject("Cells(int,int)",3,9);
           cell->dynamicCall("Value","备注");
           cell->setProperty("RowHeight",20);
           cell->setProperty("ColumnWidth",8);

              work_book->dynamicCall("SaveAs(const QString &)", QDir::toNativeSeparators(fileName)); //转换路径不可少，否则会崩溃
              work_book->dynamicCall("Close(Boolean)", false);  //关闭文件
              excel.dynamicCall("Quit(void)");  //退出
    }


}
