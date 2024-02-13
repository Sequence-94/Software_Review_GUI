#include "listreader.h"
#include<QString>
#include<QVariant>
#include"filereader.h"

ListReader::ListReader() {}

SoftwareList* ListReader::read() const
{
    FileReader fr("sequencefile.txt");
    QString str = fr.read();
    SoftwareList* list(new SoftwareList());
    QStringList data = str.split("\n");
    for(int i=1;i<data.size()-1;i++){
        QStringList line = data.at(i).split("#");
        Software* s(new Software(line.at(0),
                   QDate::fromString(line.at(1),"yyyy/MM/dd"),
                                 QVariant(line.at(2)).toBool())
                   );
        list->add(s);
    }
    return list;
}
