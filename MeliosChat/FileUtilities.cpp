#include "FileUtilities.h"

namespace MeliosChat
{
	void FileUtilities::SkipLine(std::ifstream& stream)
	{
		stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	void FileUtilities::SkipLines(std::ifstream& stream, const int count)
	{
		for (int i = 0; i < count; i++)
		{
			// See https://stackoverflow.com/questions/477408/ifstream-end-of-line-and-move-to-next-line.
			stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}
