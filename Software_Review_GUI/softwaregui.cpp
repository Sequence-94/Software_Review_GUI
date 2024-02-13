#include "softwaregui.h"
#include<QLineEdit>
#include<QDateEdit>
#include<QCheckBox>
#include<QPushButton>
#include<QLabel>
#include<QGridLayout>
#include<QMessageBox>
#include<QObject>
#include<QMetaProperty>
#include<QMetaObject>
#include"listwriter.h"
#include"software.h"
#include"listreader.h"





SoftwareGui::SoftwareGui(QWidget *parent)
    : QWidget{parent},
    nameInput(new QLineEdit),
    dateInput(new QDateEdit),
    recoInput(new QCheckBox),
    addButton(new QPushButton("Add")),
    disButton(new QPushButton("Display"))
{
    //GUI
    softwareReviewGui();
    setWindowTitle("Software Review");
    setMinimumSize(350,350);

    //signals & slots
    connect(addButton,&QPushButton::clicked,this,&SoftwareGui::addSoftware);
    connect(disButton,&QPushButton::clicked,this,&SoftwareGui::displaySoftware);

    //initialize widgets
    nameInput->setPlaceholderText("Enter Software Name Here");
    nameInput->setToolTip("Max 50 characters");
    nameInput->setMaxLength(50);

    dateInput->setToolTip("Enter The Date Of The Review");

    recoInput->setToolTip("Mark if you would recommend software otherwise leave as unmarked");

    addButton->setToolTip("Add Review To Container");
    disButton->setToolTip("Display All Reviews Currently Inside The Container");
}

void SoftwareGui::addSoftware()
{
    Software* s(new Software(nameInput->text(),dateInput->date(),recoInput->isChecked()));
    SoftwareList* sl(new SoftwareList());
    sl->add(s);
    ListWriter lw;
    lw.write(sl);

    //reset widgets
    nameInput->clear();
    nameInput->setFocus();

    dateInput->setDate(QDate(2000,01,01));

    recoInput->setChecked(false);

    QMessageBox msgBox;
    msgBox.setText("The Review Has Been Added To The Container.");
    msgBox.exec();


}

void SoftwareGui::displaySoftware()
{
    SoftwareList* list(new SoftwareList());
    ListReader lr;
    list = lr.read();

    QTextStream cout(stdout);
    QList<Software*>* sl = list->getSoftList();
    // foreach(QObject* s,*sl){
    //     cout<<
    //         s->getName()<<": "<<
    //         s->getDate().toString("yyyy/MM/dd")<<": "<<
    //         QVariant(s->getRecommend()).toString()
    //          <<"\n";
    // }

    foreach(QObject*s,*sl){

        const QMetaObject *meta = s->metaObject();
        int totalProperties = meta->propertyCount();
        QString data="";
        for(int i=1;i<totalProperties;i++){
            QMetaProperty prop = meta->property(i);
            QVariant propValue = prop.read(s);
            if(propValue.typeId()==QVariant::String){
                QString value = propValue.toString();
                data.append(value);
                data.append(" : ");
            }
            if(propValue.typeId()==QVariant::Date){
                QString value = propValue.toDate().toString("yyyy/MM/dd");
                data.append(value);
                data.append(" : ");
            }
            if(propValue.typeId()==QVariant::Bool){
                QString value = QVariant(propValue.toBool()).toString();
                data.append(value);
                data.append("\n");
            }
        }
        cout<<data;
    }
}

void SoftwareGui::softwareReviewGui()
{

    QGridLayout *layout(new QGridLayout(this));
    QLabel *instructionLabel(new QLabel("Fill in the data and click add"));
    QLabel *nameLabel(new QLabel("Name"));
    QLabel *DateLabel(new QLabel("Date"));
    QLabel *recoLabel(new QLabel("Recommend"));

    layout->addWidget(instructionLabel,0,0,1,2);
    layout->addWidget(nameLabel,1,0);
    layout->addWidget(nameInput,1,1);
    layout->addWidget(DateLabel,2,0);
    layout->addWidget(dateInput,2,1);
    layout->addWidget(recoLabel,3,1);
    layout->addWidget(recoInput,3,2);

    layout->addWidget(addButton,4,0);
    layout->addWidget(disButton,4,2);




}
