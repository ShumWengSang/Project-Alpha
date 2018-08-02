#pragma once
#include "vector3D.h"
#include "basicShape.h"
//Very basic object pool with minimal optimization.
class Circle;

class Object
{
	//We do this so that only the pool can create Object
	//Don't let fools (me) create out of nowhere
	template <class C> friend class ObjectPool;
	friend class Circle;
public:
	bool GetActive();
	void SetActive(bool);

public:
	virtual void Draw()
	{
		
	}
	virtual void Update()
	{

	}
private:
	bool b_active = false;

private:
	Object();
	~Object();
};


class Circle : public Object
{
private:
	Vector3D vel;
	Vector3D pos;
	Vector3D color;
	Vector3D scale;
public:
	Circle() {}
	~Circle() {}

	void Draw()
	{
		basicShape::drawSphere(5.f);
	}
};

template <class T>
class ObjectPool
{
private:
	const static int POOL_SIZE = 100;

	T ObjPool[POOL_SIZE];
public:

	Object * GetAvailable();
};

template <>
class ObjectPool<Circle>{
	const static int POOL_SIZE = 100;

	Circle ObjPool[POOL_SIZE];
public:

	Object * GetAvailable()
	{
		for (int i = 0; i < POOL_SIZE; i++)
		{
			if (!ObjPool[i].GetActive())
			{
				ObjPool[i].SetActive(true);
				return &ObjPool[i];
			}
		}
	}
};