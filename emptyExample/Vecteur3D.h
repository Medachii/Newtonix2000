#pragma once
class Vecteur3D
{
	// Attributs
private:
	double x;
	double y;
	double z;
	// Méthodes
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
	// Autres méthodes
	Vecteur3D add(Vecteur3D q);
	Vecteur3D mul(double k);
};
