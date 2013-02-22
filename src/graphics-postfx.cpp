////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>


////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////
int main()
{
    // Check that the system can use post effects
    if (sf::PostFX::CanUsePostFX() == false)
        return EXIT_SUCCESS;

    // Create the main window
    sf::RenderWindow App(sf::VideoMode(800, 600), "SFML PostFX");

    // Load a cute background image to display :)
    sf::Image BackgroundImage;
    if (!BackgroundImage.LoadFromFile("mer.JPG"))
        return EXIT_FAILURE;
    sf::Sprite Background(BackgroundImage);

    // Load the effect
    sf::PostFX Effect;
    if (!Effect.LoadFromFile("colorize.sfx"))
        return EXIT_SUCCESS;

    // Setup the effect parameters
    Effect.SetTexture("framebuffer", NULL);
    Effect.SetParameter("color", 1.f, 1.f, 1.f);

    // Start the game loop
    while (App.IsOpened())
    {
        // Process events
        sf::Event Event;
        while (App.GetEvent(Event))
        {
            // Close window : exit
            if (Event.Type == sf::Event::Closed)
                App.Close();

            // Escape key : exit
            if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape))
                App.Close();
        }

        // Get the mouse position in the range [0, 1]
        float X = App.GetInput().GetMouseX() / static_cast<float>(App.GetWidth());
        float Y = App.GetInput().GetMouseY() / static_cast<float>(App.GetHeight());

        // Update the effect parameters
        Effect.SetParameter("color", 0.5f, X, Y);
 
        // Clear screen
        App.Clear();

        // Draw the background and apply the post-effect
        App.Draw(Background);
        App.Draw(Effect);

        // Finally, display the rendered frame on screen
        App.Display();
    }

    return EXIT_SUCCESS;
}
