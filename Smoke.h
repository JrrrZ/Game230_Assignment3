//Haobin Zhang & Lirong Liang
#ifndef SMOKE_H
#define SMOKE_H
#include "Game.h"
#include "Particle.h"
#include "CircleParticle.h"
#include "ParticleEffect.h"

using namespace sf;
using namespace gm;

class Smoke : public ParticleEffect
{
private:
	float axV = 0;
	float ayV = 0;
public:
	Smoke(const Vector2f positionPE, int timePE, int number);
	virtual void update(RenderWindow& window);
	virtual void AddParticle(int index);
	~Smoke();
};

#endif
