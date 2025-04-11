#include "circle.hpp"

/**
 * @brief Constructs a Circle object.
 * @param world The Box2D world in which the circle exists.
 * @param radius The radius of the circle.
 * @param positionPixels The initial position of the circle in pixels.
 */
Circle::Circle(b2World& world, float radius, sf::Vector2f positionPixels)
    : m_radius(radius)
{
    b2BodyDef bodyDef; 
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(positionPixels.x / SCALE, positionPixels.y / SCALE);
    m_body = world.CreateBody(&bodyDef);

    b2CircleShape shape;
    shape.m_radius = radius / SCALE;

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.density = 1000.f;
    fixtureDef.friction = 0.05f;
    m_body->CreateFixture(&fixtureDef);

    m_body->SetAngularDamping(5.f);
    m_body->SetLinearDamping(5.f);

    m_circle.setRadius(radius);
    m_circle.setFillColor(sf::Color::Green);
    m_circle.setOrigin(radius, radius);
}

/**
 * @brief Applies control inputs to the circle.
 */
void Circle::applyControl() {
    b2Vec2 direction;
    b2Vec2 force;

    // Apply rotation
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        m_body->ApplyTorque(m_torque, true);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        m_body->ApplyTorque(-m_torque, true);

    // Apply acceleration
    m_angle = m_body->GetAngle();
    direction = { cos(m_angle), sin(m_angle) };
    force = m_magnitude * direction;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        m_body->ApplyForceToCenter(force, true);;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        m_body->ApplyForceToCenter(-force, true);;
}

/**
 * @brief Draws the circle in the SFML render window.
 * @param window The SFML render window.
 */
void Circle::draw(sf::RenderWindow& window)
{
    b2Vec2 pos = m_body->GetPosition();
    m_circle.setPosition(pos.x * SCALE, pos.y * SCALE);
    window.draw(m_circle);
    drawDirectionLine(window);
}

/**
 * @brief Draws the direction line of the circle.
 * @param window The SFML render window.
 */
void Circle::drawDirectionLine(sf::RenderWindow& window) {
    float angle = m_body->GetAngle();
    float lineLength = m_radius * 1.2f;
    sf::Vector2f center = m_circle.getPosition();
    sf::Vector2f direction(cos(angle) * lineLength, sin(angle) * lineLength);

    sf::Vertex line[] = {
        sf::Vertex(center, sf::Color::Red),
        sf::Vertex(center + direction, sf::Color::Red)
    };
    window.draw(line, 2, sf::Lines);
}
