#pragma once
#include "SpriteFont.h"

namespace MeliosChat
{
	class FontLoader
	{
	private:

		static int ParseValue(const std::string& s);

	public:

		static SpriteFont Load(const std::string& name, bool useKerning);
	};
}
