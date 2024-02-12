#include <QApplication>
#include"software.h"
#include"softwarelist.h"
#include"softwaregui.h"
#include"listreader.h"
#include"listwriter.h"
#include<QDate>
#include<QString>
#include<QTextStream>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDate d1(1995, 5, 17);
    QDate d2(1995, 5, 20);
    Software soft1("Marvel",d1,true);
    Software soft2("Star Wars",d2,true);

    SoftwareList list1;
    list1.add(soft1);
    list1.add(soft2);

    ListWriter lw;
    lw.write(list1);

    SoftwareList list2;
    ListReader lr;
    list2 = lr.read();

    QTextStream cout(stdout);
    QList<Software> sl = list2.getSoftList();
    foreach(Software s,sl){
        cout<<s.getName()<<": "<<s.getDate().toString("yyyy/MM/dd")<<": "<<QVariant(s.getRecommend()).toString()<<"\n";
    }

    SoftwareGui software;
    software.show();

    return a.exec();
}
