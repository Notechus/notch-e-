#include "mat4.h"
#include <math.h>

namespace notche
{
	namespace maths
	{

		mat4::mat4()
		{
			for (int i = 0; i < 4 * 4; i++)
			{
				elements[i] = 0.0f;
			}
		}

		mat4::mat4(const float& diagonal)
		{
			for (int i = 0; i < 4 * 4; i++)
			{
				elements[i] = 0.0f;
			}
			elements[0 + 0 * 4] = diagonal;
			elements[1 + 1 * 4] = diagonal;
			elements[2 + 2 * 4] = diagonal;
			elements[3 + 3 * 4] = diagonal;
		}

		vec4 mat4::getColumn(int index) const
		{
			index *= 4;
			return vec4(elements[index], elements[index + 1], elements[index + 2], elements[index + 3]);
		}

		mat4 mat4::identity()
		{
			return mat4(1.0f);
		}

		mat4 mat4::orthographic(const float& left, const float& right, const float& bottom, const float& top, const float& near, const float& far)
		{
			mat4 result(1.0f);

			result.elements[0 + 0 * 4] = 2.0f / (right - left);

			result.elements[1 + 1 * 4] = 2.0f / (top - bottom);

			result.elements[2 + 2 * 4] = 2.0f / (near - far);

			result.elements[0 + 3 * 4] = (left + right) / (left - right);
			result.elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
			result.elements[2 + 3 * 4] = (far + near) / (far - near);

			return result;
		}

		mat4 mat4::perspective(const float& fov, const float& aspectRatio, const float& near, const float& far)
		{
			mat4 result(1.0f);

			float q = 1.0f / (float) tan(maths::toRadians(0.5f*fov));
			float a = q / aspectRatio;
			float b = (near + far) / (near - far);
			float c = (2.0f * near * far) / (near - far);

			result.elements[0 + 0 * 4] = a;
			result.elements[1 + 1 * 4] = q;
			result.elements[2 + 2 * 4] = b;
			result.elements[3 + 2 * 4] = -1.0f;
			result.elements[2 + 3 * 4] = c;

			return result;
		}

		mat4 mat4::translation(const vec3& translation)
		{
			mat4 result(1.0f);

			result.elements[0 + 3 * 4] = translation.x;
			result.elements[1 + 3 * 4] = translation.y;
			result.elements[2 + 3 * 4] = translation.z;

			return result;
		}

		mat4 mat4::rotation(const float& angle, const vec3& axis)
		{
			mat4 result(1.0f);

			float r = maths::toRadians(angle);
			float c = cos(r);
			float s = sin(r);
			float oc = 1.0f - c;

			result.elements[0 + 0 * 4] = axis.x * oc + c;
			result.elements[1 + 0 * 4] = axis.y * axis.x * oc + axis.z * s;
			result.elements[2 + 0 * 4] = axis.x * axis.z * oc - axis.z * s;

			result.elements[0 + 1 * 4] = axis.x * axis.y * oc - axis.z * s;
			result.elements[1 + 1 * 4] = axis.y * oc + c;
			result.elements[2 + 1 * 4] = axis.y * axis.z * oc + axis.x * s;

			result.elements[0 + 2 * 4] = axis.x * axis.z * oc + axis.y * s;
			result.elements[1 + 2 * 4] = axis.y * axis.z * oc - axis.x * s;
			result.elements[2 + 2 * 4] = axis.z * oc + c;

			return result;
		}

		mat4 mat4::scale(const vec3& scale)
		{
			mat4 result(1.0f);

			result.elements[0 + 0 * 4] = scale.x;
			result.elements[1 + 1 * 4] = scale.y;
			result.elements[2 + 2 * 4] = scale.z;

			return result;
		}

		mat4& mat4::multiply(const mat4& other)
		{
			float data[16];
			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					float sum = 0.0f;
					for (int e = 0; e < 4; e++)
					{
						sum += elements[x + e * 4] * other.elements[e + y * 4];
					}
					data[x + y * 4] = sum;
				}
			}
			memcpy(elements, data, 4 * 4 * sizeof(float));

			return *this;
		}

		vec3 mat4::multiply(const vec3& other) const
		{
			return vec3(
				columns[0].x * other.x + columns[1].x * other.y + columns[2].x * other.z + columns[3].x,
				columns[0].y * other.x + columns[1].y * other.y + columns[2].y * other.z + columns[3].y,
				columns[0].z * other.x + columns[1].z * other.y + columns[2].z * other.z + columns[3].z
				);
		}

		vec4 mat4::multiply(const vec4& other) const
		{
			return vec4(
				columns[0].x * other.x + columns[1].x * other.y + columns[2].x * other.z + columns[3].x * other.w,
				columns[0].y * other.x + columns[1].y * other.y + columns[2].y * other.z + columns[3].y * other.w,
				columns[0].z * other.x + columns[1].z * other.y + columns[2].z * other.z + columns[3].z * other.w,
				columns[0].w * other.x + columns[1].w * other.y + columns[2].w * other.z + columns[3].w * other.w
				);
		}

		vec3 operator*(const mat4& left, const vec3& right)
		{
			return left.multiply(right);
		}

		vec4 operator*(const mat4& left, const vec4& right)
		{
			return left.multiply(right);
		}

		mat4 operator*(mat4 left, const mat4& right)
		{
			return left.multiply(right);
		}

		mat4& mat4::operator*=(const mat4& other)
		{
			return multiply(other);
		}
	}
}