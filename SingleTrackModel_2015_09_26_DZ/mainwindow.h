#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>

#include "MDF/MDFLib.h"
#include "mysignal.h"
#include <QMessageBox>


#include "dmc.h"
#include "qcustomplot.h"

/* for debug */
#include <QDebug>

#define MaximumMeasurements 12
#define CfMax 100
#define CfMin 0
#define CrMax 100
#define CrMin 0
#define ThetaMax 100
#define ThetaMin 0
#define LfMax 100
#define LfMin 0
#define LrMax 100
#define LrMin 0
#define MMax 100
#define MMin 0
#define ESMMax 100
#define ESMMin 0

#define MeasurementLineNumber 2

extern QCustomPlot *Customplott[MaximumMeasurements];



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    double Cf = 1;
    double Cr = 1;
    double Theta = 1;
    double Lf = 1;
    double Lr = 1;
    double M = 1;
    double ESM = 1;
    double x_position[MaximumMeasurements];
    double y_position[MaximumMeasurements];


    QVector<double> OutputYawRateValues[MaximumMeasurements];
    QVector<double> Time[MaximumMeasurements];
    QVector<double> MeasuredYawRateValues[MaximumMeasurements];
    QVector<double> EstimatedYawRateValues[MaximumMeasurements];
    QVector<double> AYC_VREF_Values[MaximumMeasurements];
    QVector<double> FSTANGLE_Values[MaximumMeasurements];
    QVector<double> FSTANGLEP_Values[MaximumMeasurements];
    QVector<double> FYAWACC_Values[MaximumMeasurements];
    QVector<double> AFLATACCC_Values[MaximumMeasurements];
    QVector<double> COUNTER_ST_Values[MaximumMeasurements];
    QVector<double> DPSIPIN_Values[MaximumMeasurements];
    QVector<double> BETAPIN_Values[MaximumMeasurements];
    QVector<double> RAWSWA_Values[MaximumMeasurements];
    QVector<double> SLP_ANG_REF_values[MaximumMeasurements];
    QVector<double> AYCESTIMMY_values[MaximumMeasurements];
    QVector<double> SASINIT_values[MaximumMeasurements];
    QVector<double> REFYRSA_values[MaximumMeasurements];
    QVector<double> RES_AYC_CTRL_value[MaximumMeasurements];
    QVector<double> RESET_PROHIB_values[MaximumMeasurements];
    QVector<double> RUNNING_value[MaximumMeasurements];


    QGridLayout *InitMeasurementsLayout();
    QVBoxLayout *InitEstimationSubLayout();
    mySignal *RawYR, *EstimatedYawRate;
    mySignal *AYC_VREF, *FSTANGLE, *FSTANGLEP, *FYAWRATE, *FYAWACC, *YAWRREF, *AFLATACCC, *COUNTER_ST, *DPSIPIN, *BETAPIN, *RAWSWA, *SLP_ANG_REF, *AYCESTIMMY, *SASINIT, *REFYRSA, *RES_AYC_CTRL, *RESET_PROHIB, *RUNNING;
    QVector<double> Calculate_Estimated_Yaw_Rate(int loopcount, int NumberOfMeasurement);
    ~MainWindow();

private slots:
    void on_actionLoad_Identification_Project_triggered();

    void on_actionLoad_vehicle_parameter_triggered();

    void on_actionSave_vehicle_parameter_triggered();

    void on_actionSave_Identification_Project_triggered();

    void on_actionLoad_DAS_Measurement_triggered();


    void on_Optimize_button_clicked();

    void on_Apply_Parameters_clicked();

private:
    Ui::MainWindow *ui;
    QGridLayout *MeasurementLayout;
    void openMDF(QString name);

    /* Helper function. Deletes all child widgets of the given layout @a item.*/
    void deleteChildWidgets(QLayoutItem *item);

    MDFlib::MDF *mdf;
    QList<QString> signalNameList;
    QMap<QString, mySignal*>* allSignal;
    QStringList notSelectedSignals;
    QString m_fileNameMDF;
    DMC *dmc;
    //QCustomPlot *PositionSelection;

protected:
    void  closeEvent(QCloseEvent*);
    void onMouseMoveGraph(QMouseEvent* evt);


};

#endif // MAINWINDOW_H
