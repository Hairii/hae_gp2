// Sfml.cpp : Ce fichier contient la fonction 'main'. L'execution du programme commence et se termine a cet endroit.
//

#include <iostream>//inclut un entete/header qui s'apelle iostream
#include <SFML/Graphics.hpp> //inclut un entete/header( .hpp)

int main()//fonction main
{

    std::cout << "Hello World!\n"; //affiche la chaine de charactere en out (Hello World!)
    sf::RenderWindow window(sf::VideoMode(720, 460), "SFML works!"); //creer une fenetre window de 200 sur 200 avec comme titre (SFML work!)
    sf::CircleShape shape(100.f); //creer un cercle de rayon 100
    shape.setFillColor(sf::Color::Green); //appelle shape et appelle la fonction setFillColor qui met la couleur vert au cercle

    while (window.isOpen()) //tant que le fentre window est ouverte
    {
        sf::Event event;    //creer une variable qui s'appelle event qui sert pour les boutons
        auto pos = shape.getPosition();
        float speed =10;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::F1)//si la touche appuyer et la toucha A
                    shape.setFillColor(sf::Color::Red);//appelle shape et appelle la fonction setFillColor qui met la couleur rouge au cercle

                if (event.key.code == sf::Keyboard::F2)
                    shape.setFillColor(sf::Color::Blue);


                if (event.key.code == sf::Keyboard::Right) pos.x += speed;
                if (event.key.code == sf::Keyboard::Left) pos.x -= speed;
                if (event.key.code == sf::Keyboard::Up) pos.y -= speed;
                if (event.key.code == sf::Keyboard::Down) pos.y += speed;

                /* sf::Vector2f dir(0, 0);

                 if (event.key.code == sf::Keyboard::Left) dir.x --;
                 if (event.key.code == sf::Keyboard::Right) dir.x ++;
                 if (event.key.code == sf::Keyboard::Up) dir.y --;
                 if (event.key.code == sf::Keyboard::Down) dir.y ++;

                                                                             //plus compliquer
                 float len = sqrt(dir.x * dir.x + dir.y * dir.y);
                 int sp = 0.33;

                 if (len) {
                     dir.x /= len;
                     dir.y /= len;

                     dir.x *= sp;
                     dir.y *= sp;

                     pos.x += dir.x;
                     pos.y += dir.y;
                 }*/
            }

            if (event.type == sf::Event::MouseMoved) {

                pos.x = event.mouseMove.x - shape.getRadius();
                pos.y = event.mouseMove.y - shape.getRadius();
            }

            if (event.type == sf::Event::MouseWheelScrolled)
            {
                int rad = shape.getRadius();
                rad += event.mouseWheelScroll.delta;
                if (rad < 10)rad = 10;
                shape.setRadius(rad);
            }
                
            /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))//meme chose que ce qu'il y a dessus mais interroge si l'evenement d'une touche et appuyer
                shape.setFillColor(sf::Color::Yellow);*/

            if (event.type == sf::Event::Closed)//si evenement ferme la fentre est 'vrai'
                window.close();//ferme la fenetre window
        }

        window.clear();//efface ce qui est afficher sur la fentre window 
        window.draw(shape);//dessine le cercle dans le fentre window
        shape.setPosition(pos);
        window.display();//affiche le fentre window
    }

    return 0;
}
// Executer le programme?: Ctrl+F5 ou menu Deboguer?> Executer sans debogage
// Deboguer le programme?: F5 ou menu Deboguer?> Demarrer le debogage

// Astuces pour bien demarrer?: 
//   1. Utilisez la fenetre Explorateur de solutions pour ajouter des fichiers et les gerer.
//   2. Utilisez la fenetre Team Explorer pour vous connecter au controle de code source.
//   3. Utilisez la fenetre Sortie pour voir la sortie de la generation et d'autres messages.
//   4. Utilisez la fenetre Liste d'erreurs pour voir les erreurs.
//   5. Accedez a Projet?> Ajouter un nouvel element pour creer des fichiers de code, ou a Projet?> Ajouter un element existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accedez a Fichier?> Ouvrir?> Projet et selectionnez le fichier .sln.
