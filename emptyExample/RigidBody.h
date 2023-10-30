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
	RigidBody();
	~RigidBody();
	void integrate(double duration);
	double getInverseMass();
	void setInverseMass(double mass);
	double getLinearDamping();
	void setLinearDamping(double damping);
	Vecteur3D getPosition();
	void setPosition(Vecteur3D pos);
	Vecteur3D getVelocity();
	void setVelocity(Vecteur3D vel);
	Quaternion getOrientation();
	void setOrientation(Quaternion q);
	Vecteur3D getRotation();
	void setRotation(Vecteur3D rot);
	Matrix34 getTransformMatrix();
	void setTransformMatrix(Matrix34 matrix);

private:
	void calculateDerivedData();
};

