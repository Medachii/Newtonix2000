#pragma once

#include "Vecteur3D.h"
#include "Quaternion.h"
#include "Matrix34.h"

class RigidBody
{
private:
	double inverseMass;
	double linearDamping;
	Vecteur3D position;
	Vecteur3D velocity;

	Quaternion orientation;
	Vecteur3D rotation;
	Matrix34 transformMatrix;

public :
	void integrate(double duration);
private:
	void calculateDerivedData();
};

