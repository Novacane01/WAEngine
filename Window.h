#pragma once
#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include <iostream>

namespace WAEngine {
	namespace Graphics {
		class Window {
		private:
			int WWidth, WHeight;
			const char *WTitle;
			GLFWwindow *WWindow;
			bool Closed;
		public:
			Window(const char*, int, int);
			void Update();
			bool IsClosed() const;
			void Clear();
			~Window();
		private:
			bool init();
			
		};
	}
}