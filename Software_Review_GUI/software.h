#ifndef SOFTWARE_H
#define SOFTWARE_H
#include<QString>
#include<QDate>
#include<QObject>

class Software :public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName)
    Q_PROPERTY(QDate date READ getDate WRITE setDate)
    Q_PROPERTY(bool recommend READ getRecommend  WRITE setRecommend)

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
