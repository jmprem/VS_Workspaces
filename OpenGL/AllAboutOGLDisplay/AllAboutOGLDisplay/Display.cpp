#include <iostream>

#include "Display.h"
#include <GL/glew.h>

using namespace std;

Display::Display(int width, int height, const std::string& title)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	//Need some additional parameters in addition to SDL_CreateWindow.
	//Sets the number of bits used to store the Red/Green/Blue/Alpha(transparency) value corresponding to a pixel
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	//Set the total data in bits that SDL will allocate per pixel. This is 8*4 = 32 for RGBA
	//This says, SDL will ATLEAST allocate this many bits and it may or may not be exactly that many bits.
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	//Allocate space for 2 windows. (But we actually create only 1. The second one will not be displayed. More info later.)
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	//SDL has to know that it will not be using SDL to draw on window but would use OpenGL. So the last parameter of
	//CreateWindow would specify this as a flag
	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	m_glContext = SDL_GL_CreateContext(m_window);

	//glewInit is going to find all the supported OpenGL capabilities in the OS/Machine it is run and initialize it for 
	//further usage.
	GLenum status = glewInit();
	if (status != GLEW_OK)
	{
		cerr << "Glew failed to inialize!" << endl;
	}

	m_isClosed = false;
}


Display::~Display()
{
	//Do things in reverse order to what was done in the constructor
	SDL_GL_DeleteContext(m_glContext);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void Display::Update()
{
	SDL_GL_SwapWindow(m_window);

	//OS is going to keep sending events and if it isn't handled, it will think app is not responsive and would crash the
	//application. So, events need to be handled.
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
			m_isClosed = true;
	}
}

void Display::Clear(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT);
}

bool Display::IsClosed()
{
	return m_isClosed;
}