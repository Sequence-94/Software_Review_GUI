#include <QApplication>
#include"softwaregui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SoftwareGui software;
    software.show();

    return a.exec();
}
