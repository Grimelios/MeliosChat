#include "ChatWindow.h"

namespace MeliosChat
{
	ChatWindow::ChatWindow(const int width, const int height)
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		window = glfwCreateWindow(width, height, "MeliosChat", nullptr, nullptr);

		if (window == nullptr)
		{
			glfwTerminate();

			return;
		}

		glfwMakeContextCurrent(window);
		glfwSetWindowUserPointer(window, this);

		if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
		{
			glfwTerminate();

			return;
		}

		glEnable(GL_DEPTH_TEST);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glViewport(0, 0, width, height);
	}

	void ChatWindow::Update(const float dt)
	{
	}

	void ChatWindow::Draw()
	{
	}

	void ChatWindow::Run()
	{
		while (!glfwWindowShouldClose(window))
		{
			const float time = static_cast<float>(glfwGetTime());
			const float target = 1.0f / TargetFramerate;

			// Using an accumulator helps limit FPS to the desired target.
			accumulator += time - previousTime;
			previousTime = time;

			const bool shouldUpdate = accumulator >= target;

			if (shouldUpdate)
			{
				glfwPollEvents();

				while (accumulator >= target)
				{
					Update(target);
					accumulator -= target;
				}

				Draw();

				glfwSwapBuffers(window);
			}
		}

		glfwTerminate();
	}
}
