#include "ParticleContact.h"




void ParticleContact::resolve(float duration) {
	resolveVelocity();
	resolveInterpenetration();
}

float ParticleContact::calculateSeparatingVelocity() {
	return 0;
}

void ParticleContact::resolveVelocity() {

	//post collision velocity = velocity + k*vector normal /mass (=1)
	//k = -(1+e) * (v1-v2) * n / (1/m1 + 1/m2)
//e = restitution	

	float k = -(1 + restitution) * (particle[0]->getVelocite() - particle[1]->getVelocite()).ProduitScalaire(contactNormal) / (1 / particle[0]->getMasse() + 1 / particle[1]->getMasse());
	particle[0]->setVelocite(particle[0]->getVelocite() + contactNormal.mul(k / particle[0]->getMasse()));
	particle[1]->setVelocite(particle[1]->getVelocite() - contactNormal.mul(k / particle[1]->getMasse()));

}

void ParticleContact::resolveInterpenetration() {

}





