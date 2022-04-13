/*
** EPITECH PROJECT, 2022
** pie
** File description:
** Pie
*/

#include "Pie.hpp"

Pie::Pie()
{
    initWindow();
    srand(time(NULL));

    _circle.setOutlineColor(sf::Color::White);
    _circle.setFillColor(sf::Color::Black);
    _circle.setOutlineThickness(1);
    _circle.setRadius(400);

    _rect.setOutlineColor(sf::Color::White);
    _rect.setFillColor(sf::Color::Black);
    _rect.setOutlineThickness(1);
    _rect.setSize({800, 800});

    _inside = 0;
    _total = 0;
    _pie = 0;
    _best = 0;
}

Pie::~Pie()
{
}

void Pie::initWindow()
{
    _window.create(sf::VideoMode(800, 800), "PIE");
    _window.setFramerateLimit(144);
}

int Pie::handleEvents()
{
    sf::Event event;
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _window.close();
    }
    return (0);
}

void Pie::draw()
{
    _window.draw(_rect);
    _window.draw(_circle);
    _window.display();
}

void Pie::insertPoint()
{
    for (int i = 0; i < 10000; i++){ 

        float x = rand() % (800 - 0 + 1);
        float y = rand() % (800 - 0 + 1);

        sf::CircleShape point;
        point.setRadius(1);
        point.setPosition({x, y});

        if (pow(x - 400, 2) + pow(y - 400, 2) < 400 * 400) {
            _inside++;
            point.setFillColor(sf::Color::Green);
        } else {
            point.setFillColor(sf::Color::Blue);
        }
        _total++;
        
        _window.draw(point);
    }

    _pie = 4 * ((double) _inside / (double) _total);

    if (abs(_pie - M_PI) < abs(_best - M_PI)) {
        _best = _pie;
        std::cout << std::to_string(_pie) << std::endl;
    }
    _window.display();
}

bool Pie::isOpen()
{
    return (_window.isOpen());
}

int Pie::run()
{
    draw();
    while (isOpen()) {
        handleEvents();
        insertPoint();
    }
    return (0);
}