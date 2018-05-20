#pragma once
#include "Texture2D.h"
#include <string>
#include "Paths.h"

namespace MeliosChat
{
	class TextureLoader
	{
	public:

		static Texture2D Load(const std::string& filename, const std::string& folder = Paths::Textures);
	};
}
