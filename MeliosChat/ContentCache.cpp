#include "ContentCache.h"
#include "TextureLoader.h"
#include "MapUtilities.h"
#include "FontLoader.h"

namespace MeliosChat
{
	ContentCache::FontCache ContentCache::fontCache;
	ContentCache::TextureCache ContentCache::textureCache;

	const SpriteFont& ContentCache::GetFont(const std::string& name, const bool useKerning)
	{
		const auto i = fontCache.find(name);

		if (i != fontCache.end())
		{
			return i->second;
		}

		return MapUtilities::Add(fontCache, name, FontLoader::Load(name, useKerning));
	}

	const Texture2D& ContentCache::GetTexture(const std::string& filename, const std::string& folder)
	{
		const auto i = textureCache.find(filename);

		if (i != textureCache.end())
		{
			return i->second;
		}

		return MapUtilities::Add(textureCache, filename, TextureLoader::Load(filename, folder));
	}
}
