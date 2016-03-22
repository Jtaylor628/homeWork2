#pragma once
class PicLocation {
public:

	int getx()
	{
		return x;
	}
	int gety()
	{
		return y;
	}
	PicLocation() {
		x = 0;
		y = 0;
	}
	void setx(int x1)
	{
		x = x1;
	}
	void sety(int y1)
	{
		y = y1;
	}
private:
	int x;
	int y;

};