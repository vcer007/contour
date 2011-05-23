#ifndef TRACEDIALOG_H
#define TRACEDIALOG_H

#include <QDialog>
#include "ui_trace.h"

class TraceDialog : public QDialog , public Ui::TracingDialog
{
Q_OBJECT
public:
     TraceDialog( QWidget * parent = 0, Qt::WindowFlags f = 0);

     ~TraceDialog();

     void setTraceValue(QVector<float> &valueList);

     QVector<float> getTraceValue();

     int getTraceNumber(){
	  return _defNum;
     }

     void setDefault(float min,float max,int number);


private slots:

     void addValue();

     void removeValue();

     void cleanAllValue();

     void toDefault();

     void getList();
private: 

     float _defMin;
     float _defMax;
     float _defNum;
     QButtonGroup *_buttonGroup;

};


#endif
