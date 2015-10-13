#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qfiledialog.h>
#include "QTextEdit"
#include "QGridLayout"
#include <QtQuick/qquickview.h>
#include <QtGui>
#include <QtCore>
#include <qtextbrowser.h>
#include <qcustomplot.h>

int MeasurementCount = 0;
int MeasurementColumns = 0;
int MeasurementLines = 0;
int Number = 0;
int MeasurementCountOrigi = 0;
int MeasurementCountOld = 0;
int Remain = 0;
int RemainOld = 0;
double Difference = 0.0;
double AverageDifference[MaximumMeasurements];

QGroupBox *Data[MaximumMeasurements], *SumData;
QVBoxLayout *VerticalLayout[MaximumMeasurements], *SumVerticalLayout;
QLabel *Euler[MaximumMeasurements], *Normal[MaximumMeasurements], *Other[MaximumMeasurements], *EulerSumLabel, *NormalSumLabel, *OtherSumLabel;
QCustomPlot *Customplott[MaximumMeasurements];
QVector<double> Time[MaximumMeasurements], MeasuredYawRateValues[MaximumMeasurements],EstimatedYawRateValues[MaximumMeasurements], temporary(5000);

//QString *FYAWRATE_Name = "FYAWRATE";

double EulerValue[MaximumMeasurements], NormalValue[MaximumMeasurements], OtherValue[MaximumMeasurements];
double EulerSumValue, NormalSumValue, OtherSumValue, SumDelta;

QString EulerSumString, NormalSumString, OtherSumString, EulerValueString[MaximumMeasurements], NormalValueString[MaximumMeasurements], OtherValueString[MaximumMeasurements];

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    allSignal = new QMap<QString, mySignal*>();

    /* Only numbers are accepted (Bottom, top, decimals, parent */
    /* Define the min-max values!!! */

    ui->Cf_value->setValidator( new QDoubleValidator(CfMin, CfMax, 2, this) );
    ui->Cr_value->setValidator( new QDoubleValidator(CrMin, CrMax, 2, this) );
    ui->Theta_value->setValidator( new QDoubleValidator(ThetaMin, ThetaMax, 2, this) );
    ui->Lf_value->setValidator( new QDoubleValidator(LfMin, LfMax, 2, this) );
    ui->Lr_value->setValidator( new QDoubleValidator(LrMin, LrMax, 2, this) );
    ui->M_value->setValidator( new QDoubleValidator(MMin, MMax, 2, this) );
    ui->ESM_value->setValidator( new QDoubleValidator(ESMMin, ESMMax, 2, this) );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLoad_vehicle_parameter_triggered()
{
    QStringList LoadVehicleParameter = QFileDialog::getOpenFileNames(this,"","","Vehicle Parameter (*.veh)");
}

void MainWindow::on_actionSave_vehicle_parameter_triggered()
{
    QString SaveVehicleParameter = QFileDialog::getSaveFileName(this,"","","Vehicle Parameter (*.veh)");
}

void MainWindow::on_actionLoad_Identification_Project_triggered()
{
    QStringList LoadIdentificationProject = QFileDialog::getOpenFileNames(this,"","","Identification Project (*.ipt)");
}

void MainWindow::on_actionSave_Identification_Project_triggered()
{
    QString LoadIdentificationProject = QFileDialog::getSaveFileName(this,"","","Identification Project (*.ipt)");
}

void MainWindow::on_actionLoad_DAS_Measurement_triggered()
{


    for (int i = 0; i < MaximumMeasurements; i++)
    {
        Data[i] = new QGroupBox;
        Euler[i] = new QLabel;
        Normal[i] = new QLabel;
        Other[i] = new QLabel;
        VerticalLayout[i] = new QVBoxLayout;
        Customplott[i] = new QCustomPlot; // Handle the different measurements on separate customplots
        EulerValue[i] = 0;
        NormalValue[i] = 0;
        OtherValue[i] = 0;
    }

    SumData = new QGroupBox;
    EulerSumLabel = new QLabel;
    NormalSumLabel = new QLabel;
    OtherSumLabel = new QLabel;
    SumVerticalLayout = new QVBoxLayout;

    EulerSumValue = 0;
    NormalSumValue = 0;
    OtherSumValue = 0;

    QString path = "D:\\Measurement\\STM\\";

    /* Opening measurements in mdf format (in the future dl3 will be supported)*/
    QStringList LoadDASMeasurement = QFileDialog::getOpenFileNames(this,"",path,"DAS Measurement (*.mdf)");

    MeasurementCount = LoadDASMeasurement.count(); //Saving the number of the loaded measurement
    MeasurementCountOrigi = MeasurementCount;

    QProgressDialog ProgressBar("Please wait...",NULL,0,MeasurementCountOrigi,this);
    ProgressBar.setWindowModality(Qt::WindowModal);
    ProgressBar.setFixedHeight(100);
    ProgressBar.setFixedWidth(300);
    ProgressBar.setWindowFlags(ProgressBar.windowFlags() & ~Qt::WindowCloseButtonHint);
    ProgressBar.setWindowTitle("Loading Measurements");
    ProgressBar.setValue(0);
    ProgressBar.show();

    Remain = MeasurementCount % 2; // Checking if it is an even number


    if (MeasurementCount != 0)
    {
        if (LoadDASMeasurement.empty())
        {
            /* If no measurement was selected, leave everything as it is */
        }
        else if (MeasurementCount > 1)
        {
            if (!(ui->MeasurementsLayout->isEmpty()))
            {
                for (int i = 0; i < MeasurementCountOld; i++)
                {
                    deleteChildWidgets(ui->MeasurementsLayout);
                    deleteChildWidgets(ui->EstimationSubLayout);
                }
                qDebug() << "RemainOld: " << RemainOld;
                if (RemainOld == 1)
                {
                    deleteChildWidgets(ui->EstimationSubLayout);
                }
            }
            else
            {

            }

            if (Remain == 1)
            {
                MeasurementCount++; //Increasing the number of the loaded measurement, to create enough columns after the division
            }
            else
            {

            }

            MeasurementLines = MeasurementLineNumber; // 2 lines are used. Can be modified in the future
            MeasurementColumns = MeasurementCount / MeasurementLines;
            Number = 0;

            for (int LineCount = 0; LineCount < MeasurementLines; LineCount++)
            {
                for (int ColumnCount = 0; ColumnCount < MeasurementColumns; ColumnCount++)
                {
                    qDebug() << Number;
                    if ((Remain == 1) && (Number == MeasurementCountOrigi))
                    {
                        qDebug() << "Beléptünk az ágba";
                        // If uneven number of measurement is loaded, put a blankspot to the last place.
                        ui->MeasurementsLayout->addWidget(Customplott[Number],LineCount,ColumnCount);
                        Number++;
                    }
                    else
                    {
                        /* Clearing containers before reading new measurements */
                        Time[Number].clear();
                        MeasuredYawRateValues[Number].clear();
                        EstimatedYawRateValues[Number].clear();

                        ProgressBar.setValue(Number);
                        QApplication::processEvents();
                        openMDF(LoadDASMeasurement[Number]);

                        Time[Number] = FYAWRATE->getTime();
                        MeasuredYawRateValues[Number] = FYAWRATE->getData();
                        EstimatedYawRateValues[Number] = YAWRREF->getData();

                        for (int l = 1; l < (Time[Number].count()); l++)
                        {
                            if(((MeasuredYawRateValues[Number][l]) - (EstimatedYawRateValues[Number][l])) > 0)
                            {
                                Difference += (MeasuredYawRateValues[Number][l]) - (EstimatedYawRateValues[Number][l]);
                            }
                            else
                            {
                                Difference += (EstimatedYawRateValues[Number][l]) - (MeasuredYawRateValues[Number][l]);
                            }
                        }
                        AverageDifference[Number] = Difference/(Time[Number].count());
                        qDebug() << "Átlag különbség a " << Number << ". mérésben: " << AverageDifference[Number];

                        /* create and configure plottables */
                        QCPGraph *mainGraph = Customplott[Number]->addGraph();
                        QCPGraph *SecondaryGraph = Customplott[Number]->addGraph();

                        mainGraph->setAdaptiveSampling(true);
                        mainGraph->setData(Time[Number], MeasuredYawRateValues[Number]);
                        mainGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssNone, QPen(Qt::red), QBrush(Qt::white), 3));
                        mainGraph->setPen(QPen(QColor( 00,  150,  00), 1)); // Magic only happens, when line width == 1

                        SecondaryGraph->setData(Time[Number], EstimatedYawRateValues[Number]);
                        SecondaryGraph->setPen(QPen(Qt::red));

                        Customplott[Number]->setObjectName("YawRate");
                        Customplott[Number]->xAxis->setLabel("Time [s]");
                        Customplott[Number]->yAxis->setLabel("Yaw Rate"); 

                        /* rescale axes according to graph's data */
                        mainGraph->rescaleAxes();
                        SecondaryGraph->rescaleAxes();

                        Customplott[Number]->replot();

                        ui->MeasurementsLayout->addWidget(Customplott[Number],LineCount,ColumnCount);

                        Number++;
                    }
                }
            }
        }

        else if (MeasurementCount == 1)
        {
            if (!(ui->MeasurementsLayout->isEmpty()))
            {
                for (int i = 0; i < MeasurementCountOld; i++)
                {
                    /* Removing the existing widgets from the layouts, to avoid overlapping */
                    qDebug() << "Layouts were deleted";
                    deleteChildWidgets(ui->MeasurementsLayout);
                    deleteChildWidgets(ui->EstimationSubLayout);
                }
                qDebug() << "RemainOld: " << RemainOld;
                if (RemainOld == 1)
                {
                    deleteChildWidgets(ui->EstimationSubLayout);
                }
            }

            ProgressBar.setValue(Number);
            QApplication::processEvents();
            openMDF(LoadDASMeasurement[0]);

            Time[0] = FYAWRATE->getTime();
            MeasuredYawRateValues[0] = FYAWRATE->getData();

            EstimatedYawRateValues[0] = YAWRREF->getData();

            for (int l = 1; l < (Time[0].count()); l++)
            {
                temporary[l] = (MeasuredYawRateValues[0][l]) + 2;
            }

            for (int l = 1; l < (Time[0].count()); l++)
            {
                if(((MeasuredYawRateValues[0][l]) - (EstimatedYawRateValues[0][l])) > 0)
                {
                    Difference += (MeasuredYawRateValues[0][l]) - (EstimatedYawRateValues[0][l]);
                }
                else
                {
                    Difference += (EstimatedYawRateValues[0][l]) - (MeasuredYawRateValues[0][l]);
                }
            }
            AverageDifference[0] = Difference / (Time[0].count());
            qDebug() << "Átlag különbség a " << 0 << ". mérésben: " << AverageDifference[0];

            /* create and configure plottables */
            QCPGraph *mainGraph = Customplott[0]->addGraph();
            QCPGraph *SecondaryGraph = Customplott[0]->addGraph();

            mainGraph->setAdaptiveSampling(true);
            mainGraph->setData(Time[0], MeasuredYawRateValues[0]);
            mainGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssNone, QPen(Qt::red), QBrush(Qt::white), 3));
            mainGraph->setPen(QPen(QColor( 00,  150,  00), 1)); // Magic only happens, when line width == 1

            SecondaryGraph->setData(Time[0], EstimatedYawRateValues[0]);
            SecondaryGraph->setPen(QPen(Qt::red));

            Customplott[0]->setObjectName("YawRate");
            Customplott[0]->xAxis->setLabel("Time [s]");
            Customplott[0]->yAxis->setLabel("Yaw Rate");

            /* rescale axes according to graph's data */
            mainGraph->rescaleAxes();
            SecondaryGraph->rescaleAxes();

            ui->MeasurementsLayout->addWidget(Customplott[0],0,0);
        }
        else
        {

        }

        for (int k = 0; k < MeasurementCountOrigi; k++)
        {
            ui->EstimationSubLayout->setAlignment(Qt::AlignLeft);
            ui->EstimationSubLayout->addWidget(Data[k]);

            if (k == 0)
            {
                EulerValue[k] = AverageDifference[k];
                NormalValue[k] = 0;
                OtherValue[k] = 0;
                EulerSumValue += EulerValue[k];
            }
            else
            {
                EulerValue[k] = AverageDifference[k];
                //NormalValue[k] = NormalValue[k - 1] + 0.1;
                NormalValue[k] = NormalValue[k - 1] + 0.1;
                OtherValue[k] = OtherValue[k - 1] + 0.1;
                EulerSumValue += EulerValue[k];
            }

            EulerValueString[k].setNum(EulerValue[k],'g', 2);
            NormalValueString[k].setNum(NormalValue[k],'g', 2);
            OtherValueString[k].setNum(NormalValue[k],'g', 2);
            Euler[k]->setText(EulerValueString[k]);
            Normal[k]->setText(NormalValueString[k]);
            Other[k]->setText(OtherValueString[k]);

            Data[k]->setLayout(VerticalLayout[k]);
            Data[k]->setTitle(QString::number(k+1));

            VerticalLayout[k]->addWidget(Normal[k]);
            VerticalLayout[k]->addWidget(Euler[k]);
            VerticalLayout[k]->addWidget(Other[k]);
        }

        ui->EstimationSubLayout->addWidget(SumData);
        EulerSumString.setNum(EulerSumValue,'g', 3);
        EulerSumLabel->setText(EulerSumString);
        NormalSumLabel->setNum(99);
        OtherSumLabel->setNum(99);

        SumData->setLayout(SumVerticalLayout);
        SumData->setTitle("Sum");

        SumVerticalLayout->addWidget(NormalSumLabel);
        SumVerticalLayout->addWidget(EulerSumLabel);
        SumVerticalLayout->addWidget(OtherSumLabel);

        ui->MeasurementsWidget->setLayout(ui->MeasurementsLayout); //Assign the widget to the GridLayout
        ui->EstimationDataGroupBox->setLayout(ui->EstimationSubLayout);
        MeasurementCountOld = MeasurementCount;
        RemainOld = Remain;
    }
    else /* MeasrementCount == 0 */
    {

    }
}

void MainWindow::openMDF(QString name)
{
    QList<MDFlib::MDFDG*> *dgList;
    QList<MDFlib::MDFCG*> *cgList;
    QList<MDFlib::MDFChannel*> *cnList;
    mdf = new MDFlib::MDF();
    signalNameList.clear();
    allSignal->clear();
    notSelectedSignals.clear();
    //signalNameList = new QList<QString>();

    /* Debug Változó */
    int debugg = 0;

    int numberOfSignals = 0;
    bool error = mdf->Open(& name);
    if(error)
    {
        QMessageBox mb(QMessageBox::Critical, tr("Unable to Open"), tr("Unable to open the MDF file!"));
        mb.exec();
        //ui->statusbar->showMessage("ERROR: File not loaded!", 10000);
    }
    else
    {
        //ui->statusbar->showMessage("Loading from file!");
        dgList = mdf->getDataGroups();
        for(QList<MDFlib::MDFDG*>::iterator dgIt = dgList->begin(); dgIt != dgList->end(); dgIt++)
        {
            cgList = (*dgIt)->getChannelGroups();
            for(QList<MDFlib::MDFCG*>::iterator cgIt = cgList->begin(); cgIt != cgList->end(); cgIt++)
            {
                cnList = (*cgIt)->getChannels();
                for(QList<MDFlib::MDFChannel*>::iterator cnIt = cnList->begin(); cnIt != cnList->end(); cnIt++)
                {
                    signalNameList.append(*((*cnIt)->getNameOfSignal()));
                    numberOfSignals++;

                    mySignal* signal = new mySignal(*cnIt);
                    /* feltétel a beolvasáshoz */
                    if(signal->getName()->compare("XCP_DAQ.Main.MAIN_CLOCK") == 0)
                    {
                        qDebug() << "MAIN_CLOCK:" << *signal->getName();
                        RawYR = signal;
                        RawYR->loadData();
                    }

                    if(signal->getName()->compare("XCP_DAQ.Main.FYAWRATE") == 0)
                    {

                        qDebug() << "FYAWRATE:" << *signal->getName();
                        FYAWRATE = signal;
                        FYAWRATE->loadData();
                    }

                    if(signal->getName()->compare("XCP_DAQ.Main.AYC_VREF") == 0)
                    {

                        qDebug() << "AYC_VREF:" << *signal->getName();
                        AYC_VREF = signal;
                        AYC_VREF->loadData();
                    }

                    if(signal->getName()->compare("XCP_DAQ.Main.FSTANGLE") == 0)
                    {

                        qDebug() << "FSTANGLE:" << *signal->getName();
                        FSTANGLE = signal;
                        FSTANGLE->loadData();
                    }

                    if(signal->getName()->compare("XCP_DAQ.Main.FSTANGLEP") == 0)
                    {

                        qDebug() << "FSTANGLEP:" << *signal->getName();
                        FSTANGLEP = signal;
                        FSTANGLEP->loadData();
                    }

                    if(signal->getName()->compare("XCP_DAQ.Main.FYAWACC") == 0)
                    {

                        qDebug() << "FYAWACC:" << *signal->getName();
                        FYAWACC = signal;
                        FYAWACC->loadData();
                    }

                    if(signal->getName()->compare("XCP_DAQ.Main.YAWRREF") == 0)
                    {

                        qDebug() << "YAWRREF:" << *signal->getName();
                        YAWRREF = signal;
                        YAWRREF->loadData();
                    }

                    if(signal->getName()->compare("XCP_DAQ.Main.AFLATACCC") == 0)
                    {

                        qDebug() << "AFLATACCC:" << *signal->getName();
                        AFLATACCC = signal;
                        AFLATACCC->loadData();
                    }

                    if(signal->getName()->compare("XCP_DAQ.Main.COUNTER_ST") == 0)
                    {

                        qDebug() << "COUNTER_ST:" << *signal->getName();
                        COUNTER_ST = signal;
                        COUNTER_ST->loadData();
                    }

                    if(signal->getName()->compare("XCP_DAQ.Main.DPSIPIN") == 0)
                    {

                        qDebug() << "DPSIPIN:" << *signal->getName();
                        DPSIPIN = signal;
                        DPSIPIN->loadData();
                    }

                    if(signal->getName()->compare("XCP_DAQ.Main.BETAPIN") == 0)
                    {

                        qDebug() << "BETAPIN:" << *signal->getName();
                        BETAPIN = signal;
                        BETAPIN->loadData();
                    }

                    if(signal->getName()->compare("XCP_DAQ.Main.RAWSWA") == 0)
                    {

                        qDebug() << "RAWSWA:" << *signal->getName();
                        RAWSWA = signal;
                        RAWSWA->loadData();
                    }

                    allSignal->insert(*signal->getName(), signal);
                }
            }
        }
        notSelectedSignals.append(signalNameList);
        //ui->statusbar->showMessage("Signals loaded!", 15000);
        //ui->actionMDF_file_info->setEnabled(true);
        //ui->actionSelect_Signals->setEnabled(true);
        m_fileNameMDF = name;
    }
    //ui->statusbar->clearMessage();
}

void MainWindow::on_Optimize_button_clicked()
{
    QHBoxLayout *SumDeltaGBLayout = new QHBoxLayout;
    QMessageBox messageBox;
    QLabel *SumDeltaValues = new QLabel;
    QLabel *SumDeltaLabel = new QLabel;

    QGroupBox *SumDeltaGB = new QGroupBox;

    /* At least 1 measurement needs to be loaded before we can start the optimization */
    if ( MeasurementCountOrigi == 0)
    {
        messageBox.warning(0,"Error", "Open at least 1 measurement!");
        messageBox.setFixedSize(500,200);
    }
    /* Empty lines are not accepted */
    else if ((ui->Cf_value->text().isEmpty()) || (ui->Cr_value->text().isEmpty()) || (ui->Theta_value->text().isEmpty()))
    {
        messageBox.warning(0,"Error", "Enter values for all of the parameters!");
        messageBox.setFixedSize(500,200);
    }
    /* Zero values are not accepted */
    else if ((QString(ui->Cf_value->text()).toDouble(0) == 0) || (QString(ui->Cr_value->text()).toDouble(0) == 0) || (QString(ui->Theta_value->text()).toDouble(0) == 0))
    {
        messageBox.warning(0,"Error", "Parameter values must not be 0!");
        messageBox.setFixedSize(500,200);
    }
    else
    {

        /*Deleting all the widgets from the MeasurementLayout */
        if ( ui->SumDeltaLayout != NULL )
        {
            QLayoutItem* item;
            while ( ( item = ui->SumDeltaLayout->takeAt( 0 ) ) != NULL )
            {
                delete item->widget();
                delete item;
            }
            //delete SumDeltaSubLayout;
        }

        //QHBoxLayout *SumDeltaSubLayout = new QHBoxLayout;

        EulerSumValue = 0;
        NormalSumValue = 0;
        OtherSumValue = 0;
        Cf = QString(ui->Cf_value->text()).toDouble(0);
        Cr = QString(ui->Cr_value->text()).toDouble(0);
        Theta = QString(ui->Theta_value->text()).toDouble(0);

        for (int j = 0; j < MeasurementCountOrigi; j++)
        {
            Euler[j]->setNum(Cr);
            Normal[j]->setNum(Cf);
            Other[j]->setNum(Theta);
            EulerSumValue += Cr;
            NormalSumValue += Cf;
            OtherSumValue += Theta;
        }

        Euler[MeasurementCountOrigi]->setNum(EulerSumValue);
        Normal[MeasurementCountOrigi]->setNum(NormalSumValue);
        Other[MeasurementCountOrigi]->setNum(OtherSumValue);

        Data[MeasurementCountOrigi]->setLayout(VerticalLayout[MeasurementCountOrigi]);
        Data[MeasurementCountOrigi]->setTitle("Sum");

        VerticalLayout[MeasurementCountOrigi]->addWidget(Normal[MeasurementCountOrigi]);
        VerticalLayout[MeasurementCountOrigi]->addWidget(Euler[MeasurementCountOrigi]);
        VerticalLayout[MeasurementCountOrigi]->addWidget(Other[MeasurementCountOrigi]);

        SumDelta = EulerSumValue + NormalSumValue + OtherSumValue;
        SumDeltaValues->setNum(SumDelta);

        ui->SumDeltaLayout->addWidget(SumDeltaLabel);
        ui->SumDeltaLayout->addWidget(SumDeltaValues);
        ui->SumDeltaLayout->setAlignment(Qt::AlignRight);
    }
}


void MainWindow::on_Apply_Parameters_clicked()
{
    QMessageBox messageBox;

    /* Empty lines are not accepted */
    /*else*/ if ((ui->Lf_value->text().isEmpty()) || (ui->Lr_value->text().isEmpty()) || (ui->M_value->text().isEmpty()) || (ui->ESM_value->text().isEmpty()))
    {
        messageBox.warning(0,"Error", "Enter values for all of the parameters!");
        messageBox.setFixedSize(500,200);
    }
    /* Zero values are not accepted */
    else if ((QString(ui->Lf_value->text()).toDouble(0) == 0) || (QString(ui->Lr_value->text()).toDouble(0) == 0) || (QString(ui->M_value->text()).toDouble(0) == 0) || (QString(ui->ESM_value->text()).toDouble(0) == 0))
    {
        messageBox.warning(0,"Error", "Parameter values must not be 0!");
        messageBox.setFixedSize(500,200);
    }
    else
    {

    }
}

void MainWindow::deleteChildWidgets(QLayoutItem *item)
{
    if (item->layout())
    {
        // Process all child items recursively.
        for (int i = 0; i < item->layout()->count(); i++) {
            deleteChildWidgets(item->layout()->itemAt(i));
        }
    }
    delete item->widget();
}
