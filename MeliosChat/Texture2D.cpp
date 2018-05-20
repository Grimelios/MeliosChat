#include "Texture2D.h"

namespace MeliosChat
{
	Texture2D::Texture2D(const int width, const int height, const GLuint textureId) :
		width(width),
		height(height),
		textureId(textureId)
	{
	}

	int Texture2D::Width() const
	{
		return width;
	}

	int Texture2D::Height() const
	{
		return height;
	}

	GLuint Texture2D::TextureId() const
	{
		return textureId;
	}
}
