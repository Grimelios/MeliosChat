#pragma once
#include <vector>
#include <string>

namespace MeliosChat::StringUtilities
{
	std::vector<std::string> Split(const std::string& s, char delimeter, bool removeEmpty);

	int IndexOf(const std::string& s, char c);
	int IndexOf(const std::string& s, char c, int start);
	int IndexOf(const std::string& s, const std::string& value);
}
