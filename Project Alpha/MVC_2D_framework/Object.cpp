#include "Object.h"



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