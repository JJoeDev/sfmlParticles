#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>

class Particle {
public:
    Particle();
    ~Particle();

    inline void setLooping(const bool& loop) { _loop = loop; }
    inline void setShrinking(const bool& shrink) { _shrink = shrink; }
    inline void setRadius(const float& radius) { _radius = radius; _initRad = radius; _pUpdate(); }
    inline void setLifetime(const float& lifetime) { _lifetime = lifetime; _initLife = lifetime; _pUpdate(); }
    inline void setSpeed(const float& speed) { _speed = speed; }
    inline void setColor(const sf::Color& color) { _color = color; _pUpdate(); }
    inline void setVelocity(const sf::Vector2f& velocity) { _velocity = velocity; _normalize(_velocity); }
    inline void setPos(const sf::Vector2f& pos) { _pos = pos; _initPos = pos; }

    inline bool& getIsAlive() { return _alive; }

    void update(const double& deltaT);
    void render(sf::RenderWindow& window);

private:
    inline void _pUpdate() {
        _shape.setRadius(_radius);
        _shape.setFillColor(_color);
        _shape.setPosition(_pos);
    }

    inline void _normalize(sf::Vector2f& vec){
        float len = std::sqrt((vec.x * vec.x) + (vec.y * vec.y));
        if (len != 0)
            vec = sf::Vector2f(vec.x / len, vec.y / len);
    }

    bool _alive{true};
    bool _shrink{false};
    bool _loop{false};

    float _initRad{0};
    float _initLife{0};

    float _radius{0};
    float _lifetime{0};

    float _speed{0};

    sf::CircleShape _shape;

    sf::Vector2f _initPos{0, 0};
    sf::Vector2f _pos{0, 0};

    sf::Vector2f _velocity{0, 0};
    sf::Color _color{sf::Color::Green};
};

#endif