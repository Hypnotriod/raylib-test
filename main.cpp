
#include <stdio.h>
#include <math.h>
#include "raylib.h"

const char *WINDOW_TITLE = "test";
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 480;
const int FPS_MAX = 60;
const int SCREEN_WIDTH_HALF = SCREEN_WIDTH / 2;
const int SCREEN_HEIGHT_HALF = SCREEN_HEIGHT / 2;
const int SCREEN_WIDTH_QUATER = SCREEN_WIDTH / 4;
const int SCREEN_HEIGHT_QUATER = SCREEN_HEIGHT / 4;

Texture2D txrSuperhero;
Texture2D txrKitty;

Vector2 orbitalposition(Texture2D *texture, float angle, float distanceDelta, Vector2 *mousePosition)
{
    Vector2 p;
    p.x = sin(angle) * texture->width / 2 * distanceDelta + mousePosition->x - texture->width / 2;
    p.y = cos(angle) * texture->width / 2 * distanceDelta / 2 + mousePosition->y - texture->height / 2;
    return p;
}

void init(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(FPS_MAX);
    SetExitKey(KEY_NULL);

    txrSuperhero = LoadTexture("resources/superhero.png");
    txrKitty = LoadTexture("resources/kitty.png");
}

void loop()
{
    Vector2 mousePosition;
    Vector2 superheroPosition;
    Vector2 kittyPosition;
    float angle = 0;
    float distanceDelta = 1.f;
    float heightDelta = 1.f;

    while (!WindowShouldClose())
    {
        angle -= (PI * 0.5f) * GetFrameTime();
        if (angle < PI * 2.f)
            angle += PI * 2.f;

        distanceDelta += GetMouseWheelMove() * 0.1f;

        BeginDrawing();

        ClearBackground(WHITE);

        mousePosition = GetMousePosition();

        superheroPosition = orbitalposition(&txrSuperhero, angle, distanceDelta, &mousePosition);
        kittyPosition = orbitalposition(&txrKitty, angle + PI, distanceDelta, &mousePosition);
        heightDelta = (superheroPosition.y - kittyPosition.y) * 0.001f;

        if (superheroPosition.y < kittyPosition.y)
        {
            DrawLineEx(mousePosition, Vector2{x : kittyPosition.x + txrKitty.width / 2, y : kittyPosition.y + txrKitty.height / 2}, 2, BLACK);
            DrawTextureEx(txrSuperhero, superheroPosition, 0, 1 + heightDelta, WHITE);
            DrawLineEx(mousePosition, Vector2{x : superheroPosition.x + txrSuperhero.width / 2, y : superheroPosition.y + txrSuperhero.height / 2}, 2, BLACK);
            DrawTextureEx(txrKitty, kittyPosition, 0, 1 - heightDelta, WHITE);
        }
        else
        {
            DrawLineEx(mousePosition, Vector2{x : superheroPosition.x + txrSuperhero.width / 2, y : superheroPosition.y + txrSuperhero.height / 2}, 2, BLACK);
            DrawTextureEx(txrKitty, kittyPosition, 0, 1 - heightDelta, WHITE);
            DrawLineEx(mousePosition, Vector2{x : kittyPosition.x + txrKitty.width / 2, y : kittyPosition.y + txrKitty.height / 2}, 2, BLACK);
            DrawTextureEx(txrSuperhero, superheroPosition, 0, 1 + heightDelta, WHITE);
        }

        // DrawCircle(mousePosition.x, mousePosition.y, SCREEN_HEIGHT_QUATER, RED);

        // DrawText("Hello World", mousePosition.x - 55, mousePosition.y - 10, 20, WHITE);

        EndDrawing();
    }
}

int main(void)
{
    init();
    loop();
    CloseWindow();
    return 0;
}
