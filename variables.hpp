#include <SDL2/SDL.h>
#include <GL/gl.h>
#ifndef _VARIABLES_HPP 
#define _VARIABLES_HPP
		
		bool 
		Running = true;
		
		SDL_Window  *MainWindow;
		SDL_Renderer *MainRenderer;
		SDL_GLContext MainContext;
		
		SDL_Event event;
		
		GLuint VertexArrayID;
		GLuint VertexBuffer;
		
		static const GLfloat gl_vertex_buffer_data[] = {
		-1.0f , -1.0f , 0.0f,
		 1.0f, -1.0f , 0.0f,
		 0.0f , 1.0f, 0.0f,
		};
		
#endif