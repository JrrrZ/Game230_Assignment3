//Haobin Zhang & Lirong Liang
#ifndef PARTICLE_EFFECT_H
#define PARTICLE_EFFECT_H
#include "Game.h"
#include "Particle.h"
#include "CircleParticle.h"

using namespace sf;
using namespace gm;

class ParticleEffect
{
	protected:
		Particle** objects;
		Vector2f peposition;
		int pelifespan;
		int numberObjects;

	public:
		ParticleEffect(const Vector2f positionPE, int timePE, int number);
		virtual void update(RenderWindow& window);
		virtual void render(RenderWindow& window);
		virtual void Emit();
		virtual void AddParticles();
		virtual void AddParticle(int index);
		//void getPeposition();
		//boolean isAlive();
		~ParticleEffect();
		int random(int minNum, int maxNum);
};

#endif
