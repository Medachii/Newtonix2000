#pragma once
#include "Vecteur3D.h"

class Particule
{

	float rayon = 10;

	// Attributs
	Vecteur3D position;
	Vecteur3D velocite;
	Vecteur3D acceleration;

	// M�thodes
	public:
		// Constructeurs
		Particule();
		Particule(Vecteur3D position, Vecteur3D velocite, Vecteur3D acceleration);
		// Destructeur
		~Particule();
		// Accesseurs
		Vecteur3D getPosition();
		Vecteur3D getVelocite();
		Vecteur3D getAcceleration();
		// Mutateurs
		void setPosition(Vecteur3D position);
		void setVelocite(Vecteur3D velocite);
		void setAcceleration(Vecteur3D acceleration);
		// Autres m�thodes
		void setRayon(float rayon);
		float getRayon();
};

