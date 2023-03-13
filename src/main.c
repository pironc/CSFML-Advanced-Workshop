/*
** EPITECH WORKSHOP, 2022
** CSFML Introduction
** File description:
** CSFML main
*/

#include "my.h"

// Menu scene
void menu(sfRenderWindow *window, sfEvent event, int *current_scene)
{
    // Your code goes here (creating new textures, sprites, music, songs...)
    // You can enhance it by creating different functions for each scene in
    // multiple files so everything doesn't get packed in one function
    sfVector2f winmode = {1600, 800};
    sfSprite *bg_sprite = sfSprite_create();
    sfTexture *bg_texture = sfTexture_createFromFile("./assets/sprites/background.png", NULL);
    sfVector2u bg_size = sfTexture_getSize(bg_texture);

    // IGNORE -- This is just to make the background fit the window
    sfSprite_setScale(bg_sprite, (sfVector2f){winmode.x / bg_size.x,
                                              winmode.y / bg_size.y});
    sfSprite_setTexture(bg_sprite, bg_texture, sfFalse);

    // Your code goes here
    while (sfRenderWindow_isOpen(window)) {

        // Check for events (and EVENTs only) happening in your window
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }

            // Use ESCAPE to exit - Don't waste time reaching to the red cross (use for debug)
            if (sfKeyboard_isKeyPressed(sfKeyEscape))
                sfRenderWindow_close(window);

            // Goes to settings scene
            if (sfKeyboard_isKeyPressed(sfKeyNum1)) {
                *current_scene = 1;
                return;
            }
        }

        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, bg_sprite, NULL);
        sfRenderWindow_display(window);
    }
}

// Settings scene
void settings(sfRenderWindow *window, sfEvent event, int *current_scene)
{
    // Your code goes here
}

// Gameplay scene
void gameplay(sfRenderWindow *window, sfEvent event, int *current_scene)
{
    // Your code goes here
}



// Main function to handle window opening, "global" variables, etc...
int main(void)
{
    // CSFML Window mandatory variables in order to run a window
    sfVector2f winmode = {1600, 800};
    sfVideoMode mode = {winmode.x, winmode.y, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "CSFML !", sfClose | sfResize, NULL);
    sfEvent event;
    int current_scene = 0;

    // Create your function pointer here

    // Array of function pointers
    while (sfRenderWindow_isOpen(window))
        menu(window, event, &current_scene);
    return (0);
}