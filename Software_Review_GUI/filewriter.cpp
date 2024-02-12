#include "filewriter.h"
#include <QFile>
#include<QTextStream>

FileWriter::FileWriter(QString fn):fileName{fn}
{

}

void FileWriter::write(QString s) const
{

    QFile file(fileName);
    if(file.open(QIODevice::WriteOnly)){
        QTextStream cout(&file);
        cout<<s;
        file.close();
    }
}
