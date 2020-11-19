#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include "tex_res.c"
#include "math.h"

sfVector2f make_vec2(int _x, int _y)
{
    sfVector2f vec2 = {_x, _y};
    return vec2;
}

sfVector2f make_Dvec2(double _x, double _y)
{
    sfVector2f vec2 = {_x, _y};
    return vec2;
}

void load_level(int jb, int ib, int num[10][7], textures *texres, brick *bricks[12][12])
{
    printf("0 malloc: %d:%d= 0x%x\n", ib, jb, bricks[ib][jb]);
    bricks[ib][jb] = malloc(sizeof(brick));
    printf("1 malloc: %d:%d= 0x%x\n", ib, jb, bricks[ib][jb]);
    bricks[ib][jb]->sprite = sfSprite_create();
    switch (num[ib][jb])
    {
    case 0:
        bricks[ib][jb]->worth = 0;
        sfSprite_setTexture(bricks[ib][jb]->sprite, texres->BRICK_1_GR1_tex, sfTrue);
        bricks[ib][jb]->hit = true;
        break;
    case 1:
        bricks[ib][jb]->worth = 100;
        sfSprite_setTexture(bricks[ib][jb]->sprite, texres->BRICK_1_G1_tex, sfTrue);
        break;
    case 2:
        bricks[ib][jb]->worth = 200;
        sfSprite_setTexture(bricks[ib][jb]->sprite, texres->BRICK_1_B1_tex, sfTrue);
        break;
    case 3:
        bricks[ib][jb]->worth = 300;
        sfSprite_setTexture(bricks[ib][jb]->sprite, texres->BRICK_1_O1_tex, sfTrue);
        break;
    case 4:
        bricks[ib][jb]->worth = 400;
        sfSprite_setTexture(bricks[ib][jb]->sprite, texres->BRICK_1_R1_tex, sfTrue);
        break;
    case 5:
        bricks[ib][jb]->worth = 500;
        sfSprite_setTexture(bricks[ib][jb]->sprite, texres->BRICK_1_V1_tex, sfTrue);
        break;
    case 6:
        bricks[ib][jb]->worth = 600;
        sfSprite_setTexture(bricks[ib][jb]->sprite, texres->BRICK_1_Y1_tex, sfTrue);
        break;
    case 7:
        bricks[ib][jb]->worth = 0;
        sfSprite_setTexture(bricks[ib][jb]->sprite, texres->BRICK_1_GR1_tex, sfTrue);
        bricks[ib][jb]->hit = true;
        break;
    }
    sfSprite_setScale(bricks[ib][jb]->sprite, make_Dvec2(1.1, 1.17));
    if (!num[ib][jb])
    {
        sfSprite_setPosition(bricks[ib][jb]->sprite, make_vec2(-500, 0));
    }
    else
    {
        sfVector2f vec2 = {6 + jb * 90, 20 + ib * 30};
        sfSprite_setPosition(bricks[ib][jb]->sprite, vec2);
    }
}

int main(int argc, char *argv[])
{

    typedef enum
    {
        MENU,
        GAME,
        OPTIONS,
        HIGHSCORES
    } STATES;

    int levels[10][10][7] =
        {
            {//0
             {0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0}},
            {//1
             {0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0},
             {0, 2, 2, 2, 2, 2, 0},
             {0, 1, 1, 1, 1, 1, 0},
             {0, 0, 0, 0, 0, 0, 0},
             {0, 1, 1, 1, 1, 1, 0},
             {0, 2, 2, 2, 2, 2, 0},
             {0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0}},
            {//2
             {1, 1, 4, 1, 4, 1, 1},
             {1, 4, 1, 4, 1, 4, 1},
             {0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0},
             {3, 2, 0, 0, 0, 2, 3},
             {1, 2, 0, 0, 0, 2, 1},
             {0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0},
             {1, 1, 1, 1, 1, 1, 1},
             {1, 1, 1, 1, 1, 1, 1}

            },
            {//3
             {1, 1, 1, 1, 1, 1, 1},
             {1, 1, 5, 0, 5, 1, 1},
             {1, 5, 0, 0, 0, 5, 1},
             {1, 5, 0, 6, 0, 5, 1},
             {1, 1, 0, 6, 0, 1, 1},
             {1, 0, 3, 6, 3, 0, 1},
             {0, 0, 6, 6, 6, 0, 0},
             {0, 3, 0, 1, 0, 3, 0},
             {0, 2, 0, 1, 0, 2, 0},
             {0, 3, 0, 1, 0, 3, 0}

            },
            {//4
             {4, 0, 2, 0, 4, 0, 2},
             {0, 2, 0, 4, 0, 2, 0},
             {2, 0, 4, 0, 2, 0, 4},
             {0, 4, 0, 2, 0, 4, 0},
             {4, 0, 2, 0, 4, 0, 2},
             {0, 2, 0, 4, 0, 2, 0},
             {2, 0, 4, 0, 2, 0, 4},
             {0, 4, 0, 2, 0, 4, 0},
             {4, 0, 2, 0, 4, 0, 2},
             {0, 2, 0, 4, 0, 2, 0}

            },
            {//5
             {0, 0, 0, 0, 0, 0, 0},
             {0, 1, 1, 1, 1, 1, 0},
             {0, 1, 2, 2, 2, 1, 0},
             {0, 1, 3, 6, 3, 1, 0},
             {0, 1, 4, 6, 4, 1, 0},
             {0, 1, 4, 6, 4, 1, 0},
             {0, 1, 3, 6, 3, 1, 0},
             {0, 1, 2, 2, 2, 1, 0},
             {0, 1, 1, 1, 1, 1, 0},
             {0, 7, 0, 0, 0, 7, 0}

            },
            {//6
             {6, 6, 6, 7, 6, 6, 6},
             {0, 0, 0, 7, 0, 0, 0},
             {4, 4, 4, 4, 4, 4, 4},
             {4, 4, 4, 4, 4, 4, 4},
             {7, 3, 3, 3, 3, 3, 7},
             {7, 3, 3, 3, 3, 3, 7},
             {2, 2, 2, 2, 2, 2, 2},
             {2, 2, 2, 2, 2, 2, 2},
             {0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0}

            },
            {//7
             {6, 0, 2, 0, 6, 0, 2},
             {0, 2, 0, 4, 0, 2, 0},
             {2, 0, 6, 0, 2, 0, 6},
             {0, 4, 0, 2, 0, 4, 0},
             {6, 0, 2, 0, 6, 0, 2},
             {0, 2, 0, 4, 0, 2, 0},
             {2, 0, 6, 0, 2, 0, 6},
             {0, 4, 0, 2, 0, 4, 0},
             {6, 0, 2, 0, 6, 0, 2},
             {0, 2, 0, 4, 0, 2, 0}

            },
            {//8
             {1, 2, 3, 4, 3, 2, 1},
             {2, 0, 2, 5, 2, 0, 2},
             {3, 0, 0, 3, 0, 0, 3},
             {4, 0, 4, 0, 4, 0, 4},
             {5, 5, 0, 0, 0, 5, 5},
             {6, 0, 0, 0, 0, 0, 6},
             {1, 0, 0, 0, 0, 0, 1},
             {2, 0, 0, 0, 0, 0, 2},
             {3, 0, 0, 0, 0, 0, 3},
             {0, 0, 0, 0, 0, 0, 0}

            }};
    int framerate = 60;

    int c_level[10][7];
    bool cl_first = false;

    int points = 0;
    double combo_ctr = 0;
    double combo = 1;
    double combo_time = 2.5;

    int lives = 3;
    int frame = 0;
    int cur_level = 1;

    double b_speed = 3;
    double x_speed = b_speed;
    double y_speed = b_speed;

    int start_count = 3;
    int start_ctr = 60;
    bool running = false;
    bool ready = false;
    bool speed_set = false;
    bool game_start = false;
    bool game_end = false;
    bool level_loaded = false;

    double alive_bricks = 70;

    double font_ctr = 0;

    bool level_load = false;
    int ll_ctr_x = 0;
    int ll_ctr_y = 0;
    bool ll_act[10][7];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            ll_act[i][j] = false;
        }
    }
    int menu_selected = 1;

    //Resources
    textures *texres = malloc(sizeof(*texres));

    texres->BRICK_1_G1_tex = sfTexture_createFromFile("./png/brick01g1.png", NULL);
    texres->BRICK_1_B1_tex = sfTexture_createFromFile("./png/brick01b1.png", NULL);
    texres->BRICK_1_GR1_tex = sfTexture_createFromFile("./png/brick01gr1.png", NULL);
    texres->BRICK_1_O1_tex = sfTexture_createFromFile("./png/brick01o1.png", NULL);
    texres->BRICK_1_R1_tex = sfTexture_createFromFile("./png/brick01r1.png", NULL);
    texres->BRICK_1_V1_tex = sfTexture_createFromFile("./png/brick01v1.png", NULL);
    texres->BRICK_1_Y1_tex = sfTexture_createFromFile("./png/brick01y1.png", NULL);
    texres->MAIN_M = sfTexture_createFromFile("./png/main_m.png", NULL);
    texres->BLANK_M = sfTexture_createFromFile("./png/blank_m.png", NULL);
    texres->BACKGROUND = sfTexture_createFromFile("./png/bg.png", NULL);
    texres->BALL = sfTexture_createFromFile("./png/ball.png", NULL);
    texres->PAD = sfTexture_createFromFile("./png/pad2.png", NULL);

    sfSprite *pad = sfSprite_create();
    sfSprite_setTexture(pad, texres->PAD, sfTrue);
    sfSprite_setPosition(pad, make_vec2(-40 + 640 / 2, 640 - 50));
    sfSprite_setScale(pad, make_Dvec2(1, 1.14));

    sfRectangleShape *menu_box = sfRectangleShape_create();
    sfRectangleShape_setSize(menu_box, make_vec2(191, 38));
    sfColor boxcolor = sfColor_fromRGBA(10, 10, 10, 100);
    sfRectangleShape_setFillColor(menu_box, boxcolor);

    sfSprite *mainmenu = sfSprite_create();
    sfSprite_setTexture(mainmenu, texres->MAIN_M, sfTrue);
    sfSprite_setPosition(mainmenu, make_vec2((640 / 2) - (300 / 2), (640 / 2) - (300 / 2)));

    bool KEY_LEFT = false;
    bool KEY_RIGHT = false;
    bool L_KEY_LEFT = false;
    bool L_KEY_RIGHT = false;

    bool KEY_UP = false;
    bool KEY_DOWN = false;
    bool L_KEY_UP = false;
    bool L_KEY_DOWN = false;

    bool KEY_ENTER = false;
    bool L_KEY_ENTER = false;

    bool FOCUS = true;

    sfSprite *ball = sfSprite_create();
    sfSprite_setTexture(ball, texres->BALL, sfTrue);
    sfVector2f vec2 = {640 / 2, 640 - 200};
    sfSprite_setPosition(ball, vec2);

    sfSprite *bg = sfSprite_create();
    sfSprite_setTexture(bg, texres->BACKGROUND, sfTrue);

    brick *bricks[12][12];
    //load_level(level_1,texres,bricks);

    sfRectangleShape *xlvlbox;
    xlvlbox = sfRectangleShape_create();
    sfRectangleShape_setSize(xlvlbox, make_vec2(200, 40));
    boxcolor = sfColor_fromRGBA(0, 255, 255, 24);
    sfRectangleShape_setFillColor(xlvlbox, boxcolor);

    sfRectangleShape *ylvlbox;
    ylvlbox = sfRectangleShape_create();
    sfRectangleShape_setSize(ylvlbox, make_vec2(40, 200));
    boxcolor = sfColor_fromRGBA(0, 255, 255, 24);
    sfRectangleShape_setFillColor(ylvlbox, boxcolor);

    sfFont *font = sfFont_createFromFile("font.ttf");

    sfText *text_points = sfText_create();
    sfText_setFont(text_points, font);
    sfText_setCharacterSize(text_points, 24);

    sfText *text_combo = sfText_create();
    sfText_setFont(text_combo, font);
    sfText_setCharacterSize(text_combo, 24);
    sfText_setPosition(text_combo, make_vec2(0, 24));

    sfRectangleShape *combo_rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(combo_rect, make_vec2(0, 60));
    sfRectangleShape_setSize(combo_rect, make_vec2(10, 10));

    sfText *text_start = sfText_create();
    sfText_setFont(text_start, font);
    sfText_setCharacterSize(text_start, 32);
    sfText_setPosition(text_start, make_vec2(245, 320));

    sfText *text_lives = sfText_create();
    sfText_setFont(text_lives, font);
    sfText_setCharacterSize(text_lives, 24);
    sfText_setPosition(text_lives, make_vec2(500, 0));

    sfText *text_bspeed = sfText_create();
    sfText_setFont(text_bspeed, font);
    sfText_setCharacterSize(text_bspeed, 32);
    sfText_setPosition(text_bspeed, make_vec2(210, 320));

    sfText *text_gameover = sfText_create();
    sfText_setFont(text_gameover, font);
    sfText_setCharacterSize(text_gameover, 32);
    sfText_setPosition(text_gameover, make_vec2(270, 320));
    sfText_setString(text_gameover, "Gameover");

    sfText *textc = sfText_create();
    sfText_setFont(textc, font);
    sfText_setCharacterSize(textc, 16);
    sfText_setPosition(textc, make_vec2(0, 620));
    sfText_setString(textc, "(C) 2019 slxfld");

    int highscore[10];
    for (int i = 0; i < 11; i++)
    {
        highscore[i] = 0;
    }
    sfText *text_hisc[10];
    for (int i = 0; i < 10; i++)
    {
        text_hisc[i] = sfText_create();
        sfText_setFont(text_hisc[i], font);
        sfText_setString(text_hisc[i], "Points:");
        sfText_setCharacterSize(text_hisc[i], 24);
        sfText_setPosition(text_hisc[i], make_vec2(200, 200 + (i * 30)));
    }

    sfVideoMode mode = {640, 640, 32};
    sfRenderWindow *window;
    sfEvent event;
    window = sfRenderWindow_create(mode, "Breakout70", sfNone | sfClose, NULL);

    if (!window)
    {
        printf("Could not initialise Window\n");
        return 1;
    }

    sfRenderWindow_setFramerateLimit(window, framerate);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);

    STATES state = MENU;

    while (sfRenderWindow_isOpen(window))
    {
        while (sfRenderWindow_pollEvent(window, &event))
        {

            if (event.type == sfEvtMouseMoved)
            {
                sfVector2i vec2m = sfMouse_getPositionRenderWindow(window);
                sfSprite_setPosition(pad, make_vec2(vec2m.x - (96 / 2), 640 - 50));
            }

            if (event.type == sfEvtClosed)
            {
                sfRenderWindow_close(window);
                break;
            }

            if (event.type == sfEvtGainedFocus)
            {
                FOCUS = true;
            }
            if (event.type == sfEvtLostFocus)
            {
                FOCUS = false;
            }

            if (FOCUS)
            {

                if (sfKeyboard_isKeyPressed(sfKeyW))
                {
                    KEY_UP = true;
                    if (!L_KEY_UP && !game_start)
                    {
                        L_KEY_UP = true;
                        if (menu_selected > 1)
                        {
                            menu_selected--;
                        }
                    }
                }
                else
                {
                    KEY_UP = false;
                    L_KEY_UP = false;
                }

                if (sfKeyboard_isKeyPressed(sfKeyS))
                {
                    KEY_DOWN = true;
                    if (!L_KEY_DOWN && !game_start)
                    {
                        L_KEY_DOWN = true;
                        if (menu_selected < 3)
                        {
                            menu_selected++;
                        }
                    }
                }
                else
                {
                    KEY_DOWN = false;
                    L_KEY_DOWN = false;
                }

                if (sfKeyboard_isKeyPressed(sfKeyA))
                {
                    KEY_LEFT = true;
                    if (!L_KEY_LEFT && !game_start)
                    {
                        L_KEY_LEFT = true;
                        if (!speed_set)
                        {
                            if (b_speed > 0)
                            {
                                b_speed -= 0.5;
                            }
                            x_speed = b_speed;
                            y_speed = b_speed;
                        }
                    }
                }
                else
                {
                    KEY_LEFT = false;
                    L_KEY_LEFT = false;
                }

                if (sfKeyboard_isKeyPressed(sfKeyD))
                {
                    KEY_RIGHT = true;
                    if (!L_KEY_RIGHT && !game_start)
                    {
                        L_KEY_RIGHT = true;
                        if (!speed_set)
                        {
                            if (b_speed < 10)
                            {
                                b_speed += 0.5;
                            }
                            x_speed = b_speed;
                            y_speed = b_speed;
                        }
                    }
                }
                else
                {
                    KEY_RIGHT = false;
                    L_KEY_RIGHT = false;
                }

                if (sfKeyboard_isKeyPressed(sfKeyReturn) || sfMouse_isButtonPressed(sfMouseLeft))
                {
                    KEY_ENTER = true;
                    if (!L_KEY_ENTER && !game_start)
                    {
                        L_KEY_ENTER = true;
                        switch (state)
                        {
                        case MENU:
                            switch (menu_selected)
                            {
                            case 1:
                                state = GAME;
                                if (!game_start)
                                {
                                    level_load = true;
                                    lives = 3;
                                    combo = 0;
                                    combo_ctr = 0;
                                    font_ctr = 0;
                                    points = 0;
                                }
                                break;
                            case 2:
                                state = HIGHSCORES;
                                break;
                            case 3:
                                //state = OPTIONS;
                                break;
                            }
                            break;
                        case HIGHSCORES:
                            state = MENU;
                            break;
                        case GAME:
                            if (!game_end)
                            {
                                ready = true;
                                game_start = true;
                                speed_set = true;
                            }
                            else
                            {
                                sfText_setPosition(text_points, make_vec2(0, 0));
                                sfSprite_setPosition(pad, make_vec2(-40 + 640 / 2, 640 - 50));
                                sfSprite_setPosition(ball, make_vec2(640 / 2, 640 - 200));
                                cur_level = 1;
                                cl_first = false;
                                ready = false;
                                game_start = false;
                                game_end = false;
                                level_loaded = false;
                                level_load = false;
                                speed_set = false;
                                running = false;
                                state = MENU;
                            }
                            break;
                        }
                    }
                }
                else
                {
                    KEY_ENTER = false;
                    L_KEY_ENTER = false;
                }

            } /*End Focus*/
        }

        switch (state)
        {
        case OPTIONS:
            /* Clear */
            sfRenderWindow_clear(window, sfBlack);
            /* Background */
            sfRenderWindow_drawSprite(window, bg, NULL);
            sfRenderWindow_drawSprite(window, mainmenu, NULL);

            /* Display */
            sfRenderWindow_display(window);
            break;

        case HIGHSCORES:
            /* Clear */
            sfRenderWindow_clear(window, sfBlack);
            /* Background */
            sfRenderWindow_drawSprite(window, bg, NULL);

            for (int i = 0; i < 9; i++)
            {

                char xhigh[24] = {
                    0};
                sprintf(xhigh, "Points: %d", highscore[i]);
                sfText_setString(text_hisc[i], xhigh);
                sfRenderWindow_drawText(window, text_hisc[i], NULL);
            }

            /* Display */
            sfRenderWindow_display(window);
            break;

        case MENU:
            /* Clear */
            sfRenderWindow_clear(window, sfBlack);
            /* Background */
            sfRenderWindow_drawSprite(window, bg, NULL);

            sfRenderWindow_drawSprite(window, mainmenu, NULL);

            switch (menu_selected)
            {
            case 1:
                sfRectangleShape_setPosition(menu_box, make_vec2(225, 224));
                break;
            case 2:
                sfRectangleShape_setPosition(menu_box, make_vec2(225, 224 + (39 * 2)));
                break;
            case 3:
                sfRectangleShape_setPosition(menu_box, make_vec2(225, 224 + (39 * 4)));
                break;
            }

            sfRenderWindow_drawRectangleShape(window, menu_box, NULL);
            sfRenderWindow_drawText(window, textc, NULL);
            /* Display */
            sfRenderWindow_display(window);
            break;

        case GAME:

            if (speed_set)
            {
                if (KEY_LEFT)
                {
                    if (sfSprite_getPosition(pad).x > 0)
                    {
                        sfSprite_move(pad, make_vec2(-6, 0));
                    }
                }

                if (KEY_RIGHT)
                {
                    if (sfSprite_getPosition(pad).x + 96 < 640)
                    {
                        sfSprite_move(pad, make_vec2(6, 0));
                    }
                }
            }

            /* load */
            if (level_load)
            {

                if (cur_level == 9 || lives == 0)
                {
                    game_end = true;
                    level_load = false;
                    level_loaded = true;
                    highscore[9] = points;
                    for (int i = 0; i < 10; i++)
                    {
                        if (!i)
                        {
                        }
                        else
                        {
                            highscore[i] = highscore[i + 1];
                        }
                    }
                }
                else
                {

                    /* Clear */
                    sfRenderWindow_clear(window, sfBlack);

                    /* Background */
                    sfRenderWindow_drawSprite(window, bg, NULL);

                    if (cl_first == false)
                    {
                        cl_first = true;
                        /* Clear */
                        for (int i = 0; i < 10; i++)
                        {
                            for (int j = 0; j < 7; j++)
                            {
                                c_level[i][j] = 0;
                            }
                        }
                        for (int i = 0; i < 10; i++)
                        {
                            for (int j = 0; j < 7; j++)
                            {
                                ll_act[i][j] = 0;
                            }
                        }

                        /* Apply */
                        for (int i = 0; i < 10; i++)
                        {
                            for (int j = 0; j < 7; j++)
                            {
                                c_level[i][j] = levels[cur_level][i][j];
                            }
                        }
                    }

                    load_level(ll_ctr_x, ll_ctr_y, c_level, texres, bricks);

                    ll_act[ll_ctr_y][ll_ctr_x] = true;
                    sfVector2f vec2x = {
                        32 + 41 + (6 + ll_ctr_x * 90) - (200 / 1.5),
                        20 + ll_ctr_y * 30 - 4};
                    sfVector2f vec2y = {
                        -8 + 38 + ll_ctr_x * 90,
                        41 + (30 + ll_ctr_y * 30) - (200 / 1.5) - 4};

                    sfRectangleShape_setPosition(xlvlbox, vec2x);
                    sfRectangleShape_setPosition(ylvlbox, vec2y);

                    /* Bricks  */
                    for (int i = 0; i < 10; i++)
                    {
                        for (int j = 0; j < 7; j++)
                        {
                            if (ll_act[i][j])
                            {
                                sfRenderWindow_drawSprite(window, bricks[i][j]->sprite, NULL);
                            }
                        }
                    }
                    if (ll_act[ll_ctr_y][ll_ctr_x])
                    {
                        if (c_level[ll_ctr_y][ll_ctr_x] != 0)
                        {
                            sfRenderWindow_drawRectangleShape(window, xlvlbox, NULL);
                            sfRenderWindow_drawRectangleShape(window, ylvlbox, NULL);
                        }
                    }

                    ll_ctr_x++;

                    if (ll_ctr_x == 7)
                    {
                        ll_ctr_x = 0;
                        ll_ctr_y++;
                    }
                    if (ll_ctr_y == 10)
                    {
                        ll_ctr_y = 0;
                        level_load = false;
                        level_loaded = true;
                    }

                    /* Display */
                    sfRenderWindow_display(window);
                }
            }
            /* /load */

            /* UPDATE */
            if (level_loaded)
            {
                if (running && !game_end)
                {

                    /* End Ball->Bricks Collision Check */
                    /* BallPosition Next X */

                    sfVector2f vec2 = {
                        -200,
                        -200};
                    sfVector2f l_vec2 = {};
                    sfRectangleShape_setPosition(xlvlbox, vec2);
                    sfRectangleShape_setPosition(ylvlbox, vec2);
                    l_vec2 = make_vec2(sfSprite_getPosition(ball).x, sfSprite_getPosition(ball).y);

                    sfSprite_move(ball, make_Dvec2(x_speed, 0));

                    for (int i = 0; i < 10; i++)
                    {
                        for (int j = 0; j < 7; j++)
                        {

                            sfFloatRect ball_rect = sfSprite_getGlobalBounds(ball);
                            sfFloatRect *p_ball = &ball_rect;
                            sfFloatRect brick_rect = sfSprite_getGlobalBounds(bricks[i][j]->sprite);
                            sfFloatRect *b_rect = &brick_rect;

                            if (sfFloatRect_intersects(p_ball, b_rect, NULL))
                            {

                                sfSprite_setPosition(ball, l_vec2);
                                x_speed = -x_speed;
                                if (bricks[i][j]->worth > 0)
                                {
                                    sfSprite_setPosition(bricks[i][j]->sprite, make_vec2(0, -200));

                                    combo_ctr = combo_ctr + (framerate * (bricks[i][j]->worth / 100));
                                    if (combo_ctr > (framerate * 1))
                                    {
                                        combo += bricks[i][j]->worth / 100;
                                        combo_ctr = combo_ctr - framerate * 1;
                                        font_ctr = 10;
                                    }

                                    points += (bricks[i][j]->worth * combo);
                                    bricks[i][j]->hit = true;
                                    /* Check Level Complete */
                                    bool levelcom = true;
                                    alive_bricks = 0;
                                    for (int i = 0; i < 10; i++)
                                    {
                                        for (int j = 0; j < 7; j++)
                                        {
                                            if (!bricks[i][j]->hit)
                                            {
                                                levelcom = false;
                                                alive_bricks++;
                                            }
                                        }
                                    }
                                    if (levelcom)
                                    {
                                        /* Level switch */
                                        sfSprite_setPosition(ball, make_vec2(640 / 2, 640 - 200));
                                        running = false;
                                        start_count = 3;
                                        start_ctr = framerate;

                                        cur_level++;
                                        game_start = false;
                                        level_loaded = false;
                                        level_load = true;
                                        cl_first = false;
                                    }
                                }
                            }
                        }
                    }

                    /* BallPosition Next Y */
                    l_vec2 = make_vec2(sfSprite_getPosition(ball).x, sfSprite_getPosition(ball).y);

                    sfSprite_move(ball, make_Dvec2(0, y_speed));

                    for (int i = 0; i < 10; i++)
                    {
                        for (int j = 0; j < 7; j++)
                        {

                            sfFloatRect ball_rect = sfSprite_getGlobalBounds(ball);
                            sfFloatRect *p_ball = &ball_rect;
                            sfFloatRect brick_rect = sfSprite_getGlobalBounds(bricks[i][j]->sprite);
                            sfFloatRect *b_rect = &brick_rect;

                            if (sfFloatRect_intersects(p_ball, b_rect, NULL))
                            {

                                sfSprite_setPosition(ball, l_vec2);
                                y_speed = -y_speed;
                                if (bricks[i][j]->worth > 0)
                                {
                                    sfSprite_setPosition(bricks[i][j]->sprite, make_vec2(0, -200));

                                    combo_ctr = combo_ctr + (framerate * (bricks[i][j]->worth / 100));
                                    if (combo_ctr > (framerate * 1))
                                    {
                                        combo += bricks[i][j]->worth / 100;
                                        combo_ctr = combo_ctr - framerate * 1;
                                        font_ctr = 10;
                                    }

                                    points += (bricks[i][j]->worth * combo);
                                    bricks[i][j]->hit = true;
                                    /* Check Level Complete */
                                    bool levelcom = true;
                                    alive_bricks = 0;
                                    for (int i = 0; i < 10; i++)
                                    {
                                        for (int j = 0; j < 7; j++)
                                        {
                                            if (!bricks[i][j]->hit)
                                            {
                                                levelcom = false;
                                                alive_bricks++;
                                            }
                                        }
                                    }
                                    if (levelcom)
                                    {
                                        /* Level switch */
                                        sfSprite_setPosition(ball, make_vec2(640 / 2, 640 - 200));
                                        x_speed = b_speed;
                                        y_speed = b_speed;
                                        running = false;
                                        start_count = 3;
                                        start_ctr = framerate;

                                        cur_level++;
                                        game_start = false;
                                        level_loaded = false;
                                        level_load = true;
                                        cl_first = false;
                                    }
                                }
                            }
                        }
                    }
                    /* End Ball->Bricks Collision Check */
                    /* combo count */

                    if (combo_ctr > 0)
                    {
                        combo_ctr -= (0.04 * (combo));
                        if (combo_ctr <= 0 && combo != 1)
                        {
                            combo--;
                            combo_ctr = framerate * 1;
                        }
                    }
                    if (combo_ctr > framerate * 1)
                    {
                        combo_ctr = framerate * 1;
                    }

                    if (font_ctr > 0)
                    {
                        font_ctr--;
                    }

                    /* Ball Border Check */
                    if (sfSprite_getPosition(ball).x + 16 > 640)
                    {
                        if (x_speed > 0)
                        {
                            x_speed = -x_speed;
                        }
                    }
                    if (sfSprite_getPosition(ball).x < 0)
                    {
                        if (x_speed < 0)
                        {
                            x_speed = -x_speed;
                        }
                    }
                    if (sfSprite_getPosition(ball).y < 0)
                    {
                        if (y_speed < 0)
                        {
                            y_speed = -y_speed;
                        }
                    }
                    if (sfSprite_getPosition(ball).y > 640)
                    {
                        lives--;
                        if (lives == 0)
                        {

                            cur_level = 0;
                            game_start = false;
                            level_loaded = false;
                            level_load = true;
                            cl_first = false;
                            running = false;
                        }
                        else
                        {
                            //sfSprite_setPosition(ball,make_vec2(640/2,640-200));
                            sfSprite_setPosition(ball, make_vec2(sfSprite_getPosition(pad).x + (96 / 2) - 10, sfSprite_getPosition(pad).y - 30));
                            x_speed = b_speed;
                            y_speed = b_speed;
                            running = false;
                            start_count = 3;
                            start_ctr = 60;
                            ready = false;
                            game_start = false;
                        }
                    }
                    /* //Ball Border Check */

                    sfFloatRect ball_rect = sfSprite_getGlobalBounds(ball);
                    sfFloatRect *p_ball = &ball_rect;
                    sfFloatRect pad_rect = sfSprite_getGlobalBounds(pad);
                    sfFloatRect *pa_rect = &pad_rect;
                    if (sfFloatRect_intersects(p_ball, pa_rect, NULL) &&
                        sfSprite_getPosition(ball).y + 16 < sfSprite_getPosition(pad).y + 14)
                    {
                        if (y_speed > 0)
                        {
                            y_speed = -y_speed;
                        }
                        /* calc new x-speed */
                        // length of pad = 96
                        x_speed = (-b_speed + ((sfSprite_getPosition(ball).x - sfSprite_getPosition(pad).x) / 96) * (b_speed * 2));
                    }
                }
                else
                {
                    sfSprite_setPosition(ball, make_vec2(sfSprite_getPosition(pad).x + (96 / 2) - 10, sfSprite_getPosition(pad).y - 30));
                }

                if (start_count > 0)
                {
                    if (ready)
                    {
                        start_ctr--;
                        if (!start_ctr)
                        {
                            start_count--;
                            start_ctr = 60;
                            if (!start_count)
                            {
                                start_count = 3;
                                game_start = true;
                                running = true;
                                ready = false;
                            }
                        }
                    }
                }

                /* Clear */
                sfRenderWindow_clear(window, sfBlack);

                /* Background */
                sfRenderWindow_drawSprite(window, bg, NULL);

                /* Bricks */
                for (int i = 0; i < 10; i++)
                {
                    for (int j = 0; j < 7; j++)
                    {
                        sfRenderWindow_drawSprite(window, bricks[i][j]->sprite, NULL);
                    }
                }
                char frames[12] = {
                    0};
                sprintf(frames, "Points:  %d", points);
                sfRenderWindow_drawSprite(window, ball, NULL);
                sfRenderWindow_drawSprite(window, pad, NULL);
                if (!game_end)
                {
                    frame++;

                    sfText_setString(text_points, frames);
                    sfRenderWindow_drawText(window, text_points, NULL);

                    char xcombo[12] = {0};
                    sprintf(xcombo, "Combo: x%.2f", combo);
                    sfText_setString(text_combo, xcombo);
                    sfRenderWindow_drawText(window, text_combo, NULL);

                    sfRectangleShape_setSize(combo_rect, make_vec2((((combo_ctr / framerate) * 120) * 120) / 120, 10));
                    sfRenderWindow_drawRectangleShape(window, combo_rect, NULL);

                    char xlives[12] = {0};
                    sprintf(xlives, "Lives: %d", lives);
                    sfText_setString(text_lives, xlives);
                    sfRenderWindow_drawText(window, text_lives, NULL);

                    char xstart[12] = {0};
                    sprintf(xstart, "Start in %d", start_count);
                    sfText_setString(text_start, xstart);
                    if (start_count > 0 && ready)
                    {
                        sfRenderWindow_drawText(window, text_start, NULL);
                    }

                    if (start_count == 0)
                    {
                        /* draw explode effect */
                        sfRenderWindow_drawRectangleShape(window, xlvlbox, NULL);
                        sfRenderWindow_drawRectangleShape(window, ylvlbox, NULL);
                    }

                    char xbspeed[12] = {0};
                    sprintf(xbspeed, "Enter to Start\nSpeed:<- x%.2f ->", b_speed);
                    sfText_setString(text_bspeed, xbspeed);
                    sfText_setScale(text_combo, make_Dvec2(1 + (font_ctr / 20), 1 + (font_ctr / 20)));
                    if (!speed_set)
                    {
                        sfRenderWindow_drawText(window, text_bspeed, NULL);
                    }
                }
                else
                {
                    sfRenderWindow_drawText(window, text_gameover, NULL);
                    sfText_setPosition(text_points, make_vec2(270, 380));
                    if (cur_level == 9)
                    {
                        strcat(frames, "\nAll Levels Completed!");
                    }
                    sfText_setString(text_points, frames);
                    sfRenderWindow_drawText(window, text_points, NULL);
                }
                /* Display */
                sfRenderWindow_display(window);
                break;
            }
        } //State

    } //While

    /* CLEANUP */
    free(texres);
    sfSprite_destroy(pad);
    sfSprite_destroy(ball);
    sfSprite_destroy(bg);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            free(bricks[i][j]);
        }
    }

    sfFont_destroy(font);
    sfText_destroy(text_points);
    sfText_destroy(text_combo);
    sfText_destroy(text_lives);
    sfRectangleShape_destroy(combo_rect);

    sfRenderWindow_destroy(window);

    return 0;
}
