#include <cstdlib>
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    // Fenêtre de rendu
    RenderWindow app(VideoMode(600, 600, 32), "Mon superbe polygone SFML !");

    Shape carre;
    carre.AddPoint(200, 200, Color(255, 255, 0), Color(255,255,255));
    carre.AddPoint(400, 200, Color(255, 255, 0), Color(255,0,0));
    carre.AddPoint(400, 400, Color(0, 255, 255), Color(0,255,0));
    carre.AddPoint(200, 400, Color(0, 255, 255), Color(0,0,255));
    carre.EnableFill(true); // Remplissage activé
    carre.EnableOutline(true); // Bordures activées
    carre.SetOutlineWidth(20); // Bordures de taille 20 pixels

    // Boucle principale
    while (app.IsOpened())
    {
        Event event;
        while (app.GetEvent(event))
        {
            // Fenêtre fermée : on quitte
            if (event.Type == Event::Closed)
                app.Close();
        }

        // Efface l'écran (remplissage avec du noir)
        app.Clear();

        // Affichage de notre carre dans la fenêtre
        app.Draw(carre);

        // Affichage du contenu de la fenêtre à l'écran
        app.Display();

    }

    return EXIT_SUCCESS;
}
