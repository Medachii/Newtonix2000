#pragma once

#include "Vecteur3D.h"
#include "Particule.h"

class Integrateur
{
	public:
		Integrateur();
		~Integrateur();
		void integrer(Particule* p);
};

