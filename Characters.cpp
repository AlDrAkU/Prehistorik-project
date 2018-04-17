#include "stdafx.h"
#include "Characters.h"
#include "Avatar.h"


Characters::Characters()
	:m_HorSpeed{ 200.0f },
	m_JumpSpeed{ 600.0f },
	m_Velocity{},
	m_Acceleration{ 0.0f,-981.0f },
	m_ActionState{},
	m_SpriteTexture{ "Resources/prehistorik-2-sprites-collage a.png" },
	m_ClipHeight{ 57.f },
	m_ClipWidth{ 57.f },
	m_NrFrameMax{ 3,3,7,6,8,4,5,3,4,4,2,5,2,3 },
	m_NrOfFrames{ 5 },
	m_NrOfFramesPerSec{ m_NrOfFrames },
	m_AnimTime{},
	m_AnimFrame{},
	m_Health{ 1 },
	m_isSpawning{ true },
	m_isDead{ false }
{
	m_Shape = Rectf{ 110.0f,688.0f,m_ClipWidth,m_ClipHeight };
}


Characters::~Characters()
{
}

void Characters::ChangeFrame(float elapsedSec)
{
	
}
