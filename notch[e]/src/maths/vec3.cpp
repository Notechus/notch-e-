#include "vec3.h"

namespace notche {
	namespace maths {

		vec3::vec3() {
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
		}

		vec3::vec3(const float& x, const float& y, const float& z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}

		vec3& vec3::add(const vec3& other) {
			x += other.x;
			y += other.y;
			z += other.z;

			return *this;
		}

		vec3& vec3::subtract(const vec3& other) {
			x -= other.x;
			y -= other.y;
			z -= other.z;

			return *this;
		}

		vec3& vec3::multiply(const float& scalar) {
			x *= scalar;
			y *= scalar;
			z *= scalar;

			return *this;
		}

		vec3& vec3::divide(const float& scalar) {
			x /= scalar;
			y /= scalar;
			z /= scalar;

			return *this;
		}

		std::ostream& operator<<(std::ostream& out, const vec3& vector) {
			out << "(" << vector.x << " , " << vector.y << " , " << vector.z << ")";
			return out;
		}

		bool operator==(const vec3& left, const vec3& right) {
			return (left.x == right.x) && (left.y == right.y) && (left.z == right.z);
		}

		bool operator!=(const vec3& left, const vec3& right) {
			return !operator==(left, right);
		}
	}
}