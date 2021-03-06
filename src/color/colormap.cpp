#include "colormap.h"
#include <cassert>
#include <string>
#include <ctime>
#include <iostream>
#include <QDebug>
#include <QTime>

ColorMap::ColorMap()
{
	colorMap = new std::map<float,Rgb>;
}

ColorMap::~ColorMap()
{

}

void ColorMap::useMapOf(int mapIndex)
{
	if(mapIndex>(mapsize-1))
		return;

	currentMap=mapIndex;
	memcpy((char*)useMap,(char*)maps[mapIndex],sizeof(useMap)); 
}

void ColorMap::setRange(float minValue,float maxValue)
{
	max = maxValue;
	min = minValue;
	initial();
}

Rgb ColorMap::sebcolors[]={
	Rgb(144,144,144),Rgb(0,0,255),Rgb(0,64,255),Rgb(0,95,255),
	Rgb(0,127,255),Rgb(0,159,255),Rgb(0,191,255),Rgb(0,223,255),
	Rgb(0,255,255),Rgb(32,255,223),Rgb(64,255,191),Rgb(95,255,159),
	Rgb(127,255,127),Rgb(159,255,95),Rgb(191,255,64),Rgb(223,255,32),
	Rgb(255,255,0),Rgb(255,223,0),Rgb(255,191,0),Rgb(255,159,0),
	Rgb(255,127,0),Rgb(255,95,0),Rgb(255,64,0),Rgb(255,32,0),
	Rgb(255,0,0),Rgb(255,0,64),Rgb(255,0,95),Rgb(255,0,127),
	Rgb(255,0,159),Rgb(255,0,191),Rgb(255,0,223),Rgb(255,0,255)
};

Rgb ColorMap::gathercolors[]={
	Rgb(0,0,255),Rgb(0,0,255),Rgb(1,1,255),Rgb(4,4,255),
	Rgb(8,8,255),Rgb(14,14,255),Rgb(22,22,255),Rgb(33,33,255),
	Rgb(45,45,255),Rgb(60,60,255),Rgb(79,79,255),Rgb(100,100,255),
	Rgb(124,124,255),Rgb(152,152,255),Rgb(183,183,255),Rgb(217,217,255),
	Rgb(255,255,255),Rgb(255,217,217),Rgb(255,183,183),Rgb(255,152,152),
	Rgb(255,124,123),Rgb(255,100,100),Rgb(255,79,79),Rgb(255,60,60),
	Rgb(255,45,45),Rgb(255,33,33),Rgb(255,22,22),Rgb(255,14,14),
	Rgb(255,8,8),Rgb(255,4,4),Rgb(255,1,1),Rgb(255,0,0)
};





Rgb* ColorMap::maps[] ={sebcolors,gathercolors}; 

int ColorMap::mapsize = 2;
int ColorMap::currentMap = 0;	// initial currentMap to 0

void ColorMap::initial()
{  
	step = (max - min)/31;
	for(int i=0;i<=31;i++)
	{
		colorMap->insert(std::make_pair(min+step*(i), useMap[i]));
		colorindex.push_back(min+step*i);
	}
}

/*
base的作用,如果base是1，则在每两个颜色之间插入一个颜色，如果是2，
则在每两个颜色之间插入2个颜色。两端不插入颜色（min之下，max之上）。
*/

void ColorMap::interpose(int base)
{
	/*保证基数大于0*/
	assert(base>0);

	int i,k,j;
	float w;
	float increaseStep;
	float startStep;
	Rgb c;
	w=1;	
	k=0;
	increaseStep = step/(base+1);
	for(i=1;i<32;i++)
	{
		startStep = min + (k++)*step;
		for(j=0;j<base;j++)
		{
			w=(float)j/base;
			c=Rgb(
				(int)(useMap[i-1].red()+(useMap[i].red()-useMap[i-1].red())*w),
				(int)(useMap[i-1].green()+(useMap[i].green()-useMap[i-1].green())*w),

				(int)(useMap[i-1].blue()+(useMap[i].blue()-useMap[i-1].blue())*w)
				);

			colorMap->insert(std::make_pair(startStep+increaseStep*j,c));

			colorindex.push_back(startStep+increaseStep*j);
		}
	}
	quicksort(colorindex,0,colorindex.size()-1);
}



Rgb ColorMap::findIndex(float key)
{
	if(key <= min) return colorMap->find(min)->second;
	if(key >= max) return colorMap->find(max)->second;
	static std::map<float,Rgb>::iterator iter;

	if((iter =colorMap->find(key)) != colorMap->end())
		return iter->second;	

	/*折半搜索法*/
	static int left; 
	static int right; 
	static int middle; 
	left = 0;

	right = colorMap->size()-1;
	middle =0;
	while(left <= right){
		middle = (left+right)/2;
		if(colorindex.at(middle)==key) 
			return colorMap->find(key)->second;

		else if(colorindex.at(middle)<key) 
			left = middle + 1;
		else 
			right = middle - 1;
	}
	return colorMap->find(colorindex.at(middle))->second;	
}





int ColorMap::partition(std::vector<float> &a, int left,int right,int pivotIndex)
{
	/*快速排序法的分割点*/
	float pivotValue = a[pivotIndex];
	swap(a,pivotIndex,right);
	int storeIndex = left;
	for(int i=left;i<=right-1;i++)
	{
		if(a[i]<=pivotValue)
		{
			swap(a,storeIndex,i);
			storeIndex += 1;
		}
	}

	swap(a,right,storeIndex);// 把 pivot 移到它最後的地方
	return storeIndex;
}





void ColorMap::quicksort(std::vector<float> &a, int left, int right)
{
	if (right > left)
	{
		int pivotNewIndex = partition(a, left, right,(left+right)/2);
		quicksort(a, left, pivotNewIndex-1);
		quicksort(a, pivotNewIndex+1, right);
	}
}
