#ifndef __BASIC_H__
#define __BASIC_H__

namespace basicShape
{
	void drawAxis();
	float GetRad(float degree);
	void drawCube();
	void drawSquare();//square

	//Sphere
	float GetX(float phi,float theta,float radius);
	float GetY(float phi,float radius);
	float GetZ(float phi,float theta,float radius);
	void drawSphere(float radius);
	void drawCircleOutline(float cx, float cy, float r, int num_segments);
	void drawCircleSolid(float x, float y, float radius);

	//Cylinder
	float GetCX(float theta,float radius);
	float GetCZ(float theta,float radius);
	void drawCylinder(float scale,float scalez=2);
}

#endif
