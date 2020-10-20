// sfml_test.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream> // inclut un entete/header appelé iostream

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Dice.hpp"
#include "Lib.hpp"
#include "Game.hpp"
#include "Interp.hpp"

using namespace std;
using namespace sf;

int main()
{
    cout << "Hello World!\n";
    sf::RenderWindow window(sf::VideoMode(1280, 720,32), "SFML works!");
    Font font;
    if (!font.loadFromFile("res/MAIAN.TTF")) {
        cout << "ERROR NO FONT" << endl;
        return 1;
    }
    Game g(&window);

    sf::Clock timer;
    sf::Text fpsCounter;

    fpsCounter.setFont(font);
    fpsCounter.setString("FPS:");

    double frameStart = 0.0;
    double frameEnd = 0.0;

    while (window.isOpen())
    {

        double dt = frameEnd - frameStart;
        frameStart = Lib::getTimeStamp();

        if (dt < 0.001) {
            dt = 0.001;
        }

        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::MouseButtonPressed)
            {
                g.shoot(event);
            }
            g.processInput(event);
        }
        g.update(dt);
        window.clear();
        g.draw(window);
        window.draw(fpsCounter);
        window.display();

        frameEnd = Lib::getTimeStamp();
        fpsCounter.setString("FPS:" + std::to_string(1.0 / dt));
    }

    return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
