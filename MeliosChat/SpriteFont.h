#pragma once
#include "Texture2D.h"
#include <vector>
#include "CharacterData.h"
#include <optional>

namespace MeliosChat
{
	class SpriteFont
	{
	private:

		const Texture2D& texture;

		// Using std::optional allows characters to be indexed by ID (meaning that some entries will be empty).
		std::vector<std::optional<CharacterData>> dataList;

		int size;

	public:

		SpriteFont(const Texture2D& texture, int size, const std::vector<std::optional<CharacterData>>& dataList);

		const Texture2D& Texture() const;
		const CharacterData& Data(char c) const;

		int Size() const;
	};
}
