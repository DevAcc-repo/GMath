/* Provide simple mathematic functions involving vectors and matrices for use with OpenGL */

#include "gmath.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include <float.h>

/* ---- Comparison procedures ----
Compare data between variables. */

gmboolean gm_comp_epsilon(gmfloat f1, gmfloat f2, gmfloat tolerance) {
	return !(abs(f1 - f2) > tolerance);
}


gmboolean gm_vector2_comp_epsilon(vector2 vec, vector2 vec2, gmfloat tolerance) {
	for (unsigned char i = 0; i < 2; i++) {
		if (gm_comp_epsilon(vec[i], vec2[i], tolerance) != GM_TRUE) return GM_FALSE;
	}
	return GM_TRUE;
}

gmboolean gm_vector3_comp_epsilon(vector3 vec, vector3 vec2, gmfloat tolerance) {
	for (unsigned char i = 0; i < 3; i++) {
		if (gm_comp_epsilon(vec[i], vec2[i], tolerance) != GM_TRUE) return GM_FALSE;
	}
	return GM_TRUE;
}

gmboolean gm_vector4_comp_epsilon(vector4 vec, vector4 vec2, gmfloat tolerance) {
	for (unsigned char i = 0; i < 4; i++) {
		if (gm_comp_epsilon(vec[i], vec2[i], tolerance) != GM_TRUE) return GM_FALSE;
	}
	return GM_TRUE;
}


gmboolean gm_matrix3x3_comp_epsilon(matrix3x3 mat, matrix3x3 mat2, gmfloat tolerance) {
	for (unsigned char i = 0; i < 9; i++) {
		if (gm_comp_epsilon(mat[i], mat2[i], tolerance) != GM_TRUE) return GM_FALSE;
	}
	return GM_TRUE;
}

gmboolean gm_matrix4x4_comp_epsilon(matrix4x4 mat, matrix4x4 mat2, gmfloat tolerance) {
	for (unsigned char i = 0; i < 16; i++) {
		if (gm_comp_epsilon(mat[i], mat2[i], tolerance) != GM_TRUE) return GM_FALSE;
	}
	return GM_TRUE;
}

/* ---- Conversion procedures ----
Convert data between variables. */

gmfloat gm_conv_deg_rad(gmfloat deg) {
	return deg * M_PI / 180.0f;
}

gmfloat gm_conv_rad_deg(gmfloat rad) {
	return 180.0f * M_PI / rad;
}

/*** end of file  ***/
