//*************************************************************************************************************************************//
//
//	Original MVC framework made by Mr Toh Da Jun for DM2231 Game Development Techniques
//	Adapted and modified by Kennard Kee Wei Sheng
//
//************************************************************************************************************************************//
#ifndef __MVC_MODEL_H__
#include "MVC_Model.h"
#endif
#ifndef __MVC_TIME_H__
#include "MVCtime.h"
#endif


MVC_Model::MVC_Model(void)
{
	m_timer=MVCTime::GetInstance();
}

MVC_Model::~MVC_Model(void)
{
}

bool MVC_Model::Init(float fpsLimit)
{
	m_timer->Init(true,int(fpsLimit));
	return true;
}

bool MVC_Model::InitPhase2(void)
{
	Objects.push_back(CirclePool.GetAvailable());
	return true;
}

// Update the model
void MVC_Model::Update(void)
{
	m_timer->UpdateTime();
	if(m_timer->TestFramerate())
	{
		for each (auto obj in Objects)
		{
			obj->Update();
		}
	}
}

void MVC_Model::Draw()
{
	glColor3f(0, 0, 1);
	glTranslatef(m_worldSizeX *0.5f, m_worldSizeY*0.5f, 0);
	for each (auto obj in Objects)
	{
		obj->Draw();
	}
}



