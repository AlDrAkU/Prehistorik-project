#pragma once
#include "Characters.h"
class Pengu :
	public Characters
{
public:
	Pengu();
	enum class ActionState
	{

		moving,
		dying,

	};
	~Pengu();
	virtual void Update(float elapsedSec, const Level& level)override;
	virtual void Draw() override;

	Rectf GetShape();
	const int GetHp();
	void SetHp(int value);
private:
	virtual void Move(float elapsedSec, const Level& level);
	void ChangeFrame(float elapsedSec);
	virtual void DrawSpriteTest(int value)override;

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

