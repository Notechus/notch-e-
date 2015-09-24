#pragma once
#ifndef MATHS_H_INCLUDED
#define MATHS_H_INCLUDED
#define _USE_MATH_DEFINES

#include <math.h>
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "mat4.h"

namespace notche {
	namespace maths {
		struct maths {
			static float toRadians(float degrees) {
				return degrees * (M_PI / 180.0f);
			}
		};
	}
}
#endif