#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <random>
#include <bitset> // Gestion de bits
#include <cmath>

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
    float m_mass;
    float m_inertiaMoment;
    sf::CircleShape m_circle;
    std::vector<Circle*> m_visibleCircles; // List of other circles in the field of view
    static int m_circleID; // Static member to keep track of the ID across all 

    /**
     * @brief Draws the direction line of the circle.
     * @param window The SFML render window.
     */
    void drawDirectionLine(sf::RenderWindow& window);

public:
    int m_instanceID; // Unique ID for each Circle instance

    Circle(b2World& world, float radius);

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
    void applyControl(std::bitset<4> directions);

    std::bitset<4> botControl(sf::RenderWindow& window);

    /**
     * @brief Updates the list of visible circles using raycasting.
     * @param world The Box2D world.
     * @param allCircles The list of all circles in the world.
     */
    void updateVision(b2World& world, const std::vector<Circle*>& allCircles);

    /**
     * @brief Draws the circle in the SFML render window.
     * @param window The SFML render window.
     */
    void draw(sf::RenderWindow& window);

};

