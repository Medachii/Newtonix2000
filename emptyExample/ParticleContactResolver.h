#pragma once
#include "ParticleContact.h"
class ParticleContactResolver
{
protected:
	unsigned int iteration;
public:
	void resolveContacts(ParticleContact* contactArray, unsigned int numContacts, float duration);
};

