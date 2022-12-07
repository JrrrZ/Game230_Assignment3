//Haobin Zhang & Lirong Liang
#ifndef PARTICLE_H
#define PARTICLE_H

/* SFML Includes             *
 * Add to every SFML project */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

using namespace sf;

namespace gm {
	class Particle {
	private:
		// Our shape object that the class maintains
		float lifespan;
		float velocityX;
		float velocityY;
	public:
		// Default constructor
		Particle();
		// Overloaded constructor
		Particle(const Vector2f& position, Color color, float time, float vX, float vY);
		
		// Game loop programming pattern functions
		virtual void update(RenderWindow& window);

		virtual void render(RenderWindow& window);

		// Getter
		virtual const Vector2f& getPosition() const;

		Vector2f getVelocity();

		float getLifespan();

		//float getLifespanRemaining();

		boolean isAlive();

		// Setters
		virtual void setPosition(const Vector2f& position);

		void setVelocity(float vX, float vY);

		void setLifespan(float time);

		//void setLifespanRemaining(float rtime);

		//void setAlive(bool alive);

		// Destructor
		~Particle();
	};
}

#endif