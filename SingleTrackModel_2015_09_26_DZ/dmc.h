#ifndef DMC_H
#define DMC_H

#include <QObject>
#include "qcustomplot.h"
//class MainWindow;
//class QCustomPlot;

class DMC : public QObject
{
    Q_OBJECT
public:
    explicit DMC(QObject *parent = 0);
    ~DMC();

signals:

public slots:
    void WidgetClicked_0(QMouseEvent*);
    void WidgetClicked_1(QMouseEvent*);
    void WidgetClicked_2(QMouseEvent*);
    void WidgetClicked_3(QMouseEvent*);
    void WidgetClicked_4(QMouseEvent*);
    void WidgetClicked_5(QMouseEvent*);
    void WidgetClicked_6(QMouseEvent*);
    void WidgetClicked_7(QMouseEvent*);
    void WidgetClicked_8(QMouseEvent*);
    void WidgetClicked_9(QMouseEvent*);
    void WidgetClicked_10(QMouseEvent*);
    void WidgetClicked_11(QMouseEvent*);

private:
    MainWindow *mainWindow;
    QCustomPlot *qcustom;
    //QCustomPlot *selectPos;
};

#endif // DMC_H
