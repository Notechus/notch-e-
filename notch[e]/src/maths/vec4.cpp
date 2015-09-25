#include "vec4.h"

namespace notche
{
	namespace maths
	{

		vec4::vec4(const float& x, const float& y, const float& z, const float& w)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		vec4& vec4::add(const vec4& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;

			return *this;
		}

		vec4& vec4::subtract(const vec4& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			w -= other.w;

			return *this;
		}

		vec4& vec4::multiply(const float& scalar)
		{
			x *= scalar;
			y *= scalar;
			z *= scalar;
			w *= scalar;

			return *this;
		}

		vec4& vec4::divide(const float& scalar)
		{
			x /= scalar;
			y /= scalar;
			z /= scalar;
			w /= scalar;

			return *this;
		}

		std::ostream& operator<<(std::ostream& out, const vec4& vector)
		{
			out << "(" << vector.x << " , " << vector.y << " , " << vector.z << " , " << vector.w << ")";
			return out;
		}

		bool operator==(const vec4& left, const vec4& right)
		{
			return (left.x == right.x) && (left.y == right.y) && (left.z == right.z) && (left.w == right.w);
		}

		bool operator!=(const vec4& left, const vec4& right)
		{
			return !operator==(left, right);
		}
	}
}