/* Provide simple mathematic functions involving vectors and matrices for use with OpenGL */

#include "gmath.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include <float.h>

/* ---- Set vectors ---- 
Set vector data to specified values. */

Vec2 gm_vec2(gmfloat32 x, gmfloat32 y) {
	return (Vec2) { { x, y } };
}

Vec3 gm_vec3(gmfloat32 x, gmfloat32 y, gmfloat32 z) {
	return (Vec3) { { x, y, z } };
}

Vec4 gm_vec4(gmfloat32 x, gmfloat32 y, gmfloat32 z, gmfloat32 w) {
	return (Vec4) { { x, y, z, w } };
}


Vec2 gm_vec2v(gmfloat32 val) {
	return (Vec2) { { val, val } };
}

Vec3 gm_vec3v(gmfloat32 val) {
	return (Vec3) { { val, val, val } };
}

Vec4 gm_vec4v(gmfloat32 val) {
	return (Vec4) { { val, val, val, val } };
}

/* ---- Vector arithmetic ----
Modify properties of vectors using mathematics. */

Vec2 gm_vec2_add(Vec2 vec, Vec2 vec2) {
	return (Vec2) { { vec.x + vec2.x, vec.y + vec2.y } };
}

Vec3 gm_vec3_add(Vec3 vec, Vec3 vec2) {
	return (Vec3) { { vec.x + vec2.x, vec.y + vec2.y, vec.z + vec2.z } };
}

Vec4 gm_vec4_add(Vec4 vec, Vec4 vec2) {
	return (Vec4) { { vec.x + vec2.x, vec.y + vec2.y, vec.z + vec2.z, vec.w + vec2.w } };
}


Vec2 gm_vec2_sub(Vec2 vec, Vec2 vec2) {
	return (Vec2) { { vec.x - vec2.x, vec.y - vec2.y } };
}

Vec3 gm_vec3_sub(Vec3 vec, Vec3 vec2) {
	return (Vec3) { { vec.x - vec2.x, vec.y - vec2.y, vec.z - vec2.z } };
}

Vec4 gm_vec4_sub(Vec4 vec, Vec4 vec2) {
	return (Vec4) { { vec.x - vec2.x, vec.y - vec2.y, vec.z - vec2.z, vec.w - vec2.w } };
}


Vec2 gm_vec2_mul(Vec2 vec, Vec2 vec2) {
	return (Vec2) { { vec.x * vec2.x, vec.y * vec2.y } };
}

Vec3 gm_vec3_mul(Vec3 vec, Vec3 vec2) {
	return (Vec3) { { vec.x * vec2.x, vec.y * vec2.y, vec.z * vec2.z } };
}

Vec4 gm_vec4_mul(Vec4 vec, Vec4 vec2) {
	return (Vec4) { { vec.x * vec2.x, vec.y * vec2.y, vec.z * vec2.z, vec.w * vec2.w } };
}


Vec2 gm_vec2_mul_scalar(Vec2 vec, gmfloat32 scalar) {
	return (Vec2) { { vec.x * scalar, vec.y * scalar } };
}

Vec3 gm_vec3_mul_scalar(Vec3 vec, gmfloat32 scalar) {
	return (Vec3) { { vec.x * scalar, vec.y * scalar, vec.z * scalar } };
}

Vec4 gm_vec4_mul_scalar(Vec4 vec, gmfloat32 scalar) {
	return (Vec4) { { vec.x * scalar, vec.y * scalar, vec.z * scalar, vec.w * scalar } };
}


gmfloat32 gm_vec2_dot(Vec2 vec, Vec2 vec2) {
	gmfloat32 product = 0.0f;
	for (int i = 0; i < 2; i++) {
		product += vec.data[i] * vec2.data[i];
	}

	return product;
}

gmfloat32 gm_vec3_dot(Vec3 vec, Vec3 vec2) {
	gmfloat32 product = 0.0f;
	for (int i = 0; i < 3; i++) {
		product += vec.data[i] * vec2.data[i];
	}

	return product;
}

gmfloat32 gm_vec4_dot(Vec4 vec, Vec4 vec2) {
	gmfloat32 product = 0.0f;
	for (int i = 0; i < 4; i++) {
		product += vec.data[i] * vec2.data[i];
	}

	return product;
}


gmfloat32 gm_vec2_cross(Vec2 vec, Vec2 vec2) {
	return vec.x * vec2.y - vec.y * vec2.x;
}

Vec3 gm_vec3_cross(Vec3 vec, Vec3 vec2) {
	return (Vec3) { {
		vec.y * vec2.z - vec.z * vec2.y,
		vec.z * vec2.x - vec.x * vec2.z,
		vec.x * vec2.y - vec.y * vec2.x
	} };
}


gmfloat32 gm_vec2_length_sq(Vec2 vec) {
	return vec.x * vec.x + vec.y * vec.y;
}

gmfloat32 gm_vec3_length_sq(Vec3 vec) {
	return vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;
}

gmfloat32 gm_vec4_length_sq(Vec4 vec) {
	return vec.x * vec.x + vec.y * vec.y + vec.z * vec.z + vec.w * vec.w;
}


gmfloat32 gm_vec2_length(Vec2 vec) {
	return sqrtf(gm_vec2_length_sq(vec));
}

gmfloat32 gm_vec3_length(Vec3 vec) {
	return sqrtf(gm_vec3_length_sq(vec));
}

gmfloat32 gm_vec4_length(Vec4 vec) {
	return sqrtf(gm_vec4_length_sq(vec));
}


gmfloat32 gm_vec2_distance(Vec2 vec, Vec2 vec2) {
	Vec2 distance = { {
		vec.x - vec2.x,
		vec.y - vec2.y
	} };
	
	return gm_vec2_length(distance);
}

gmfloat32 gm_vec3_distance(Vec3 vec, Vec3 vec2) {
	Vec3 distance = { {
		vec.x - vec2.x,
		vec.y - vec2.y,
		vec.z - vec2.z
	} };
	
	return gm_vec3_length(distance);
}

gmfloat32 gm_vec4_distance(Vec4 vec, Vec4 vec2) {
	Vec4 distance = { {
		vec.x - vec2.x,
		vec.y - vec2.y,
		vec.z - vec2.z,
		vec.w - vec2.w
	} };
	
	return gm_vec4_length(distance);
}


Vec2 gm_vec2_normalized(Vec2 vec) {
	const gmfloat32 length = gm_vec2_length(vec);
	vec.x /= length;
	vec.y /= length;

	return vec;
}

Vec3 gm_vec3_normalized(Vec3 vec) {
	const gmfloat32 length = gm_vec3_length(vec);
	vec.x /= length;
	vec.y /= length;
	vec.z /= length;

	return vec;
}

Vec4 gm_vec4_normalized(Vec4 vec) {
	const gmfloat32 length = gm_vec4_length(vec);
	vec.x /= length;
	vec.y /= length;
	vec.z /= length;
	vec.w /= length;

	return vec;
}

/*** end of file ***/
