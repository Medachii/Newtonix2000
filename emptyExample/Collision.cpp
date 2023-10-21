#include "Collision.h"
#include <math.h>

Collision::Collision()
{
	// Constructeur par défaut
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

