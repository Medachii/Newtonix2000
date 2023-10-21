#include "ParticleCable.h"

unsigned int ParticleCable::addContact(ParticleContact* contact, unsigned int limit) const {
    // Calcul de la longueur actuelle du c�ble entre les deux sph�res
    float distance = currentLength();

    // V�rification de la violation de la longueur maximale du c�ble
    if (distance < maxLength) {
        return 0; // Pas de contact g�n�r�, le c�ble est dans les limites
    }

    ParticleContact newContact;
    newContact.particle[0] = particle[0];
    newContact.particle[1] = particle[1];
    newContact.restitution = restitution;

    // Calcul de la normale de contact (de la sph�re 0 vers la sph�re 1)
    newContact.contactNormal = (particle[1]->getPosition() - particle[0]->getPosition()).normalize();

    // Calcul de la p�n�tration (d�passement de la longueur maximale)
    newContact.penetration = distance - maxLength;

    if (limit > 0) {
        contact[0] = newContact;
        return 1; // Un contact g�n�r�
    }

    return 0;
}