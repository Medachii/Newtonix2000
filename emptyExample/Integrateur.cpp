#include "Integrateur.h"
#include <ofAppRunner.h>


Integrateur::Integrateur()
{
	// Constructeur par défaut
}

Integrateur::~Integrateur()
{
	// Destructeur
}

void Integrateur::integrer(Particule* p)
{
	Vecteur3D position = p->getPosition();
	Vecteur3D velocite = p->getVelocite();
	Vecteur3D acceleration = p->getAcceleration();
	double t = ofGetLastFrameTime();
	p->setPosition(position.add(velocite.mul(t)));
	p->setVelocite(velocite.add(acceleration.mul(t)));
}