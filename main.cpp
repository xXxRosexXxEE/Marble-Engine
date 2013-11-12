/*
			Marble Engine Source Code 
			
			Version 1.0
			
			Written by Rose Hughes
*/
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <math.h>
#include <iostream>

#include "Objects.hpp"
#include "variables.hpp"
#include "LillyGUI.hpp"
#include "LillyGUI.cpp"
#include "main.hpp"

int SDL_Manager::SwitchSDL(bool Switch)
{
	if(Switch == true)
		{
			if(SDL_Init(SDL_INIT_EVERYTHING) == -1){
				std::cout << SDL_GetError() << std::endl;
				return 1;
				}
			}
	}

int SDL_Manager::SetupWindow(bool Switch)
{
	if(Switch == true)
		{
			MainWindow = NULL;
			
			MainWindow = SDL_CreateWindow("Marble Engine 1.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480 , SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL );
			
			if(MainWindow == NULL){
				std::cout << SDL_GetError() << std::endl;
			}
	
				 SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
				 SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
				 
				 MainContext = SDL_GL_CreateContext(MainWindow);
				 
				 SDL_GL_SetSwapInterval(1);
				 glClearColor(0.0,0.0,1.0,1.0);
				 
				 glMatrixMode(GL_PROJECTION);
				 glOrtho(0.0, 1.0, 0.0, 1.0, -1.0 , 1.0);
				 glMatrixMode(GL_MODELVIEW);
				 glLoadIdentity();
		}
	}

int SDL_Manager::RenderFrame(bool Switch)
{
	  if(Switch == true)
		{
					glClear(GL_COLOR_BUFFER_BIT);
					
					glBegin(GL_QUADS);
					 glColor3f(1.0, 0.0 , 0.0);
					glVertex2f(0.0,1.0);
					 glColor3f(1.0, 1.0 , 0.0);
					glVertex2f(1.0,1.0);
					 glColor3f(1.0, 0.0 , 1.0);
					glVertex2f(1.0,0.0);
					 glColor3f(0.0, 0.0 , 1.0);
					glVertex2f(0.0,0.0);
					glEnd();
										
					SDL_GL_SwapWindow(MainWindow);
			}
	}

int main(int argc, char **)
{
	SDL_Manager.SetupWindow(true);
	
	while(Running == true)
	{	
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
					case SDL_QUIT:
					Running = false;
					return 0;
				}
		}
				SDL_Manager.RenderFrame(true);
	}
}
