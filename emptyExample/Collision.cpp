#include "Collision.h"
#include <math.h>

Collision::Collision()
{
	// Constructeur par d�faut
}

Collision::~Collision()
{
	// Destructeur
}

bool Collision::checkCollisionWithGround(Particule p, Ground g)
{
	// Check if the particle is in the ground
	if (p.getPosition().getY()+p.getRayon() <= g.getY()+g.getH()/2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Particule Collision::resolveCollisionWithGround(Particule p, Ground g)
{
	p.setVelocite(Vecteur3D(p.getVelocite().getX(), p.getVelocite().getY()*-1, p.getVelocite().getZ()));  //doit �tre possible sans retourner de valeur, jouer avec les pointeurs ?
	return p;
}

bool Collision::checkCollision(Particule p1, Particule p2)
{
	// Check if the distance between the two particles is less than the sum of their radius
	double distance = sqrt(pow(p1.getPosition().getX() - p2.getPosition().getX(), 2) + pow(p1.getPosition().getY() - p2.getPosition().getY(), 2) + pow(p1.getPosition().getZ() - p2.getPosition().getZ(), 2));
	if (distance <= p1.getRayon() + p2.getRayon())
	{
		return true;
	}
	else
	{
		return false;
	}
}

