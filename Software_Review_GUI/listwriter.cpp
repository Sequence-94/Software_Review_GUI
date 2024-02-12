#include "listwriter.h"
#include"filewriter.h"
#include<QVariant>
ListWriter::ListWriter() {}

void ListWriter::write(SoftwareList sl) const
{
    QList<Software> list = sl.getSoftList();
    QString alldata;
    foreach(Software s,list){
        alldata.append(QString(s.getName() + "#" +
                               s.getDate().toString("yyyy/MM/dd") + "#" +
                               QVariant(s.getRecommend()).toString()) + "\n");
    }
    FileWriter f("sequencefile.txt");
    f.write(alldata);

}
