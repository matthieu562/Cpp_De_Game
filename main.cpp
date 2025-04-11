#include "main.hpp"

static constexpr float FPS = 60.f; // static limite au fichier 
static constexpr float WALL_THICKNESS = 10.f;

int main() {
    sf::RenderWindow window(sf::VideoMode((unsigned int)WINDOW_WIDTH, (unsigned int)WINDOW_HEIGHT), "The Game !");
    b2Vec2 gravity(0.f, 0.f);
    b2World world(gravity);

    std::vector<Wall> walls; // emplace_back construit directement l’objet dans le vecteur
    walls.emplace_back(world, WINDOW_WIDTH / 2, WALL_THICKNESS / 2, WINDOW_WIDTH, WALL_THICKNESS); // top
    walls.emplace_back(world, WINDOW_WIDTH / 2, WINDOW_HEIGHT - WALL_THICKNESS / 2, WINDOW_WIDTH, WALL_THICKNESS); // bottom
    walls.emplace_back(world, WINDOW_WIDTH - WALL_THICKNESS / 2, WINDOW_HEIGHT / 2, WALL_THICKNESS, WINDOW_HEIGHT); // right
    walls.emplace_back(world, WALL_THICKNESS / 2, WINDOW_HEIGHT / 2, WALL_THICKNESS, WINDOW_HEIGHT); // left

    Circle cercle(world, 20.f, { 400.f, 100.f });

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        world.Step(1.f / FPS, 8, 3);

        window.clear();
        cercle.applyControl();

        for(const Wall& wall : walls)
            wall.draw(window);
        cercle.draw(window);
        window.setFramerateLimit((unsigned int)FPS);
        window.display();
    }

    return 0;
}


/*
Sujet à réflechir :
Passer les parametres par valeur ou par référence ? Ajouter autant de 'const' que possible
    Pour des parametres leger :
     -> La différence de performance est pratiquement insignifiante dans ce cas, donc il est préférable de privilégier la lisibilité.
ko Ajouter les Logs (=> Trace File, vraiment (pas) nécéssaire quand tout est sur un composant et qu'on peut debug?)
Ajouter les tests
Ajouter les commentaires de documentation (utiliser un générateur de page html automatique, Doxygen ?)
S'assurer d'utliser le plus de Callback possible (=> poster les messages, lire les msgs en buffer)
ok Gérer le mode Release/Debug
ok Mettre en place Git
*/
