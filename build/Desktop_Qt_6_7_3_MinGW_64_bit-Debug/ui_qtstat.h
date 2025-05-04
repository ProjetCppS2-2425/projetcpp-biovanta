/********************************************************************************
** Form generated from reading UI file 'qtstat.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTSTAT_H
#define UI_QTSTAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Qtstat
{
public:

    void setupUi(QDialog *Qtstat)
    {
        if (Qtstat->objectName().isEmpty())
            Qtstat->setObjectName("Qtstat");
        Qtstat->resize(640, 480);

        retranslateUi(Qtstat);

        QMetaObject::connectSlotsByName(Qtstat);
    } // setupUi

    void retranslateUi(QDialog *Qtstat)
    {
        Qtstat->setWindowTitle(QCoreApplication::translate("Qtstat", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Qtstat: public Ui_Qtstat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTSTAT_H
