#include "particleSpawner.h"
#include "particles.h"
#include "random.h"
#include <SFML/Graphics/RenderWindow.hpp>

#include <iostream>
#include <algorithm>

pSpawner::pSpawner(const sf::Vector2f& pos, sf::RenderWindow& window){
    _window = &window;

    _pos = pos;

    _visualizer.setRadius(5.0f);
    _visualizer.setFillColor(sf::Color::Green);
    _visualizer.setPosition(sf::Vector2f(_pos.x - _visualizer.getRadius(), _pos.y - _visualizer.getRadius()));

    setParticleAmount();
}

pSpawner::~pSpawner(){
    for (Particle* p : particles){
        delete p;
    }

    delete _window;
}

void pSpawner::particlesInit(const float& radius, const sf::Color& color, const float& speed, const float& lifetime, const bool& shrink, const bool& loop){
    _looping = loop;

    for (Particle* p : particles){
        p->setRadius(radius);
        p->setColor(color);
        p->setPos(_pos);
        p->setVelocity(randVec2(-10, -10, 10, 10));
        p->setSpeed(speed);
        p->setLifetime(randF(2, lifetime));
        p->setShrinking(shrink);
        p->setLooping(loop);
    }
}

void pSpawner::setParticleAmount(const unsigned int& amount){ // default = 10
    particles.resize(amount);

    for (unsigned int i = 0; i < amount; ++i) {
        if (particles[i] == nullptr)
            particles[i] = new Particle();
    }
}

void pSpawner::update(const double& deltaT){
    for (Particle* p : particles){

        p->update(deltaT);
        p->render(*_window);
    }

    if (!_looping && particles.size() >= 1){
        _allDead = std::all_of(particles.begin(), particles.end(), [](Particle* p){
            return !p->getIsAlive();;
        });

        if (_allDead){
            for (Particle* p : particles){
                delete p;
            }

            particles.clear();
        }
    }

}

void pSpawner::render(){
    _window->draw(_visualizer);
}