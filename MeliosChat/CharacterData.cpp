#include "CharacterData.h"

namespace MeliosChat
{
	CharacterData::CharacterData(const int id, const Rectangle& source, const glm::ivec2& offset, const int advance) :
		source(source),
		offset(offset),
		id(id),
		advance(advance)
	{
	}

	const Rectangle& CharacterData::Source() const
	{
		return source;
	}

	const glm::ivec2& CharacterData::Offset() const
	{
		return offset;
	}

	int CharacterData::Id() const
	{
		return id;
	}

	int CharacterData::Advance() const
	{
		return advance;
	}
}
