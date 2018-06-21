#include "stdafx.h"
#include "Window.h"

namespace WAEngine{
	namespace Graphics {

		void resize(GLFWwindow *, int, int);

		//Window Constructor
		Window::Window(const char* title, int width, int height) {
			WTitle = title;
			WWidth = width;
			WHeight = height;
			if (!init()) {
				glfwTerminate();
			}
		}

		//Initializes Window and sets Current Context
		bool Window::init() {
			if (!glfwInit()) {
				std::cout << "Could not initialize GLFW!" << std::endl;
				return false;
			}
			else {
				std::cout << "GLFW successfully initialized!" << std::endl;
			}

			WWindow = glfwCreateWindow(WWidth, WHeight, WTitle, NULL, NULL);

			if (!WWindow) {
				std::cout << "Failed to Create Window" << std::endl;
				return false;
			}

			glfwMakeContextCurrent(WWindow);
			glfwSwapInterval(1);
			glfwSetWindowSizeCallback(WWindow, resize);

			if (glewInit() != GLEW_OK) {
				std::cout << "Failed to initialize GLEW!"<<std::endl;
				return false;
			}
			else {
				std::cout << "GLEW successfully initialized!" << std::endl;
			}

			return true;
		}

		//Clears Window
		void Window::Clear() {
			glClear(GL_COLOR_BUFFER_BIT);
		}

		//Updates Window
		void Window::Update() {
			if (!IsClosed()) {
				//Window Update Loop
				glfwPollEvents();
				glfwSwapBuffers(WWindow);
			}
			else{
				glfwDestroyWindow(WWindow);
			}
		}

		//Checks if window is closed 
		bool Window::IsClosed() const {
			return glfwWindowShouldClose(WWindow);
		}

		//Window Destructor
		Window::~Window() {
			glfwTerminate();
		}

		//Resizes window
		void resize(GLFWwindow *window,int width,int height) {
			glViewport(0, 0, width, height);
		}

	}
}