#include "softwarelist.h"

SoftwareList::SoftwareList() {}

void SoftwareList::add(Software s)
{
    softList.append(s);
}

QList<Software> SoftwareList::getSoftList() const
{
    return softList;
}
