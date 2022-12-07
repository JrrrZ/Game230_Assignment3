//Haobin Zhang & Lirong Liang
// Include our header so that we can define our method declarations made there
#include "CircleParticle.h"

// For using random functionality
#include <cstdlib>
using namespace std;
#include <iostream>

// It's fine to use namespaces in .cpp files, just not .h files (will pollute your namespace otherwise)
using namespace sf;
using namespace gm;


// Our default constructor
// Makes a white circle shape on the heap with no specified position or size
CircleParticle::CircleParticle() : Particle() {
	shape = new CircleShape();
	shape->setFillColor(Color::White);
	radius = 0;
}

// Our overloaded constructor
// Makes a white circle shape on the heap with a specified position and size
CircleParticle::CircleParticle(const Vector2f& position, float size, Color color, float time, float vX, float vY) : Particle(position, color, time, vX, vY) {
	shape = new CircleShape(size);
	shape->setPosition(position);
	shape->setFillColor(color);
	radius = size;
	
}

// Virtual function
void CircleParticle::update(RenderWindow& window) {
	// Calculate the random movement amound in x and y directions
	//int velocityX =  + randomSpeedX;
	//int velocityY = BaseMovementAmount + randomSpeedY;

	// Set the game object's new position with this random movement offset
	setPosition(Vector2f(getPosition().x + getVelocity().x, getPosition().y +getVelocity().y));
	setLifespan(getLifespan()-1);
	//lifespan -= clock.getElapsedTime().asSeconds();
	//clock.restart();
	if (isAlive() == false) {
		shape->setFillColor(Color::Transparent);
	}
}

// Virtual function
void CircleParticle::render(RenderWindow& window) {
	window.draw(*shape);
}

// Getters
// Return by reference so that the returned object isn't returned by value/copied (which wastes space and time)
// Also return by const so that anyone who calls this function can't modify the referenced position within the class
// NOTE: Mark this function const since it should never modify anything in the class itself when called (i.e., it's a getter)
float CircleParticle::getSize() {
	radius = shape->getRadius();
	return radius;
}

const Vector2f& CircleParticle::getPosition() const {
	return shape->getPosition();
}

// Setters
void CircleParticle::setSize(float size) {
	radius = size;
}

void CircleParticle::setPosition(const Vector2f& position) {
	shape->setPosition(position);
}

// Destructor
// We put the shape on the heap in the constructor, make sure we free it here now that we are done with it!
CircleParticle::~CircleParticle() {
	delete shape;
}