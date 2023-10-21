#include "Particule.h"

Particule::Particule()
{
	// Constructeur par défaut
	position = Vecteur3D();
	velocite = Vecteur3D();
	acceleration = Vecteur3D();
}

Particule::Particule(Vecteur3D position, Vecteur3D velocite, Vecteur3D acceleration)
{
	// Constructeur avec paramètres
	this->position = position;
	this->velocite = velocite;
	this->acceleration = acceleration;
}

Particule::~Particule()
{
	// Destructeur
}

Vecteur3D Particule::getPosition()
{
	// Accesseur
	return position;
}

Vecteur3D Particule::getVelocite()
{
	// Accesseur
	return velocite;
}

Vecteur3D Particule::getAcceleration()
{
	// Accesseur
	return acceleration;
}

void Particule::setPosition(Vecteur3D position)
{
	// Mutateur
	this->position = position;
}

void Particule::setVelocite(Vecteur3D velocite)
{
	// Mutateur
	this->velocite = velocite;
}

void Particule::setAcceleration(Vecteur3D acceleration)
{
	// Mutateur
	this->acceleration = acceleration;
}

void Particule::addAcceleration(Vecteur3D acceleration)
{
	this->setAcceleration(this->acceleration + acceleration);
}

void Particule::setRayon(float rayon)
{
	// Mutateur
	this->rayon = rayon;
}

float Particule::getRayon()
{
	// Accesseur
	return rayon;
}

void Particule::setMasse(float masse)
{
	// Mutateur
	this->masse = masse;
}

float Particule::getMasse()
{
	// Accesseur
	return masse;
}