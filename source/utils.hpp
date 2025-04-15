#pragma once 

#include <SFML/Graphics.hpp>

class Utils
{
public:
    static sf::Vector2f polarToCartesian(float radius, float angleRad);
    static std::pair<float, float> cartesianToPolar(const sf::Vector2f& vec);
    static float deg2Rad(float degrees);
    static float rad2Deg(float radians);
};
