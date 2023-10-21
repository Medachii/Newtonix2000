#include "ParticleRod.h"
#include <vector>
void ParticleRod::setParticleRod(Particule p1, Particule p2, float length) {
	particle1 = p1;
	particle2 = p2;
	this->length = length;
}

Particule ParticleRod::getParticleRod1() const {
	return particle1;
}

Particule ParticleRod::getParticleRod2() const {
	return particle2;
}

void ParticleRod::setParticleRod1(Particule p1) {
	particle1 = p1;
}

void ParticleRod::setParticleRod2(Particule p2) {
	particle2 = p2;
}

float ParticleRod::getLength() const {
	return length;
}

unsigned int ParticleRod::addContact(std::vector<ParticleContact>& contact, unsigned int limit) {
	float currentLength = (particle1.getPosition() - particle2.getPosition()).norme();
	if (currentLength == length) {
		return 0;
	}
	ParticleContact newContact;
	newContact.particle[0] = &particle1;
	newContact.particle[1] = &particle2;
	newContact.restitution = 0;
	newContact.contactNormal = (particle2.getPosition() - particle1.getPosition()).normalize();

	if (currentLength > length) {
		newContact.penetration = currentLength - length;
	}
	else {
		newContact.penetration = length - currentLength;
	}
	if (limit > 0) {
		contact.push_back(newContact);
		return 1;
	}

	return 0;
	
}
