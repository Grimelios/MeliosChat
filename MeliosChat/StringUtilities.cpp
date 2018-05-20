#include "StringUtilities.h"
#include <sstream>

namespace MeliosChat
{
	std::vector<std::string> StringUtilities::Split(const std::string& s, const char delimeter, const bool removeEmpty)
	{
		std::stringstream stream(s);
		std::string token;
		std::vector<std::string> list;

		while (std::getline(stream, token, delimeter))
		{
			if (!removeEmpty || !token.empty())
			{
				list.push_back(std::move(token));
			}
		}

		return list;
	}

	int StringUtilities::IndexOf(const std::string& s, const char c)
	{
		return static_cast<int>(s.find(c));
	}

	int StringUtilities::IndexOf(const std::string& s, const char c, const int start)
	{
		return static_cast<int>(s.find(c, start));
	}

	int StringUtilities::IndexOf(const std::string& s, const std::string& value)
	{
		return static_cast<int>(s.find(value));
	}
}
