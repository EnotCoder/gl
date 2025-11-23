#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>

using namespace std;

int main(){
	
	glfwInit();

	GLFWwindow* window = glfwCreateWindow(800,800,"enotic_game",nullptr,nullptr);
	
	glfwMakeContextCurrent(window);

	if (!gladLoadGL()){
		cout << "error glad";
		return -1;
	}

	while (!glfwWindowShouldClose(window)){
		glClearColor(1,1,1,1);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;	

}
