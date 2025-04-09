#pragma once

#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include "constants.hpp"

class Wall
{
private:
	b2Body* m_body;

public:
	sf::RectangleShape m_wall; // Test
	Wall(b2World& world, float pos_x, float pos_y, float len_x, float len_y);

	void draw(sf::RenderWindow& window) const;

};