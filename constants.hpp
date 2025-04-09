#pragma once

// pixels (utilisés par SFML) en mètres (unité de Box2D), 30 pixels = 1 mètre
constexpr int SCALE = 30;

// Window
constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 600;










/*
constexpr est typé, vérifié à la compilation, scoped (limité à un namespace/classe), et respecte les règles du C++.
#define est un remplacement de texte brut sans type, ni portée, ni vérification par le compilateur.
*/