#pragma once
#include "Particule.h"
class ParticleContact
{
public:

	Particule* particle[2];
	float restitution;
	float penetration;
	Vecteur3D contactNormal;

	ParticleContact resolve(float duration);
	float calculateSeparatingVelocity();
private:
	void resolveVelocity();
	void resolveInterpenetration();
};

