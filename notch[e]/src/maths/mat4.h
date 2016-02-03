#pragma once
#ifndef MAT4_H_INCLUDED
#define MAT4_H_INCLUDED

#include "maths.h"

namespace notche
{
	namespace maths
	{
		//float toRadians(float degrees);
		struct mat4
		{
			union
			{
				float elements[4 * 4];
				vec4 columns[4];
			};
			mat4();
			mat4(const float& diag);
			vec4 getColumn(int index) const;

			static mat4 identity();
			static mat4 orthographic(const float& left, const float& right, const float& bottom, const float& top, const float& near, const float& far);
			static mat4 perspective(const float& fov, const float& aspectRatio, const float& near, const float& far);
			static mat4 translation(const vec3& translation);
			static mat4 rotation(const float& angle, const vec3& axis);
			static mat4 scale(const vec3& scale);

			mat4& multiply(const mat4& other);
			vec3 multiply(const vec3& other) const;
			vec4 multiply(const vec4& other) const;
			mat4& operator*=(const mat4& other);
			friend mat4 operator*(mat4 left, const mat4& right);
			friend vec3 operator*(const mat4& left, const vec3& right);
			friend vec4 operator*(const mat4& left, const vec4& right);
		};
	}
}

#endif