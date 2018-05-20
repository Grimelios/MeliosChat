#pragma once
#include "Rectangle.h"
#include <glm/vec2.hpp>

namespace MeliosChat
{
	class CharacterData
	{
	private:

		Rectangle source;
		glm::ivec2 offset;

		int id;
		int advance;

	public:

		CharacterData(int id, const Rectangle& source, const glm::ivec2& offset, int advance);

		const Rectangle& Source() const;
		const glm::ivec2& Offset() const;

		int Id() const;
		int Advance() const;
	};
}
