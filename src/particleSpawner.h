#ifndef PARTICLE_SPAWNER_H
#define PARTICLE_SPAWNER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

#include "particles.h"
#include "random.h"

class pSpawner{
public:
    pSpawner(const sf::Vector2f& pos, sf::RenderWindow& window);
    ~pSpawner();

    void particlesInit(const float& radius, const sf::Color& color, const float& speed, const float& lifetime, const bool& shrink, const bool& loop);
    void setParticleAmount(const unsigned int& amount = 10);

    void update(const double& deltaT);
    void render();
    
private:
    bool _looping{false};
    bool _allDead{true};

    sf::RenderWindow* _window{nullptr};

    sf::CircleShape _visualizer;

    sf::Vector2f _pos{0, 0};

    std::vector<Particle*> particles{};
};

#endif