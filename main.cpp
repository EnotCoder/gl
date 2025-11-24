#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>
#include <renderer/ShaderProgram.h>

using namespace std;


float vert[] = {
    // позиции       // цвета
     0.0f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,
     0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f
};

const char* vert_sh = R"(#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;

out vec3 ourColor;

void main()
{
    gl_Position = vec4(aPos, 1.0);
    ourColor = aColor;
}
)";

const char* frag_sh = R"(#version 330 core
in vec3 ourColor;
out vec4 FragColor;

void main()
{
    FragColor = vec4(ourColor, 1.0);
}
)";
   
int main(){
	
	if (!glfwInit()){
		cout << "error glfw";
		return -1;
	}


	GLFWwindow* window = glfwCreateWindow(800,800,"enotic_game",nullptr,nullptr);
	
	glfwMakeContextCurrent(window);//Указываем текущее окно

	if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
		std::cerr << "Failed to initialize GLAD" << std::endl;
		return -1;
	}


	
	string vertexShader(vert_sh);
	string fragmentShader(frag_sh);
	rend::ShaderProgram shaderProgram(vertexShader,fragmentShader);
	if (!shaderProgram.isCompiled())
	{
		cerr << "error" << endl;
	};

    // Создаем Vertex Array Object и Vertex Buffer Object
    GLuint vao, vbo;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    // Активируем VAO
    glBindVertexArray(vao);

    // Активируем VBO и загружаем данные
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vert), vert, GL_STATIC_DRAW);

    // Позиция атрибута (location = 0)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Цвет атрибута (location = 1)
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

	while (!glfwWindowShouldClose(window)){
		glClearColor(0,0,0,1);
		glClear(GL_COLOR_BUFFER_BIT);

		shaderProgram.use();
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);//Буферы
		glfwPollEvents();//Обновление кадра
	}

	// Очистка ресурсов
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);

	glfwDestroyWindow(window);//Удаление окна
	glfwTerminate(); //Выход из программы

	return 0;	

}
