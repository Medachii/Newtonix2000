#pragma once
#include "ParticleForceGenerator.h"



class ParticleGravity : public ParticleForceGenerator
{
private:
	Vecteur3D gravity = Vecteur3D(0,-9.81,0);
public:
	virtual void updateForce(Particule* p, float dt) = 0;
	void setGravity(Vecteur3D g);
};

