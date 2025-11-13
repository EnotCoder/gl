#include <GLFW/glfw3.h>
#include <iostream>

int main() {
    if (!glfwInit()) {
        std::cerr << "Ошибка инициализации GLFW" << std::endl;
        return -1;
    }

    // Создаем окно 800x600 с заголовком "Тест GLFW"
    GLFWwindow* window = glfwCreateWindow(800, 600, "Тест GLFW", nullptr, nullptr);
    if (!window) {
        std::cerr << "Ошибка создания окна" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Главный цикл приложения
    while (!glfwWindowShouldClose(window)) {
        // Очистка экрана с цветом (черный)
        glClearColor(1.0f, 0.1f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Обработка событий
        glfwPollEvents();

        // Обновление содержимого окна
        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
