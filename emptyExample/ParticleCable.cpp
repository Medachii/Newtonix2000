#include "ParticleCable.h"


unsigned int ParticleCable::addContact(std::vector<ParticleContact>& contact, unsigned int limit) {
    // Calcul de la longueur actuelle du câble entre les deux sphères
    Particule p1 = getParticleCable1();
    Particule p2 = getParticleCable2();
    float distance = (p1.getPosition() - p2.getPosition()).norme();



    // Vérification de la violation de la longueur maximale du câble
    if (distance <= maxLength) {
        return 0; // Pas de contact généré, le câble est dans les limites
    }

    ParticleContact newContact;
    newContact.particle[0] = &particle1;
    newContact.particle[1] = &particle2;
    newContact.restitution = restitution;

    // Calcul de la normale de contact (de la sphère 0 vers la sphère 1)
    newContact.contactNormal = (particle2.getPosition() - particle1.getPosition()).normalize();

    // Calcul de la pénétration (dépassement de la longueur maximale)
    newContact.penetration = distance - maxLength;

    if (limit > 0) {
        contact.push_back(newContact);
        return 1; // Un contact généré
    }

    return 0;
}

void ParticleCable::setParticleCable(Particule p1, Particule p2, float maxLength, float restitution) {
    particle1 = p1;
    particle2 = p2;
    this->maxLength = maxLength;
    this->restitution = restitution;
}



Particule ParticleCable::getParticleCable1() const {
    return particle1;
}

Particule ParticleCable::getParticleCable2() const {
    return particle2;
}

void ParticleCable::setParticleCable1(Particule p1) {
    particle1 = p1;
}

void ParticleCable::setParticleCable2(Particule p2) {
    particle2 = p2;
}

float ParticleCable::getMaxLength() const {
    return maxLength;
}

float ParticleCable::getRestitution() const {
    return restitution;
}
