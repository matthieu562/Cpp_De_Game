#include "Box2D_DLL.h"  // Inclut le fichier d'en-tête pour avoir la déclaration
#include <windows.h>

// Définition de la fonction exportée depuis la DLL
extern "C" {
    void CreateWorld() {
        // Logique de la fonction qui pourrait créer un monde physique avec Box2D
        // Par exemple :
        // b2Vec2 gravity(0.0f, -9.8f);
        // b2World world(gravity);

        // Simple message pour démonstration
        MessageBox(NULL, L"Le monde Box2D a été créé!", L"Box2D", MB_OK);
    }
}
