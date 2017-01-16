/********************************************************************************
** Form generated from reading UI file 'makefonts.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAKEFONTS_H
#define UI_MAKEFONTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MakeFontsClass
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *settingName;
    QTabWidget *tabWidget;
    QWidget *tab_text;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableTexts;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *butAddTextFile;
    QPushButton *butRemoveTextFile;
    QWidget *tab_fonts;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableFonts;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *butAddFont;
    QPushButton *butRemoveFont;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *butGenerate;
    QPushButton *butClose;

    void setupUi(QDialog *MakeFontsClass)
    {
        if (MakeFontsClass->objectName().isEmpty())
            MakeFontsClass->setObjectName(QStringLiteral("MakeFontsClass"));
        MakeFontsClass->resize(785, 519);
        verticalLayout_3 = new QVBoxLayout(MakeFontsClass);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        widget_2 = new QWidget(MakeFontsClass);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, 0, -1);
        label = new QLabel(widget_2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        settingName = new QLineEdit(widget_2);
        settingName->setObjectName(QStringLiteral("settingName"));

        horizontalLayout_2->addWidget(settingName);


        verticalLayout_3->addWidget(widget_2);

        tabWidget = new QTabWidget(MakeFontsClass);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_text = new QWidget();
        tab_text->setObjectName(QStringLiteral("tab_text"));
        verticalLayout_2 = new QVBoxLayout(tab_text);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tableTexts = new QTableWidget(tab_text);
        tableTexts->setObjectName(QStringLiteral("tableTexts"));
        tableTexts->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableTexts->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_2->addWidget(tableTexts);

        widget = new QWidget(tab_text);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(576, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        butAddTextFile = new QPushButton(widget);
        butAddTextFile->setObjectName(QStringLiteral("butAddTextFile"));

        horizontalLayout->addWidget(butAddTextFile);

        butRemoveTextFile = new QPushButton(widget);
        butRemoveTextFile->setObjectName(QStringLiteral("butRemoveTextFile"));

        horizontalLayout->addWidget(butRemoveTextFile);


        verticalLayout_2->addWidget(widget);

        tabWidget->addTab(tab_text, QString());
        tab_fonts = new QWidget();
        tab_fonts->setObjectName(QStringLiteral("tab_fonts"));
        verticalLayout = new QVBoxLayout(tab_fonts);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableFonts = new QTableWidget(tab_fonts);
        if (tableFonts->columnCount() < 1)
            tableFonts->setColumnCount(1);
        if (tableFonts->rowCount() < 1)
            tableFonts->setRowCount(1);
        tableFonts->setObjectName(QStringLiteral("tableFonts"));
        tableFonts->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableFonts->setRowCount(1);
        tableFonts->setColumnCount(1);
        tableFonts->horizontalHeader()->setVisible(false);
        tableFonts->horizontalHeader()->setCascadingSectionResizes(false);
        tableFonts->horizontalHeader()->setHighlightSections(true);
        tableFonts->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableFonts->horizontalHeader()->setStretchLastSection(true);
        tableFonts->verticalHeader()->setVisible(false);
        tableFonts->verticalHeader()->setHighlightSections(true);

        verticalLayout->addWidget(tableFonts);

        widget_4 = new QWidget(tab_fonts);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(578, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        butAddFont = new QPushButton(widget_4);
        butAddFont->setObjectName(QStringLiteral("butAddFont"));

        horizontalLayout_4->addWidget(butAddFont);

        butRemoveFont = new QPushButton(widget_4);
        butRemoveFont->setObjectName(QStringLiteral("butRemoveFont"));

        horizontalLayout_4->addWidget(butRemoveFont);


        verticalLayout->addWidget(widget_4);

        tabWidget->addTab(tab_fonts, QString());

        verticalLayout_3->addWidget(tabWidget);

        widget_3 = new QWidget(MakeFontsClass);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(602, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        butGenerate = new QPushButton(widget_3);
        butGenerate->setObjectName(QStringLiteral("butGenerate"));

        horizontalLayout_3->addWidget(butGenerate);

        butClose = new QPushButton(widget_3);
        butClose->setObjectName(QStringLiteral("butClose"));

        horizontalLayout_3->addWidget(butClose);


        verticalLayout_3->addWidget(widget_3);


        retranslateUi(MakeFontsClass);
        QObject::connect(butClose, SIGNAL(clicked()), MakeFontsClass, SLOT(close()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MakeFontsClass);
    } // setupUi

    void retranslateUi(QDialog *MakeFontsClass)
    {
        MakeFontsClass->setWindowTitle(QApplication::translate("MakeFontsClass", "MakeFonts", 0));
        label->setText(QApplication::translate("MakeFontsClass", "Settings name", 0));
#ifndef QT_NO_ACCESSIBILITY
        tab_text->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        butAddTextFile->setText(QApplication::translate("MakeFontsClass", "Add...", 0));
        butRemoveTextFile->setText(QApplication::translate("MakeFontsClass", "Remove", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_text), QApplication::translate("MakeFontsClass", "Text", 0));
        butAddFont->setText(QApplication::translate("MakeFontsClass", "Add...", 0));
        butRemoveFont->setText(QApplication::translate("MakeFontsClass", "Remove", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_fonts), QApplication::translate("MakeFontsClass", "Fonts", 0));
        butGenerate->setText(QApplication::translate("MakeFontsClass", "Generate", 0));
        butClose->setText(QApplication::translate("MakeFontsClass", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class MakeFontsClass: public Ui_MakeFontsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAKEFONTS_H
