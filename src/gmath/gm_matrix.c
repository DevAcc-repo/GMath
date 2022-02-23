/* Provide simple mathematic functions involving vectors and matrices for use with OpenGL */

#include "gmath.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include <float.h>

/* ---- Set matrices ---- 
Set matrix data to specified values. */

Mat3x3 gm_mat3x3(gmfloat32 data[9]) {
	Mat3x3 mat;
	for (int i = 0; i < 9; i++) {
		mat.data[i] = data[i];
	};

	return mat;
}

Mat4x4 gm_mat4x4(gmfloat32 data[16]) {
	Mat4x4 mat;
	for (int i = 0; i < 16; i++) {
		mat.data[i] = data[i];
	};

	return mat;
}


Mat3x3 gm_mat3x3v(gmfloat32 val) {
	Mat3x3 mat;
	for (int i = 0; i < 9; i++) {
		mat.data[i] = val;
	}

	return mat;
}

Mat4x4 gm_mat4x4v(gmfloat32 val) {
	Mat4x4 mat;
	for (int i = 0; i < 16; i++) {
		mat.data[i] = val;
	}

	return mat;
}


Mat3x3 gm_mat3x3vd(gmfloat32 val) {
	Mat3x3 mat = { .data = { 0.0f } };
	mat.m[0][0] = val;
	mat.m[1][1] = val;
	mat.m[2][2] = val;

	return mat;
}

Mat4x4 gm_mat4x4vd(gmfloat32 val) {
	Mat4x4 mat = { .data = { 0.0f } };
	mat.m[0][0] = val;
	mat.m[1][1] = val;
	mat.m[2][2] = val;
	mat.m[3][3] = val;

	return mat;
}

/* ---- Generate matrices ----
Generate matrices using user given values */

Mat4x4 gm_mat4x4_orthographic(gmfloat32 left, gmfloat32 right, gmfloat32 bottom, gmfloat32 top, gmfloat32 near, gmfloat32 far) {
	Mat4x4 proj = gm_mat4x4_identity();

	proj.m00 = 2.0f / (right - left);
	proj.m11 = 2.0f / (top - bottom);
	proj.m22 = 2.0f / (near - far);

	proj.m03 = (left + right) / (left - right);
	proj.m13 = (bottom + top) / (bottom - top);
	proj.m23 = (far + near) / (far - near);

	return proj;
}

Mat4x4 gm_mat4x4_perspective(gmfloat32 fov, gmfloat32 aspect, gmfloat32 near, gmfloat32 far) {
	Mat4x4 proj = gm_mat4x4_identity();
	gmfloat32 mb11 = 1.0f / tanf(fov * 0.5f);

	proj.m00 = mb11 / aspect;
	proj.m11 = mb11;
	proj.m22 = (near + far) / (near - far);;
	proj.m32 = -1.0f;
	proj.m23 = (2.0f * near * far) / (near - far);;

	return proj;
}


Mat3x3 gm_mat3x3_translate(Vec2 vec) {
	Mat3x3 mat = gm_mat3x3_identity();
	mat.m02 = vec.x;
	mat.m12 = vec.y;

	return mat;
}

Mat4x4 gm_mat4x4_translate(Vec3 vec) {
	Mat4x4 mat = gm_mat4x4_identity();
	mat.m03 = vec.x;
	mat.m13 = vec.y;
	mat.m23 = vec.z;

	return mat;
}


Mat3x3 gm_mat3x3_scale(Vec2 vec) {
	Mat3x3 mat = { .data = { 0.0f } };
	mat.m00 = vec.x;
	mat.m11 = vec.y;
	mat.m22 = 1.0f;

	return mat;
}

Mat4x4 gm_mat4x4_scale(Vec3 vec) {
	Mat4x4 mat = { .data = { 0.0f } };
	mat.m00 = vec.x;
	mat.m11 = vec.y;
	mat.m22 = vec.z;
	mat.m33 = 1.0f;

	return mat;
}


Mat3x3 gm_mat3x3_rotate(gmfloat32 angle) {
	Mat3x3 mat = gm_mat3x3_identity();
	gmfloat32 s = sinf(angle);
	gmfloat32 c = cosf(angle);

	mat.m00 = c;
	mat.m10 = -s;
	mat.m01 = s;
	mat.m11 = c;

	return mat;
}

Mat4x4 gm_mat4x4_rotate(gmfloat32 angle, Vec3 axis) {
	Mat4x4 mat = gm_mat4x4_identity();
	gmfloat32 s = sinf(angle);
	gmfloat32 c = cosf(angle);
	gmfloat32 omc = 1.0f - c;

	mat.m00 = axis.x * omc + c;
	mat.m10 = axis.y * axis.x * omc + axis.z * s;
	mat.m20 = axis.x * axis.z * omc - axis.y * s;

	mat.m01 = axis.x * axis.y * omc - axis.z * s;
	mat.m11 = axis.y * omc + c;
	mat.m21 = axis.y * axis.z * omc + axis.x * s;

	mat.m02 = axis.x * axis.z * omc + axis.y * s;
	mat.m12 = axis.y * axis.z * omc - axis.x * s;
	mat.m22 = axis.z * omc + c;

	return mat;
}

/* ---- Matrix arithmetic ----
Modify properties of matrices using mathematics. */

Mat3x3 gm_mat3x3_add(Mat3x3 mat, Mat3x3 mat2) {
	for (int i = 0; i < 9; i++) {
		mat.data[i] += mat2.data[i];
	}

	return mat;
}

Mat4x4 gm_mat4x4_add(Mat4x4 mat, Mat4x4 mat2) {
	for (int i = 0; i < 16; i++) {
		mat.data[i] += mat2.data[i];
	}

	return mat;
}


Mat3x3 gm_mat3x3_sub(Mat3x3 mat, Mat3x3 mat2) {
	for (int i = 0; i < 9; i++) {
		mat.data[i] -= mat2.data[i];
	}

	return mat;
}

Mat4x4 gm_mat4x4_sub(Mat4x4 mat, Mat4x4 mat2) {
	for (int i = 0; i < 16; i++) {
		mat.data[i] -= mat2.data[i];
	}

	return mat;
}


Mat3x3 gm_mat3x3_mul(Mat3x3 mat, Mat3x3 mat2) {
	Mat3x3 product = { .data = { 0.0f } };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				product.m[k][j] += mat.m[k][j] * mat2.m[i][k];
			}
		}
	}

	return product;
}

Mat4x4 gm_mat4x4_mul(Mat4x4 mat, Mat4x4 mat2) {
	Mat4x4 product = { .data = { 0.0f } };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				product.m[k][j] += mat.m[k][j] * mat2.m[i][k];
			}
		}
	}

	return product;
}


Mat3x3 gm_mat3x3_mul_scalar(Mat3x3 mat, gmfloat32 scalar) {
	for (int i = 0; i < 9; i++) {
		mat.data[i] *= scalar;
	}

	return mat;
}

Mat4x4 gm_mat4x4_mul_scalar(Mat4x4 mat, gmfloat32 scalar) {
	for (int i = 0; i < 16; i++) {
		mat.data[i] *= scalar;
	}

	return mat;
}


Mat3x3 gm_mat3x3_mul_vector(Mat3x3 mat, Vec3 vec) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			mat.m[i][j] *= vec.data[i];
		}
	}

	return mat;
}

Mat4x4 gm_mat4x4_mul_vector(Mat4x4 mat, Vec4 vec) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			mat.m[i][j] *= vec.data[j];
		}
	}

	return mat;
}


Mat3x3 gm_mat3x3_transpose(Mat3x3 mat) {
	Mat3x3 out;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			out.m[i][j] = mat.m[j][i];
		}
	}

	return out;
}

Mat4x4 gm_mat4x4_transpose(Mat4x4 mat) {
	Mat4x4 out;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			out.m[i][j] = mat.m[j][i];
		}
	}

	return out;
}

/*** end of file ***/
