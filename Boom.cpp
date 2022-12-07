//Haobin Zhang & Lirong Liang
using namespace std;
#include <iostream>
#include "ParticleEffect.h"
#include "Boom.h"
#include <cstdlib>
#include "Particle.h"

using namespace sf;
using namespace gm;

Boom::Boom(const Vector2f positionPE, int timePE, int number) : ParticleEffect(positionPE, timePE, number) {

}

void Boom::AddParticle(int index) {
	Color colors[6] = { Color::White, Color::Green, Color::Red, Color::Yellow, Color::Blue, Color::Cyan};
	float randomA = random(50, 300);
	float randomB = random(3000, 5000);
	float randomC = random(-150, 150);
	float randomD = random(-150, 150);
	Color color = colors[random(0, 5)];
	CircleParticle* shape = new CircleParticle(Vector2f(float(peposition.x) + random(-15, 15), float(peposition.y) + random(-15, 15)), randomA / 10, color, randomB / 10, randomC / 10, randomD / 10);
	objects[index] = shape;
}

Boom::~Boom() {
	for (int i = 0; i < numberObjects; i++) {
		if (objects[i] != nullptr) {
			delete objects[i];
		}
	}
}


