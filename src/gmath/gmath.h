/* Provide simple mathematic functions involving vectors and matrices for use with OpenGL */

#ifndef GMATH_H
#define GMATH_H

#define _USE_MATH_DEFINES
#include <math.h>
#include <float.h>

/* ---- Type defines  ----
Define data types to be used internally by GMath. */

typedef float gmfloat32;
typedef enum { GM_FALSE, GM_TRUE } gmboolean;

/* ---- Vector data ---- 
GMath provides functionality for vector procdures. */

typedef union Vec2 {
	struct {
		gmfloat32 x, y;
	};
	gmfloat32 data[2];
} Vec2;

typedef union Vec3 {
	struct { 
		gmfloat32 x, y, z;
	};
	gmfloat32 data[3];
} Vec3;

typedef union Vec4 {
	struct {
		gmfloat32 x, y, z, w;
	};
	gmfloat32 data[4];
} Vec4;

/* ---- Matrix data ---- 
GMath provides functionality for matrix procedures. */

typedef union Mat3x3 {
	struct {
		gmfloat32 m00, m01, m02;
		gmfloat32 m10, m11, m12;
		gmfloat32 m20, m21, m22;
	};
	gmfloat32 data[9];
	gmfloat32 m[3][3];
} Mat3x3;

typedef union Mat4x4 {
	struct {
		gmfloat32 m00, m01, m02, m03;
		gmfloat32 m10, m11, m12, m13;
		gmfloat32 m20, m21, m22, m23;
		gmfloat32 m30, m31, m32, m33;
	};
	gmfloat32 data[16];
	gmfloat32 m[4][4];
} Mat4x4;

/* ---- Set vectors ---- 
Set vector data to specified values. */

extern Vec2 gm_vec2(gmfloat32 x, gmfloat32 y); /* Set vector x and y values. */
extern Vec3 gm_vec3(gmfloat32 x, gmfloat32 y, gmfloat32 z); /* Set vector x, y, and z values. */
extern Vec4 gm_vec4(gmfloat32 x, gmfloat32 y, gmfloat32 z, gmfloat32 w); /* Set vector x, y, z and w values. */

extern Vec2 gm_vec2v(gmfloat32 v); /* Set vector x and y to specified value. */
extern Vec3 gm_vec3v(gmfloat32 v); /* Set vector x, y, and z to specified value. */
extern Vec4 gm_vec4v(gmfloat32 v); /* Set vector x, y, z, and w to specified value.. */

/* ---- Vector arithmetic ----
Modify properties of vectors using mathematics. */

extern Vec2 gm_vec2_add(Vec2 vec, Vec2 vec2); /* Add two vectors together. */
extern Vec3 gm_vec3_add(Vec3 vec, Vec3 vec2); /* Add two vectors together. */
extern Vec4 gm_vec4_add(Vec4 vec, Vec4 vec2); /* Add two vectors together. */

extern Vec2 gm_vec2_sub(Vec2 vec, Vec2 vec2); /* Subtract one vector from another. */
extern Vec3 gm_vec3_sub(Vec3 vec, Vec3 vec2); /* Subtract one vector from another. */
extern Vec4 gm_vec4_sub(Vec4 vec, Vec4 vec2); /* Subtract one vector from another. */

extern Vec2 gm_vec2_mul(Vec2 vec, Vec2 vec2); /* Multiply two vectors together. */
extern Vec3 gm_vec3_mul(Vec3 vec, Vec3 vec2); /* Multiply two vectors together. */
extern Vec4 gm_vec4_mul(Vec4 vec, Vec4 vec2); /* Multiply two vectors together. */

extern Vec2 gm_vec2_mul_scalar(Vec2 vec, gmfloat32 scalar); /* Multiply vector by scalar. */
extern Vec3 gm_vec3_mul_scalar(Vec3 vec, gmfloat32 scalar); /* Multiply vector by scalar. */
extern Vec4 gm_vec4_mul_scalar(Vec4 vec, gmfloat32 scalar); /* Multiply vector by scalar. */

extern gmfloat32 gm_vec2_dot(Vec2 vec, Vec2 vec2); /* Find the dot product of two vectors. */
extern gmfloat32 gm_vec3_dot(Vec3 vec, Vec3 vec2); /* Find the dot product of two vectors. */
extern gmfloat32 gm_vec4_dot(Vec4 vec, Vec4 vec2); /* Find the dot product of two vectors. */

extern gmfloat32 gm_vec2_cross(Vec2 vec, Vec2 vec2); /* Find the cross product of two vectors. */
extern Vec3 gm_vec3_cross(Vec3 vec, Vec3 vec2); /* Find the cross product of two vectors. */

extern gmfloat32 gm_vec2_length_sq(Vec2 vec); /* Return length of squared vector. */
extern gmfloat32 gm_vec3_length_sq(Vec3 vec); /* Return length of squared vector. */
extern gmfloat32 gm_vec4_length_sq(Vec4 vec); /* Return length of squared vector. */

extern gmfloat32 gm_vec2_length(Vec2 vec); /* Return length of vector. */
extern gmfloat32 gm_vec3_length(Vec3 vec); /* Return length of vector. */
extern gmfloat32 gm_vec4_length(Vec4 vec); /* Return length of vector. */

extern gmfloat32 gm_vec2_distance(Vec2 vec, Vec2 vec2); /* Return distance between vectors. */
extern gmfloat32 gm_vec3_distance(Vec3 vec, Vec3 vec2); /* Return distance between vectors. */
extern gmfloat32 gm_vec4_distance(Vec4 vec, Vec4 vec2); /* Return distance between vectors. */

extern Vec2 gm_vec2_normalized(Vec2 vec); /* Normalize vector. */
extern Vec3 gm_vec3_normalized(Vec3 vec); /* Normalize vector. */
extern Vec4 gm_vec4_normalized(Vec4 vec); /* Normalize vector. */

/* ---- Set matrices ---- 
Set matrix data to specified values. */

#define gm_mat3x3_identity() gm_mat3x3vd(1.0f)
#define gm_mat4x4_identity() gm_mat4x4vd(1.0f)

extern Mat3x3 gm_mat3x3(gmfloat32 arr[9]); /* Set matrix values. */
extern Mat4x4 gm_mat4x4(gmfloat32 arr[16]); /* Set matrix values. */

extern Mat3x3 gm_mat3x3v(gmfloat32 val); /* Set matrix attributes to specified value. */
extern Mat4x4 gm_mat4x4v(gmfloat32 val); /* Set matrix attributes to specified value. */

extern Mat3x3 gm_mat3x3vd(gmfloat32 val); /* Set matrices diagonal attributes to specified value. */
extern Mat4x4 gm_mat4x4vd(gmfloat32 val); /* Set matrices diagonal attributes to specified value. */

/* ---- Generate matrices ----
Generate matrices using user given values */

extern Mat4x4 gm_mat4x4_orthographic(gmfloat32 left, gmfloat32 right, gmfloat32 bottom, gmfloat32 top, gmfloat32 near, gmfloat32 far); /* Generate orthographic projection matrix. */
extern Mat4x4 gm_mat4x4_perspective(gmfloat32 fov, gmfloat32 aspect, gmfloat32 near, gmfloat32 far); /* Generate perspective projection matrix. */

extern Mat3x3 gm_mat3x3_translate(Vec2 vec); /* Generate translation matrix using vector. */
extern Mat4x4 gm_mat4x4_translate(Vec3 vec); /* Generate translation matrix using vector. */

extern Mat3x3 gm_mat3x3_scale(Vec2 vec); /* Generate scale matrix using vector provided. */
extern Mat4x4 gm_mat4x4_scale(Vec3 vec); /* Generate scale matrix using vector provided. */

extern Mat3x3 gm_mat3x3_rotate(gmfloat32 angle); /* Generate rotation matrix from an angle. */
extern Mat4x4 gm_mat4x4_rotate(gmfloat32 angle, Vec3 axis); /* Generate rotation matrix from an angle on an axis. */

/* ---- Matrix arithmetic ----
Modify properties of matrices using mathematics. */

extern Mat3x3 gm_mat3x3_add(Mat3x3 mat, Mat3x3 mat2); /* Add two matrices together. */
extern Mat4x4 gm_mat4x4_add(Mat4x4 mat, Mat4x4 mat2); /* Add two matrices together. */

extern Mat3x3 gm_mat3x3_sub(Mat3x3 mat, Mat3x3 mat2); /* Subtract one matrix from another. */
extern Mat4x4 gm_mat4x4_sub(Mat4x4 mat, Mat4x4 mat2); /* Subtract one matrix from another. */

extern Mat3x3 gm_mat3x3_mul(Mat3x3 mat, Mat3x3 mat2); /* Multiply two matrices together. */
extern Mat4x4 gm_mat4x4_mul(Mat4x4 mat, Mat4x4 mat2); /* Multiply two matrices together. */

extern Mat3x3 gm_mat3x3_mul_scalar(Mat3x3 mat, gmfloat32 scalar); /* Multiply matrix by scalar. */
extern Mat4x4 gm_mat4x4_mul_scalar(Mat4x4 mat, gmfloat32 scalar); /* Multiply matrix by scalar. */

extern Mat3x3 gm_mat3x3_mul_vector(Mat3x3 mat, Vec3 vec); /* Multiply matrix by vector. */
extern Mat4x4 gm_mat4x4_mul_vector(Mat4x4 mat, Vec4 vec); /* Multiply matrix by vector. */

extern Mat3x3 gm_mat3x3_transpose(Mat3x3 mat); /* Transpose matrix. */
extern Mat4x4 gm_mat4x4_transpose(Mat4x4 mat); /* Transpose matrix. */

/* ---- Comparison procedures ----
Compare data between variables. */

#define gm_comp(f1, f2) gm_comp_epsilon(f1, f2, FLT_EPSILON) /* Compare two floating point variables. */

#define gm_vec2_comp(vec, vec2) gm_vec2_comp_epsilon(vec, vec2, FLT_EPSILON) /* Compare two vectors. */
#define gm_vec3_comp(vec, vec2) gm_vec3_comp_epsilon(vec, vec2, FLT_EPSILON) /* Compare two vectors. */
#define gm_vec4_comp(vec, vec2) gm_vec4_comp_epsilon(vec, vec2, FLT_EPSILON) /* Compare two vectors. */

#define gm_mat3x3_comp(mat, mat2) gm_mat3x3_comp_epsilon(mat, mat2, FLT_EPSILON) /* Compare two matrices. */
#define gm_mat4x4_comp(mat, mat2) gm_mat4x4_comp_epsilon(mat, mat2, FLT_EPSILON) /* Compare two matrices. */

extern gmboolean gm_comp_epsilon(gmfloat32 f1, gmfloat32 f2, gmfloat32 tolerance); /* Compare two floating point variables within a given range. */

extern gmboolean gm_vec2_comp_epsilon(Vec2 vec, Vec2 vec2, gmfloat32 tolerance); /* Compare two vectors within a given range. */
extern gmboolean gm_vec3_comp_epsilon(Vec3 vec, Vec3 vec2, gmfloat32 tolerance); /* Compare two vectors within a given range. */
extern gmboolean gm_vec4_comp_epsilon(Vec4 vec, Vec4 vec2, gmfloat32 tolerance); /* Compare two vectors within a given range. */

extern gmboolean gm_mat3x3_comp_epsilon(Mat3x3 mat, Mat3x3 mat2, gmfloat32 tolerance); /* Compare two matrices within a given range. */
extern gmboolean gm_mat4x4_comp_epsilon(Mat4x4 mat, Mat4x4 mat2, gmfloat32 tolerance); /* Compare two matrices within a given range. */

/* ---- Conversion procedures ----
Convert data between variables. */

extern gmfloat32 gm_conv_deg_rad(gmfloat32 deg); /* Convert degrees into radians. */
extern gmfloat32 gm_conv_rad_deg(gmfloat32 rad); /* Convert radians into degrees. */

#endif /* GMATH */

/*** end of file ***/
