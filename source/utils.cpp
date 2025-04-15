#include "utils.hpp"

sf::Vector2f Utils::polarToCartesian(float radius, float angleRad) {
    return sf::Vector2f(radius * std::cos(angleRad), radius * std::sin(angleRad));
}


std::pair<float, float> Utils::cartesianToPolar(const sf::Vector2f& vec) {
    float radius = std::sqrt(vec.x * vec.x + vec.y * vec.y);
    float angleRad = std::atan2(vec.y, vec.x);
    return { radius, angleRad };
}

float Utils::deg2Rad(float degrees) {
    return degrees * 3.14159265f / 180.f;
}

float Utils::rad2Deg(float radians) {
    return radians * 180.f / 3.14159265f;
}
