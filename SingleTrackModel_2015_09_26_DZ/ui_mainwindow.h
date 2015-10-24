/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad_vehicle_parameter;
    QAction *actionSave_vehicle_parameter;
    QAction *actionLoad_Identification_Project;
    QAction *actionSave_Identification_Project;
    QAction *actionSteer_Gain_Ratio;
    QAction *actionLoad_DAS_Measurement;
    QAction *actionShow_YAWREF_and_FLATACC;
    QAction *actionBacksteerfilter_YawRate_Depend;
    QAction *actionBacksteer_for_model_filter;
    QAction *actionSignal_Setup;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGridLayout *MainLayout;
    QWidget *MeasurementsWidget;
    QWidget *gridLayoutWidget_3;
    QGridLayout *MeasurementsLayout;
    QWidget *Data;
    QHBoxLayout *horizontalLayout;
    QGridLayout *DataLayout;
    QGridLayout *EstimationLayout;
    QGroupBox *EstimationDataGroupBox;
    QHBoxLayout *EstimationDataLayout;
    QGroupBox *EstimationTypeGroupBox;
    QVBoxLayout *verticalLayout;
    QLabel *Normal;
    QLabel *Euler;
    QLabel *Other;
    QHBoxLayout *EstimationSubLayout;
    QGroupBox *SumDeltaGroupBox;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *SumDeltaLayout;
    QLabel *delta;
    QGroupBox *Optimization_groupbox;
    QGridLayout *gridLayout_2;
    QPushButton *Optimize_button;
    QLineEdit *Theta_value;
    QLineEdit *Cf_value;
    QLineEdit *Cr_value;
    QLabel *ThetaLabel;
    QLabel *CrLabel;
    QLabel *CfLabel;
    QGroupBox *Parameters_groupbox;
    QGridLayout *gridLayout_3;
    QLabel *LfLabel;
    QLabel *LrLabel;
    QLabel *MLabel;
    QLabel *ESMLabel;
    QLineEdit *ESM_value;
    QLineEdit *Lr_value;
    QLineEdit *Lf_value;
    QLineEdit *M_value;
    QLabel *LrLabel_3;
    QLabel *LrLabel_2;
    QPushButton *Apply_Parameters;
    QLineEdit *lineEdit_9;
    QMenuBar *menuBar;
    QMenu *menuVehicle;
    QMenu *menuMeasurement;
    QMenu *menuBacksteerfilter;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setContextMenuPolicy(Qt::DefaultContextMenu);
        actionLoad_vehicle_parameter = new QAction(MainWindow);
        actionLoad_vehicle_parameter->setObjectName(QStringLiteral("actionLoad_vehicle_parameter"));
        actionSave_vehicle_parameter = new QAction(MainWindow);
        actionSave_vehicle_parameter->setObjectName(QStringLiteral("actionSave_vehicle_parameter"));
        actionLoad_Identification_Project = new QAction(MainWindow);
        actionLoad_Identification_Project->setObjectName(QStringLiteral("actionLoad_Identification_Project"));
        actionSave_Identification_Project = new QAction(MainWindow);
        actionSave_Identification_Project->setObjectName(QStringLiteral("actionSave_Identification_Project"));
        actionSteer_Gain_Ratio = new QAction(MainWindow);
        actionSteer_Gain_Ratio->setObjectName(QStringLiteral("actionSteer_Gain_Ratio"));
        actionLoad_DAS_Measurement = new QAction(MainWindow);
        actionLoad_DAS_Measurement->setObjectName(QStringLiteral("actionLoad_DAS_Measurement"));
        actionShow_YAWREF_and_FLATACC = new QAction(MainWindow);
        actionShow_YAWREF_and_FLATACC->setObjectName(QStringLiteral("actionShow_YAWREF_and_FLATACC"));
        actionShow_YAWREF_and_FLATACC->setCheckable(true);
        actionBacksteerfilter_YawRate_Depend = new QAction(MainWindow);
        actionBacksteerfilter_YawRate_Depend->setObjectName(QStringLiteral("actionBacksteerfilter_YawRate_Depend"));
        actionBacksteerfilter_YawRate_Depend->setCheckable(true);
        actionBacksteer_for_model_filter = new QAction(MainWindow);
        actionBacksteer_for_model_filter->setObjectName(QStringLiteral("actionBacksteer_for_model_filter"));
        actionBacksteer_for_model_filter->setCheckable(true);
        actionSignal_Setup = new QAction(MainWindow);
        actionSignal_Setup->setObjectName(QStringLiteral("actionSignal_Setup"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        MainLayout = new QGridLayout();
        MainLayout->setSpacing(6);
        MainLayout->setObjectName(QStringLiteral("MainLayout"));
        MeasurementsWidget = new QWidget(centralWidget);
        MeasurementsWidget->setObjectName(QStringLiteral("MeasurementsWidget"));
        MeasurementsWidget->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(MeasurementsWidget->sizePolicy().hasHeightForWidth());
        MeasurementsWidget->setSizePolicy(sizePolicy1);
        MeasurementsWidget->setMinimumSize(QSize(776, 350));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(252, 252, 252, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(253, 253, 253, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(126, 126, 126, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(168, 168, 168, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        MeasurementsWidget->setPalette(palette);
        MeasurementsWidget->setAutoFillBackground(true);
        gridLayoutWidget_3 = new QWidget(MeasurementsWidget);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(-1, -1, 781, 401));
        MeasurementsLayout = new QGridLayout(gridLayoutWidget_3);
        MeasurementsLayout->setSpacing(6);
        MeasurementsLayout->setContentsMargins(11, 11, 11, 11);
        MeasurementsLayout->setObjectName(QStringLiteral("MeasurementsLayout"));
        MeasurementsLayout->setContentsMargins(0, 0, 0, 0);

        MainLayout->addWidget(MeasurementsWidget, 1, 0, 1, 1);

        Data = new QWidget(centralWidget);
        Data->setObjectName(QStringLiteral("Data"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Data->sizePolicy().hasHeightForWidth());
        Data->setSizePolicy(sizePolicy2);
        Data->setMinimumSize(QSize(0, 200));
        Data->setMaximumSize(QSize(16777215, 200));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush7(QColor(230, 230, 230, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush8(QColor(242, 242, 242, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush8);
        QBrush brush9(QColor(115, 115, 115, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush9);
        QBrush brush10(QColor(153, 153, 153, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush10);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush8);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        Data->setPalette(palette1);
        Data->setAutoFillBackground(true);
        horizontalLayout = new QHBoxLayout(Data);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        DataLayout = new QGridLayout();
        DataLayout->setSpacing(6);
        DataLayout->setObjectName(QStringLiteral("DataLayout"));
        EstimationLayout = new QGridLayout();
        EstimationLayout->setSpacing(6);
        EstimationLayout->setObjectName(QStringLiteral("EstimationLayout"));
        EstimationDataGroupBox = new QGroupBox(Data);
        EstimationDataGroupBox->setObjectName(QStringLiteral("EstimationDataGroupBox"));
        EstimationDataLayout = new QHBoxLayout(EstimationDataGroupBox);
        EstimationDataLayout->setSpacing(6);
        EstimationDataLayout->setContentsMargins(11, 11, 11, 11);
        EstimationDataLayout->setObjectName(QStringLiteral("EstimationDataLayout"));
        EstimationTypeGroupBox = new QGroupBox(EstimationDataGroupBox);
        EstimationTypeGroupBox->setObjectName(QStringLiteral("EstimationTypeGroupBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(EstimationTypeGroupBox->sizePolicy().hasHeightForWidth());
        EstimationTypeGroupBox->setSizePolicy(sizePolicy3);
        EstimationTypeGroupBox->setMinimumSize(QSize(70, 102));
        EstimationTypeGroupBox->setMaximumSize(QSize(70, 16777215));
        verticalLayout = new QVBoxLayout(EstimationTypeGroupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Normal = new QLabel(EstimationTypeGroupBox);
        Normal->setObjectName(QStringLiteral("Normal"));

        verticalLayout->addWidget(Normal, 0, Qt::AlignRight);

        Euler = new QLabel(EstimationTypeGroupBox);
        Euler->setObjectName(QStringLiteral("Euler"));

        verticalLayout->addWidget(Euler, 0, Qt::AlignRight);

        Other = new QLabel(EstimationTypeGroupBox);
        Other->setObjectName(QStringLiteral("Other"));

        verticalLayout->addWidget(Other, 0, Qt::AlignRight);


        EstimationDataLayout->addWidget(EstimationTypeGroupBox, 0, Qt::AlignHCenter);

        EstimationSubLayout = new QHBoxLayout();
        EstimationSubLayout->setSpacing(6);
        EstimationSubLayout->setObjectName(QStringLiteral("EstimationSubLayout"));
        EstimationSubLayout->setSizeConstraint(QLayout::SetMinimumSize);
        EstimationSubLayout->setContentsMargins(1, 1, 1, 1);

        EstimationDataLayout->addLayout(EstimationSubLayout);


        EstimationLayout->addWidget(EstimationDataGroupBox, 1, 0, 1, 1, Qt::AlignLeft);

        SumDeltaGroupBox = new QGroupBox(Data);
        SumDeltaGroupBox->setObjectName(QStringLiteral("SumDeltaGroupBox"));
        SumDeltaGroupBox->setMinimumSize(QSize(50, 30));
        SumDeltaGroupBox->setMaximumSize(QSize(16777215, 30));
        horizontalLayout_6 = new QHBoxLayout(SumDeltaGroupBox);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(5, 5, 5, 5);
        SumDeltaLayout = new QHBoxLayout();
        SumDeltaLayout->setSpacing(6);
        SumDeltaLayout->setObjectName(QStringLiteral("SumDeltaLayout"));
        delta = new QLabel(SumDeltaGroupBox);
        delta->setObjectName(QStringLiteral("delta"));

        SumDeltaLayout->addWidget(delta, 0, Qt::AlignRight);


        horizontalLayout_6->addLayout(SumDeltaLayout);


        EstimationLayout->addWidget(SumDeltaGroupBox, 2, 0, 1, 1);


        DataLayout->addLayout(EstimationLayout, 0, 0, 1, 1);

        Optimization_groupbox = new QGroupBox(Data);
        Optimization_groupbox->setObjectName(QStringLiteral("Optimization_groupbox"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(Optimization_groupbox->sizePolicy().hasHeightForWidth());
        Optimization_groupbox->setSizePolicy(sizePolicy4);
        Optimization_groupbox->setMinimumSize(QSize(105, 0));
        Optimization_groupbox->setMaximumSize(QSize(105, 16777215));
        Optimization_groupbox->setLayoutDirection(Qt::LeftToRight);
        Optimization_groupbox->setAutoFillBackground(true);
        Optimization_groupbox->setAlignment(Qt::AlignCenter);
        gridLayout_2 = new QGridLayout(Optimization_groupbox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        Optimize_button = new QPushButton(Optimization_groupbox);
        Optimize_button->setObjectName(QStringLiteral("Optimize_button"));

        gridLayout_2->addWidget(Optimize_button, 3, 0, 1, 2, Qt::AlignHCenter);

        Theta_value = new QLineEdit(Optimization_groupbox);
        Theta_value->setObjectName(QStringLiteral("Theta_value"));
        Theta_value->setMinimumSize(QSize(45, 25));

        gridLayout_2->addWidget(Theta_value, 2, 1, 1, 1);

        Cf_value = new QLineEdit(Optimization_groupbox);
        Cf_value->setObjectName(QStringLiteral("Cf_value"));
        Cf_value->setMinimumSize(QSize(45, 25));
        Cf_value->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhPreferNumbers);

        gridLayout_2->addWidget(Cf_value, 0, 1, 1, 1);

        Cr_value = new QLineEdit(Optimization_groupbox);
        Cr_value->setObjectName(QStringLiteral("Cr_value"));
        Cr_value->setMinimumSize(QSize(45, 25));

        gridLayout_2->addWidget(Cr_value, 1, 1, 1, 1);

        ThetaLabel = new QLabel(Optimization_groupbox);
        ThetaLabel->setObjectName(QStringLiteral("ThetaLabel"));
        ThetaLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(ThetaLabel, 2, 0, 1, 1);

        CrLabel = new QLabel(Optimization_groupbox);
        CrLabel->setObjectName(QStringLiteral("CrLabel"));
        CrLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(CrLabel, 1, 0, 1, 1);

        CfLabel = new QLabel(Optimization_groupbox);
        CfLabel->setObjectName(QStringLiteral("CfLabel"));
        CfLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(CfLabel, 0, 0, 1, 1);


        DataLayout->addWidget(Optimization_groupbox, 0, 1, 1, 1);

        Parameters_groupbox = new QGroupBox(Data);
        Parameters_groupbox->setObjectName(QStringLiteral("Parameters_groupbox"));
        sizePolicy3.setHeightForWidth(Parameters_groupbox->sizePolicy().hasHeightForWidth());
        Parameters_groupbox->setSizePolicy(sizePolicy3);
        Parameters_groupbox->setMinimumSize(QSize(150, 0));
        Parameters_groupbox->setMaximumSize(QSize(150, 9999999));
        Parameters_groupbox->setAlignment(Qt::AlignCenter);
        gridLayout_3 = new QGridLayout(Parameters_groupbox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        LfLabel = new QLabel(Parameters_groupbox);
        LfLabel->setObjectName(QStringLiteral("LfLabel"));
        LfLabel->setLayoutDirection(Qt::LeftToRight);
        LfLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(LfLabel, 0, 0, 1, 1);

        LrLabel = new QLabel(Parameters_groupbox);
        LrLabel->setObjectName(QStringLiteral("LrLabel"));
        LrLabel->setLayoutDirection(Qt::LeftToRight);
        LrLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(LrLabel, 1, 0, 1, 1);

        MLabel = new QLabel(Parameters_groupbox);
        MLabel->setObjectName(QStringLiteral("MLabel"));
        MLabel->setLayoutDirection(Qt::LeftToRight);
        MLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(MLabel, 0, 2, 1, 1);

        ESMLabel = new QLabel(Parameters_groupbox);
        ESMLabel->setObjectName(QStringLiteral("ESMLabel"));
        ESMLabel->setLayoutDirection(Qt::LeftToRight);
        ESMLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(ESMLabel, 1, 2, 1, 1);

        ESM_value = new QLineEdit(Parameters_groupbox);
        ESM_value->setObjectName(QStringLiteral("ESM_value"));
        ESM_value->setMinimumSize(QSize(40, 25));

        gridLayout_3->addWidget(ESM_value, 1, 3, 1, 1);

        Lr_value = new QLineEdit(Parameters_groupbox);
        Lr_value->setObjectName(QStringLiteral("Lr_value"));
        Lr_value->setMinimumSize(QSize(40, 25));

        gridLayout_3->addWidget(Lr_value, 1, 1, 1, 1);

        Lf_value = new QLineEdit(Parameters_groupbox);
        Lf_value->setObjectName(QStringLiteral("Lf_value"));
        Lf_value->setMinimumSize(QSize(40, 25));

        gridLayout_3->addWidget(Lf_value, 0, 1, 1, 1);

        M_value = new QLineEdit(Parameters_groupbox);
        M_value->setObjectName(QStringLiteral("M_value"));
        M_value->setMinimumSize(QSize(40, 25));

        gridLayout_3->addWidget(M_value, 0, 3, 1, 1);

        LrLabel_3 = new QLabel(Parameters_groupbox);
        LrLabel_3->setObjectName(QStringLiteral("LrLabel_3"));
        LrLabel_3->setMinimumSize(QSize(40, 0));
        LrLabel_3->setLayoutDirection(Qt::LeftToRight);
        LrLabel_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(LrLabel_3, 2, 2, 1, 1);

        LrLabel_2 = new QLabel(Parameters_groupbox);
        LrLabel_2->setObjectName(QStringLiteral("LrLabel_2"));
        LrLabel_2->setLayoutDirection(Qt::LeftToRight);
        LrLabel_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(LrLabel_2, 2, 0, 1, 1);

        Apply_Parameters = new QPushButton(Parameters_groupbox);
        Apply_Parameters->setObjectName(QStringLiteral("Apply_Parameters"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(Apply_Parameters->sizePolicy().hasHeightForWidth());
        Apply_Parameters->setSizePolicy(sizePolicy5);
        Apply_Parameters->setMinimumSize(QSize(0, 0));

        gridLayout_3->addWidget(Apply_Parameters, 3, 0, 1, 4, Qt::AlignHCenter);

        lineEdit_9 = new QLineEdit(Parameters_groupbox);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        lineEdit_9->setMinimumSize(QSize(40, 25));

        gridLayout_3->addWidget(lineEdit_9, 2, 3, 1, 1);


        DataLayout->addWidget(Parameters_groupbox, 0, 2, 1, 1);


        horizontalLayout->addLayout(DataLayout);


        MainLayout->addWidget(Data, 2, 0, 1, 1);


        gridLayout->addLayout(MainLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 26));
        sizePolicy2.setHeightForWidth(menuBar->sizePolicy().hasHeightForWidth());
        menuBar->setSizePolicy(sizePolicy2);
        menuBar->setAutoFillBackground(true);
        menuVehicle = new QMenu(menuBar);
        menuVehicle->setObjectName(QStringLiteral("menuVehicle"));
        menuMeasurement = new QMenu(menuBar);
        menuMeasurement->setObjectName(QStringLiteral("menuMeasurement"));
        menuBacksteerfilter = new QMenu(menuBar);
        menuBacksteerfilter->setObjectName(QStringLiteral("menuBacksteerfilter"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuVehicle->menuAction());
        menuBar->addAction(menuMeasurement->menuAction());
        menuBar->addAction(menuBacksteerfilter->menuAction());
        menuVehicle->addAction(actionLoad_vehicle_parameter);
        menuVehicle->addAction(actionSave_vehicle_parameter);
        menuVehicle->addAction(actionLoad_Identification_Project);
        menuVehicle->addAction(actionSave_Identification_Project);
        menuVehicle->addAction(actionSteer_Gain_Ratio);
        menuMeasurement->addAction(actionLoad_DAS_Measurement);
        menuMeasurement->addAction(actionShow_YAWREF_and_FLATACC);
        menuMeasurement->addAction(actionSignal_Setup);
        menuBacksteerfilter->addAction(actionBacksteerfilter_YawRate_Depend);
        menuBacksteerfilter->addAction(actionBacksteer_for_model_filter);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "STM Identification Tool - v2015", 0));
        actionLoad_vehicle_parameter->setText(QApplication::translate("MainWindow", "Load Vehicle Parameter", 0));
        actionSave_vehicle_parameter->setText(QApplication::translate("MainWindow", "Save Vehicle Parameter", 0));
        actionLoad_Identification_Project->setText(QApplication::translate("MainWindow", "Load Identification Project", 0));
        actionSave_Identification_Project->setText(QApplication::translate("MainWindow", "Save Identification Project", 0));
        actionSteer_Gain_Ratio->setText(QApplication::translate("MainWindow", "Steer Gain Ratio", 0));
        actionLoad_DAS_Measurement->setText(QApplication::translate("MainWindow", "Load DAS Measurement", 0));
        actionShow_YAWREF_and_FLATACC->setText(QApplication::translate("MainWindow", "Show YAWREF Vehicle and FLATACC", 0));
        actionBacksteerfilter_YawRate_Depend->setText(QApplication::translate("MainWindow", "Backsteerfilter YawRate Depend", 0));
        actionBacksteer_for_model_filter->setText(QApplication::translate("MainWindow", "Backsteer for Model Filter", 0));
        actionSignal_Setup->setText(QApplication::translate("MainWindow", "Signal Setup", 0));
        EstimationTypeGroupBox->setTitle(QApplication::translate("MainWindow", "Estimation", 0));
        Normal->setText(QApplication::translate("MainWindow", "Normal", 0));
        Euler->setText(QApplication::translate("MainWindow", "Euler", 0));
        Other->setText(QApplication::translate("MainWindow", "Other", 0));
        SumDeltaGroupBox->setTitle(QString());
        delta->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        Optimization_groupbox->setTitle(QApplication::translate("MainWindow", "Optimization", 0));
        Optimize_button->setText(QApplication::translate("MainWindow", "Optimize", 0));
#ifndef QT_NO_TOOLTIP
        Theta_value->setToolTip(QApplication::translate("MainWindow", "Vehicle's moment of inertia", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        Cf_value->setToolTip(QApplication::translate("MainWindow", "Cornering stiffness on the front wheel", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        Cr_value->setToolTip(QApplication::translate("MainWindow", "Cornering stiffness on the rear wheel", 0));
#endif // QT_NO_TOOLTIP
        ThetaLabel->setText(QApplication::translate("MainWindow", "Theta", 0));
        CrLabel->setText(QApplication::translate("MainWindow", "Cr", 0));
        CfLabel->setText(QApplication::translate("MainWindow", "Cf", 0));
        Parameters_groupbox->setTitle(QApplication::translate("MainWindow", "Parameters", 0));
        LfLabel->setText(QApplication::translate("MainWindow", "Lf", 0));
        LrLabel->setText(QApplication::translate("MainWindow", "Lr", 0));
        MLabel->setText(QApplication::translate("MainWindow", "M", 0));
        ESMLabel->setText(QApplication::translate("MainWindow", "ESM", 0));
#ifndef QT_NO_TOOLTIP
        Lf_value->setToolTip(QApplication::translate("MainWindow", "Distance of the front axle and the COG", 0));
#endif // QT_NO_TOOLTIP
        LrLabel_3->setText(QString());
        LrLabel_2->setText(QString());
        Apply_Parameters->setText(QApplication::translate("MainWindow", "Apply", 0));
        menuVehicle->setTitle(QApplication::translate("MainWindow", "Vehicle", 0));
        menuMeasurement->setTitle(QApplication::translate("MainWindow", "Measurement", 0));
        menuBacksteerfilter->setTitle(QApplication::translate("MainWindow", "Backsteerfilter", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
