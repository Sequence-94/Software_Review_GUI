#include "softwaregui.h"
#include<QLineEdit>
#include<QDateEdit>
#include<QCheckBox>
#include<QPushButton>
#include<QLabel>
#include<QGridLayout>



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
    //setMinimumSize(350,350);

    //signals & slots
    connect(addButton,&QPushButton::clicked,this,&SoftwareGui::addSoftware);
    connect(disButton,&QPushButton::clicked,this,&SoftwareGui::displaySoftware);

}

void SoftwareGui::addSoftware()
{

}

void SoftwareGui::displaySoftware()
{

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
