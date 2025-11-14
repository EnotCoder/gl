#include <GLFW/glfw3.h>
#include <iostream>

GLfloat vert[4][3] = {
    {0.1,0.1,0},
    {0.1,-0.1,0},
    {-0.1,-0.1,0},
    {-0.1,0.1,0}
};

int main() {
    if (!glfwInit()) {
        std::cerr << "Ошибка инициализации GLFW" << std::endl;
        return -1;
    }

    // Создаем окно 800x600 с заголовком "Тест GLFW"
    GLFWwindow* window = glfwCreateWindow(800, 800, "Тест GLFW", nullptr, nullptr);
    if (!window) {
        std::cerr << "Ошибка создания окна" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Главный цикл приложения
    while (!glfwWindowShouldClose(window)) {
        // Очистка экрана с цветом (черный)
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_QUADS);
        glColor3f(1,0,0);
        glVertex3fv(vert[0]);
        glColor3f(0,1,0);
        glVertex3fv(vert[1]);
        glColor3f(0,0,1);
        glVertex3fv(vert[2]);
        glColor3f(1,1,1);
        glVertex3fv(vert[3]);
        glEnd();
        // Обработка событий
        glfwPollEvents();

        // Обновление содержимого окна
        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
