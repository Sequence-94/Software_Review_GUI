#include "softwarelist.h"

SoftwareList::SoftwareList():softList{new QList<Software*>} {

}

SoftwareList::~SoftwareList()
{
    qDeleteAll(*softList);
    softList->clear();
    delete softList;
}

void SoftwareList::add(Software* s)
{
    softList->append(s);
}

QList<Software*>* SoftwareList::getSoftList() const
{
    return softList;
}
