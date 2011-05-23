#ifndef RANDSETDIALOG_H
#define RANDSETDIALOG_H

#include <QDialog>
#include "../ui_randset.h"
#include "../contourstruct.h"

class RandSetDialog :public QDialog ,public Ui::RandSet
{
public:
     RandSetDialog( QWidget * parent = 0, Qt::WindowFlags f = 0 );

     ~ RandSetDialog();

     void initialInfo(CGridDataInfo info,int number);

     void getInfo(CGridDataInfo &info,int &number); 
};

#endif
