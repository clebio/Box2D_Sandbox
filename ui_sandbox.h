/********************************************************************************
** Form generated from reading UI file 'sandbox.ui'
**
** Created: Sun Apr 24 09:41:23 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SANDBOX_H
#define UI_SANDBOX_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "box2dview.h"

QT_BEGIN_NAMESPACE

class Ui_sandboxClass
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *createObjLabel;
    QVBoxLayout *verticalLayout;
    QRadioButton *circleRadio;
    QRadioButton *rectRadio;
    QRadioButton *polyRadio;
    QHBoxLayout *horizontalLayout;
    QLabel *densitySlideLabel;
    QSlider *densitySlider;
    QHBoxLayout *horizontalLayout_2;
    QLabel *restitutionSlide;
    QSlider *restitutionSlider;
    QHBoxLayout *horizontalLayout_3;
    QLabel *frictionSlide;
    QSlider *frictionSlider;
    QSpacerItem *verticalSpacer;
    QPushButton *resetButton;
    Box2DView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QButtonGroup *createGroup;

    void setupUi(QMainWindow *sandboxClass)
    {
        if (sandboxClass->objectName().isEmpty())
            sandboxClass->setObjectName(QString::fromUtf8("sandboxClass"));
        sandboxClass->resize(800, 600);
        centralwidget = new QWidget(sandboxClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        createObjLabel = new QLabel(frame);
        createObjLabel->setObjectName(QString::fromUtf8("createObjLabel"));

        verticalLayout_2->addWidget(createObjLabel);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        circleRadio = new QRadioButton(frame);
        createGroup = new QButtonGroup(sandboxClass);
        createGroup->setObjectName(QString::fromUtf8("createGroup"));
        createGroup->addButton(circleRadio);
        circleRadio->setObjectName(QString::fromUtf8("circleRadio"));
        circleRadio->setChecked(true);

        verticalLayout->addWidget(circleRadio);

        rectRadio = new QRadioButton(frame);
        createGroup->addButton(rectRadio);
        rectRadio->setObjectName(QString::fromUtf8("rectRadio"));

        verticalLayout->addWidget(rectRadio);

        polyRadio = new QRadioButton(frame);
        createGroup->addButton(polyRadio);
        polyRadio->setObjectName(QString::fromUtf8("polyRadio"));

        verticalLayout->addWidget(polyRadio);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        densitySlideLabel = new QLabel(frame);
        densitySlideLabel->setObjectName(QString::fromUtf8("densitySlideLabel"));

        horizontalLayout->addWidget(densitySlideLabel);

        densitySlider = new QSlider(frame);
        densitySlider->setObjectName(QString::fromUtf8("densitySlider"));
        densitySlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(densitySlider);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        restitutionSlide = new QLabel(frame);
        restitutionSlide->setObjectName(QString::fromUtf8("restitutionSlide"));

        horizontalLayout_2->addWidget(restitutionSlide);

        restitutionSlider = new QSlider(frame);
        restitutionSlider->setObjectName(QString::fromUtf8("restitutionSlider"));
        restitutionSlider->setMaximum(100);
        restitutionSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(restitutionSlider);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        frictionSlide = new QLabel(frame);
        frictionSlide->setObjectName(QString::fromUtf8("frictionSlide"));

        horizontalLayout_3->addWidget(frictionSlide);

        frictionSlider = new QSlider(frame);
        frictionSlider->setObjectName(QString::fromUtf8("frictionSlider"));
        frictionSlider->setMaximum(100);
        frictionSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(frictionSlider);


        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 255, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        resetButton = new QPushButton(frame);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));

        verticalLayout_3->addWidget(resetButton);


        horizontalLayout_4->addWidget(frame);

        graphicsView = new Box2DView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy1);
        graphicsView->setMinimumSize(QSize(500, 0));
        graphicsView->setRenderHints(QPainter::Antialiasing|QPainter::HighQualityAntialiasing|QPainter::TextAntialiasing);

        horizontalLayout_4->addWidget(graphicsView);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        sandboxClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(sandboxClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        sandboxClass->setMenuBar(menubar);
        statusbar = new QStatusBar(sandboxClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        sandboxClass->setStatusBar(statusbar);

        retranslateUi(sandboxClass);

        QMetaObject::connectSlotsByName(sandboxClass);
    } // setupUi

    void retranslateUi(QMainWindow *sandboxClass)
    {
        sandboxClass->setWindowTitle(QApplication::translate("sandboxClass", "MainWindow", 0, QApplication::UnicodeUTF8));
        createObjLabel->setText(QApplication::translate("sandboxClass", "Create object...", 0, QApplication::UnicodeUTF8));
        circleRadio->setText(QApplication::translate("sandboxClass", "Circle", 0, QApplication::UnicodeUTF8));
        rectRadio->setText(QApplication::translate("sandboxClass", "Rectangle", 0, QApplication::UnicodeUTF8));
        polyRadio->setText(QApplication::translate("sandboxClass", "Polygon", 0, QApplication::UnicodeUTF8));
        densitySlideLabel->setText(QApplication::translate("sandboxClass", "Density:", 0, QApplication::UnicodeUTF8));
        restitutionSlide->setText(QApplication::translate("sandboxClass", "Restitution:", 0, QApplication::UnicodeUTF8));
        frictionSlide->setText(QApplication::translate("sandboxClass", "Friction", 0, QApplication::UnicodeUTF8));
        resetButton->setText(QApplication::translate("sandboxClass", "Reset world", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class sandboxClass: public Ui_sandboxClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SANDBOX_H
