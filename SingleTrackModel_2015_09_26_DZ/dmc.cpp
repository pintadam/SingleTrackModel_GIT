#include "dmc.h"
#include "QDebug"
#include "mainwindow.h"

DMC::DMC(QObject *parent) : QObject(parent)
{
    this->mainWindow = (MainWindow*) parent;

}

DMC::~DMC()
{

}

void DMC::WidgetClicked_0(QMouseEvent *)
{
    mainWindow->setEnabled(false);

    QVBoxLayout *newLayout = new QVBoxLayout;
    QPushButton *done0 = new QPushButton;
    QPushButton *reset0 = new QPushButton;
    QPushButton *start0 = new QPushButton;
    QPushButton *end0 = new QPushButton;

    QWidget *wdg = new QWidget;
    QCustomPlot *temp = new QCustomPlot;


    done0->setText("Done");
    reset0->setText("Reset");
    start0->setText("Start Point");
    end0->setText("End point");
    //SelectedMeasurement = 0;


    QCPGraph *mainGraph = temp->addGraph();
    QCPGraph *SecondaryGraph = temp->addGraph();
    QCPGraph *TertiaryGraph = temp->addGraph();

    mainGraph->setAdaptiveSampling(true);
    mainGraph->setData(mainWindow->Time[0], mainWindow->MeasuredYawRateValues[0]);
    mainGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssNone, QPen(Qt::red), QBrush(Qt::white), 3));
    mainGraph->setPen(QPen(Qt::blue)); // Magic only happens, when line width == 1

    SecondaryGraph->setData(mainWindow->Time[0], mainWindow->EstimatedYawRateValues[0]);
    SecondaryGraph->setPen(QPen(Qt::red));

    TertiaryGraph->setData(mainWindow->Time[0], mainWindow->OutputYawRateValues[0]);
    TertiaryGraph->setPen(QPen(Qt::green));

    temp->setObjectName("YawRate");
    temp->xAxis->setLabel("Time [s]");
    temp->yAxis->setLabel("Yaw Rate");

    /* rescale axes according to graph's data */
    mainGraph->rescaleAxes();
    SecondaryGraph->rescaleAxes(true);
    TertiaryGraph->rescaleAxes(true);

    connect(temp, SIGNAL(plottableClick(QCPAbstractPlottable*,QMouseEvent*)), temp, SLOT(showPointToolTip(QCPAbstractPlottable*,QMouseEvent*)));
    connect(done0, SIGNAL(clicked()), temp, SLOT(DoneEditing()));

    wdg->setLayout(newLayout);
    newLayout->addWidget(temp);
    newLayout->addWidget(done0);
    newLayout->addWidget(reset0);
    newLayout->addWidget(start0);
    newLayout->addWidget(end0);
    wdg->setMinimumHeight(600);
    wdg->setMinimumWidth(1000);
    wdg->setWindowTitle("Measurement 0");
    wdg->show();
    qDebug() << "0";
    temp->setInteraction(QCP::iSelectPlottables);


    //connect(temp, SIGNAL(mouseMove(QMouseEvent*)), selectPos, SLOT(showPointToolTip(QMouseEvent)));

}

void DMC::WidgetClicked_1(QMouseEvent *)
{
    AdjustmentRequested = 0;
    QVBoxLayout *newLayout1 = new QVBoxLayout;
    QWidget *wdg1 = new QWidget;
    QCustomPlot *temp1 = new QCustomPlot;

    QCPGraph *mainGraph = temp1->addGraph();
    QCPGraph *SecondaryGraph = temp1->addGraph();
    QCPGraph *TertiaryGraph = temp1->addGraph();

    mainGraph->setAdaptiveSampling(true);
    mainGraph->setData(mainWindow->Time[1], mainWindow->MeasuredYawRateValues[1]);
    mainGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssNone, QPen(Qt::red), QBrush(Qt::white), 3));
    mainGraph->setPen(QPen(Qt::blue)); // Magic only happens, when line width == 1

    SecondaryGraph->setData(mainWindow->Time[1], mainWindow->EstimatedYawRateValues[1]);
    SecondaryGraph->setPen(QPen(Qt::red));

    TertiaryGraph->setData(mainWindow->Time[1], mainWindow->OutputYawRateValues[1]);
    TertiaryGraph->setPen(QPen(Qt::green));

    temp1->setObjectName("YawRate");
    temp1->xAxis->setLabel("Time [s]");
    temp1->yAxis->setLabel("Yaw Rate");



    /* rescale axes according to graph's data */
    mainGraph->rescaleAxes();
    SecondaryGraph->rescaleAxes(true);
    TertiaryGraph->rescaleAxes(true);

    connect(temp1, SIGNAL(plottableClick(QCPAbstractPlottable*,QMouseEvent*)), temp1, SLOT(showPointToolTip(QCPAbstractPlottable*,QMouseEvent*)));

    wdg1->setLayout(newLayout1);
    newLayout1->addWidget(temp1);
    wdg1->setMinimumHeight(600);
    wdg1->setMinimumWidth(1000);
    wdg1->setWindowTitle("Measurement 1");
    wdg1->show();
    qDebug() << "1";
}

void DMC::WidgetClicked_2(QMouseEvent *)
{
    QVBoxLayout *newLayout2 = new QVBoxLayout;
    QWidget *wdg2 = new QWidget;
    QCustomPlot *temp2 = new QCustomPlot;

    QCPGraph *mainGraph = temp2->addGraph();
    QCPGraph *SecondaryGraph = temp2->addGraph();
    QCPGraph *TertiaryGraph = temp2->addGraph();

    mainGraph->setAdaptiveSampling(true);
    mainGraph->setData(mainWindow->Time[2], mainWindow->MeasuredYawRateValues[2]);
    mainGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssNone, QPen(Qt::red), QBrush(Qt::white), 3));
    mainGraph->setPen(QPen(Qt::blue)); // Magic only happens, when line width == 1

    SecondaryGraph->setData(mainWindow->Time[2], mainWindow->EstimatedYawRateValues[2]);
    SecondaryGraph->setPen(QPen(Qt::red));

    TertiaryGraph->setData(mainWindow->Time[2], mainWindow->OutputYawRateValues[2]);
    TertiaryGraph->setPen(QPen(Qt::green));

    temp2->setObjectName("YawRate");
    temp2->xAxis->setLabel("Time [s]");
    temp2->yAxis->setLabel("Yaw Rate");



    /* rescale axes according to graph's data */
    mainGraph->rescaleAxes();
    SecondaryGraph->rescaleAxes(true);
    TertiaryGraph->rescaleAxes(true);

    connect(temp2, SIGNAL(plottableClick(QCPAbstractPlottable*,QMouseEvent*)), temp2, SLOT(showPointToolTip(QCPAbstractPlottable*,QMouseEvent*)));

    wdg2->setLayout(newLayout2);
    newLayout2->addWidget(temp2);
    wdg2->setMinimumHeight(600);
    wdg2->setMinimumWidth(1000);
    wdg2->setWindowTitle("Measurement 2");
    wdg2->show();
    qDebug() << "2";
}

void DMC::WidgetClicked_3(QMouseEvent *)
{
    QVBoxLayout *newLayout3 = new QVBoxLayout;
    QWidget *wdg3 = new QWidget;
    QCustomPlot *temp3 = new QCustomPlot;

    QCPGraph *mainGraph = temp3->addGraph();
    QCPGraph *SecondaryGraph = temp3->addGraph();
    QCPGraph *TertiaryGraph = temp3->addGraph();

    mainGraph->setAdaptiveSampling(true);
    mainGraph->setData(mainWindow->Time[3], mainWindow->MeasuredYawRateValues[3]);
    mainGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssNone, QPen(Qt::red), QBrush(Qt::white), 3));
    mainGraph->setPen(QPen(Qt::blue)); // Magic only happens, when line width == 1

    SecondaryGraph->setData(mainWindow->Time[3], mainWindow->EstimatedYawRateValues[3]);
    SecondaryGraph->setPen(QPen(Qt::red));

    TertiaryGraph->setData(mainWindow->Time[3], mainWindow->OutputYawRateValues[3]);
    TertiaryGraph->setPen(QPen(Qt::green));

    temp3->setObjectName("YawRate");
    temp3->xAxis->setLabel("Time [s]");
    temp3->yAxis->setLabel("Yaw Rate");

    /* rescale axes according to graph's data */
    mainGraph->rescaleAxes();
    SecondaryGraph->rescaleAxes(true);
    TertiaryGraph->rescaleAxes(true);

    connect(temp3, SIGNAL(plottableClick(QCPAbstractPlottable*,QMouseEvent*)), temp3, SLOT(showPointToolTip(QCPAbstractPlottable*,QMouseEvent*)));

    wdg3->setLayout(newLayout3);
    newLayout3->addWidget(temp3);
    wdg3->setMinimumHeight(600);
    wdg3->setMinimumWidth(1000);
    wdg3->setWindowTitle("Measurement 3");
    wdg3->show();
    qDebug() << "3";
}

void DMC::WidgetClicked_4(QMouseEvent *)
{
    QVBoxLayout *newLayout4 = new QVBoxLayout;
    QWidget *wdg4 = new QWidget;
    QCustomPlot *temp4 = new QCustomPlot;

    QCPGraph *mainGraph = temp4->addGraph();
    QCPGraph *SecondaryGraph = temp4->addGraph();
    QCPGraph *TertiaryGraph = temp4->addGraph();

    mainGraph->setAdaptiveSampling(true);
    mainGraph->setData(mainWindow->Time[4], mainWindow->MeasuredYawRateValues[4]);
    mainGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssNone, QPen(Qt::red), QBrush(Qt::white), 3));
    mainGraph->setPen(QPen(Qt::blue)); // Magic only happens, when line width == 1

    SecondaryGraph->setData(mainWindow->Time[4], mainWindow->EstimatedYawRateValues[4]);
    SecondaryGraph->setPen(QPen(Qt::red));

    TertiaryGraph->setData(mainWindow->Time[4], mainWindow->OutputYawRateValues[4]);
    TertiaryGraph->setPen(QPen(Qt::green));

    temp4->setObjectName("YawRate");
    temp4->xAxis->setLabel("Time [s]");
    temp4->yAxis->setLabel("Yaw Rate");

    /* rescale axes according to graph's data */
    mainGraph->rescaleAxes();
    SecondaryGraph->rescaleAxes(true);
    TertiaryGraph->rescaleAxes(true);

    connect(temp4, SIGNAL(plottableClick(QCPAbstractPlottable*,QMouseEvent*)), temp4, SLOT(showPointToolTip(QCPAbstractPlottable*,QMouseEvent*)));

    wdg4->setLayout(newLayout4);
    newLayout4->addWidget(temp4);
    wdg4->setMinimumHeight(600);
    wdg4->setMinimumWidth(1000);
    wdg4->setWindowTitle("Measurement 4");
    wdg4->show();
    qDebug() << "4";
}

void DMC::WidgetClicked_5(QMouseEvent *)
{
    QVBoxLayout *newLayout5 = new QVBoxLayout;
    QWidget *wdg5 = new QWidget;
    QCustomPlot *temp5 = new QCustomPlot;

    QCPGraph *mainGraph = temp5->addGraph();
    QCPGraph *SecondaryGraph = temp5->addGraph();
    QCPGraph *TertiaryGraph = temp5->addGraph();

    mainGraph->setAdaptiveSampling(true);
    mainGraph->setData(mainWindow->Time[5], mainWindow->MeasuredYawRateValues[5]);
    mainGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssNone, QPen(Qt::red), QBrush(Qt::white), 3));
    mainGraph->setPen(QPen(Qt::blue)); // Magic only happens, when line width == 1

    SecondaryGraph->setData(mainWindow->Time[5], mainWindow->EstimatedYawRateValues[5]);
    SecondaryGraph->setPen(QPen(Qt::red));

    TertiaryGraph->setData(mainWindow->Time[5], mainWindow->OutputYawRateValues[5]);
    TertiaryGraph->setPen(QPen(Qt::green));

    temp5->setObjectName("YawRate");
    temp5->xAxis->setLabel("Time [s]");
    temp5->yAxis->setLabel("Yaw Rate");

    /* rescale axes according to graph's data */
    mainGraph->rescaleAxes();
    SecondaryGraph->rescaleAxes(true);
    TertiaryGraph->rescaleAxes(true);

    connect(temp5, SIGNAL(plottableClick(QCPAbstractPlottable*,QMouseEvent*)), temp5, SLOT(showPointToolTip(QCPAbstractPlottable*,QMouseEvent*)));

    wdg5->setLayout(newLayout5);
    newLayout5->addWidget(temp5);
    wdg5->setMinimumHeight(600);
    wdg5->setMinimumWidth(1000);
    wdg5->setWindowTitle("Measurement 5");
    wdg5->show();
    qDebug() << "5";
}

void DMC::WidgetClicked_6(QMouseEvent *)
{
    QVBoxLayout *newLayout6 = new QVBoxLayout;
    QWidget *wdg6 = new QWidget;
    QCustomPlot *temp6 = new QCustomPlot;

    QCPGraph *mainGraph = temp6->addGraph();
    QCPGraph *SecondaryGraph = temp6->addGraph();
    QCPGraph *TertiaryGraph = temp6->addGraph();

    mainGraph->setAdaptiveSampling(true);
    mainGraph->setData(mainWindow->Time[6], mainWindow->MeasuredYawRateValues[6]);
    mainGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssNone, QPen(Qt::red), QBrush(Qt::white), 3));
    mainGraph->setPen(QPen(Qt::blue)); // Magic only happens, when line width == 1

    SecondaryGraph->setData(mainWindow->Time[6], mainWindow->EstimatedYawRateValues[6]);
    SecondaryGraph->setPen(QPen(Qt::red));

    TertiaryGraph->setData(mainWindow->Time[6], mainWindow->OutputYawRateValues[6]);
    TertiaryGraph->setPen(QPen(Qt::green));

    temp6->setObjectName("YawRate");
    temp6->xAxis->setLabel("Time [s]");
    temp6->yAxis->setLabel("Yaw Rate");

    /* rescale axes according to graph's data */
    mainGraph->rescaleAxes();
    SecondaryGraph->rescaleAxes(true);
    TertiaryGraph->rescaleAxes(true);

    connect(temp6, SIGNAL(plottableClick(QCPAbstractPlottable*,QMouseEvent*)), temp6, SLOT(showPointToolTip(QCPAbstractPlottable*,QMouseEvent*)));

    wdg6->setLayout(newLayout6);
    newLayout6->addWidget(temp6);
    wdg6->setMinimumHeight(600);
    wdg6->setMinimumWidth(1000);
    wdg6->setWindowTitle("Measurement 6");
    wdg6->show();
    qDebug() << "6";
}

void DMC::WidgetClicked_7(QMouseEvent *)
{
    QVBoxLayout *newLayout7 = new QVBoxLayout;
    QWidget *wdg7 = new QWidget;
    QCustomPlot *temp7 = new QCustomPlot;

    QCPGraph *mainGraph = temp7->addGraph();
    QCPGraph *SecondaryGraph = temp7->addGraph();
    QCPGraph *TertiaryGraph = temp7->addGraph();

    mainGraph->setAdaptiveSampling(true);
    mainGraph->setData(mainWindow->Time[7], mainWindow->MeasuredYawRateValues[7]);
    mainGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssNone, QPen(Qt::red), QBrush(Qt::white), 3));
    mainGraph->setPen(QPen(Qt::blue)); // Magic only happens, when line width == 1

    SecondaryGraph->setData(mainWindow->Time[7], mainWindow->EstimatedYawRateValues[7]);
    SecondaryGraph->setPen(QPen(Qt::red));

    TertiaryGraph->setData(mainWindow->Time[7], mainWindow->OutputYawRateValues[7]);
    TertiaryGraph->setPen(QPen(Qt::green));

    temp7->setObjectName("YawRate");
    temp7->xAxis->setLabel("Time [s]");
    temp7->yAxis->setLabel("Yaw Rate");

    /* rescale axes according to graph's data */
    mainGraph->rescaleAxes();
    SecondaryGraph->rescaleAxes(true);
    TertiaryGraph->rescaleAxes(true);

    connect(temp7, SIGNAL(plottableClick(QCPAbstractPlottable*,QMouseEvent*)), temp7, SLOT(showPointToolTip(QCPAbstractPlottable*,QMouseEvent*)));

    wdg7->setLayout(newLayout7);
    newLayout7->addWidget(temp7);
    wdg7->setMinimumHeight(600);
    wdg7->setMinimumWidth(1000);
    wdg7->setWindowTitle("Measurement 7");
    wdg7->show();
    qDebug() << "7";
}

void DMC::WidgetClicked_8(QMouseEvent *)
{
    QVBoxLayout *newLayout8 = new QVBoxLayout;
    QWidget *wdg8 = new QWidget;
    QCustomPlot *temp8 = new QCustomPlot;

    QCPGraph *mainGraph = temp8->addGraph();
    QCPGraph *SecondaryGraph = temp8->addGraph();
    QCPGraph *TertiaryGraph = temp8->addGraph();

    mainGraph->setAdaptiveSampling(true);
    mainGraph->setData(mainWindow->Time[6], mainWindow->MeasuredYawRateValues[6]);
    mainGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssNone, QPen(Qt::red), QBrush(Qt::white), 3));
    mainGraph->setPen(QPen(Qt::blue)); // Magic only happens, when line width == 1

    SecondaryGraph->setData(mainWindow->Time[6], mainWindow->EstimatedYawRateValues[6]);
    SecondaryGraph->setPen(QPen(Qt::red));

    TertiaryGraph->setData(mainWindow->Time[6], mainWindow->OutputYawRateValues[6]);
    TertiaryGraph->setPen(QPen(Qt::green));

    temp8->setObjectName("YawRate");
    temp8->xAxis->setLabel("Time [s]");
    temp8->yAxis->setLabel("Yaw Rate");

    /* rescale axes according to graph's data */
    mainGraph->rescaleAxes();
    SecondaryGraph->rescaleAxes(true);
    TertiaryGraph->rescaleAxes(true);

    connect(temp8, SIGNAL(plottableClick(QCPAbstractPlottable*,QMouseEvent*)), temp8, SLOT(showPointToolTip(QCPAbstractPlottable*,QMouseEvent*)));

    wdg8->setLayout(newLayout8);
    newLayout8->addWidget(temp8);
    wdg8->setMinimumHeight(600);
    wdg8->setMinimumWidth(1000);
    wdg8->setWindowTitle("Measurement 6");
    wdg8->show();
    qDebug() << "6";
}

void DMC::WidgetClicked_9(QMouseEvent *)
{
    QVBoxLayout *newLayout9 = new QVBoxLayout;
    QWidget *wdg9 = new QWidget;
    QCustomPlot *temp9 = new QCustomPlot;

    QCPGraph *mainGraph = temp9->addGraph();
    QCPGraph *SecondaryGraph = temp9->addGraph();
    QCPGraph *TertiaryGraph = temp9->addGraph();

    mainGraph->setAdaptiveSampling(true);
    mainGraph->setData(mainWindow->Time[6], mainWindow->MeasuredYawRateValues[6]);
    mainGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssNone, QPen(Qt::red), QBrush(Qt::white), 3));
    mainGraph->setPen(QPen(Qt::blue)); // Magic only happens, when line width == 1

    SecondaryGraph->setData(mainWindow->Time[6], mainWindow->EstimatedYawRateValues[6]);
    SecondaryGraph->setPen(QPen(Qt::red));

    TertiaryGraph->setData(mainWindow->Time[6], mainWindow->OutputYawRateValues[6]);
    TertiaryGraph->setPen(QPen(Qt::green));

    temp9->setObjectName("YawRate");
    temp9->xAxis->setLabel("Time [s]");
    temp9->yAxis->setLabel("Yaw Rate");

    /* rescale axes according to graph's data */
    mainGraph->rescaleAxes();
    SecondaryGraph->rescaleAxes(true);
    TertiaryGraph->rescaleAxes(true);

    connect(temp9, SIGNAL(plottableClick(QCPAbstractPlottable*,QMouseEvent*)), temp9, SLOT(showPointToolTip(QCPAbstractPlottable*,QMouseEvent*)));

    wdg9->setLayout(newLayout9);
    newLayout9->addWidget(temp9);
    wdg9->setMinimumHeight(600);
    wdg9->setMinimumWidth(1000);
    wdg9->setWindowTitle("Measurement 6");
    wdg9->show();
    qDebug() << "6";
}

void DMC::WidgetClicked_10(QMouseEvent *)
{
    QVBoxLayout *newLayout10 = new QVBoxLayout;
    QWidget *wdg10 = new QWidget;
    QCustomPlot *temp10 = new QCustomPlot;

    QCPGraph *mainGraph = temp10->addGraph();
    QCPGraph *SecondaryGraph = temp10->addGraph();
    QCPGraph *TertiaryGraph = temp10->addGraph();

    mainGraph->setAdaptiveSampling(true);
    mainGraph->setData(mainWindow->Time[6], mainWindow->MeasuredYawRateValues[6]);
    mainGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssNone, QPen(Qt::red), QBrush(Qt::white), 3));
    mainGraph->setPen(QPen(Qt::blue)); // Magic only happens, when line width == 1

    SecondaryGraph->setData(mainWindow->Time[6], mainWindow->EstimatedYawRateValues[6]);
    SecondaryGraph->setPen(QPen(Qt::red));

    TertiaryGraph->setData(mainWindow->Time[6], mainWindow->OutputYawRateValues[6]);
    TertiaryGraph->setPen(QPen(Qt::green));

    temp10->setObjectName("YawRate");
    temp10->xAxis->setLabel("Time [s]");
    temp10->yAxis->setLabel("Yaw Rate");

    /* rescale axes according to graph's data */
    mainGraph->rescaleAxes();
    SecondaryGraph->rescaleAxes(true);
    TertiaryGraph->rescaleAxes(true);

    connect(temp10, SIGNAL(plottableClick(QCPAbstractPlottable*,QMouseEvent*)), temp10, SLOT(showPointToolTip(QCPAbstractPlottable*,QMouseEvent*)));

    wdg10->setLayout(newLayout10);
    newLayout10->addWidget(temp10);
    wdg10->setMinimumHeight(600);
    wdg10->setMinimumWidth(1000);
    wdg10->setWindowTitle("Measurement 6");
    wdg10->show();
    qDebug() << "6";


}

void DMC::WidgetClicked_11(QMouseEvent *)
{
    QVBoxLayout *newLayout11 = new QVBoxLayout;
    QWidget *wdg11 = new QWidget;
    QCustomPlot *temp11 = new QCustomPlot;

    QCPGraph *mainGraph = temp11->addGraph();
    QCPGraph *SecondaryGraph = temp11->addGraph();
    QCPGraph *TertiaryGraph = temp11->addGraph();

    mainGraph->setAdaptiveSampling(true);
    mainGraph->setData(mainWindow->Time[6], mainWindow->MeasuredYawRateValues[6]);
    mainGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssNone, QPen(Qt::red), QBrush(Qt::white), 3));
    mainGraph->setPen(QPen(Qt::blue)); // Magic only happens, when line width == 1

    SecondaryGraph->setData(mainWindow->Time[6], mainWindow->EstimatedYawRateValues[6]);
    SecondaryGraph->setPen(QPen(Qt::red));

    TertiaryGraph->setData(mainWindow->Time[6], mainWindow->OutputYawRateValues[6]);
    TertiaryGraph->setPen(QPen(Qt::green));

    temp11->setObjectName("YawRate");
    temp11->xAxis->setLabel("Time [s]");
    temp11->yAxis->setLabel("Yaw Rate");

    /* rescale axes according to graph's data */
    mainGraph->rescaleAxes();
    SecondaryGraph->rescaleAxes(true);
    TertiaryGraph->rescaleAxes(true);

    connect(temp11, SIGNAL(plottableClick(QCPAbstractPlottable*,QMouseEvent*)), temp11, SLOT(showPointToolTip(QCPAbstractPlottable*,QMouseEvent*)));

    wdg11->setLayout(newLayout11);
    newLayout11->addWidget(temp11);
    wdg11->setMinimumHeight(600);
    wdg11->setMinimumWidth(1000);
    wdg11->setWindowTitle("Measurement 6");
    wdg11->show();
    qDebug() << "6";
}


