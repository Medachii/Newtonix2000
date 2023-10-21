#pragma once
#include "ParticleContact.h"
#include "ParticleLink.h"
#include <vector>
class ParticleCable : public ParticleLink
{
public:

	float maxLength;
	float restitution;
	unsigned int addContact(std::vector<ParticleContact>& contact, unsigned int limit);
	void setParticleCable(Particule p1, Particule p2, float maxLength, float restitution);
	Particule getParticleCable1() const;
	Particule getParticleCable2() const;

};

