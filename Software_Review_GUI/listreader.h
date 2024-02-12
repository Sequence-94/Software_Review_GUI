#ifndef LISTREADER_H
#define LISTREADER_H
#include"softwarelist.h"
class ListReader
{
public:
    ListReader();
    SoftwareList read() const;
};

#endif // LISTREADER_H
