#pragma once
#ifndef VEC3_H_INCLUDED
#define VEC3_H_INCLUDED

#include <iostream>

namespace notche
{
	namespace maths
	{
		struct vec3
		{
			float x, y, z;

			vec3();
			vec3(const float& x, const float& y, const float& z);

			vec3& add(const vec3& other);
			vec3& subtract(const vec3& other);
			vec3& multiply(const float& scalar);
			vec3& divide(const float& scalar);
		};

		std::ostream& operator<<(std::ostream& out, const vec3& vector);
		bool operator==(const vec3& left, const vec3& right);
		bool operator!=(const vec3& left, const vec3& right);
	}
}

#endif