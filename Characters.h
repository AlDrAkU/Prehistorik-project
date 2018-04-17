#pragma once
#include "Level.h"
#include "Avatar.h"
#include "Item.h"
class Characters
{
public:
	Characters();
	enum class ActionState
	{
		appearing,
		moving,
		dying,

	};
	~Characters();
	virtual void Update(float elapsedSec, const Level& level)=0;
	virtual void Draw()=0;
	virtual void Move(float elapsedSec, const Level& level)=0;
	virtual void ChangeFrame(float elapsedSec);
	virtual void DrawSpriteTest(int value)=0;
private:
	const float m_HorSpeed;
	const float m_JumpSpeed;
	const float m_ClipHeight;
	const float m_ClipWidth;
	int m_NrOfFrames{};
	const std::vector<int> m_NrFrameMax{};
	const int m_NrOfFramesPerSec;
	bool m_isSpawning;
	Rectf m_Shape;
	Vector2f m_Velocity;
	Vector2f m_Acceleration;
	ActionState m_ActionState;
	Texture m_SpriteTexture;
	int m_AnimFrame;
	float m_AnimTime;
	int m_Health;
	bool m_isDead;

};

