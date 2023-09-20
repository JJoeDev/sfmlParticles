#ifndef RANDOM_H
#define RANDOM_H

#include <SFML/System/Vector2.hpp>
#include <random>

inline sf::Vector2f randVec2(const float& minX, const float& minY, const float& maxX, const float& maxY){
    sf::Vector2f vec;

    std::random_device rd;
    std::mt19937 mt(rd());

    std::uniform_real_distribution<float> xDist(minX, maxX);
    std::uniform_real_distribution<float> yDist(minY, maxY);

    vec.x = xDist(mt);
    vec.y = yDist(mt);

    return vec;
}

inline float randF(const float& min, const float& max){
    std::random_device rd;
    std::mt19937 mt(rd());

    std::uniform_real_distribution<float> dist(min, max);

    return dist(mt);
}

#endif