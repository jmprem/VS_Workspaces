#include <iostream>
#include <GL/glew.h>
#include "Display.h"

using namespace std;

int main(int argc, char **argv)
{
	Display display(800, 600, "Hello World!");

	while (!display.IsClosed())
	{
		glClearColor(0.0f, 0.15f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		display.Update();
	}

//	cout << "Hello World!";
//	cin.ignore();
//	cin.get();

	return 0;
}