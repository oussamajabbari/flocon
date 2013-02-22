/*
 * flocon.cpp
 *
 *  Created on: Feb 20, 2013
 *      Author: ousjab01
 */

#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int main()
{
    // Fenetre de rendu
    RenderWindow app(VideoMode(600, 600, 32), "Mon superbe polygone SFML !");

    // Activate verticale synchronisation in order to have
    // 60 frame/second
    app.UseVerticalSync(true);

    sf::Image        image(800, 600, sf::Color(0, 0, 0));
    sf::Sprite       sprite;
    sf::Uint8        *pixels  = new sf::Uint8[800 * 600 * 4];

    sf::Image formeDuPoint(5, 5, sf::Color(255, 0, 0));
    sf::Sprite monPoint(formeDuPoint);


    sf::Vector2f position(100, 100);
    monPoint.SetPosition(position);

    for(int x = 0; x < 800; x++)
    {
        for(int y = 0; y < 600; y++)
        {
          pixels[4*(x * 600+y)]      = 255; // R?
          pixels[4*(x * 600+y)+1] = 255; // G?
          pixels[4*(x * 600+y)+2] = 255; // B?
          pixels[4*(x * 600+y)+3] = 255; // A?
        }
    }
    image.LoadFromPixels(800, 600, pixels);
    sprite.SetImage(image);


    // Boucle principale
    while (app.IsOpened())
    {
        Event event;
        while (app.GetEvent(event))
        {
            // Fenetre fermee : on quitte
            if (event.Type == Event::Closed)
                app.Close();
        }

        float Framerate = 1.f / app.GetFrameTime();

        cout << "Framerate : " << Framerate << endl;

        // Efface l'ecran (remplissage avec du noir)
        app.Clear();

        // Affichage de notre point dans la fenetre
        app.Draw(sprite);
        app.Draw(monPoint);

        // Affichage du contenu de la fenetre e l'ecran
        app.Display();

    }

    return EXIT_SUCCESS;
}

