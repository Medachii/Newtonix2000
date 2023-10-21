#pragma once
#include "ParticleForceGenerator.h"



class ParticleGravity : public ParticleForceGenerator
{
private:
	Vecteur3D gravity;
public:
	virtual void updateForce(Particule* p, float dt) = 0;
};

