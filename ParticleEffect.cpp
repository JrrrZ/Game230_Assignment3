//Haobin Zhang & Lirong Liang
using namespace std;
#include <iostream>
#include "ParticleEffect.h"
#include "Particle.h"

#include "CircleParticle.h"
#include <cstdlib>

using namespace sf;
using namespace gm;

ParticleEffect::ParticleEffect(const Vector2f positionPE, int timePE, int number) {
	peposition = positionPE;
	pelifespan = timePE;
	numberObjects = number;
	srand(time(NULL));
}

void ParticleEffect::update(RenderWindow& window) {
	for (int i = 0; i < numberObjects; i++) {
		objects[i]->update(window);
	}
	pelifespan--;
}

void ParticleEffect::render(RenderWindow& window) {
	for (int i = 0; i < numberObjects; i++) {
		objects[i]->render(window);
	}
}

void ParticleEffect::Emit() {
	AddParticles();
	for (int i = 0; i < numberObjects; i++) {
		AddParticle(i);
		//cout << "hello" << endl;
	}
}

void ParticleEffect::AddParticles() {
	objects = new Particle * [numberObjects];
}

void ParticleEffect::AddParticle(int index) {

}

ParticleEffect::~ParticleEffect() {
	for (int i = 0; i < numberObjects; i++) {
		if (objects[i] != nullptr) {
			delete objects[i];
		}	
	}
}

int ParticleEffect::random(int minNum, int maxNum) {
	return minNum + rand() % (maxNum - minNum + 1);
}

