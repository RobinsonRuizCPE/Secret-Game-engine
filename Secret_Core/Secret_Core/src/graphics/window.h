#pragma once
#include <GLFW/glfw3.h>
namespace Secret {
	namespace graphics {
		void windowResize(GLFWwindow *window, int width, int height);
		class window
		{
		private:
			const char *_name;
			int _width; int _height;
			GLFWwindow	*_glfWindow;

			bool init();
			


		public:
			window(const char *name, int width, int height);
			~window();

			void update();
			bool closed() const;
			void clear() const;

			inline int getWidth() const { return _width; }
			inline int getHeight() const { return _height; }
		};
} }
