#ifndef LISTWRITER_H
#define LISTWRITER_H
#include"softwarelist.h"

class ListWriter
{
public:
    ListWriter();
    void write(SoftwareList* sl) const;
};

#endif // LISTWRITER_H
