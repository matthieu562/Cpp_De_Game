#include "wall.hpp"

/**
 * @brief Constructs a Wall object.
 * @param world The Box2D world in which the wall exists.
 * @param pos_x The x position of the wall.
 * @param pos_y The y position of the wall.
 * @param len_x The length of the wall along the x-axis.
 * @param len_y The length of the wall along the y-axis.
 */
Wall::Wall(b2World& world, float pos_x, float pos_y, float len_x, float len_y)
{

    b2BodyDef bodyDef;
    bodyDef.position.Set(pos_x / SCALE, pos_y / SCALE);
    m_body = world.CreateBody(&bodyDef);

    b2PolygonShape box;
    box.SetAsBox(len_x / 2 / SCALE, len_y / 2 / SCALE);
    m_body->CreateFixture(&box, 0.f);

    m_wall.setSize(sf::Vector2f(len_x, len_y));
    m_wall.setFillColor(sf::Color::White);
    m_wall.setOrigin(len_x / 2, len_y / 2);
    m_wall.setPosition(pos_x, pos_y);
}

/**
 * @brief Draws the wall in the SFML render window.
 * @param window The SFML render window.
 */
void Wall::draw(sf::RenderWindow& window) const {
    window.draw(m_wall);
}