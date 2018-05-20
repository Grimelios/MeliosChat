#pragma once
#include <map>
#include "Texture2D.h"
#include "Paths.h"
#include "SpriteFont.h"

namespace MeliosChat
{
	class ContentCache
	{
	private:

		using FontCache = std::map<std::string, SpriteFont>;
		using TextureCache = std::map<std::string, Texture2D>;

		static FontCache fontCache;
		static TextureCache textureCache;

	public:

		static const SpriteFont& GetFont(const std::string& name, bool useKerning);
		static const Texture2D& GetTexture(const std::string& filename, const std::string& folder = Paths::Textures);
	};
}
