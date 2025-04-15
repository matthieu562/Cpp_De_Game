#include "circle.hpp"

std::random_device rd;
std::mt19937 gen(rd());

static constexpr float TARGET_ANGULAR_ACCELERATION = 30.f;  // Accélération angulaire souhaitée (en rad/s²)
static constexpr float TARGET_ACCELERATION = 100.f;  // Accélération souhaitée (en m/s²)

static constexpr float MAX_ACCELERATION_BOT = 10.0f;  // Valeur de l'accélération maximale pour le bot
static constexpr float MAX_ANGULAR_SPEED_BOT = 10.0f;  // Vitesse angulaire maximale pour le bot
static constexpr float MAX_SPEED_BOT = 20.0f;  // Vitesse maximale du bot
static constexpr float M_PI = 3.14159265358979323846;

int Circle::m_circleID = 0;

Circle::Circle(b2World& world, float radius)
    : Circle(world, radius, sf::Vector2f(
        std::uniform_int_distribution<>(1, WINDOW_WIDTH - 1)(gen),
        std::uniform_int_distribution<>(1, WINDOW_HEIGHT - 1)(gen)
    )) {
}

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

    m_mass = m_body->GetMass();
    m_inertiaMoment = m_body->GetInertia();

    m_circle.setRadius(radius);
    m_circle.setFillColor(sf::Color::Green);
    m_circle.setOrigin(radius, radius);

    m_instanceID = m_circleID++;
}

/**
 * @brief Applies control inputs to the circle.
 */
void Circle::applyControl() {
    b2Vec2 direction;
    b2Vec2 force;
    float torque;
    b2Vec2 velocity;

    torque = TARGET_ANGULAR_ACCELERATION * m_inertiaMoment;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        m_body->ApplyTorque(torque, true);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        m_body->ApplyTorque(-torque, true);

    //// Apply rotation, depends on mass
    //if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    //    m_body->ApplyTorque(m_torque, true);
    //if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    //    m_body->ApplyTorque(-m_torque, true);

    //// Apply acceleration, depends on mass
    m_angle = m_body->GetAngle();
    direction = { cos(m_angle), sin(m_angle) };
    //force = m_magnitude * direction;
    //if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    //    m_body->ApplyForceToCenter(force, true);;
    //if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    //    m_body->ApplyForceToCenter(-force, true);;


    velocity = m_body->GetLinearVelocity();
    force = TARGET_ACCELERATION * m_mass * direction;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        m_body->ApplyForceToCenter(force, true);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        m_body->ApplyForceToCenter(-force, true);
    }

}

void Circle::applyControl(std::bitset<4> directions) { // bool goUp, bool goDown, bool goRight, bool goLeft
    b2Vec2 orientation;
    b2Vec2 force;
    float torque;
    b2Vec2 velocity;
    enum Direction { Up = 0, Down, Right, Left };

    torque = TARGET_ANGULAR_ACCELERATION * m_inertiaMoment;
    if(directions[Right])
        m_body->ApplyTorque(torque, true);
    if(directions[Left])
        m_body->ApplyTorque(-torque, true);

    m_angle = m_body->GetAngle();
    orientation = { cos(m_angle), sin(m_angle) };
    velocity = m_body->GetLinearVelocity();
    force = TARGET_ACCELERATION * m_mass * orientation;
    if(directions[Up]) {
        m_body->ApplyForceToCenter(force, true);
    }
    if(directions[Down]) {
        m_body->ApplyForceToCenter(-force, true);
    }

}

//std::bitset<4> Circle::botControl(sf::RenderWindow& window) {
//    std::bitset<4> directions;
//    enum Direction { Up = 0, Down, Right, Left };
//
//    // Vecteur vers la cible en pixels
//    sf::Vector2f posPixels = m_circle.getPosition();
//    sf::Vector2i mousePosPixels = sf::Mouse::getPosition(window);
//    sf::Vector2f delta = sf::Vector2f(mousePosPixels) - posPixels;
//
//    float angleToTarget = std::atan2(delta.y, delta.x);
//    float currentAngle = m_body->GetAngle();
//
//    float angleDiff = angleToTarget - currentAngle;
//
//    // Normaliser l'angle entre -pi et pi
//    while(angleDiff > 3.14159265f) angleDiff -= 2 * 3.14159265f;
//    while(angleDiff < -3.14159265f) angleDiff += 2 * 3.14159265f;
//
//    // Décide de tourner à droite ou à gauche
//    if(angleDiff > 0.1f)
//        directions[Right] = true;
//    else if(angleDiff < -0.1f)
//        directions[Left] = true;
//
//    // Si on est presque aligné, avancer
//    if(std::abs(angleDiff) < 0.3f)
//        directions[Up] = true;
//
//    return directions;
//}

inline float degToRad(float deg) {
    return deg * M_PI / 180.0f;
}

std::bitset<4> Circle::botControl(sf::RenderWindow& window) {
    // Pas du tout optimisé, juste une traduction bete et mechante de mon code python
    std::bitset<4> directions;
    enum Direction { Up = 0, Down, Right, Left };

    // Position du bot (cercle)
    b2Vec2 pos = m_body->GetPosition();
    sf::Vector2f botPos(pos.x * SCALE, pos.y * SCALE);

    // Position cible (souris)
    sf::Vector2i mousePosPixels = sf::Mouse::getPosition(window);
    sf::Vector2f targetPos = window.mapPixelToCoords(mousePosPixels);

    // Vecteur direction vers la cible
    sf::Vector2f delta = targetPos - botPos;

    // Angle vers la cible
    float targetAngle = std::atan2(delta.y, delta.x);
    float currentAngle = m_body->GetAngle();
    float angleDiff = targetAngle - currentAngle;

    while(angleDiff > M_PI) angleDiff -= 2 * M_PI;
    while(angleDiff < -M_PI) angleDiff += 2 * M_PI;

    float speed = m_body->GetLinearVelocity().Length();
    float acceleration = MAX_ACCELERATION_BOT;
    float movingAngle = 0;

    float threshold = -180.0f / MAX_ANGULAR_SPEED_BOT / 2.0f;

    if(speed > threshold) {
        if(std::abs(angleDiff) > degToRad(MAX_ANGULAR_SPEED_BOT)) {
            int nbRotationBefore90 = std::floor((std::abs(angleDiff) - M_PI / 2.0f) / degToRad(MAX_ANGULAR_SPEED_BOT));
            if(nbRotationBefore90 > 1 && speed > MAX_SPEED_BOT - nbRotationBefore90) {
                acceleration = -MAX_ACCELERATION_BOT / 2.0f;
            }
            else if(nbRotationBefore90 == 1 && speed > MAX_SPEED_BOT - nbRotationBefore90) {
                acceleration = 0;
            }
            movingAngle = degToRad(MAX_ANGULAR_SPEED_BOT) * std::copysign(1.0f, angleDiff);
        }
        else if(std::abs(angleDiff) > 0) {
            movingAngle = angleDiff;
        }
    }
    else {
        float deltaToPi = std::abs(M_PI - std::abs(angleDiff));
        if(deltaToPi > degToRad(MAX_ANGULAR_SPEED_BOT)) {
            movingAngle = -degToRad(MAX_ANGULAR_SPEED_BOT) * std::copysign(1.0f, angleDiff);
        }
        else if(deltaToPi > 0) {
            movingAngle = -deltaToPi * std::copysign(1.0f, angleDiff);
        }
    }

    // Convertit le mouvement en directions
    if(std::abs(2 * movingAngle) > 0.01f) {
        directions[Right] = (2 * movingAngle > 0);
        directions[Left] = (2 * movingAngle < 0);
    }

    if(acceleration > 0.01f) directions[Up] = true;
    else if(acceleration < -0.01f) directions[Down] = true;

    return directions;
}

/**
 * @brief Updates the list of visible circles using raycasting.
 * @param world The Box2D world.
 * @param allCircles The list of all circles in the world.
 */
void Circle::updateVision(b2World& world, const std::vector<Circle*>& allCircles) {
    m_visibleCircles.clear();
    b2Vec2 pos = m_body->GetPosition();

    for(Circle* other : allCircles) {
        if(other == this) continue;

        b2Vec2 otherPos = other->m_body->GetPosition();
        b2RayCastInput input;
        input.p1 = pos;
        input.p2 = otherPos;
        input.maxFraction = 1.0f;

        b2RayCastOutput output;
        for(b2Body* b = world.GetBodyList(); b; b = b->GetNext()) {
            for(b2Fixture* f = b->GetFixtureList(); f; f = f->GetNext()) {
                if(!f->RayCast(&output, input, 0)) continue;
                if(output.fraction < input.maxFraction) {
                    input.maxFraction = output.fraction;
                }
            }
        }

        if(input.maxFraction == 1.0f) {
            m_visibleCircles.push_back(other);
        }
    }
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
