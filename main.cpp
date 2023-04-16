
#include "raylib.h"

const char *WINDOW_TITLE = "test";
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 450;
const int FPS_MAX = 60;
const int SCREEN_WIDTH_HALF = SCREEN_WIDTH / 2;
const int SCREEN_HEIGHT_HALF = SCREEN_HEIGHT / 2;
const int SCREEN_WIDTH_QUATER = SCREEN_WIDTH / 4;
const int SCREEN_HEIGHT_QUATER = SCREEN_HEIGHT / 4;

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(FPS_MAX);
    SetExitKey(KEY_NULL);

    Vector2 mousePosition;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(WHITE);

        mousePosition = GetMousePosition();

        DrawCircle(mousePosition.x, mousePosition.y, SCREEN_HEIGHT_QUATER, RED);

        DrawText("Hello World", mousePosition.x - 55, mousePosition.y - 10, 20, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}