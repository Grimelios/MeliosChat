#pragma once

namespace MeliosChat
{
	class Rectangle
	{
	private:

		float x;
		float y;
		float width;
		float height;

	public:

		Rectangle(float x, float y, float width, float height);

		float X() const;
		float Y() const;
		float Width() const;
		float Height() const;
		float Left() const;
		float Right() const;
		float Top() const;
		float Bottom() const;
	};
}
