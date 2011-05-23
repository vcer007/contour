#ifndef COLORMAP_H
#define COLORMAP_H

#include <vector>
#include <map>
#include <cstring>
#include <QDebug>

struct Rgb
{
	short r;
	short g;
	short b;

	int red()
	{ return r; }

	int green()
	{ return g; }

	int blue() 
	{ return b; }

	Rgb(){}
	Rgb(int r, int g, int b)
	{
		this->r= r;
		this->g= g;
		this->b= b;
	}
};

class ColorMap 
{
public:

	ColorMap();

	~ColorMap();

	/* which color map to use */
	void useMapOf(int mapIndex);

	void setRange(float minValue,float maxValue);

	/*由本先的个颜色进行插值，插值个数由倍数base指定，如果是则插值后的颜色为*/
	void interpose(int base);

	/*给定一个key值(这个key值有可能不存在)，返回一个与它相近的存在的key值(四舍五入法)对应的

	颜色*/
	Rgb  findIndex(float key);

	inline void clear()
	{
		colorMap->clear();
		colorindex.clear();
	}

	inline Rgb* getColors()
	{
		return useMap;
	}

	inline void setColor(Rgb* colorMap)
	{
		memcpy((char*)useMap,(char*)colorMap,sizeof(useMap)); 
	}

public:

	static Rgb  sebcolors[];

	static Rgb  gathercolors[];

	static Rgb* maps[];

	static int mapsize;	/* mapsize is the size of maps */

	static int currentMap;

private:
	/*初始化基本的位颜色表*/
	void initial();

	/*快速排序算法，这个主要针对哈希表索引排序*/
	void quicksort(std::vector<float> &a, int left, int right);

	/*快速排序算法的分割部分*/
	int partition(std::vector<float> &a, int left,int right,int pivotIndex);

	void swap(std::vector<float> &a , int p, int q)
	{
		float tmp = a[p];
		a[p]=a[q];
		a[q]=tmp;
	}

	/*这个是key值和QRgb(用int表示)的哈希表，用哈希表的原因是因为速度快*/
	std::map<float,Rgb> *colorMap;

	/*这个是哈希表key值得索引，因为需要key值是按顺序排列，但是哈希表是自由排序的*/
	std::vector<float>  colorindex;	

	Rgb useMap[32];

	/*key的范围*/
	float max,min;

	/*初始增量*/
	float step;
};
#endif

