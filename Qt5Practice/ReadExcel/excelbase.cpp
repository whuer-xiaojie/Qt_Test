
#include "excelbase.h"
#include<QFile>
#include<QAxObject>
#include<QDebug>

ExcelBase::ExcelBase()
{
    QString S="物料信息.xls";
    QFile file(S);
    if(file.open(QIODevice::ReadOnly))
    {
        QAxObject *work_book=NULL;
        QAxObject excel("Excel.Application");
        excel.setProperty("Visible",false);
        excel.setProperty("DisplayAlerts",false);
        QAxObject *work_books=excel.querySubObject("WorkBooks");
        work_books->dynamicCall("Open(const QString &)",QString("C:/Users/xid01406/Desktop/build-ReadExcel-Desktop_Qt_5_6_0_MinGW_32bit-Debug/物料信息.xls"));
        work_book=excel.querySubObject("ActiveWorkBook");
        QAxObject *work_sheets=work_book->querySubObject("WorkSheets");
        QAxObject *first_sheet=work_sheets->querySubObject("Item(int)",1);
        QVariant var;
        if (first_sheet != NULL && ! first_sheet->isNull())
        {
            QAxObject *usedRange =first_sheet->querySubObject("UsedRange");
            if(NULL == usedRange || usedRange->isNull())
            {
                return ;
            }
            var = usedRange->dynamicCall("Value");
            delete usedRange;
        }
        QVariantList varRows = var.toList();
        if(varRows.isEmpty())
        {
            return;
        }
        const int rowCount = varRows.size();
        QVariantList rowData;
        for(int i=0;i<rowCount;++i)
        {
            rowData = varRows[i].toList();
            m_datas.push_back(rowData);
        }
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<m_datas[i].size();j++)
            qDebug()<<"111"<<QString("%0").arg(m_datas[i].at(j).toString());
        }
        QString S1=m_datas[38].at(2).toString();
        QStringList list=S1.split(" ");
       qDebug()<< list.at(1);
    }

}

void castVariant2ListListVariant(const QVariant &var, QList<QList<QVariant> > &res)
{
    QVariantList varRows = var.toList();
    if(varRows.isEmpty())
    {
        return;
    }
    const int rowCount = varRows.size();
    QVariantList rowData;
    for(int i=0;i<rowCount;++i)
    {
        rowData = varRows[i].toList();
        res.push_back(rowData);
    }
}


/*
QVariant ExcelBase::readAll()
{
    QVariant var;
    if (this->sheet != NULL && ! this->sheet->isNull())
    {
        QAxObject *usedRange = this->sheet->querySubObject("UsedRange");
        if(NULL == usedRange || usedRange->isNull())
        {
            return var;
        }
        var = usedRange->dynamicCall("Value");
        delete usedRange;
    }
    return var;
}
*/
