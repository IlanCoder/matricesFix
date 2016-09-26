#include "Mat4.h"

Mat4::Mat4(){
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j) {
				mat4[i][j] = 1;
			}
			else {
				mat4[i][j] = 0;
			}
		}
	}
}

Mat4::Mat4(Vec4 &vec1, Vec4 &vec2, Vec4 &vec3, Vec4 &vec4){
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == 0) {
				mat4[i][j] = vec1.vec4[j];
			}
			else if (i == 1) {
				mat4[i][j] = vec2.vec4[j];
			}
			else if (i == 2) {
				mat4[i][j] = vec3.vec4[j];
			}
			else {
				mat4[i][j] = vec4.vec4[j];
			}
		}
	}
}

Mat4 Mat4::operator*(Mat4 & right){
	Mat4 matR;
	cout << "matrizR" << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matR.mat4[i][j] = 0;
			for (int k = 0; k < 4; k++) {
				matR.mat4[i][j] += mat4[i][k] * right.mat4[k][j];
			}
		}
		cout << matR.mat4[i][0] << "," << matR.mat4[i][1] << "," << matR.mat4[i][2] << "," << matR.mat4[i][3] << endl;
	}
	return matR;
}

Vec4 Mat4::operator*(Vec4 & right){
	Vec4 vecR = Vec4(0, 0, 0, 0);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			vecR.vec4[i] += mat4[i][j] * right.vec4[j];
		}
	}
	cout << vecR.vec4[0] << "," << vecR.vec4[1] << "," << vecR.vec4[2] << "," << vecR.vec4[3] << endl;
	return vecR;
}

Mat4 Mat4::rotateX(const float angle){
	float rad = angle / 180;
	Mat4 rm = Mat4(Vec4(1, 0, 0, 0), Vec4(0, cos(rad), -sin(rad), 0), Vec4(0, sin(rad), cos(rad), 0));
	Mat4 ma = Mat4(Vec4(mat4[0][0], mat4[0][1], mat4[0][2], mat4[0][3]),
		Vec4(mat4[1][0], mat4[1][1], mat4[1][2], mat4[1][3]),
		Vec4(mat4[2][0], mat4[2][1], mat4[2][2], mat4[2][3]),
		Vec4(mat4[3][0], mat4[3][1], mat4[3][2], mat4[3][3]));
	return rm*ma;
}

Mat4 Mat4::rotateY(const float angle){
	float rad = angle / 180;
	Mat4 rm = Mat4(Vec4(cos(rad), 0,sin(rad), 0), Vec4(0, 1, 0, 0), Vec4(-sin(rad), 0, cos(rad), 0));
	Mat4 ma = Mat4(Vec4(mat4[0][0], mat4[0][1], mat4[0][2], mat4[0][3]),
		Vec4(mat4[1][0], mat4[1][1], mat4[1][2], mat4[1][3]),
		Vec4(mat4[2][0], mat4[2][1], mat4[2][2], mat4[2][3]),
		Vec4(mat4[3][0], mat4[3][1], mat4[3][2], mat4[3][3]));
	return rm*ma;
}

Mat4 Mat4::rotateZ(const float angle){
	float rad = angle / 180;
	Mat4 rm = Mat4(Vec4(cos(rad), -sin(rad), 0, 0), Vec4(sin(rad), cos(rad), 0, 0), Vec4(0,0, 1, 0));
	Mat4 ma = Mat4(Vec4(mat4[0][0], mat4[0][1], mat4[0][2], mat4[0][3]),
		Vec4(mat4[1][0], mat4[1][1], mat4[1][2], mat4[1][3]),
		Vec4(mat4[2][0], mat4[2][1], mat4[2][2], mat4[2][3]),
		Vec4(mat4[3][0], mat4[3][1], mat4[3][2], mat4[3][3]));
	return rm*ma;
}

Mat4 Mat4::translate(const float x, const float y, const float z){
	Mat4 tm = Mat4(Vec4(1, 0, 0,x), Vec4(0, 1, 0,y), Vec4(0, 0, 1, z));
	Mat4 ma = Mat4(Vec4(mat4[0][0], mat4[0][1], mat4[0][2], mat4[0][3]), 
		Vec4(mat4[1][0], mat4[1][1], mat4[1][2], mat4[1][3]), 
		Vec4(mat4[2][0], mat4[2][1], mat4[2][2], mat4[2][3]), 
		Vec4(mat4[3][0], mat4[3][1], mat4[3][2], mat4[3][3]));
	return tm*ma;
}

Mat4 Mat4::shear(const float x, const float y, const float z){
	Mat4 sm = Mat4(Vec4(1,x, z, 0), Vec4(y, 1, z, 0), Vec4(y, x, 1, 0));
	Mat4 ma = Mat4(Vec4(mat4[0][0], mat4[0][1], mat4[0][2], mat4[0][3]),
		Vec4(mat4[1][0], mat4[1][1], mat4[1][2], mat4[1][3]),
		Vec4(mat4[2][0], mat4[2][1], mat4[2][2], mat4[2][3]),
		Vec4(mat4[3][0], mat4[3][1], mat4[3][2], mat4[3][3]));
	return sm*ma;
}

Mat4 Mat4::scale(const float x, const float y, const float z){
	Mat4 sm = Mat4(Vec4(x, 0, 0, 0), Vec4(0, y, 0, 0), Vec4(0, 0, z, 0));
	Mat4 ma = Mat4(Vec4(mat4[0][0], mat4[0][1], mat4[0][2], mat4[0][3]),
		Vec4(mat4[1][0], mat4[1][1], mat4[1][2], mat4[1][3]),
		Vec4(mat4[2][0], mat4[2][1], mat4[2][2], mat4[2][3]),
		Vec4(mat4[3][0], mat4[3][1], mat4[3][2], mat4[3][3]));
	return sm*ma;
}

Mat4 Mat4::lookAt(Vec4 &eye, Vec4 &target, Vec4 &up){
	Vec4 w = Vec4(0, 0, 0, 0);
	Vec4 u = Vec4(0, 0, 0, 0);
	Vec4 v = Vec4(0, 0, 0, 0);
	w = w.normalize(target - eye);
	u = u.normalize(w.cross(up));
	v = v.normalize(u.cross(w));
	Mat4 matR = Mat4(Vec4(u.vec4[0],u.vec4[1],u.vec4[2],0), 
		Vec4(v.vec4[0], v.vec4[1], v.vec4[2], 0), 
		Vec4(w.vec4[0], w.vec4[1], w.vec4[2], 0));
	Mat4 matT = Mat4(Vec4(1,0,0,-eye.vec4[0]), 
		Vec4(0, 1, 0, -eye.vec4[1]), 
		Vec4(0, 0, 1, -eye.vec4[2]));
	return matT*matR;
}
