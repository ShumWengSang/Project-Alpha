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
#pragma once
#include "basicShape.h"


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
	m_moveX=m_moveY=0;
	return true;
}

bool MVC_Model::InitPhase2(void)
{
	m_testX=m_worldSizeX*0.5f;
	m_testY=m_worldSizeY*0.5f;
	return true;
}

// Update the model
void MVC_Model::Update(void)
{
	m_timer->UpdateTime();
	if(m_timer->TestFramerate())
	{
		m_testX+=m_moveX*m_timer->GetDelta();
		m_testY+=m_moveY*m_timer->GetDelta();
	}
}

void MVC_Model::Draw()
{
	glColor3f(0, 0, 1);
	basicShape::drawSphere(5.0f);
	basicShape::drawSquare();
}



