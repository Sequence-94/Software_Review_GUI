#include "listwriter.h"
#include"filewriter.h"
#include<QVariant>
#include<QMetaObject>
#include<QMetaProperty>

ListWriter::ListWriter() {}

void ListWriter::write(SoftwareList* sl) const
{

    QList<Software*>* list = sl->getSoftList();
    QString alldata="";

    foreach(QObject* s,*list){
        const QMetaObject *meta = s->metaObject();
        int totalProperties = meta->propertyCount();
        for(int i=1;i<totalProperties;i++){
            QMetaProperty prop = meta->property(i);
            QVariant propValue = prop.read(s);
            if(propValue.typeId()==QVariant::String){
                QString value = propValue.toString();
                alldata.append(value);

            }
            if(propValue.typeId()==QVariant::Date){
                QString value = propValue.toDate().toString("yyyy/MM/dd");
                alldata.append(value);

            }
            if(propValue.typeId()==QVariant::Bool){
                QString value = QVariant(propValue.toBool()).toString();
                alldata.append(value);

            }alldata.append("#");

        }alldata.append("\n");
    }
    FileWriter f("sequencefile.txt");
    f.write(alldata);

}
