#pragma once
#include <map>
#include "Object.h"
#include "obj_enum.h"

class AdvancedFactory
{
public:

	static AdvancedFactory * GetInstance()
	{
		static AdvancedFactory instance; //Guranteed to be destroyed
		return &instance;
	}

public:
	template <typename T>
	void Register(Obj_Name name)
	{
		m_FactoryMap[name] = &CreateFunc<T>;
	}
private:
	template <typename T>
	static Object* CreateFunc()
	{
		static ObjectPool<T> pool;
		return pool.GetAvailable();
	}
public:
	Object * Create(Obj_Name name)
	{
		FactoryMap::iterator it = m_FactoryMap.find(name);
		if (it != m_FactoryMap.end())
		{
			CreateFn create_func = it->second;
			return create_func();
		}
		return NULL;
	}
private:
	typedef Object * (*CreateFn)(void);
	typedef std::map<Obj_Name, CreateFn> FactoryMap;
	FactoryMap m_FactoryMap;

};