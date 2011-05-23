#ifndef COLORMAPEDIT_H
#define COLORMAPEDIT_H

#include <QDialog>
#include <QLinkedList>
#include <QList>
#include <QColor>
#include "../ui_colormapedit.h"
#include "../../color/colormap.h"

class  ColormapEdit : public QDialog ,public Ui::colormapEdit
{
	Q_OBJECT

public:
	ColormapEdit(QWidget *parent = 0);
	~ColormapEdit();
	void setColorList(QList<QColor> colors);

	void setColorList(Rgb* colors)
	{
	     QList<QColor> qcolors;
	     for(int i=0;i<32;i++)
		  qcolors<<QColor(colors[i].red(),colors[i].green(),colors[i].blue());
	     setColorList(qcolors);
	}

signals:
	void newColorList(QList<QColor> colors);

private slots:
	/*将颜色表进行循环旋转,就是把现在的第一个颜色依次放到第i个颜色中去*/
	void rotate(int n);	

	/*颜色从两边向中间压缩*/
	void bias(int n);

	/*颜色从中间向两边扩展*/
	void contrast(int n);
	
	/*设置某个位置的颜色*/
	void setColor();

	void okPressed();

	void applyPressed();

	void biasReset()
	{
		biasSlider->setValue(0);
	}
	void rotateReset()
	{
		rotateSlider->setValue(0);
	}
	void contrastRest()
	{
		contrastSlider->setValue(0);
	}

	/*重新显示colorMap的颜色*/
	void updateColormap();

	void resetMap(int index);

private:
	/*得到一个颜色为color的像素图*/
	QPixmap getPixmap(QColor color,int width,int height,int number);

	/*得到一个颜色条的像素图 */
	QPixmap getPixmap(Rgb *colors,int width,int height);
	
	/*当前的颜色表，用于用户暂时编辑*/
	QList<QColor> colors;

	/*记录前一次颜色表进行循环旋转的值*/
	int lastRotate;
	int lastBias;
	int lastContrast;

	bool rotated,biased,contrasted;

};


#endif // COLORMAPEDIT_H
