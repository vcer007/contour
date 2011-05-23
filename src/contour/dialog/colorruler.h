#ifndef COLORRULER_H
#define COLORRULER_H

#include <QList>
#include <QWidget>
#include <QFrame>
#include <QColor>

/*ColorFrame 是用来在颜色调制器上显示当前的颜色表的*/
class  ColorFrame : public QFrame
{
     Q_OBJECT
		
 public:
     enum {horizontal,vertical};

     ColorFrame(QWidget *parent = 0);

     ~ColorFrame();
     
     void setColorMap(QList<QColor> colorMap)
     {
	  colors = colorMap;
	  update();
     }

     void setDirection(int d)
     {
	  direction = d;
     }

private:

     void paintEvent ( QPaintEvent * event );

     QList<QColor> colors;

     int direction ;
};

class  TextFrame : public QFrame
{
public:
     TextFrame(QWidget *parent =0);

     ~TextFrame();

     void setRange(qreal min,qreal max){
	  minV = min;
	  maxV = max;
	  update();
     }

private:
     void paintEvent ( QPaintEvent * event );

     qreal minV,maxV;
};


class ColorRuler : public QFrame
{
public:
     ColorRuler(QWidget *parent = 0);
     ~ColorRuler();

     void setColorMap(QList<QColor> colorMap);

 
     void setRange(qreal min,qreal max);
 
private:
     void resizeEvent(QResizeEvent *event)
     {
	  QFrame::resizeEvent(event);
     }
     ColorFrame *colorframe;
     TextFrame *textframe;
};

#endif


