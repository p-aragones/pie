/*
** EPITECH PROJECT, 2022
** pie
** File description:
** Pie
*/

#ifndef PIE_HPP_
#define PIE_HPP_

#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>

class Pie {
    public:
        Pie();
        ~Pie();
        
        void initWindow();
        void draw();
        void insertPoint();
        int handleEvents();
        bool isOpen();
        int run();

    protected:
    private:
        int _inside;
        int _total;
        double _pie;
        double _best;

        sf::RenderWindow _window;
        sf::RectangleShape _rect;
        sf::CircleShape _circle;
};

#endif /* !PIE_HPP_ */
