#pragma once
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

namespace MeliosChat
{
	class Component2D
	{
	protected:

		glm::ivec2 origin = glm::ivec2(0);

	public:

		glm::vec2 position = glm::vec2(0);
		glm::vec3 color = glm::vec3(1);

		float rotation = 0;
	};
}
