#pragma once

// pixels (utilisés par SFML) en mètres (unité de Box2D), 30 pixels = 1 mètre
constexpr float SCALE = 30.f;

// Window
constexpr float WINDOW_WIDTH = 1500.f;
constexpr float WINDOW_HEIGHT = 900.f;










/*
constexpr est typé, vérifié à la compilation, scoped (limité à un namespace/classe), et respecte les règles du C++.
#define est un remplacement de texte brut sans type, ni portée, ni vérification par le compilateur.
*/