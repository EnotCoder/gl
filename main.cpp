#define GLFW_INCLUDE_NONE
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <math.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;

GLfloat vert[8][3] = {
    { 0.1f,  0.1f,  0.1f},  // 0 - передний верхний правый
    { 0.1f, -0.1f,  0.1f},  // 1 - передний нижний правый
    {-0.1f, -0.1f,  0.1f},  // 2 - передний нижний левый
    {-0.1f,  0.1f,  0.1f},  // 3 - передний верхний левый
    { 0.1f,  0.1f, -0.1f},  // 4 - задний верхний правый
    { 0.1f, -0.1f, -0.1f},  // 5 - задний нижний правый
    {-0.1f, -0.1f, -0.1f},  // 6 - задний нижний левый
    {-0.1f,  0.1f, -0.1f}   // 7 - задний верхний левый
};

// Индексы для 12 треугольников куба (6 граней по 2 треугольника)
GLuint indices[] = {
    0, 1, 2,  2, 3, 0,  // передняя грань
    4, 5, 6,  6, 7, 4,  // задняя грань
    0, 4, 7,  7, 3, 0,  // верхняя грань
    1, 5, 6,  6, 2, 1,  // нижняя грань
    0, 1, 5,  5, 4, 0,  // правая грань
    3, 2, 6,  6, 7, 3   // левая грань
};


int main(){
	
	glfwInit();

	GLFWwindow* window = glfwCreateWindow(800,800,"enotic_game",nullptr,nullptr);
	
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cerr << "Не удалось инициализировать GLEW" << std::endl;
		return -1;
	}

	GLuint VAO;
	glGenVertexArrays(1,&VAO);
	glBindVertexArray(VAO);
	
	GLuint VBO;
	glGenBuffers(1,&VBO);
	glBindBuffer(GL_ARRAY_BUFFER,VBO);
	glBufferData(GL_ARRAY_BUFFER,sizeof(vert),vert,GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);	

	GLuint EBO;
	glGenBuffers(1,&EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices),indices,GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER,0);
	glBindVertexArray(0);


	while (!glfwWindowShouldClose(window)){
		glEnable(GL_DEPTH_TEST);
		glClearColor(0,0,0,1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glRotatef(45,1,1,1);

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, sizeof(indices), GL_UNSIGNED_INT,0);
		glBindVertexArray(0);

	
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;	

}
