#include <QApplication>
#include"softwaregui.h"
#include"software.h"
#include"softwarelist.h"
#include<QDate>
#include<QString>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDate d1(1995, 5, 17);
    QDate d2(1995, 5, 20);
    Software soft1("Marvel",d1,true);
    Software soft2("Star Wars",d2,true);

    SoftwareList list;
    list.add(soft1);
    list.add(soft2);

    SoftwareGui software;
    software.show();

    return a.exec();
}
