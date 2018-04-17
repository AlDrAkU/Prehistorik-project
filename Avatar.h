#pragma once
#include "Vector2f.h"
#include "Level.h"
#include "Item.h"
class Avatar
{
public:
	enum class ActionState
	{
		waiting,
		idle, 
		moving,
		crouch ,
		attacking,
		jumping,
		falling, 
		dying, 
		transforming
	};

	Avatar();
	void Update(float elapsedSec, const Level& level);
	void Draw();
	void PowerUpHit();
	bool IsOverlapping(const Rectf& rect) const;
	float GetXCoord();
	void AttackHit();

	Vector2f GetVelocity();
	Rectf GetShape();
	const int GetHp();
	void SetHp(int value);
	Item::Type m_TypeOfItem;
	bool isAttacking;
	bool isWaiting;
	bool isCrouching;
	bool isMoving;
	bool isJumping;
	
private:

	void Move(float elapsedSec, const Level& level);
	void ChangeFrame(float elapsedSec);
	/*void DrawRectAvatar();
	void DrawSprite();*/
	void DrawSpriteTest();




	const float m_HorSpeed;
	const float m_JumpSpeed;
	const float m_MaxTransformSec;
	const float m_ClipHeight;
	const float m_ClipWidth;
	int m_NrOfFrames{};
	const std::vector<int> m_NrFrameMax{};
	const int m_NrOfFramesPerSec;

	Rectf m_Shape;
	Vector2f m_Velocity;
	Vector2f m_Acceleration;
	ActionState m_ActionState;
	Texture m_SpriteTexture;
	float m_AccuTransformSec;
	int m_AnimFrame;
	float m_AnimTime;
	signed int m_Health;
	int m_Score;

};

