//Haobin Zhang & Lirong Liang
// Include our header so that we can define our method declarations made there
#include "Particle.h"

// For using random functionality
#include <cstdlib>
using namespace std;
#include <iostream>

// It's fine to use namespaces in .cpp files, just not .h files (will pollute your namespace otherwise)
using namespace sf;
using namespace gm;

// Our default constructor
// Makes a white circle shape on the heap with no specified position or size
Particle::Particle() {
	lifespan = 200;
	velocityX = 10.0f;
	velocityY = 10.0f;
	//cout << "default" << velocityX << " " << velocityY << " " << lifespan << endl;
}

// Our overloaded constructor
// Makes a white circle shape on the heap with a specified position and size
Particle::Particle(const Vector2f& position, Color color, float time, float vX, float vY) {
	lifespan = time;
	velocityX = vX;
	velocityY = vY;
	//cout << velocityX << " " << velocityY << " " << lifespan << endl;
}

// Virtual function
void Particle::update(RenderWindow& window) {

}

// Virtual function
void Particle::render(RenderWindow& window) {

}

// Getters 
// Gets the game object's position (which is stored in shape)
// Return by reference so that the returned object isn't returned by value/copied (which wastes space and time)
// Also return by const so that anyone who calls this function can't modify the referenced position within the class
// NOTE: Mark this function const since it should never modify anything in the class itself when called (i.e., it's a getter)
const Vector2f& Particle::getPosition() const {
	return Vector2f(0, 0);
}

//
Vector2f Particle::getVelocity() {
	return Vector2f(velocityX, velocityY);
}

//
float Particle::getLifespan() {
	return lifespan;
}

boolean Particle::isAlive() {
	if (lifespan <= 0) {
		return false;
	}
}
// Setters
// Sets the game object's position (which is stored in shape)
void Particle::setPosition(const Vector2f& position) {

}

void Particle::setVelocity(float vX, float vY) {
	velocityX = vX;
	velocityY = vY;
}

void Particle::setLifespan(float time) {
	lifespan = time;
}

// Destructor
// We put the shape on the heap in the constructor, make sure we free it here now that we are done with it!
Particle::~Particle() {

}