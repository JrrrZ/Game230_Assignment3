//Haobin Zhang & Lirong Liang
#ifndef CIRCLE_PARTICLE_H
#define CIRCLE_PARTICLE_H

/* SFML Includes             *
 * Add to every SFML project */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "Particle.h"


using namespace sf;

namespace gm {
	class CircleParticle : public Particle {
	private:
		// Our shape object that the class maintains
		CircleShape* shape;
		float radius;

	public:
		// Default constructor
		CircleParticle();
		// Overloaded constructor
		CircleParticle(const Vector2f& position, float size, Color color, float time, float vX, float vY);

		// Game loop programming pattern functions
		virtual void update(RenderWindow& window) override;

		virtual void render(RenderWindow& window) override;

		// Getter
		float getSize();

		virtual const Vector2f& getPosition() const override;

		// Setter
		void setSize(float size);

		virtual void setPosition(const Vector2f& position) override;

		// Destructor
		~CircleParticle();

	};
}

#endif
