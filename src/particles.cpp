#include "particles.h"
#include <iostream>

Particle::Particle(){
    _shape.setRadius(_radius);
    _shape.setPosition(_pos);
    _shape.setFillColor(_color);
}

Particle::~Particle(){
    std::cout << "DELETED\n";
}

void Particle::update(const double& deltaT){
    _lifetime -= 1 * deltaT;

    if (_lifetime <= 0){
        if (_loop){
            _pos = _initPos;
            _lifetime = _initLife;
            _radius = _initRad;
        }
        else{
            _alive = false;
            return;
        }
    }

    _pos.x += _velocity.x * _speed * deltaT;
    _pos.y += _velocity.y * _speed * deltaT;

    if (_shrink)
        _radius -= (_initRad / _initLife) * deltaT;

    _pUpdate();
}

void Particle::render(sf::RenderWindow& window){
    if (_alive)
        window.draw(_shape);
}