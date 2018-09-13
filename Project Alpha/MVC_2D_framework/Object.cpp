#include "Object.h"
#ifndef __WINDOWS_H__
#include <windows.h> // Header File For Windows
#define __WINDOWS_H__
#endif
#ifndef __GL_H__
#include <gl\gl.h> // Header File For The OpenGL32 Library
#define __GL_H__
#endif
#ifndef __GLU_H__
#include <gl\glu.h> // Header File For The GLu32 Library
#define __GLU_H__
#endif

Object::Object()
{
}


Object::~Object()
{
}

bool Object::GetActive()
{
	return b_active;
}

void Object::SetActive(bool active)
{
	b_active = active;
}

Vector3D Circle::GetPos()
{
	return this->pos;
}

void Circle::SetPos(Vector3D newPos)
{
	pos = newPos;
}

void Circle::Draw()
{
	glPushMatrix();
	glTranslatef(pos.m_x, pos.m_y, pos.m_z);
	glScalef(scale.m_x, scale.m_y, scale.m_z);
	basicShape::drawCircleSolid(0, 0, 1);
	glPopMatrix();
}

Vector3D Circle::scale = Vector3D(1, 1, 1);