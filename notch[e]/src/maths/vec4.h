#pragma once
#ifndef vec4_H_INCLUDED
#define vec4_H_INCLUDED

#include <iostream>

namespace notche
{
	namespace maths
	{
		struct vec4
		{
			float x, y, z, w;

			vec4() = default;
			vec4(const float& x, const float& y, const float& z, const float& w);

			vec4& add(const vec4& other);
			vec4& subtract(const vec4& other);
			vec4& multiply(const float& scalar);
			vec4& divide(const float& scalar);
		};

		std::ostream& operator<<(std::ostream& out, const vec4& vector);
		bool operator==(const vec4& left, const vec4& right);
		bool operator!=(const vec4& left, const vec4& right);
	}
}

#endif