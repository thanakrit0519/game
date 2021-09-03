#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include "menu.h"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(720, 720), "JOSS");
    menu Menu(window.getSize().x, window.getSize().y);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
                 sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                 if (mousePos.x >= 28 && mousePos.x <= 283 && mousePos.y >= 458 && mousePos.y <= 533)
                 {
                      if( sf::Mouse::isButtonPressed(sf::Mouse::Left))
                      {
                       
                          cout<<"PLAY"<<endl;
                      }
                      Menu.mouseup(1); 
                 }
                 else
                 {
                     Menu.mousedown(1);
                 }
                 
             
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
                window.clear();
                Menu.draw(window);
                window.display();
            
        }
    }

    return 0;
}