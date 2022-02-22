/* Provide simple mathematic functions involving vectors and matrices for use with OpenGL */

#include "gmath.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include <float.h>

/* ---- Comparison procedures ----
Compare data between variables. */

gmboolean gm_comp_epsilon(gmfloat32 f1, gmfloat32 f2, gmfloat32 tolerance) {
	return !(abs(f1 - f2) > tolerance);
}


gmboolean gm_vec2_comp_epsilon(Vec2 vec, Vec2 vec2, gmfloat32 tolerance) {
	for (int i = 0; i < 2; i++) {
		if (gm_comp_epsilon(vec.data[i], vec2.data[i], tolerance) != GM_TRUE) return GM_FALSE;
	}
	return GM_TRUE;
}

gmboolean gm_vec3_comp_epsilon(Vec3 vec, Vec3 vec2, gmfloat32 tolerance) {
	for (int i = 0; i < 3; i++) {
		if (gm_comp_epsilon(vec.data[i], vec2.data[i], tolerance) != GM_TRUE) return GM_FALSE;
	}
	return GM_TRUE;
}

gmboolean gm_vec4_comp_epsilon(Vec4 vec, Vec4 vec2, gmfloat32 tolerance) {
	for (int i = 0; i < 4; i++) {
		if (gm_comp_epsilon(vec.data[i], vec2.data[i], tolerance) != GM_TRUE) return GM_FALSE;
	}
	return GM_TRUE;
}


gmboolean gm_mat3x3_comp_epsilon(Mat3x3 mat, Mat3x3 mat2, gmfloat32 tolerance) {
	for (int i = 0; i < 9; i++) {
		if (gm_comp_epsilon(mat.data[i], mat2.data[i], tolerance) != GM_TRUE) return GM_FALSE;
	}
	return GM_TRUE;
}

gmboolean gm_mat4x4_comp_epsilon(Mat4x4 mat, Mat4x4 mat2, gmfloat32 tolerance) {
	for (int i = 0; i < 16; i++) {
		if (gm_comp_epsilon(mat.data[i], mat2.data[i], tolerance) != GM_TRUE) return GM_FALSE;
	}
	return GM_TRUE;
}

/* ---- Conversion procedures ----
Convert data between variables. */

gmfloat32 gm_conv_deg_rad(gmfloat32 deg) {
	return deg * M_PI / 180.0f;
}

gmfloat32 gm_conv_rad_deg(gmfloat32 rad) {
	return 180.0f * M_PI / rad;
}

/*** end of file  ***/
