//Haobin Zhang & Lirong Liang
#ifndef BOOM_H
#define BOOM_H
#include "Game.h"
#include "Particle.h"
#include "CircleParticle.h"
#include "ParticleEffect.h"

using namespace sf;
using namespace gm;

class Boom : public ParticleEffect
{
public:
	Boom(const Vector2f positionPE, int timePE, int number);
	virtual void AddParticle(int index);
	~Boom();
};

#endif