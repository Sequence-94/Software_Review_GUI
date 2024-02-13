#ifndef SOFTWAREGUI_H
#define SOFTWAREGUI_H

#include <QWidget>
class QLineEdit;
class QDateEdit;
class QCheckBox;
class QPushButton;
class QMessageBox;


class SoftwareGui : public QWidget
{
    Q_OBJECT
public:
    explicit SoftwareGui(QWidget *parent = nullptr);

private slots:
    void addSoftware();
    void displaySoftware();

private:
    void softwareReviewGui();

    QLineEdit *nameInput;
    QDateEdit *dateInput;
    QCheckBox *recoInput;
    QPushButton *addButton;
    QPushButton *disButton;
};

#endif // SOFTWAREGUI_H
