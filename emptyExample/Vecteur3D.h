#pragma once
#include <iostream>
#include <math.h>
class Vecteur3D
{
	// Attributs
private:
	double x;
	double y;
	double z;
	// M�thodes
public:
	// Constructeurs
	Vecteur3D();
	Vecteur3D(double x, double y, double z);
	// Destructeur
	~Vecteur3D();
	// Accesseurs
	double getX();
	double getY();
	double getZ();
	// Mutateurs
	void setX(double x);
	void setY(double y);
	void setZ(double z);
	// Autres m�thodes
	Vecteur3D add(Vecteur3D q);
	Vecteur3D mul(double k);
	Vecteur3D sub(Vecteur3D q);
	Vecteur3D operator+(Vecteur3D q);
	Vecteur3D operator-(Vecteur3D q);
	Vecteur3D operator*(float k);
	Vecteur3D operator/(float k);
	double norme();
	float length();
	Vecteur3D normalize();
	float ProduitScalaire(Vecteur3D q);
};
