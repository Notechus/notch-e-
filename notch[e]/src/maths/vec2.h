#pragma once
#ifndef VEC2_H_INCLUDED
#define VEC2_H_INCLUDED

#include <iostream>

namespace notche {
	namespace maths {
		struct vec2 {
			float x, y;

			vec2();
			vec2(const float& x, const float& y);

			vec2& add(const vec2& other);
			vec2& subtract(const vec2& other);
			vec2& multiply(const float& scalar);
			vec2& divide(const float& scalar);
		};

		std::ostream& operator<<(std::ostream& out, const vec2& vector);
		bool operator==(const vec2& left, const vec2& right);
		bool operator!=(const vec2& left, const vec2& right);
	}
}

#endif