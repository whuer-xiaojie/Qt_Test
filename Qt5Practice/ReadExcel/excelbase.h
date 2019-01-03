#ifndef EXCELBASE_H
#define EXCELBASE_H
#include<QAxObject>

class ExcelBase
{
public:
    ExcelBase();
    //QVariant readAll();
   // void castVariant2ListListVariant(const QVariant &var, QList<QList<QVariant> > &res);
    QScopedPointer<ExcelBase> m_xls;
    QList< QList<QVariant> > m_datas;
};

#endif // EXCELBASE_H
