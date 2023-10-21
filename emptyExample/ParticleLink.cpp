#include "ParticleLink.h"

#include "ParticleContact.h"


float ParticleLink::currentLength() const {
	Vecteur3D relativePos = particle1.getPosition().sub(particle2.getPosition());
	return relativePos.norme();
}

void ParticleLink::setParticles(Particule p1, Particule p2) {
	particle1 = p1;
	particle2 = p2;
}
