#pragma once
#include "ParticleContact.h"
class ParticleContactGenerator
{
public :
	ParticleContactGenerator();
	~ParticleContactGenerator();
	virtual unsigned int addContact(ParticleContact* contact, unsigned int limit) const = 0;
};

