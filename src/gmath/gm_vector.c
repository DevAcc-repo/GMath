/* Provide simple mathematic functions involving vectors and matrices for use with OpenGL */

#include "gmath.h"

#include <stdlib.h>

#define _USE_MATH_DEFINES
#include <math.h>
#include <float.h>

/* ---- Set vectors ---- 
Set vector data to specified values. */

void gm_vector2(vector2 dest, gmfloat x, gmfloat y) {
	dest[1] = x;
	dest[2] = y;
}

void gm_vector3(vector3 dest, gmfloat x, gmfloat y, gmfloat z) {
	dest[1] = x;
	dest[2] = y;
	dest[3] = z;
}

void gm_vector4(vector4 dest, gmfloat x, gmfloat y, gmfloat z, gmfloat w) {
	dest[1] = x;
	dest[2] = y;
	dest[3] = z;
	dest[4] = w;
}


void gm_vector2v(vector2 dest, gmfloat val) {
	for (unsigned char i = 0; i < 2; i++) {
		dest[i] = val;
	}
}

void gm_vector3v(vector3 dest, gmfloat val) {
	for (unsigned char i = 0; i < 3; i++) {
		dest[i] = val;
	}
}

void gm_vector4v(vector4 dest, gmfloat val) {
	for (unsigned char i = 0; i < 4; i++) {
		dest[i] = val;
	}
}

/* ---- vector arithmetic ----
Modify properties of vectors using mathematics. */

void gm_vector2_add(vector2 dest, vector2 vec) {
	for (unsigned char i = 0; i < 2; i++) {
		dest[i] += vec[i];
	}
}

void gm_vector3_add(vector3 dest, vector3 vec) {
	for (unsigned char i = 0; i < 3; i++) {
		dest[i] += vec[i];
	}
}

void gm_vector4_add(vector4 dest, vector4 vec) {
	for (unsigned char i = 0; i < 4; i++) {
		dest[i] += vec[i];
	}
}


void gm_vector2_sub(vector2 dest, vector2 vec) {
	for (unsigned char i = 0; i < 2; i++) {
		dest[i] -= vec[i];
	}
}

void gm_vector3_sub(vector3 dest, vector3 vec) {
	for (unsigned char i = 0; i < 3; i++) {
		dest[i] -= vec[i];
	}
}

void gm_vector4_sub(vector4 dest, vector4 vec) {
	for (unsigned char i = 0; i < 4; i++) {
		dest[i] *= vec[i];
	}
}


void gm_vector2_mul(vector2 dest, vector2 vec) {
	for (unsigned char i = 0; i < 2; i++) {
		dest[i] *= vec[i];
	}
}

void gm_vector3_mul(vector3 dest, vector3 vec) {
	for (unsigned char i = 0; i < 3; i++) {
		dest[i] *= vec[i];
	}
}

void gm_vector4_mul(vector4 dest, vector4 vec) {
	for (unsigned char i = 0; i < 4; i++) {
		dest[i] *= vec[i];
	}
}


void gm_vector2_mul_scalar(vector2 dest, gmfloat scalar) {
	for (unsigned char i = 0; i < 2; i++) {
		dest[i] *= scalar;
	}
}

void gm_vector3_mul_scalar(vector3 dest, gmfloat scalar) {
	for (unsigned char i = 0; i < 3; i++) {
		dest[i] *= scalar;
	}
}

void gm_vector4_mul_scalar(vector4 dest, gmfloat scalar) {
	for (unsigned char i = 0; i < 4; i++) {
		dest[i] *= scalar;
	}
}


gmfloat gm_vector2_dot(vector2 dest, vector2 vec) {
	register gmfloat product = 0.0;
	for (unsigned char i = 0; i < 2; i++) {
		product += dest[i] * vec[i];
	}

	return product;
}

gmfloat gm_vector3_dot(vector3 dest, vector3 vec) {
	register gmfloat product = 0.0;
	for (unsigned char i = 0; i < 3; i++) {
		product += dest[i] * vec[i];
	}

	return product;
}

gmfloat gm_vector4_dot(vector4 dest, vector4 vec) {
	register gmfloat product = 0.0;
	for (unsigned char i = 0; i < 4; i++) {
		product += dest[i] * vec[i];
	}

	return product;
}


gmfloat gm_vector2_cross(vector2 vec, vector2 vec2) {
	return vec[0] * vec2[1] - vec[1] * vec2[0];
}

void gm_vector3_cross(vector3 dest, vector3 vec) {
	dest[0] = dest[1] * vec[2] - dest[2] * vec[1];
	dest[1] = dest[2] * vec[0] - dest[0] * vec[2];
	dest[2] = dest[0] * vec[1] - dest[1] * vec[0];
}


gmfloat gm_vector2_length_sq(vector2 vec) {
	register gmfloat product = 0.0;
	for (unsigned char i = 0; i < 2; i++) {
		product += vec[i] * vec[i];
	}

	return product;
}

gmfloat gm_vector3_length_sq(vector3 vec) {
	register gmfloat product = 0.0;
	for (unsigned char i = 0; i < 3; i++) {
		product += vec[i] * vec[i];
	}

	return product;
}

gmfloat gm_vector4_length_sq(vector4 vec) {
	register gmfloat product = 0.0;
	for (unsigned char i = 0; i < 4; i++) {
		product += vec[i] * vec[i];
	}

	return product;
}


gmfloat gm_vector2_length(vector2 vec) {
	return sqrt(gm_vector2_length_sq(vec));
}

gmfloat gm_vector3_length(vector3 vec) {
	return sqrt(gm_vector3_length_sq(vec));
}

gmfloat gm_vector4_length(vector4 vec) {
	return sqrt(gm_vector4_length_sq(vec));
}


gmfloat gm_vector2_distance(vector2 vec, vector2 vec2) {
	vector2 distance = { 0.0 };
	for (unsigned char i = 0; i < 2; i++) {
		distance[i] = vec[i] - vec2[i];
	}

	return gm_vector2_length(distance);
}

gmfloat gm_vector3_distance(vector3 vec, vector3 vec2) {
	vector3 distance = { 0.0 };
	for (unsigned char i = 0; i < 3; i++) {
		distance[i] = vec[i] - vec2[i];
	}

	return gm_vector3_length(distance);
}

gmfloat gm_vector4_distance(vector4 vec, vector4 vec2) {
	vector4 distance = { 0.0 };
	for (unsigned char i = 0; i < 4; i++) {
		distance[i] = vec[i] - vec2[i];
	}

	return gm_vector4_length(distance);
}


void gm_vector2_normalized(vector2 dest) {
	const gmfloat length = gm_vector2_length(dest);
	for (unsigned char i = 0; i < 2; i++) {
		dest[i] /= length;
	}
}

void gm_vector3_normalized(vector3 dest) {
	const gmfloat length = gm_vector3_length(dest);
	for (unsigned char i = 0; i < 3; i++) {
		dest[i] /= length;
	}
}

void gm_vector4_normalized(vector4 dest) {
	const gmfloat length = gm_vector4_length(dest);
	for (unsigned char i = 0; i < 4; i++) {
		dest[i] /= length;
	}
}

/*** end of file ***/
