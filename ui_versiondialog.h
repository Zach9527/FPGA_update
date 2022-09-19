/********************************************************************************
** Form generated from reading UI file 'versiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERSIONDIALOG_H
#define UI_VERSIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_versionDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *versionLable;

    void setupUi(QDialog *versionDialog)
    {
        if (versionDialog->objectName().isEmpty())
            versionDialog->setObjectName(QStringLiteral("versionDialog"));
        versionDialog->resize(262, 101);
        buttonBox = new QDialogButtonBox(versionDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 60, 231, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        layoutWidget = new QWidget(versionDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 241, 20));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_2);

        versionLable = new QLabel(layoutWidget);
        versionLable->setObjectName(QStringLiteral("versionLable"));

        horizontalLayout_2->addWidget(versionLable);


        retranslateUi(versionDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), versionDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), versionDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(versionDialog);
    } // setupUi

    void retranslateUi(QDialog *versionDialog)
    {
        versionDialog->setWindowTitle(QApplication::translate("versionDialog", "\347\211\210\346\234\254\344\277\241\346\201\257", Q_NULLPTR));
        label_2->setText(QApplication::translate("versionDialog", "\350\275\257\344\273\266\347\211\210\346\234\254\357\274\232", Q_NULLPTR));
        versionLable->setText(QApplication::translate("versionDialog", "V1.00", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class versionDialog: public Ui_versionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERSIONDIALOG_H
