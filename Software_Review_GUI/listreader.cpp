#include "listreader.h"
#include<QString>
#include<QVariant>
#include"filereader.h"

ListReader::ListReader() {}

SoftwareList ListReader::read() const
{
    FileReader fr("sequencefile.txt");
    QString str = fr.read();
    SoftwareList list;
    QStringList data = str.split("\n");
    for(int i=0;i<data.size()-1;i++){
        QStringList line = data.at(i).split("#");
        Software s(line.at(0),
                   QDate::fromString(line.at(1),"dd-MM-yyyy"),
                   QVariant(line.at(2)).toBool()
                   );
        list.add(s);
    }
    return list;
}
