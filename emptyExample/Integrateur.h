#pragma once

#include "Vecteur3D.h"
#include "Particule.h"
#include "ParticleForceRegistry.h"

class Integrateur
{
public:
	Integrateur();
	~Integrateur();
	void integrer(Particule* p, double time);

	double t;
};

