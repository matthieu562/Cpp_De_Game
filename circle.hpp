#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

#include "constants.hpp"
#include "utils.hpp"

class Circle {
private:
    float m_radius;
    b2Body* m_body;
    sf::CircleShape m_circle;
    float m_orientation{ 0.0f };

    void drawDirectionLine(sf::RenderWindow& window); // D�claration de la m�thode

public:
    Circle(b2World& world, float radius, sf::Vector2f positionPixels);

    void applyControl(); // � ajouter dans le public
    void draw(sf::RenderWindow& window);

};

