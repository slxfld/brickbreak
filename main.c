#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include "tex_res.c"

/**
 *
 *  Copyright 2018 by Simon Lixenfeld
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
**/

sfVector2f make_vec2(int _x,int _y){
  sfVector2f vec2 = {_x,_y};
  return vec2;
}

sfVector2f make_Dvec2(double _x,double _y){
  sfVector2f vec2 = {_x,_y};
  return vec2;
}


void load_level(int num[10][7],textures* texres,brick* bricks[12][12]){

	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 7; j++)
		{
			  bricks[i][j]=malloc(sizeof(bricks[i][j]));
		}
	}
		
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 7; j++)
		{
			  bricks[i][j]=malloc(sizeof(bricks[i][j]));
			  bricks[i][j]->sprite = sfSprite_create();
			
			switch(num[i][j])
			{
				case 0:
				  bricks[i][j]->worth = 0; 
				  sfSprite_setTexture(bricks[i][j]->sprite,texres->BRICK_1_GR1_tex,sfTrue);
				  bricks[i][j]->hit = true;
				break;
				case 1: 
				  bricks[i][j]->worth = 100; 
				  sfSprite_setTexture(bricks[i][j]->sprite,texres->BRICK_1_G1_tex,sfTrue);
				break;
				case 2:  
				  bricks[i][j]->worth = 200; 
				  sfSprite_setTexture(bricks[i][j]->sprite,texres->BRICK_1_B1_tex,sfTrue);
				break;
				case 3:  
				  bricks[i][j]->worth = 300; 
				  sfSprite_setTexture(bricks[i][j]->sprite,texres->BRICK_1_O1_tex,sfTrue);
				break;
				case 4:  
				  bricks[i][j]->worth = 400; 
				  sfSprite_setTexture(bricks[i][j]->sprite,texres->BRICK_1_R1_tex,sfTrue);
				break;
				case 5:  
				  bricks[i][j]->worth = 500; 
				  sfSprite_setTexture(bricks[i][j]->sprite,texres->BRICK_1_V1_tex,sfTrue);
				break;
				case 6:  
				  bricks[i][j]->worth = 600; 
				  sfSprite_setTexture(bricks[i][j]->sprite,texres->BRICK_1_Y1_tex,sfTrue);
				break;
				case 7:  
				bricks[i][j]->worth = 0; 
				sfSprite_setTexture(bricks[i][j]->sprite,texres->BRICK_1_GR1_tex,sfTrue);
				bricks[i][j]->hit = true;				
				break;
				
			}
				sfSprite_setScale(bricks[i][j]->sprite,make_Dvec2(1,1.17));
				if(!num[i][j]){
				sfSprite_setPosition(bricks[i][j]->sprite,make_vec2(-500,0));
				}else{
				sfVector2f vec2 = {30+j*82,20+i*30};
				sfSprite_setPosition(bricks[i][j]->sprite,vec2);
				}
		}
	}
}

int main(int argc, char* argv[]){
	  
	  
	int level_0[10][7] = 
		  {
			{0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0}
		
		  };
		  
	int level_1[10][7] = 
		  {
			{0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0},
			{0,2,2,2,2,2,0},
			{0,1,1,1,1,1,0},
			{0,0,0,0,0,0,0},
			{0,1,1,1,1,1,0},
			{0,2,2,2,2,2,0},
			{0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0}
		
		  };

		  
	int level_2[10][7] = 
		  {
			{1,1,4,1,4,1,1},
			{1,4,1,4,1,4,1},
			{0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0},
			{3,2,0,0,0,2,3},
			{1,2,0,0,0,2,1},
			{0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0},
			{1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1}
		
		  };
	int level_3[10][7] = 
		  {
			{1,1,1,1,1,1,1},
			{1,1,5,0,5,1,1},
			{1,5,0,0,0,5,1},
			{1,5,0,6,0,5,1},
			{1,1,0,6,0,1,1},
			{1,0,3,6,3,0,1},
			{0,0,6,6,6,0,0},
			{0,3,0,1,0,3,0},
			{0,2,0,1,0,2,0},
			{0,3,0,1,0,3,0}

		  };	  
	int level_4[10][7] = 
		  {
			{0,0,0,0,0,0,0},
			{3,4,3,4,3,4,3},
			{0,2,2,0,2,2,0},
			{0,0,0,0,0,0,0},
			{0,1,1,5,1,1,0},
			{0,1,1,1,1,1,0},
			{0,1,1,2,0,0,0},
			{0,1,1,2,2,2,0},
			{0,0,0,1,1,1,0},
			{0,0,0,1,1,1,0}

		  };
	int level_5[10][7] = 
		  {
			{0,0,0,0,0,0,0},
			{0,1,1,1,1,1,0},
			{0,1,2,2,2,1,0},
			{0,1,3,6,3,1,0},
			{0,1,4,6,4,1,0},
			{0,1,4,6,4,1,0},
			{0,1,3,6,3,1,0},
			{0,1,2,2,2,1,0},
			{0,1,1,1,1,1,0},
			{0,7,0,7,0,7,0}

		  };
	  
		  
  int points = 0;
  int combo_ctr= 0;
  int combo= 0;
  
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
  bool game_start = false;
  bool game_end = false;
  //Resources
  textures* texres = malloc(sizeof(*texres));

  texres->BRICK_1_G1_tex =  sfTexture_createFromFile("./png/brick01g1.png", NULL);
  texres->BRICK_1_B1_tex =  sfTexture_createFromFile("./png/brick01b1.png", NULL);
  texres->BRICK_1_GR1_tex = sfTexture_createFromFile("./png/brick01gr1.png", NULL);
  texres->BRICK_1_O1_tex =  sfTexture_createFromFile("./png/brick01o1.png", NULL);
  texres->BRICK_1_R1_tex =  sfTexture_createFromFile("./png/brick01r1.png", NULL);
  texres->BRICK_1_V1_tex =  sfTexture_createFromFile("./png/brick01v1.png", NULL);
  texres->BRICK_1_Y1_tex =  sfTexture_createFromFile("./png/brick01y1.png", NULL);
  texres->BACKGROUND =  sfTexture_createFromFile("./png/bg.png", NULL);
  texres->BALL =  sfTexture_createFromFile("./png/ball.png", NULL);
  texres->PAD =  sfTexture_createFromFile("./png/pad.png", NULL);
  
  sfSprite* pad = sfSprite_create();
  sfSprite_setTexture(pad,texres->PAD,sfTrue);
  sfSprite_setPosition(pad,make_vec2(-40+640/2,640-50));
  
  bool KEY_LEFT = false;
  bool KEY_RIGHT = false;
  
  bool L_KEY_LEFT = false;
  bool L_KEY_RIGHT = false;
	
  sfSprite* ball = sfSprite_create();
  sfSprite_setTexture(ball,texres->BALL,sfTrue);
  sfVector2f vec2 = {640/2,640-200};
  sfSprite_setPosition(ball,vec2);
  
  sfSprite* bg = sfSprite_create();
  sfSprite_setTexture(bg,texres->BACKGROUND,sfTrue);
  
  brick* bricks[12][12];
  load_level(level_1,texres,bricks);

  sfFont* font = sfFont_createFromFile("font.ttf");
  
  sfText* text_points = sfText_create();
  sfText_setFont(text_points,font);
  sfText_setCharacterSize(text_points,24);
  
  sfText* text_combo = sfText_create();
  sfText_setFont(text_combo,font);
  sfText_setCharacterSize(text_combo,24);
  sfText_setPosition(text_combo,make_vec2(0,24));
  
  sfRectangleShape* combo_rect = sfRectangleShape_create();
  sfRectangleShape_setPosition(combo_rect,make_vec2(0,60));
  sfRectangleShape_setSize(combo_rect,make_vec2(10,10));
  
  sfText* text_start = sfText_create();
  sfText_setFont(text_start,font);
  sfText_setCharacterSize(text_start,32);
  sfText_setPosition(text_start,make_vec2(245,320));
   
  sfText* text_lives = sfText_create();
  sfText_setFont(text_lives,font);
  sfText_setCharacterSize(text_lives,24);
  sfText_setPosition(text_lives,make_vec2(500,0));
   
  sfText* text_bspeed = sfText_create();
  sfText_setFont(text_bspeed,font);
  sfText_setCharacterSize(text_bspeed,32);
  sfText_setPosition(text_bspeed,make_vec2(210,320));
    
  sfText* text_gameover = sfText_create();
  sfText_setFont(text_gameover,font);
  sfText_setCharacterSize(text_gameover,32);
  sfText_setPosition(text_gameover,make_vec2(270,320));
  sfText_setString(text_gameover,"Gameover");
  
  sfText* textc = sfText_create();
  sfText_setFont(textc,font);
  sfText_setCharacterSize(textc,16);
  sfText_setPosition(textc,make_vec2(0,620));
  sfText_setString(textc,"(C)Simon Lixenfeld 2018");
  
  
  sfVideoMode mode = {640, 640, 32};
  sfRenderWindow* window;    
  sfEvent event;
  window = sfRenderWindow_create(mode, "BrickBreak", sfResize | sfClose, NULL);
	
    if (!window)
	{
		printf("Could not initialise Window\n");
        return 1;
    }

	sfRenderWindow_setFramerateLimit(window,60);
	
  typedef enum {
    MENU,
    GAME
  } STATES;
	STATES state = GAME;

    while (sfRenderWindow_isOpen(window))
    {
        while (sfRenderWindow_pollEvent(window, &event))
        {

            if (event.type == sfEvtClosed){
                sfRenderWindow_close(window);
				return 0;
			}
			
			if(sfKeyboard_isKeyPressed(sfKeyA))
			{
				KEY_LEFT = true;
				if(!L_KEY_LEFT&&!game_start){
					L_KEY_LEFT=true;
					b_speed-=0.5;
					x_speed=b_speed;
					y_speed=b_speed;
				}
			}
			else
			{
				KEY_LEFT = false;
				L_KEY_LEFT=false;
			}
			
			if(sfKeyboard_isKeyPressed(sfKeyD))
			{
				KEY_RIGHT = true;
				if(!L_KEY_RIGHT&&!game_start){
					L_KEY_RIGHT=true;
					b_speed+=0.5;
					x_speed=b_speed;
					y_speed=b_speed;
					
				}
			}
			else
			{
				KEY_RIGHT = false;
				L_KEY_RIGHT=false;
			}
			
			if(sfKeyboard_isKeyPressed(sfKeySpace)&&!game_end){
				ready = true;
				if(!game_start){
					game_start=true;
				}
			}
        }

		
		
		
	switch(state)
{
	case MENU:
	
	break;
	
	case GAME:
			
		if(game_start){
			if(KEY_LEFT)
			{
				if(sfSprite_getPosition(pad).x>0)
				{
					sfSprite_move(pad, make_vec2(-6,0));
				}
			}
			
			if(KEY_RIGHT)
			{
				if(sfSprite_getPosition(pad).x+96<640)
				{
					sfSprite_move(pad, make_vec2(6,0));
				}
			}
		}
			/* UPDATE */
		
		if(running&&!game_end){
		
		/* End Ball->Bricks Collision Check */
		/* BallPosition Next X */	
		
		sfVector2f vec2 = {};
		sfVector2f l_vec2 = {};
		
		 l_vec2 = make_vec2(sfSprite_getPosition(ball).x,sfSprite_getPosition(ball).y);
		
		sfSprite_move(ball,make_Dvec2(x_speed,0));

		for(int i = 0; i < 10;i++){
			for(int j = 0; j < 7; j++){
			
			 sfFloatRect ball_rect = sfSprite_getGlobalBounds(ball);
			 sfFloatRect* p_ball = &ball_rect;
			 sfFloatRect brick_rect = sfSprite_getGlobalBounds(bricks[i][j]->sprite);
			 sfFloatRect* b_rect = &brick_rect;
			 
			 if(sfFloatRect_intersects(p_ball,b_rect,NULL))
			 {
			 
			 	sfSprite_setPosition(ball,l_vec2);
				x_speed = -x_speed;
			    if(bricks[i][j]->worth>0){
				sfSprite_setPosition(bricks[i][j]->sprite,make_vec2(0,-200));
					combo++;
					combo_ctr=120*2;
					points+=(bricks[i][j]->worth*combo);
					bricks[i][j]->hit = true;
					/* Check Level Complete */
					bool levelcom = true;
					for(int i = 0; i < 10;i++){
						for(int j = 0; j < 7; j++){
						if(!bricks[i][j]->hit){levelcom=false;}
						}
					}
					if(levelcom){
						/* Level switch */
						sfSprite_setPosition(ball,make_vec2(640/2,640-200));
						running = false;
						start_count=3;
						start_ctr = 60;
						switch(cur_level)
						{
						  case 1: 
							load_level(level_2,texres,bricks);
						  break;
						  case 2: 
							load_level(level_3,texres,bricks);
						  break;
						  case 3: 
							load_level(level_4,texres,bricks);
						  break;
						  case 4: 
							load_level(level_5,texres,bricks);
						  break;
						}
						cur_level++;
					}
				}
			 }
			  
		  }
		}
			
		/* BallPosition Next Y */	
		 l_vec2 = make_vec2(sfSprite_getPosition(ball).x,sfSprite_getPosition(ball).y);
		
		sfSprite_move(ball,make_Dvec2(0,y_speed));

		for(int i = 0; i < 10;i++){
			for(int j = 0; j < 7; j++){
			
			 sfFloatRect ball_rect = sfSprite_getGlobalBounds(ball);
			 sfFloatRect* p_ball = &ball_rect;
			 sfFloatRect brick_rect = sfSprite_getGlobalBounds(bricks[i][j]->sprite);
			 sfFloatRect* b_rect = &brick_rect;
			 
			 if(sfFloatRect_intersects(p_ball,b_rect,NULL))
			 {
			 
			 	sfSprite_setPosition(ball,l_vec2);
				y_speed = -y_speed;
			    if(bricks[i][j]->worth>0){
				sfSprite_setPosition(bricks[i][j]->sprite,make_vec2(0,-200));
					combo++;
					combo_ctr=120*2;
					points+=(bricks[i][j]->worth*combo);
					bricks[i][j]->hit = true;
					/* Check Level Complete */
					bool levelcom = true;
					for(int i = 0; i < 10;i++){
						for(int j = 0; j < 7; j++){
						if(!bricks[i][j]->hit){levelcom=false;}
						}
					}
					if(levelcom){
						/* Level switch */
						sfSprite_setPosition(ball,make_vec2(640/2,640-200));
						x_speed=b_speed;
						y_speed=b_speed;
						running = false;
						start_count=3;
						start_ctr = 60;
						switch(cur_level)
						{
						  case 1: 
							load_level(level_2,texres,bricks);
						  break;
						  case 2: 
							load_level(level_3,texres,bricks);
						  break;
						  case 3: 
							load_level(level_4,texres,bricks);
						  break;
						  case 4: 
							load_level(level_5,texres,bricks);
						  break;  
						}
						cur_level++;
					}
				}
			 }
			  
		  }
		}
		/* End Ball->Bricks Collision Check */

		/* combo count */
		if(combo>0){
		  combo_ctr--;
		  if(!combo_ctr){combo=0;}
		}
		

		
		/* Ball Border Check */
		if(sfSprite_getPosition(ball).x+16>640){
		  if(x_speed>0){x_speed=-x_speed;}
		}
		if(sfSprite_getPosition(ball).x<0){
		  if(x_speed<0){x_speed=-x_speed;}
		}
		if(sfSprite_getPosition(ball).y<0){
		  if(y_speed<0){y_speed=-y_speed;}
		}
		if(sfSprite_getPosition(ball).y>640){
			lives--;
			if(lives==0){ game_end=true; }
			else{
			sfSprite_setPosition(ball,make_vec2(640/2,640-200));
			x_speed=b_speed;
			y_speed=b_speed;
			running = false;
			start_count=3;
			start_ctr = 60;
			}
		}
		/* //Ball Border Check */
		
		
		sfFloatRect ball_rect = sfSprite_getGlobalBounds(ball);
		sfFloatRect* p_ball = &ball_rect;
		sfFloatRect pad_rect = sfSprite_getGlobalBounds(pad);
		sfFloatRect* pa_rect = &pad_rect;
		if(sfFloatRect_intersects(p_ball,pa_rect,NULL)&&
		   sfSprite_getPosition(ball).y+16<sfSprite_getPosition(pad).y+6) { 
			if(y_speed>0){y_speed=-y_speed;}
			/* calc new x-speed */
			// length of pad = 96
			x_speed = (-b_speed +((sfSprite_getPosition(ball).x-sfSprite_getPosition(pad).x)/96)*(b_speed*2) );
		}
		
		
		
		}
		
		if(start_count>0){
		  if(ready){
		  start_ctr--;
		  if(!start_ctr){start_count--; start_ctr=60; if(!start_count){ running=true; ready=false; } }
		  }
		}
		
		/* Clear */
		sfRenderWindow_clear(window,sfBlack);

		/* Background */ 
		sfRenderWindow_drawSprite(window,bg,NULL);
			
		/* Bricks */
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < 7; j++){
			sfRenderWindow_drawSprite(window,bricks[i][j]->sprite,NULL);
		  }
		}

		  sfRenderWindow_drawSprite(window,ball,NULL);
		  sfRenderWindow_drawSprite(window,pad,NULL);
if(!game_end){
		  frame++;
		  char frames[12] = {0};
		  sprintf(frames,"Points: %d",points);
		  sfText_setString(text_points,frames);
		  sfRenderWindow_drawText(window,text_points,NULL);
		  
		  char xcombo[12] = {0};
		  sprintf(xcombo,"Combo: x%d",combo);
		  sfText_setString(text_combo,xcombo);
		  sfRenderWindow_drawText(window,text_combo,NULL);
		  
		  sfRectangleShape_setSize(combo_rect,make_vec2(combo_ctr/2,10));
		  sfRenderWindow_drawRectangleShape(window,combo_rect,NULL);
		  
		  char xlives[12] = {0};
		  sprintf(xlives,"Lives: %d",lives);
		  sfText_setString(text_lives,xlives);
		  sfRenderWindow_drawText(window,text_lives,NULL);
		  
		  char xstart[12] = {0};
		  sprintf(xstart,"Start in %d",start_count);
		  sfText_setString(text_start,xstart);
		  if(start_count>0&&ready){
			sfRenderWindow_drawText(window,text_start,NULL);
		  }
		  
		  char xbspeed[12] = {0};
		  sprintf(xbspeed,"Speed:<- %.2f ->",b_speed);
		  sfText_setString(text_bspeed,xbspeed);
		  if(!game_start){
			sfRenderWindow_drawText(window,text_bspeed,NULL);
			sfRenderWindow_drawText(window,textc,NULL);
		  }
}
		  if(game_end){
			sfRenderWindow_drawText(window,text_gameover,NULL);
			sfText_setPosition(text_points,make_vec2(280,400));
		    sfRenderWindow_drawText(window,text_points,NULL);
		  }
		  /* Display */
		  sfRenderWindow_display(window);
	break;

}	
		
		
    }

	/* CLEANUP */
	free(texres);
	sfSprite_destroy(pad);
	sfSprite_destroy(ball);
	sfSprite_destroy(bg);
	for(int i = 0; i < 10;i++){
		for(int j = 0; j < 7; j++){
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




