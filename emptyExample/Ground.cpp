#include "Ground.h"
#include <ofGraphics.h>

Ground::Ground()
{
	// Constructeur par défaut
	x = 0;
	y = 0;
	z = 0;
}

Ground::~Ground()
{
	// Destructeur
}


void Ground::setX(int x)
{
	// Mutateur
	this->x = x;
}

void Ground::setY(int y)
{
	// Mutateur
	this->y = y;
}

void Ground::setZ(int z)
{
	// Mutateur
	this->z = z;
}

void Ground::setXYZ(int x, int y, int z)
{
	// Mutateur
	this->x = x;
	this->y = y;
	this->z = z;
}

float Ground::getX()
{
	// Accesseur
	return x;
}

float Ground::getY()
{
	// Accesseur
	return y;
}

float Ground::getZ()
{
	// Accesseur
	return z;
}

float Ground::getW()
{
	// Accesseur
	return width;
}

float Ground::getH()
{
	// Accesseur
	return height;
}

float Ground::getD()
{
	// Accesseur
	return depth;
}