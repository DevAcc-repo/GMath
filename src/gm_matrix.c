/* Provide simple mathematic functions involving vectors and matrices for use with OpenGL */

#include "../include/gmath.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include <float.h>

/* ---- Set matrices ---- 
Set matrix data to specified values. */

void gm_matrix3x3v(matrix3x3 dest, gmfloat val) {
	for (unsigned char i = 0; i < 9; i++) {
		dest[i] = val;
	}
}

void gm_matrix4x4v(matrix3x3 dest, gmfloat val) {
	for (unsigned char i = 0; i < 16; i++) {
		dest[i] = val;
	}
}


void gm_matrix3x3vd(matrix3x3 dest, gmfloat val) {
	gm_matrix3x3v(dest, 0.0);
	for (unsigned char i = 0; i < 3; i++) {
		dest[i + 3 * i] = val;
	}
}

void gm_matrix4x4vd(matrix4x4 dest, gmfloat val) {
	gm_matrix4x4v(dest, 0.0);
	for (unsigned char i = 0; i < 4; i++) {
		dest[i + 4 * i] = val;
	}
}

/* ---- Generate matrices ----
Generate matrices using user given values */

void gm_matrix4x4_orthographic(matrix4x4 dest, gmfloat left, gmfloat right, gmfloat bottom, gmfloat top, gmfloat near, gmfloat far) {
	gm_matrix4x4_identity(dest);

	dest[0] = 2.0 / (right - left);
	dest[5] = 2.0 / (top - bottom);
	dest[10] = 2.0 / (near - far);

	dest[3] = (left + right) / (left - right);
	dest[7] = (bottom + top) / (bottom - top);
	dest[11] = (far + near) / (far - near);
}

void gm_matrix4x4_perspective(matrix4x4 dest, gmfloat fov, gmfloat aspect, gmfloat near, gmfloat far) {
	gm_matrix4x4_identity(dest);
	register gmfloat mb11 = 1.0 / tan(fov * 0.5);

	dest[0] = mb11 / aspect;
	dest[5] = mb11;
	dest[10] = (near + far) / (near - far);
	dest[11] = (2.0 * near * far) / (near - far);
	dest[14] = -1.0;
}


void gm_matrix3x3_translate(matrix3x3 dest, vector2 vec) {
	gm_matrix3x3_identity(dest);
	for (unsigned char i = 0; i < 2; i++) {
		dest[2 + 3 * i] = vec[i];
	}
}

void gm_matrix4x4_translate(matrix4x4 dest, vector3 vec) {
	gm_matrix4x4_identity(dest);
	for (unsigned char i = 0; i < 3; i++) {
		dest[3 + 4 * i] = vec[i];
	}
}


void gm_matrix3x3_scale(matrix3x3 dest, vector2 vec) {
	gm_matrix3x3_identity(dest);
	for (unsigned char i = 0; i < 2; i++) {
		dest[i + 3 * 1] = vec[i];
	}
}

void gm_matrix4x4_scale(matrix4x4 dest, vector3 vec) {
	gm_matrix4x4_identity(dest);
	for (unsigned char i = 0; i < 3; i++) {
		dest[i + 4 * 1] = vec[i];
	}
}


void gm_matrix3x3_rotate(matrix3x3 dest, gmfloat angle) {
	gm_matrix3x3_identity(dest);
	register gmfloat s = sin(angle);
	register gmfloat c = cos(angle);

	dest[0] = c;
	dest[1] = -s;
	dest[3] = s;
	dest[4] = c;
}

void gm_matrix4x4_rotate(matrix4x4 dest, gmfloat angle, vector3 axis) {
	gm_matrix4x4_identity(dest);
	register gmfloat s = sin(angle);
	register gmfloat c = cos(angle);
	register gmfloat omc = 1.0 - c;

	/* TODO: Could be further optimized? */
	dest[0] = axis[0] * omc + c;
	dest[1] = axis[0] * axis[1] * omc - axis[2] * s;
	dest[2] = axis[0] * axis[2] * omc + axis[1] * s;

	dest[4] = axis[1] * axis[0] * omc + axis[2] * s;
	dest[5] = axis[1] * omc + c;
	dest[6] = axis[1] * axis[2] * omc - axis[0] * s;

	dest[8] = axis[0] * axis[2] * omc - axis[1] * s;
	dest[9] = axis[1] * axis[2] * omc + axis[0] * s;
	dest[10] = axis[2] * omc + c;
}

/* ---- Matrix arithmetic ----
Modify properties of matrices using mathematics. */

void gm_matrix3x3_add(matrix3x3 dest, matrix3x3 mat) {
	for (unsigned char i = 0; i < 9; i++) {
		dest[i] += mat[i];
	}
}

void gm_matrix4x4_add(matrix4x4 dest, matrix4x4 mat) {
	for (unsigned char i = 0; i < 16; i++) {
		dest[i] += mat[i];
	}
}


void gm_matrix3x3_sub(matrix3x3 dest, matrix3x3 mat) {
	for (unsigned char i = 0; i < 9; i++) {
		dest[i] -= mat[i];
	}
}

void gm_matrix4x4_sub(matrix4x4 dest, matrix4x4 mat) {
	for (unsigned char i = 0; i < 16; i++) {
		dest[i] -= mat[i];
	}
}


void gm_matrix3x3_mul(matrix3x3 dest, matrix3x3 mat) {
	matrix3x3 product = { 0.0f };
	for (unsigned char i = 0; i < 3; i++) {
		for (unsigned char j = 0; j < 3; j++) {
			for (unsigned char k = 0; k < 3; k++) {
				product[i + 3 * j] += dest[i + 3 * k] * mat[k + 3 * j];
			}
		}
	}

	for (unsigned char i = 0; i < 9; i++) {
		dest[i] = product[i];
	}
}

void gm_matrix4x4_mul(matrix4x4 dest, matrix4x4 mat) {
	matrix4x4 product = { 0.0f };
	for (unsigned char i = 0; i < 4; i++) {
		for (unsigned char j = 0; j < 4; j++) {
			for (unsigned char k = 0; k < 4; k++) {
				product[i + 4 * j] += dest[i + 4 * k] * mat[k + 4 * j];
			}
		}
	}

	for (unsigned char i = 0; i < 16; i++) {
		dest[i] = product[i];
	}
}


void gm_matrix3x3_mul_scalar(matrix3x3 dest, gmfloat scalar) {
	for (unsigned char i = 0; i < 9; i++) {
		dest[i] *= scalar;
	}
}

void gm_matrix4x4_mul_scalar(matrix4x4 dest, gmfloat scalar) {
	for (unsigned char i = 0; i < 16; i++) {
		dest[i] *= scalar;
	}
}


void gm_matrix3x3_mul_vector(matrix3x3 dest, vector3 vec) {
	for (unsigned char i = 0; i < 3; i++) {
		for (unsigned char j = 0; j < 3; j++) {
			dest[i + 3 * j] *= vec[j];
		}
	}
}

void gm_matrix4x4_mul_vector(matrix4x4 dest, vector4 vec) {
	for (unsigned char i = 0; i < 4; i++) {
		for (unsigned char j = 0; j < 4; j++) {
			dest[i + 4 * j] *= vec[j];
		}
	}
}


void gm_matrix3x3_transpose(matrix3x3 dest) {
	matrix3x3 buf;
	for (unsigned char i = 0; i < 3; i++) {
		for (unsigned char j = 0; j < 3; j++) {
			buf[i + 3 * j] = dest[j + 3 * i];
		}
	}

	for (unsigned char i = 0; i < 9; i++) {
		dest[i] = buf[i];
	}
}

void gm_matrix4x4_transpose(matrix4x4 dest) {
	matrix4x4 buf;
	for (unsigned char i = 0; i < 4; i++) {
		for (unsigned char j = 0; j < 4; j++) {
			buf[i + 4 * j] = dest[j + 4 * i];
		}
	}

	for (unsigned char i = 0; i < 16; i++) {
		dest[i] = buf[i];
	}
}

/*** end of file ***/
