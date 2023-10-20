#pragma once
class Ground
{
	int x;
	int y;
	int z;

	

	public:
		int width = 500;
		int height = 50;
		int depth = 500;
	Ground();
	~Ground();
	void setX(int x);
	void setY(int y);
	void setZ(int z);
	void setXYZ(int x, int y, int z);
	float getX();
	float getY();
	float getZ();
	float getW();
	float getH();
	float getD();


};

