#pragma once
#include "ParticleContactGenerator.h"
#include "Particule.h"
class ParticleLink : public ParticleContactGenerator
{
public:
	Particule particle1;
	Particule particle2;
	float currentLength() const;
	unsigned int addContact(ParticleContact* contact, unsigned int limit) const;
	void setParticles(Particule p1, Particule p2);
};


