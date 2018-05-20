#pragma once
#include <fstream>

namespace MeliosChat::FileUtilities
{
	void SkipLine(std::ifstream& stream);
	void SkipLines(std::ifstream& stream, int count);
}
