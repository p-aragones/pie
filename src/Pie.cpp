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
    _font.loadFromFile("./assets/font.ttf");

    _circle.setOutlineColor(sf::Color::White);
    _circle.setFillColor(sf::Color::Black);
    _circle.setOutlineThickness(1);
    _circle.setRadius(400);

    _rect.setOutlineColor(sf::Color::White);
    _rect.setFillColor(sf::Color::Black);
    _rect.setOutlineThickness(1);
    _rect.setSize({800, 800});

    _pieText.setPosition({0, 850});
    _pieText.setFont(_font);
    _pieText.setCharacterSize(30);
    _pieText.setFillColor(sf::Color::White);

    _inside = 0;
    _total = 0;
    _pie = 0;
}

Pie::~Pie()
{
}

void Pie::initWindow()
{
    _window.create(sf::VideoMode(800, 850), "PIE");
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

    _pie = 4 * ((double) _inside / (double) _total);

    std::cout << std::to_string(_pie) << std::endl;

    _pieText.setString(std::to_string(_pie));
    _window.draw(point);
    _window.draw(_pieText);
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