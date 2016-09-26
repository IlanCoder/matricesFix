#include "Vec3.h"

Vec3::Vec3(){
	vec3[0] = 0;
	vec3[1] = 0;
	vec3[2] = 1;
}

Vec3::Vec3(const float &x,const float &y,const float &z) {
	cout << "vector" <<endl;
	vec3[0] = x;
	vec3[1] = y;
	vec3[2] = z;
	cout << vec3[0] << "," << vec3[1] << "," << vec3[2] << endl;
}

Vec3 Vec3::operator+(Vec3 &right){
	cout << vec3[0] + right.vec3[0] << "," << vec3[1] + right.vec3[1]<<endl;
	return Vec3(vec3[0]+ right.vec3[0],vec3[1] + right.vec3[1]);
}

Vec3 Vec3::operator-(Vec3 &right){
	cout << vec3[0] - right.vec3[0] << "," << vec3[1] - right.vec3[1] << endl;
	return Vec3(vec3[0] - right.vec3[0], vec3[1] - right.vec3[1]);
}

Vec3 Vec3::operator*(Vec3 &right){
	cout << vec3[0] * right.vec3[0] << "," << vec3[1] * right.vec3[1] << endl;
	return Vec3(vec3[0] * right.vec3[0], vec3[1] * right.vec3[1]);
}

Vec3 Vec3::operator*(const float num){
	cout << vec3[0] * num << "," << vec3[1] * num << endl;
	return Vec3(vec3[0] * num, vec3[1] * num);
}

Vec3 Vec3::normalize(Vec3 &vec){
	float length = sqrt(pow(vec.vec3[0], 2) + pow(vec.vec3[1], 2) + pow(vec.vec3[2], 2));
	cout << vec3[0] / length << "," << vec3[1] / length << "," << vec3[2] / length << endl;
	return Vec3(vec3[0] /length, vec3[1] / length, vec3[2] / length);
}

float Vec3::point(Vec3 &vec){
	float point = 0;
	for (int i = 0; i < 3; i++) {
		point+= vec3[i] * vec.vec3[i];
	}
	cout << point << endl;
	return point;
}

Vec3 Vec3::cross(Vec3 &vec){
	Vec3 temp;
	temp.vec3[0] = vec3[1] * vec.vec3[2] -(vec3[2] * vec.vec3[1]);
	temp.vec3[1] = vec3[0] * vec.vec3[2] - (vec3[2] * vec.vec3[0]);
	temp.vec3[2] = vec3[0] * vec.vec3[1] - (vec3[1] * vec.vec3[0]);
	cout << temp.vec3[0]<< "," << temp.vec3[1]<< "," << temp.vec3[2]<< endl;
	return temp;
}
