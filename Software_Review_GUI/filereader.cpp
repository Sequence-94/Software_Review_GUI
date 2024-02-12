#include "filereader.h"
#include<QFile>
#include<QTextStream>

FileReader::FileReader(QString fn) :fileName{fn}
{

}

QString FileReader::read() const
{
    QFile file(fileName);
    if(file.open(QIODevice::ReadOnly)){
        QTextStream cin(&file);
        QString s = cin.readAll();
        file.close();
        return s;
    }
    return QString();
}
