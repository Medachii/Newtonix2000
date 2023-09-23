#include "Vecteur3D.h"

Vecteur3D::Vecteur3D()
{
	// Constructeur par défaut
	x = 0;
	y = 0;
	z = 0;

}

Vecteur3D::Vecteur3D(double x, double y, double z)
{
	// Constructeur avec paramètres
	this->x = x;
	this->y = y;
	this->z = z;
}

Vecteur3D::~Vecteur3D()
{
	// Destructeur
}

double Vecteur3D::getX()
{
	// Accesseur
	return x;
}

double Vecteur3D::getY()
{
	// Accesseur
	return y;
}

double Vecteur3D::getZ()
{
	// Accesseur
	return z;
}

void Vecteur3D::setX(double x)
{
	// Mutateur
	this->x = x;
}

void Vecteur3D::setY(double y)
{
	// Mutateur
	this->y = y;
}

void Vecteur3D::setZ(double z)
{
	// Mutateur
	this->z = z;
}

Vecteur3D Vecteur3D::add(Vecteur3D q)
{
	// Addition de deux vecteurs
	Vecteur3D r;
	r.setX(x + q.getX());
	r.setY(y + q.getY());
	r.setZ(z + q.getZ());
	return r;
}

Vecteur3D Vecteur3D::mul(double k)
{
	// Multiplication d'un vecteur par un scalaire
	Vecteur3D r;
	r.setX(k * x);
	r.setY(k * y);
	r.setZ(k * z);
	return r;
}