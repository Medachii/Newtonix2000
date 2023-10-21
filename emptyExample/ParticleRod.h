#pragma once
#include "ParticleContact.h"
#include "ParticleLink.h"
#include <vector>
class ParticleRod : public ParticleLink
{
public:
	float length;
	unsigned int addContact(std::vector<ParticleContact>& contact, unsigned int limit);
	void setParticleRod(Particule p1, Particule p2, float length);
	Particule getParticleRod1() const;
	Particule getParticleRod2() const;
	void setParticleRod1(Particule p1);
	void setParticleRod2(Particule p2);
	float getLength() const;
};

