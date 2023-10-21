#include "ParticleLink.h"

#include "ParticleContact.h"

float ParticleLink::currentLength() const {
	Vecteur3D relativePos = particle[0]->getPosition().sub(particle[1]->getPosition());
	return relativePos.norme();
}

