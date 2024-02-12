#ifndef SOFTWARE_H
#define SOFTWARE_H
#include<QString>
#include<QDate>

class Software
{
public:
    Software();
    Software(QString n,QDate d,bool r);

    QString getName() const;
    void setName(const QString &newName);

    bool getRecommend() const;
    void setRecommend(bool newRecommend);

    QDate getDate() const;
    void setDate(const QDate &newDate);

private:
    QString name;
    QDate date;
    bool recommend;

};

#endif // SOFTWARE_H
