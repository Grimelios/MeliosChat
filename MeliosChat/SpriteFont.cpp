#include "SpriteFont.h"

namespace MeliosChat
{
	SpriteFont::SpriteFont(const Texture2D& texture, const int size,
		const std::vector<std::optional<CharacterData>>& dataList) :

		texture(texture),
		dataList(std::move(dataList)),
		size(size)
	{
	}

	const Texture2D& SpriteFont::Texture() const
	{
		return texture;
	}

	const CharacterData& SpriteFont::Data(const char c) const
	{
		return dataList[c].value();
	}

	int SpriteFont::Size() const
	{
		return size;
	}
}
