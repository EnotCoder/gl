#define GLFW_INCLUDE_NONE
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <math.h>


int main(){
	
	glfwInit();

	GLFWwindow* window = glfwCreateWindow(800,800,"enotic_game",nullptr,nullptr);
	
	glfwMakeContextCurrent(window);

	while (!glfwWindowShouldClose(window)){

		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;	

}
