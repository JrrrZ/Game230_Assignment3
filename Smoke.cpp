//Haobin Zhang & Lirong Liang
#include "Smoke.h"
using namespace std;
#include <iostream>
#include "ParticleEffect.h"
#include <cstdlib>
#include "Particle.h"


using namespace sf;
using namespace gm;

Smoke::Smoke(const Vector2f positionPE, int timePE, int number) : ParticleEffect(positionPE, timePE, number) {

}

void Smoke::update(RenderWindow& window) {
	ParticleEffect::update(window);
	//axV = axV + 0.01;
	for (int i = 0; i < numberObjects; i++) {
		Vector2f currVelocity = objects[i]->getVelocity();
		objects[i]->setVelocity(currVelocity.x + random(-5, 5) / 1000.0, (currVelocity.y + random(-8, -3) / 10000.0));
	}
}

void Smoke::AddParticle(int index) {
	Color colors[6] = { Color::White, Color::Green, Color::Red, Color::Yellow, Color::Blue, Color::Cyan };
	float randomA = random(20, 100);
	float randomB = random(12000, 24000);
	float randomC = axV + random(-1, 1);
	float randomD = ayV + random(-6, 0);
	Color color = colors[random(0, 5)];
	CircleParticle* shape = new CircleParticle(Vector2f(float(peposition.x) + random(-30, 30), float(peposition.y) + random(-30, 30)), randomA / 10, color, randomB / 10, randomC / 100, randomD / 10);
	objects[index] = shape;
}

Smoke::~Smoke() {
	for (int i = 0; i < numberObjects; i++) {
		if (objects[i] != nullptr) {
			delete objects[i];
		}
	}
}
