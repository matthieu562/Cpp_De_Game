#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

#include "constants.hpp"
#include "utils.hpp"

/**
 * @class Circle
 * @brief Represents a circle in a Box2D world with SFML rendering.
 */
class Circle {
private:
    float m_torque{ 8000.f };
    float m_angle{ 0 };
    float m_magnitude{ 60000.f };
    float m_radius;
    b2Body* m_body;
    sf::CircleShape m_circle;

    /**
     * @brief Draws the direction line of the circle.
     * @param window The SFML render window.
     */
    void drawDirectionLine(sf::RenderWindow& window); // Déclaration de la méthode

public:
    /**
     * @brief Constructs a Circle object.
     * @param world The Box2D world in which the circle exists.
     * @param radius The radius of the circle.
     * @param positionPixels The initial position of the circle in pixels.
     */
    Circle(b2World& world, float radius, sf::Vector2f positionPixels);

    /**
     * @brief Applies control inputs to the circle.
     */
    void applyControl();

    /**
     * @brief Draws the circle in the SFML render window.
     * @param window The SFML render window.
     */
    void draw(sf::RenderWindow& window);

};

