#include "Box2D_DLL.h"  // Inclut le fichier d'en-t�te pour avoir la d�claration
#include <windows.h>

// D�finition de la fonction export�e depuis la DLL
extern "C" {
    void CreateWorld() {
        // Logique de la fonction qui pourrait cr�er un monde physique avec Box2D
        // Par exemple :
        // b2Vec2 gravity(0.0f, -9.8f);
        // b2World world(gravity);

        // Simple message pour d�monstration
        MessageBox(NULL, L"Le monde Box2D a �t� cr��!", L"Box2D", MB_OK);
    }
}
