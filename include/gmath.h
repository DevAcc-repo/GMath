/* Provide simple mathematic functions involving vectors and matrices for use with OpenGL */

#ifndef GMATH_H
#define GMATH_H

#include <stdlib.h>

#define _USE_MATH_DEFINES
#include <math.h>
#include <float.h>

#ifdef _cplusplus
	extern "C" {
#endif

/* ---- Type defines  ----
Define data types to be used internally by GMath. */

/* WARNING: The use of doubles is currently untested. */
#if GM_USE_DOUBLE
	typedef double gmfloat;
#else
	typedef float gmfloat;
#endif

typedef enum { GM_FALSE, GM_TRUE } gmboolean;

typedef gmfloat vector2[2];
typedef gmfloat vector3[3];
typedef gmfloat vector4[4];

typedef gmfloat matrix3x3[9];
typedef gmfloat matrix4x4[16];

/* ---- Set vectors ---- 
Set vector data to specified values. */

extern void gm_vector2(vector2 dest, gmfloat x, gmfloat y); /* Set vector x and y values. */
extern void gm_vector3(vector3 dest, gmfloat x, gmfloat y, gmfloat z); /* Set vector x, y, and z values. */
extern void gm_vector4(vector4 dest, gmfloat x, gmfloat y, gmfloat z, gmfloat w); /* Set vector x, y, z and w values. */

extern void gm_vector2v(vector2 dest, gmfloat v); /* Set vector x and y to specified value. */
extern void gm_vector3v(vector3 dest, gmfloat v); /* Set vector x, y, and z to specified value. */
extern void gm_vector4v(vector4 dest, gmfloat v); /* Set vector x, y, z, and w to specified value.. */

/* ---- vector arithmetic ----
Modify properties of vectors using mathematics. */

extern void gm_vector2_add(vector2 dest, vector2 vec); /* Add two vectors together. */
extern void gm_vector3_add(vector3 dest, vector3 vec); /* Add two vectors together. */
extern void gm_vector4_add(vector4 dest, vector4 vec); /* Add two vectors together. */

extern void gm_vector2_sub(vector2 dest, vector2 vec); /* Subtract one vector from another. */
extern void gm_vector3_sub(vector3 dest, vector3 vec); /* Subtract one vector from another. */
extern void gm_vector4_sub(vector4 dest, vector4 vec); /* Subtract one vector from another. */

extern void gm_vector2_mul(vector2 dest, vector2 vec); /* Multiply two vectors together. */
extern void gm_vector3_mul(vector3 dest, vector3 vec); /* Multiply two vectors together. */
extern void gm_vector4_mul(vector4 dest, vector4 vec); /* Multiply two vectors together. */

extern void gm_vector2_mul_scalar(vector2 dest, gmfloat scalar); /* Multiply vector by scalar. */
extern void gm_vector3_mul_scalar(vector3 dest, gmfloat scalar); /* Multiply vector by scalar. */
extern void gm_vector4_mul_scalar(vector4 dest, gmfloat scalar); /* Multiply vector by scalar. */

extern gmfloat gm_vector2_dot(vector2 vec, vector2 vec2); /* Find the dot product of two vectors. */
extern gmfloat gm_vector3_dot(vector3 vec, vector3 vec2); /* Find the dot product of two vectors. */
extern gmfloat gm_vector4_dot(vector4 vec, vector4 vec2); /* Find the dot product of two vectors. */

extern gmfloat gm_vector2_cross(vector2 vec, vector2 vec2); /* Find the cross product of two vectors. */
extern void gm_vector3_cross(vector3 dest, vector3 vec); /* Find the cross product of two vectors. */

extern gmfloat gm_vector2_length_sq(vector2 vec); /* Return length of squared vector. */
extern gmfloat gm_vector3_length_sq(vector3 vec); /* Return length of squared vector. */
extern gmfloat gm_vector4_length_sq(vector4 vec); /* Return length of squared vector. */

extern gmfloat gm_vector2_length(vector2 vec); /* Return length of vector. */
extern gmfloat gm_vector3_length(vector3 vec); /* Return length of vector. */
extern gmfloat gm_vector4_length(vector4 vec); /* Return length of vector. */

extern gmfloat gm_vector2_distance(vector2 vec, vector2 vec2); /* Return distance between vectors. */
extern gmfloat gm_vector3_distance(vector3 vec, vector3 vec2); /* Return distance between vectors. */
extern gmfloat gm_vector4_distance(vector4 vec, vector4 vec2); /* Return distance between vectors. */

extern void gm_vector2_normalized(vector2 dest); /* Normalize vector. */
extern void gm_vector3_normalized(vector3 dest); /* Normalize vector. */
extern void gm_vector4_normalized(vector4 dest); /* Normalize vector. */

/* ---- Set matrices ---- 
Set matrix data to specified values. */

#define gm_matrix3x3_identity(dest) gm_matrix3x3vd(dest, 1.0)
#define gm_matrix4x4_identity(dest) gm_matrix4x4vd(dest, 1.0)

extern void gm_matrix3x3v(matrix3x3 dest, gmfloat val); /* Set matrix attributes to specified value. */
extern void gm_matrix4x4v(matrix4x4 dest, gmfloat val); /* Set matrix attributes to specified value. */

extern void gm_matrix3x3vd(matrix3x3 dest, gmfloat val); /* Set matrices diagonal attributes to specified value. */
extern void gm_matrix4x4vd(matrix4x4 dest, gmfloat val); /* Set matrices diagonal attributes to specified value. */

/* ---- Generate matrices ----
Generate matrices using user given values */

extern void gm_matrix4x4_ortho(matrix4x4 dest, gmfloat left, gmfloat right, gmfloat bottom, gmfloat top, gmfloat near, gmfloat far); /* Generate orthographic projection matrix. */
extern void gm_matrix4x4_perspective(matrix4x4 dest, gmfloat fov, gmfloat aspect, gmfloat near, gmfloat far); /* Generate perspective projection matrix. */

extern void gm_matrix3x3_translate(matrix3x3 dest, vector2 vec); /* Generate translation matrix using vector. */
extern void gm_matrix4x4_translate(matrix4x4 dest, vector3 vec); /* Generate translation matrix using vector. */

extern void gm_matrix3x3_scale(matrix3x3 dest, vector2 vec); /* Generate scale matrix using vector provided. */
extern void gm_matrix4x4_scale(matrix4x4 dest, vector3 vec); /* Generate scale matrix using vector provided. */

extern void gm_matrix3x3_rotate(matrix3x3 dest, gmfloat angle); /* Generate rotation matrix from an angle. */
extern void gm_matrix4x4_rotate(matrix4x4 dest, gmfloat angle, vector3 axis); /* Generate rotation matrix from an angle on an axis. */

/* ---- matrix arithmetic ----
Modify properties of matrices using mathematics. */

extern void gm_matrix3x3_add(matrix3x3 dest, matrix3x3 mat); /* Add two matrices together. */
extern void gm_matrix4x4_add(matrix4x4 dest, matrix4x4 mat); /* Add two matrices together. */

extern void gm_matrix3x3_sub(matrix3x3 dest, matrix3x3 mat); /* Subtract one matrix from another. */
extern void gm_matrix4x4_sub(matrix4x4 dest, matrix4x4 mat); /* Subtract one matrix from another. */

extern void gm_matrix3x3_mul(matrix3x3 dest, matrix3x3 mat); /* Multiply two matrices together. */
extern void gm_matrix4x4_mul(matrix4x4 dest, matrix4x4 mat); /* Multiply two matrices together. */

extern void gm_matrix3x3_mul_scalar(matrix3x3 dest, gmfloat scalar); /* Multiply matrix by scalar. */
extern void gm_matrix4x4_mul_scalar(matrix4x4 dest, gmfloat scalar); /* Multiply matrix by scalar. */

extern void gm_matrix3x3_mul_vector(matrix3x3 dest, vector3 vec); /* Multiply matrix by vector. */
extern void gm_matrix4x4_mul_vector(matrix4x4 dest, vector4 vec); /* Multiply matrix by vector. */

extern void gm_matrix3x3_transpose(matrix3x3 dest); /* Transpose matrix. */
extern void gm_matrix4x4_transpose(matrix4x4 dest); /* Transpose matrix. */

/* ---- Comparison procedures ----
Compare data between variables. */

#define gm_comp(f1, f2) gm_comp_epsilon(f1, f2, FLT_EPSILON) /* Compare two floating point variables. */

#define gm_vec2_comp(vec, vec2) gm_vec2_comp_epsilon(vec, vec2, FLT_EPSILON) /* Compare two vectors. */
#define gm_vec3_comp(vec, vec2) gm_vec3_comp_epsilon(vec, vec2, FLT_EPSILON) /* Compare two vectors. */
#define gm_vec4_comp(vec, vec2) gm_vec4_comp_epsilon(vec, vec2, FLT_EPSILON) /* Compare two vectors. */

#define gm_matrix3x3_comp(mat, mat2) gm_matrix3x3_comp_epsilon(mat, mat2, FLT_EPSILON) /* Compare two matrices. */
#define gm_matrix4x4_comp(mat, mat2) gm_matrix4x4_comp_epsilon(mat, mat2, FLT_EPSILON) /* Compare two matrices. */

extern gmboolean gm_comp_epsilon(gmfloat f1, gmfloat f2, gmfloat tolerance); /* Compare two floating point variables within a given range. */

extern gmboolean gm_vec2_comp_epsilon(vector2 vec, vector2 vec2, gmfloat tolerance); /* Compare two vectors within a given range. */
extern gmboolean gm_vec3_comp_epsilon(vector3 vec, vector3 vec2, gmfloat tolerance); /* Compare two vectors within a given range. */
extern gmboolean gm_vec4_comp_epsilon(vector4 vec, vector4 vec2, gmfloat tolerance); /* Compare two vectors within a given range. */

extern gmboolean gm_matrix3x3_comp_epsilon(matrix3x3 mat, matrix3x3 mat2, gmfloat tolerance); /* Compare two matrices within a given range. */
extern gmboolean gm_matrix4x4_comp_epsilon(matrix4x4 mat, matrix4x4 mat2, gmfloat tolerance); /* Compare two matrices within a given range. */

/* ---- Conversion procedures ----
Convert data between variables. */

extern gmfloat gm_conv_deg_rad(gmfloat deg); /* Convert degrees into radians. */
extern gmfloat gm_conv_rad_deg(gmfloat rad); /* Convert radians into degrees. */

#ifdef _cplusplus
	}
#endif

#endif /* GMATH */

/*** end of file ***/
