#include "ParticleCable.h"

unsigned int ParticleCable::addContact(ParticleContact* contact, unsigned int limit) const {
    // Calcul de la longueur actuelle du câble entre les deux sphères
    float distance = currentLength();

    // Vérification de la violation de la longueur maximale du câble
    if (distance < maxLength) {
        return 0; // Pas de contact généré, le câble est dans les limites
    }

    ParticleContact newContact;
    newContact.particle[0] = particle[0];
    newContact.particle[1] = particle[1];
    newContact.restitution = restitution;

    // Calcul de la normale de contact (de la sphère 0 vers la sphère 1)
    newContact.contactNormal = (particle[1]->getPosition() - particle[0]->getPosition()).normalize();

    // Calcul de la pénétration (dépassement de la longueur maximale)
    newContact.penetration = distance - maxLength;

    if (limit > 0) {
        contact[0] = newContact;
        return 1; // Un contact généré
    }

    return 0;
}