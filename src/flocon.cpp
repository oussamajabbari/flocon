/*
 * flocon.cpp
 *
 *  Created on: Feb 20, 2013
 *      Author: ousjab01
 */

#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>

namespace {
    const int width = 800;
    const int height = 600;
}

using namespace sf;
using namespace std;

/**
 * This program aims to draw "fougere" fractal.
 * With symmetric mode it will be a flocon.
 * @see http://villemin.gerard.free.fr/Wwwgvmm/Suite/FracPrat.htm
 * @return
 */
int main()
{
    // Fenetre de rendu
    RenderWindow app(VideoMode(width, height, 32),
            "Mon superbe polygone SFML !");

    // Activate vertical synchronization in order to have
    // 60 frame/second
    app.UseVerticalSync(true);

    // Background
    sf::Image backgroundImage(width, height, sf::Color(0, 0, 0));
    sf::Sprite       background(backgroundImage);
    sf::Uint8 *backgroundPixels = new sf::Uint8[width * height * 4];

    // One dot (finally not used)
    sf::Image dotImage(5, 5, sf::Color(255, 0, 0));
    sf::Sprite dot(dotImage);

    // Dot position
    sf::Vector2f dotPosition(100, 100);
    dot.SetPosition(dotPosition);
    

    // Fill the background with white
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            backgroundPixels[4 * (y * width + x)] = 255;       // R
            backgroundPixels[4 * (y * width + x) + 1] = 255;   // G
            backgroundPixels[4 * (y * width + x) + 2] = 255;   // B
            backgroundPixels[4 * (y * width + x) + 3] = 255;   // A
        }
    }

    // Add a red line in the background
    for (int i = 0; i < width; i++)
    {
    	// Put the G and B off
        backgroundPixels[4 * ((500+(i/8)) * width + i) + 1] = 0;
        backgroundPixels[4 * ((500+(i/8)) * width + i) + 2] = 0;
    }

    // Add a red line in the background
    for (int i = 0; i < width; i++)
    {
    	// Put the G and B off
        backgroundPixels[4 * ((600-(i/8)) * width + i) + 1] = 0;
        backgroundPixels[4 * ((600-(i/8)) * width + i) + 2] = 0;
    }

    //-------------------------------------------------------------
    //  Pixels generation
    //-------------------------------------------------------------

    for (int i = 0; i < 50000; i++)
    {
		// Choose a random X starting point
		sf::Uint32 XDot = rand() % width;
		sf::Uint32 YDot = 0;

		bool finished = false;
		// iterate until the dot touch another dot
		while (!finished)
		{

			// See if we dot touches another dot
			// or if we go below the screen
			if ( !backgroundPixels[4 * ( (YDot+1) * width + (XDot-1)) + 1] ||
				 !backgroundPixels[4 * ( (YDot+1) * width + (XDot  )) + 1] ||
				 !backgroundPixels[4 * ( (YDot+1) * width + (XDot+1)) + 1] ||
				 (YDot >= height)
			   )
			{
				finished = true;
			}
			else // go one step down
			{
				YDot++;

				// X = X + 1 or X = X - 1
				if (rand() % 2)
					XDot = XDot + 1;
				else
					XDot = XDot - 1;
			}

		}
		// If we touched another dot then draw it
		if (YDot < height)
		{
			backgroundPixels[4 * (YDot * width + XDot) + 1] = 0;
			backgroundPixels[4 * (YDot * width + XDot) + 2] = 0;

		}
    }

    //-------------------------------------------------------------

    // Copy the pixel tab to the background image
    backgroundImage.LoadFromPixels(width, height, backgroundPixels);

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

        // Get frame rate
        float Framerate = 1.f / app.GetFrameTime();
        //cout << "Framerate : " << Framerate << endl;

        // Efface l'ecran (remplissage avec du noir)
        app.Clear();

        // Affichage de notre point dans la fenetre
        app.Draw(background);
        //app.Draw(dot);

        // Affichage du contenu de la fenetre e l'ecran
        app.Display();

    }

    return EXIT_SUCCESS;
}

