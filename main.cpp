/*
			Marble Engine Source Code 
			
			Version 1.0
			
			Written by Rose Hughes
*/

#include <SDL2/SDL.h>

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
			
			MainWindow = SDL_CreateWindow("Marble Engine 1.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
			640, 480 , SDL_WINDOW_SHOWN);
			
			MainRenderer = SDL_CreateRenderer(MainWindow, -1 ,SDL_RENDERER_ACCELERATED);
			
			

			
			if(MainWindow == NULL){
				std::cout << SDL_GetError() << std::endl;
			}
		}
	}
 
int SDL_Manager::RenderFrame(bool Switch)
{
		if(Switch == true)
		{
					
					SDL_RenderDrawPoints(MainRenderer,&TestPointStructure, 1);
					SDL_RenderPresent(MainRenderer);
					SDL_RenderClear(MainRenderer);
			}
}
int main(int argc, char **)
{
	SDL_Manager.SetupWindow(true);
	
	while(Running == true)
	{	
		for(int x = 0 ; x<=100; x++)
		{
			for(int y = 0 ; y<=100; y++)
			{
				TestPointStructure={
						x,y 
					};
			}
		}
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
					case SDL_QUIT:
					SDL_DestroyRenderer(MainRenderer);
					SDL_DestroyWindow(MainWindow);
					Running = false;
					return 0;
					break;
				}
		}
				SDL_Manager.RenderFrame(true);
	}
}
