#include "software.h"

Software::Software() {}

Software::Software(QString n, QDate d, bool r):name{n},date{d},recommend{r}
{

}

QString Software::getName() const
{
    return name;
}

void Software::setName(const QString &newName)
{
    name = newName;
}

bool Software::getRecommend() const
{
    return recommend;
}

void Software::setRecommend(bool newRecommend)
{
    recommend = newRecommend;
}

QDate Software::getDate() const
{
    return date;
}

void Software::setDate(const QDate &newDate)
{
    date = newDate;
}
