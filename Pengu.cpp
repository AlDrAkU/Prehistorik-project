#include "stdafx.h"
#include "Pengu.h"


Pengu::Pengu() :m_HorSpeed{ 200.0f },
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
	m_Shape = Rectf{ 350.0f,988.0f,m_ClipWidth,m_ClipHeight };
}


Pengu::~Pengu()
{
}

void Pengu::Update(float elapsedSec, const Level & level)
{
	if (m_Health == 0)
	{
		m_isDead = true;
		m_ActionState = Pengu::ActionState::dying;
	}

	Move(elapsedSec, level);
	ChangeFrame(elapsedSec);

	m_Velocity += m_Acceleration* elapsedSec;
	m_Shape.left += m_Velocity.x * elapsedSec;
	m_Shape.bottom += m_Velocity.y * elapsedSec;
	level.HandleCollision(m_Shape, m_Velocity);
}

void Pengu::Draw()
{
	if (m_isSpawning == true)
	{
		DrawSpriteTest(12);
		m_isSpawning = false;

	}
	else if (!m_isSpawning)
	{
		m_NrOfFrames = 2;
		DrawSpriteTest(12);
	}
}

Rectf Pengu::GetShape()
{
	return m_Shape;
}

const int Pengu::GetHp()
{
	return m_Health;
}

void Pengu::SetHp(int value)
{
	m_Health = value;
}

void Pengu::Move(float elapsedSec, const Level & level)
{
	if (!m_isSpawning)
	{

		m_Velocity.x -= 1;

	}
}

void Pengu::ChangeFrame(float elapsedSec)
{
	m_AnimTime += elapsedSec;
	if (m_AnimTime >= 1.0f / m_NrOfFramesPerSec)
	{
		m_AnimTime = 0.0f;
		m_AnimFrame++;

		if (m_AnimFrame >= m_NrOfFrames)
		{
			m_AnimFrame = 0;
		}
	}
}

void Pengu::DrawSpriteTest(int value)
{
	Rectf spriteClip{ m_AnimFrame*m_ClipWidth, float(((m_ClipHeight))) + float(m_ClipHeight*int(value) - 1) + m_ClipHeight ,m_ClipWidth - 1,m_ClipHeight - 1 };
	if (m_Velocity.x < 0.0f)
	{
		glPushMatrix();
		glTranslatef(m_Shape.left + (m_Shape.width / 2), m_Shape.bottom + (m_Shape.height / 2.0f), 0.0f);
		glScalef(-1.0f, 1.0f, 1.0f);
		glTranslatef(-(m_Shape.left + (m_Shape.width / 2)), -(m_Shape.bottom + (m_Shape.height / 2)), 0.0f);
		m_SpriteTexture.Draw(m_Shape, spriteClip);
		glPopMatrix();
	}
	else
	{
		m_SpriteTexture.Draw(m_Shape, spriteClip);
	}
}
