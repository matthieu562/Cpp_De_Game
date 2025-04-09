#include "wall.hpp"


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

void Wall::draw(sf::RenderWindow& window) const {
    window.draw(m_wall);
}