#pragma once
#include <glad.h>

namespace MeliosChat
{
	class Texture2D
	{
	private:

		int width;
		int height;

		GLuint textureId;

	public:

		Texture2D(int width, int height, GLuint textureId);

		int Width() const;
		int Height() const;

		GLuint TextureId() const;
	};
}
