#include "Rectangle.h"

namespace MeliosChat
{
	Rectangle::Rectangle(const float x, const float y, const float width, const float height) :
		x(x),
		y(y),
		width(width),
		height(height)
	{
	}

	float Rectangle::X() const
	{
		return x;
	}

	float Rectangle::Y() const
	{
		return y;
	}

	float Rectangle::Width() const
	{
		return width;
	}

	float Rectangle::Height() const
	{
		return height;
	}

	float Rectangle::Left() const
	{
		return x;
	}

	float Rectangle::Right() const
	{
		return x + width;
	}

	float Rectangle::Top() const
	{
		return y;
	}

	float Rectangle::Bottom() const
	{
		return y + height;
	}
}
