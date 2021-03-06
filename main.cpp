#include "stdafx.h"
#include "Window.h"
#include <iostream>



int main()
{
	WAEngine::Graphics::Window window("WAEngine",1080,720);
	while (!window.IsClosed()) {
		window.Clear();
		glBegin(GL_TRIANGLES);
		glVertex2f(-.5f, -0.5f);
		glVertex2f(0.f, 0.5f);
		glVertex2f(.5f, -0.5f);
		glEnd();
		window.Update();
	}

    return 0;
}

