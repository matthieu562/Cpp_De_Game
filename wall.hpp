#pragma once

#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include "constants.hpp"

/**
 * @class Wall
 * @brief Represents a wall in a Box2D world with SFML rendering.
 */
class Wall
{
private:
	b2Body* m_body;
	sf::RectangleShape m_wall;

public:
    /**
     * @brief Constructs a Wall object.
     * @param world The Box2D world in which the wall exists.
     * @param pos_x The x position of the wall.
     * @param pos_y The y position of the wall.
     * @param len_x The length of the wall along the x-axis.
     * @param len_y The length of the wall along the y-axis.
     */
	Wall(b2World& world, float pos_x, float pos_y, float len_x, float len_y);

    /**
     * @brief Draws the wall in the SFML render window.
     * @param window The SFML render window.
     */
    void draw(sf::RenderWindow& window) const;

};