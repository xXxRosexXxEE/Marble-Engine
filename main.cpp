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
#include "ShaderSystem.hpp"
#include "ShaderSystem.cpp"
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
			640, 480 , SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL );
			
			if(MainWindow == NULL){
				std::cout << SDL_GetError() << std::endl;
			}
	
				 SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
				 SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
				 
				 MainContext = SDL_GL_CreateContext(MainWindow);
				 
				 SDL_GL_SetSwapInterval(1);
				 glClearColor(0.0,0.0,1.0,1.0);
				
		}
	}
int SDL_Manager::SetupGL(bool Switch)
{
		glGenVertexArrays(1, &VertexArrayID);
		glBindVertexArray(VertexArrayID);
		glGenBuffers(1, &VertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(gl_vertex_buffer_data), gl_vertex_buffer_data, GL_STATIC_DRAW);
}

int SDL_Manager::RenderFrame(bool Switch)
{
	  if(Switch == true)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			
			glEnableVertexAttribArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);
			glVertexAttribPointer(
			0,
			3,
			GL_FLOAT,
			GL_FALSE,
			0,
			(void*)0
			);
			
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
