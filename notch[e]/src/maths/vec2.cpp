#include "vec2.h"

namespace notche
{
	namespace maths
	{

		vec2::vec2()
		{
			x = 0.0f;
			y = 0.0f;
		}

		vec2::vec2(const float& x, const float& y)
		{
			this->x = x;
			this->y = y;
		}

		vec2& vec2::add(const vec2& other)
		{
			x += other.x;
			y += other.y;

			return *this;
		}

		vec2& vec2::subtract(const vec2& other)
		{
			x -= other.x;
			y -= other.y;

			return *this;
		}

		vec2& vec2::multiply(const float& scalar)
		{
			x *= scalar;
			y *= scalar;

			return *this;
		}

		vec2& vec2::divide(const float& scalar)
		{
			x /= scalar;
			y /= scalar;

			return *this;
		}

		std::ostream& operator<<(std::ostream& out, const vec2& vector)
		{
			out << "(" << vector.x << " , " << vector.y << ")";
			return out;
		}

		bool operator==(const vec2& left, const vec2& right)
		{
			return (left.x == right.x) && (left.y == right.y);
		}

		bool operator!=(const vec2& left, const vec2& right)
		{
			return !operator==(left, right);
		}
	}
}