#include "FontLoader.h"
#include <fstream>
#include "Paths.h"
#include "FileUtilities.h"
#include "StringUtilities.h"
#include <optional>
#include "ContentCache.h"

namespace MeliosChat
{
	SpriteFont FontLoader::Load(const std::string& name, const bool useKerning)
	{
		const Texture2D& texture = ContentCache::GetTexture(name + "_0.png", Paths::Fonts);

		// See https://stackoverflow.com/questions/7868936/read-file-line-by-line.
		std::ifstream stream(Paths::Fonts + name + ".fnt");
		std::string line;

		// The first line contains the font size.
		std::getline(stream, line);

		const int index1 = StringUtilities::IndexOf(line, "size") + 5;
		const int index2 = StringUtilities::IndexOf(line, ' ', index1);
		const int size = std::stoi(line.substr(index1, index2 - index1));

		// The next four lines are useless. Although the font file does list its character count, that doesn't
		// correspond to the actual highest character ID.
		FileUtilities::SkipLines(stream, 3);

		// This line should look like "chars count=X".
		const int charCount = std::stoi(line.substr(12));

		// This list contains the data parsed from the input file. There will be a second list later sized to the
		// maximum character ID.
		std::vector<CharacterData> rawList;
		rawList.reserve(charCount);

		for (int i = 0; i < charCount; i++)
		{
			std::getline(stream, line);

			std::vector<std::string> tokens = StringUtilities::Split(line, ' ', true);

			const int id = ParseValue(tokens[1]);
			const int x = ParseValue(tokens[2]);
			const int y = ParseValue(tokens[3]);
			const int width = ParseValue(tokens[4]);
			const int height = ParseValue(tokens[5]);
			const int offsetX = ParseValue(tokens[6]);
			const int offsetY = ParseValue(tokens[7]);
			const int advance = ParseValue(tokens[8]);

			const Rectangle source(x, y, width, height);
			const glm::ivec2 offset(offsetX, offsetY);

			rawList.emplace_back(id, source, offset, advance);
		}

		// The + 1 is required to make the last element fit.
		const int maximumId = rawList[charCount - 1].Id() + 1;

		std::vector<std::optional<CharacterData>> fullList;
		fullList.reserve(maximumId);

		for (int i = 0; i < maximumId; i++)
		{
			fullList.emplace_back(std::nullopt);
		}

		for (const CharacterData& data : rawList)
		{
			fullList[data.Id()] = data;
		}

		return SpriteFont(texture, size, fullList);
	}
	int FontLoader::ParseValue(const std::string& s)
	{
		const int index = StringUtilities::IndexOf(s, '=') + 1;

		return std::stoi(s.substr(index));
	}
}
