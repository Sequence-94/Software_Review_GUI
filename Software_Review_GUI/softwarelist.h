#ifndef SOFTWARELIST_H
#define SOFTWARELIST_H
#include"software.h"
#include<QList>

class SoftwareList
{
public:
    SoftwareList();
    void add(Software s);
    QList<Software> getSoftList() const;

private:
    QList<Software> softList;
};

#endif // SOFTWARELIST_H
