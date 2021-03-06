#include "colorruler.h"
#include <QHBoxLayout>
#include <QPainter>
#include <QPaintEvent>
#include <QColor>

ColorFrame::ColorFrame(QWidget *parent /* = 0 */)
:QFrame(parent)
{
	setFrameShadow(QFrame::Raised);
	setFrameShape(QFrame::Box);
	setFrameStyle(QFrame::Panel | QFrame::Raised);
	direction = horizontal;//default direction
}

ColorFrame::~ColorFrame()
{

}


void ColorFrame::paintEvent(QPaintEvent *event)
{
	QPainter painter;
	painter.begin(this);
	painter.setPen(Qt::NoPen);
	qreal step;

	// 水平显示
	if(direction == horizontal){
		step = width()/32;
		for(int i=0;i<colors.count();i++)
		{
			painter.setBrush(colors[i]);
			painter.drawRect(i*step,0,step,height());
		}
	}else{// 垂直显示
		step = height()/32.0;
		for(int i=0;i<colors.count();i++)
		{
			painter.setBrush(colors[colors.count()-i-1]);
			painter.drawRect(0,i*step,width(),step+1);
		}
	}
	painter.end();
	QFrame::paintEvent(event);
}


TextFrame::TextFrame(QWidget *parent /* =0 */)
:QFrame(parent)
{
	setFrameStyle(QFrame::NoFrame);
	resize(100,600);
}

TextFrame::~TextFrame()
{

}

void TextFrame::paintEvent(QPaintEvent * event )
{
	int number;
	// 动态计算颜色条个数
	if(height() > 120)
		number = 10;
	else if(height() > 50 )
	     number = 5;
	else 
	     number = 2;
	if(number == 0)
		return;
	qreal step = height()/number;
	qreal delV = (maxV-minV)/number;
	QPainter painter;
	painter.begin(this);
	for(int i=0;i<10;i++)
	{
                painter.drawText(0,i*step,width(),20,Qt::AlignLeft+Qt::AlignTop,QString::number(maxV - delV*i));
	}	
 	if(height() > 300)
                 painter.drawText(0,height()-20,width(),20,Qt::AlignLeft+Qt::AlignTop,QString::number(minV));
	painter.end();
	QFrame::paintEvent(event);
}


ColorRuler::ColorRuler(QWidget *parent /* = 0 */)
:QFrame(parent)
{

	setFrameStyle(QFrame::NoFrame);

	colorframe = new ColorFrame(this);	
	colorframe->setDirection(ColorFrame::vertical);
	textframe = new TextFrame(this);	
	QHBoxLayout *layout = new QHBoxLayout;
	layout->setContentsMargins(1,1,1,1);
	layout->addWidget(colorframe);
	layout->addWidget(textframe);
	setLayout(layout);
	resize(QSize(colorframe->width()+textframe->width(),height()));
}

ColorRuler::~ColorRuler()
{

}

void ColorRuler::setColorMap(QList<QColor> colorMap)
{
	colorframe->setColorMap(colorMap);
	//colorframe->show();
}

void ColorRuler::setRange(qreal min,qreal max)
{
	textframe->setRange(min,max);
	//textframe->show();
}
