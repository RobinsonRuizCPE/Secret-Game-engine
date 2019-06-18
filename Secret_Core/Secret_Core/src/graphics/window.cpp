#include "window.h"
#include <iostream>
#include <GLFW/glfw3.h>

namespace Secret {
	namespace graphics {

		window::window(const char *name, int width, int height)
		{
			_name = name;
			_width = width;
			_height = height;
			if (!init()) {
				glfwTerminate();
			}
		}

		window::~window()
		{
			glfwTerminate(); 
		}


		void window::update()
		{	
			glfwPollEvents();
			//glfwGetFramebufferSize(_glfWindow, &_width, &_height);
			glfwSwapBuffers(_glfWindow);
			
		}

		bool window::init() 
		{
			if (!glfwInit())
			{
				std::cout << "error GLFW" << std::endl;
				return false;
			}
			_glfWindow = glfwCreateWindow(_width, _height,_name, NULL, NULL);
			if (!_glfWindow) 
			{
				glfwTerminate();
				return false;
			}
			glfwMakeContextCurrent(_glfWindow);
			glfwSetWindowSizeCallback(_glfWindow, windowResize);
			return true;
		}

		bool window::closed() const {
			return glfwWindowShouldClose(_glfWindow) ==1;
		}

		void window::clear() const {
			glClear(GL_COLOR_BUFFER_BIT);
			glClear(GL_DEPTH_BUFFER_BIT);
		}

		void windowResize(GLFWwindow *window, int width, int height)
		{
			glViewport(0, 0, width, height);

		}
	}
}