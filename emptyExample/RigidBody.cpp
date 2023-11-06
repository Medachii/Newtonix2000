#include "RigidBody.h"


RigidBody::RigidBody()
{
}

RigidBody::~RigidBody()
{
}

double RigidBody::getInverseMass()
{
	return this->inverseMass;
}

void RigidBody::setInverseMass(double mass)
{
	this->inverseMass = mass;
}

double RigidBody::getLinearDamping()
{
	return this->linearDamping;
}

void RigidBody::setLinearDamping(double damping)
{
	this->linearDamping = damping;
}

double RigidBody::getAngularDamping()
{
	return this->angularDamping;
}

void RigidBody::setAngularDamping(double damping)
{
	this->angularDamping = damping;
}

Vecteur3D RigidBody::getPosition()
{
	return this->position;
}

void RigidBody::setPosition(Vecteur3D pos)
{
	this->position = pos;
}

Vecteur3D RigidBody::getVelocity()
{
	return this->velocity;
}

void RigidBody::setVelocity(Vecteur3D vel)
{
	this->velocity = vel;
}

Vecteur3D RigidBody::getForceAccum()
{
	return this->forceAccum;
}

void RigidBody::setForceAccum(Vecteur3D force)
{
	this->forceAccum = force;
}

Vecteur3D RigidBody::getTorqueAccum()
{
	return this->torqueAccum;
}

void RigidBody::setTorqueAccum(Vecteur3D torque)
{
	this->torqueAccum = torque;
}	

Quaternion RigidBody::getOrientation()
{
	return this->orientation;
}

void RigidBody::setOrientation(Quaternion q)
{
	this->orientation = q;
}

Vecteur3D RigidBody::getRotation()
{
	return this->rotation;
}

void RigidBody::setRotation(Vecteur3D rot)
{
	this->rotation = rot;
}

Matrix34 RigidBody::getTransformMatrix()
{
	return this->transformMatrix;
}

void RigidBody::setTransformMatrix(Matrix34 matrix)
{
	this->transformMatrix = matrix;
}

void RigidBody::integrate(double duration)
{

}

void RigidBody::addForce(const Vecteur3D& force)
{
	this->setForceAccum(this->getForceAccum() + force);
}

void RigidBody::calculateDerivedData()
{

}

