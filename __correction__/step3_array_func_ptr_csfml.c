/*
** EPITECH WORKSHOP, 2022
** CSFML Introduction
** File description:
** CSFML main
*/

#include "my.h"

int changeScene(int *current_scene)
{
    //TODO check for Event because it's going too quick
    if (sfKeyboard_isKeyPressed(sfKeyQ) && *current_scene > 0) {
        (*current_scene)--;
        return (1);
    }
    if (sfKeyboard_isKeyPressed(sfKeyE) && *current_scene < 2) {
        (*current_scene)++;
        return (1);
    }
    return (0);
}

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

    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("./assets/fonts/comic-sans-ms.ttf");
    sfText_setFont(text, font);
    sfText_setString(text, "Menu");
    sfText_setCharacterSize(text, 100);

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
        }
        // Check for scene change by pressing Q or E (go left or right through the scenes)
        if (changeScene(current_scene) == 1)
            return;

        // Clear, draw and display everything to the screen
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, bg_sprite, NULL);
        sfRenderWindow_drawText(window, text, NULL);
        sfRenderWindow_display(window);
    }
}

// Menu scene
void settings(sfRenderWindow *window, sfEvent event, int *current_scene)
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

    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("./assets/fonts/comic-sans-ms.ttf");
    sfText_setFont(text, font);
    sfText_setString(text, "Settings");
    sfText_setCharacterSize(text, 100);

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

            // Check for scene change by pressing Q or E (go left or right through the scenes)
            if (changeScene(current_scene) == 1)
                return;
        }

        // Clear, draw and display everything to the screen
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, bg_sprite, NULL);
        sfRenderWindow_drawText(window, text, NULL);
        sfRenderWindow_display(window);
    }
}

// Menu scene
void play(sfRenderWindow *window, sfEvent event, int *current_scene)
{
    // Your code goes here (creating new textures, sprites, music, songs...)
    // You can enhance it by creating different functions for each scene in
    // multiple files so everything doesn't get packed in one function
    sfVector2f winmode = {1600, 800};
    sfSprite *bg_sprite = sfSprite_create();
    sfTexture *bg_texture = sfTexture_createFromFile("./assets/sprites/background.png", NULL);
    sfVector2u bg_size = sfTexture_getSize(bg_texture);

    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("./assets/fonts/comic-sans-ms.ttf");
    sfText_setFont(text, font);
    sfText_setString(text, "Play");
    sfText_setCharacterSize(text, 100);

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

            // Check for scene change by pressing Q or E (go left or right through the scenes)
            if (changeScene(current_scene) == 1)
                return;
        }

        // Clear, draw and display everything to the screen
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, bg_sprite, NULL);
        sfRenderWindow_drawText(window, text, NULL);
        sfRenderWindow_display(window);
    }
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

    void (*menu_ptr[])(sfRenderWindow*, sfEvent, int*) = {menu, settings, play};

    // Array of function pointers
    while (sfRenderWindow_isOpen(window))
        menu_ptr[current_scene](window, event, &current_scene);
    return (0);
}