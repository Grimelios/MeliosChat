#include "TextureLoader.h"
#include <vector>
#include <lodepng.h>

namespace MeliosChat
{
	Texture2D TextureLoader::Load(const std::string& filename, const std::string& folder)
	{
		GLuint textureId;

		std::vector<unsigned char> buffer;

		unsigned int width;
		unsigned int height;

		lodepng::decode(buffer, width, height, folder + filename);

		glGenTextures(1, &textureId);
		glBindTexture(GL_TEXTURE_2D, textureId);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &buffer[0]);
		glGenerateMipmap(GL_TEXTURE_2D);

		return Texture2D(width, height, textureId);
	}
}
