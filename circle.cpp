#include "circle.hpp"

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
    fixtureDef.density = 0.5f;
    fixtureDef.friction = 0.3f;
    m_body->CreateFixture(&fixtureDef);

    m_circle.setRadius(radius);
    m_circle.setFillColor(sf::Color::Green);
    m_circle.setOrigin(radius, radius);
}

void Circle::applyControl() {
    b2Vec2 velocity = m_body->GetLinearVelocity();
    float speed = 10.f;

    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        velocity.x = -speed;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        velocity.x = speed;
    else
        velocity.x = 0.f;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        velocity.y = -speed;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        velocity.y = speed;
    else
        velocity.y = 0.f;
    /*
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        m_body->ApplyAngularImpulse(10, true);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        m_body->ApplyAngularImpulse(-10, true);

    //else
    //    m_body->ApplyTorque(0, true);

    b2Vec2 impulse(10 * cos(m_body->GetAngle()), 10 * sin(m_body->GetAngle()));
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        m_body->ApplyLinearImpulseToCenter(impulse, true);;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        m_body->ApplyLinearImpulseToCenter(impulse, true);;
    //else
    //    velocity.y = 0.f;
    */
    m_body->SetLinearVelocity(velocity);
}

void Circle::draw(sf::RenderWindow& window)
{
    b2Vec2 pos = m_body->GetPosition();
    m_circle.setPosition(pos.x * SCALE, pos.y * SCALE);
    window.draw(m_circle);
    drawDirectionLine(window); // Tracer la ligne de direction
}

void Circle::drawDirectionLine(sf::RenderWindow& window) {
    b2Vec2 velocity = m_body->GetLinearVelocity();
    if(velocity.Length() > 0.01f) { // Ne tracer la ligne que si la vitesse est significative
        sf::Vertex line[] = {
            sf::Vertex(m_circle.getPosition(), sf::Color::Red),
            sf::Vertex(m_circle.getPosition() + sf::Vector2f(velocity.x * SCALE, velocity.y * SCALE), sf::Color::Red)
        };
        window.draw(line, 2, sf::Lines);
    }
}