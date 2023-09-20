#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cstdio>
#include <iostream>

#include <string>

#include "particleSpawner.h"

int main(void){
    sf::RenderWindow window(sf::VideoMode(500, 500), "Particle Simulator");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/noto/NotoSansMono-Regular.ttf")){
        std::cerr << "FAILED TO LOAD FONT\n";
    }

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Red);

    pSpawner* spawner = new pSpawner(sf::Vector2f(300, 500), window);

    sf::Clock clock;
    float deltaT;

    spawner->setParticleAmount(500);
    spawner->particlesInit(5, sf::Color::Blue, 10, 20, true, true);

    while(window.isOpen()){
        sf::Event e;
        while(window.pollEvent(e)){
            if (e.type == sf::Event::Closed)
                window.close();
        }

        sf::Time time = clock.getElapsedTime();
        
        text.setString(std::to_string(1.0 / time.asSeconds()));

        deltaT = clock.restart().asSeconds();

        window.clear();

        spawner->update(deltaT);

        window.draw(text);

        //spawner->render();

        window.display();
    }

    return 0;
}