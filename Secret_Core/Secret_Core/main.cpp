#include <iostream>
#include <GLFW/glfw3.h>
#include "src/graphics/window.h"

int main() 
{
	using namespace Secret;
	using namespace graphics;

	window SecretWindow("Secret!", 800, 600);
	glClearColor(1, 0, 0, 1);
	while (!SecretWindow.closed())
	{
		SecretWindow.clear();
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
		SecretWindow.update();
	}
	return 0;

}