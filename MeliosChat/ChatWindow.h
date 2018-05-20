#pragma once
#include <glad.h>
#include <glfw3.h>

namespace MeliosChat
{
	class ChatWindow
	{
	private:

		static const int TargetFramerate = 60;

		GLFWwindow* window;

		float previousTime = 0;
		float accumulator = 0;

		void Update(float dt);
		void Draw();

	public:

		ChatWindow(int width, int height);

		void Run();
	};
}
