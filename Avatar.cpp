#include "stdafx.h"
#include "Avatar.h"
#include "utils.h"
#include "Matrix2x3.h"
#include "Item.h"
#include "Tiger.h"

Avatar::Avatar() :

	m_HorSpeed{ 200.0f },
	m_JumpSpeed{ 600.0f },
	m_Velocity{},
	m_Acceleration{ 0.0f,-981.0f },
	m_ActionState{},
	m_AccuTransformSec{},
	m_MaxTransformSec{ 1.0f },
	m_SpriteTexture{ "Resources/prehistorik-2-sprites-collage a.png" },
	m_ClipHeight{ 57.f },
	m_ClipWidth{ 57.f },
	m_NrFrameMax{ 3,3,7,6,8,4,5,3,4},
	m_NrOfFrames{3},
	m_NrOfFramesPerSec{ 2*m_NrOfFrames },
	m_AnimTime{},
	m_AnimFrame{},
	 m_Health {3},
	m_Score{0},
	isAttacking{false},
	isWaiting{ true },
	isCrouching{ false },
	isMoving{ false },
	isJumping{ false }

{
	m_Shape = Rectf{10.0f,688.0f,m_ClipWidth,m_ClipHeight };
}




void Avatar::Update(float elapsedSec, const Level& level)
{
	
	
		Move(elapsedSec, level);
	ChangeFrame(elapsedSec);
	if (m_ActionState == ActionState::transforming)
	{
			m_ActionState = ActionState::moving;
			m_NrOfFrames = m_NrFrameMax[int(m_ActionState) + 1];
			
		
	}
	else
	{
		m_Velocity += m_Acceleration* elapsedSec;
		m_Shape.left += m_Velocity.x * elapsedSec;
		m_Shape.bottom += m_Velocity.y * elapsedSec;
		level.HandleCollision(m_Shape, m_Velocity);

		/*if (m_Velocity.x != 0.0f && level.IsOnGround(m_Shape))
		{
			
			if (m_Velocity.y > 25.0f && !level.IsOnGround(m_Shape))
			{
				m_ActionState = ActionState::jumping;
				m_NrOfFrames = m_NrFrameMax[int(m_ActionState) + 1];

			}

			m_ActionState = ActionState::moving;
			m_NrOfFrames = m_NrFrameMax[int(m_ActionState) + 1];
		}
		else if (m_Velocity.y > 25.0f && !level.IsOnGround(m_Shape))
		{
			m_ActionState = ActionState::jumping;
			m_NrOfFrames = m_NrFrameMax[int(m_ActionState) + 1];
		}
		else
		{
			m_ActionState = ActionState::waiting;
			m_NrOfFrames = m_NrFrameMax[int(m_ActionState) + 1];
		}*/
	
	}
	
	
}

void Avatar::Draw()
{
	
	//DrawRectAvatar();
	//DrawSprite();
	DrawSpriteTest();
}

void Avatar::PowerUpHit()
{
	
	
	

	

	/*m_ActionState = ActionState::transforming;
	if (m_Power < 2)
	{
		m_Power++;
	};
	
	m_AnimFrame = 0;*/
}

bool Avatar::IsOverlapping(const Rectf & rect) const
{
	bool result{ false };
	if (utils::IsOverlapping(rect, m_Shape))
	{
		result = true;
	}
	return result;
}

float Avatar::GetXCoord()
{
	return m_Shape.left;
	
}

void Avatar::AttackHit()
{
	Tiger Tiger;
	Rectf tigerShape = Tiger.GetShape();
	int tigerHp;


	if (m_Shape.left   == tigerShape.left - m_Shape.width/2)
	{
		tigerHp = Tiger.GetHp() - 1;
		Tiger.SetHp(tigerHp);
	}
	
}


void Avatar::Move(float elapsedSec, const Level & level)
{

	const Uint8 *pKeysStates = SDL_GetKeyboardState(nullptr);
	if (level.IsOnGround(m_Shape) )  
	{

		if (m_Health <= 0)
		{
			m_ActionState = ActionState::dying;
			m_NrOfFrames = m_NrFrameMax[int(m_ActionState) + 1];
		}
		else
		{
					if (pKeysStates[SDL_SCANCODE_RIGHT])
					{
						
						
						m_ActionState = ActionState::moving;
						m_NrOfFrames = m_NrFrameMax[int(m_ActionState)+1] ;
						m_Velocity.x = m_HorSpeed;

					}
					else if (pKeysStates[SDL_SCANCODE_LEFT])
					{
						
						m_ActionState = ActionState::moving;
						m_NrOfFrames = m_NrFrameMax[int(m_ActionState)+1] ;
						m_Velocity.x = -m_HorSpeed;
											
					}
					else
					{
						m_Velocity.x = 0.0f;
						m_ActionState = ActionState::waiting;
						m_NrOfFrames = m_NrFrameMax[int(m_ActionState) + 1];
					}

					 if (pKeysStates[SDL_SCANCODE_UP])

					{
					
						m_ActionState = ActionState::jumping;
						m_NrOfFrames = m_NrFrameMax[int(m_ActionState)+1];
						m_Velocity.y = m_JumpSpeed;

					}
					else if (pKeysStates[SDL_SCANCODE_DOWN])

					{
						
						m_ActionState = ActionState::crouch;
						m_NrOfFrames = m_NrFrameMax[int(m_ActionState)+1];
						
					}
					else if (pKeysStates[SDL_SCANCODE_SPACE] )
					{
					
						m_ActionState = ActionState::attacking;
						m_NrOfFrames = m_NrFrameMax[int(m_ActionState)+1];
						AttackHit();
			
					}
				
				
			}
		}
					

}
void Avatar::ChangeFrame(float elapsedSec)
{
	m_AnimTime += elapsedSec;
	if (m_AnimTime >= 1.0f/m_NrOfFramesPerSec)
	{
		m_AnimTime = 0.0f;
		m_AnimFrame++;

		if (m_AnimFrame >= m_NrOfFrames)
		{
			m_AnimFrame = 0;
		}
	}
}

////void Avatar::DrawRectAvatar()
////{
////	Rectf powerMeter{ m_Shape.left ,m_Shape.bottom , 10.0f,10.0f };
////
////	switch (m_ActionState)
////	{
////	case ActionState::waiting:
////		utils::SetColor(Color4f(1.0f, 1.0f, 0.0f, 1.0f));
////		utils::FillRect(m_Shape);
////		break;
////	case ActionState::moving:
////		utils::SetColor(Color4f(1.0f, 0.0f, 0.0f, 1.0f));
////		utils::FillRect(m_Shape);
////		break;
////	case ActionState::transforming:
////		utils::SetColor(Color4f(0.0f, 0.0f, 1.0f, 1.0f));
////		utils::FillRect(m_Shape);
////		break;
////	case ActionState::attacking:
////		utils::SetColor(Color4f(0.0f, 0.0f, 1.0f, 1.0f));
////		utils::FillRect(m_Shape);
////		break;
////	case ActionState::dying:
////		utils::SetColor(Color4f(0.0f, 0.0f, 1.0f, 1.0f));
////		utils::FillRect(m_Shape);
////		break;
////	}
////
////	utils::SetColor(Color4f{ 0.0f,1.0f,0.0f,1.0f });
////
////	for (int i = 0; i < m_Power; i++)
////	{
////		utils::FillRect(powerMeter);
////		powerMeter.left += powerMeter.width + 1.0f;
////	}
////}
////
////void Avatar::DrawSprite()
////{
////	int power{m_Power };
////	if (m_ActionState == ActionState::transforming)
////	{
////		power--;
////	}
////	
////
////	Rectf spriteClip{ m_AnimFrame*m_ClipWidth, float((power*( m_ClipHeight))) + float(m_ClipHeight*int(m_ActionState)) + 1 * m_ClipHeight ,m_ClipWidth - 1,m_ClipHeight - 1 };
////	if (m_Velocity.x < 0.0f)
////	{
////		glPushMatrix();
////		glTranslatef(m_Shape.left + (m_Shape.width / 2), m_Shape.bottom + (m_Shape.height / 2.0f), 0.0f);
////		glScalef(-1.0f, 1.0f, 1.0f);
////		glTranslatef(-(m_Shape.left + (m_Shape.width / 2)), -(m_Shape.bottom + (m_Shape.height / 2)), 0.0f);
////		m_SpriteTexture.Draw(m_Shape, spriteClip);
////		glPopMatrix();
////	}
////	else
////	{
////		m_SpriteTexture.Draw(m_Shape, spriteClip);
////	}
////	//std::cout << m_Power << '\n';
////	//std::cout << int(m_ActionState) << '\n';
////
////}

void Avatar::DrawSpriteTest()
{
	
	Rectf spriteClip{ m_AnimFrame*m_ClipWidth, float(((m_ClipHeight))) + float(m_ClipHeight*int(m_ActionState)-1) +  m_ClipHeight ,m_ClipWidth - 1,m_ClipHeight - 1 };
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
	//std::cout << m_Power << '\n';
	//std::cout << int(m_ActionState) << '\n';
}



//void Avatar::ProcessKeyDownEvent(const SDL_KeyboardEvent & e)
//{
//	switch (e.keysym.sym)
//	{
//
//	case SDLK_LEFT:
//		
//			isMoving = true;
//			isWaiting = false;
//		break;
//	case SDLK_RIGHT:
//		
//			isMoving = true;
//			isWaiting = false;
//			m_ActionState = ActionState::moving;
//			m_NrOfFrames = m_NrFrameMax[int(m_ActionState)+1] ;
//			m_Velocity.x = m_HorSpeed;
//		break;
//	case SDLK_UP:
//		m_Velocity.y = m_JumpSpeed;
//		isJumping = true;
//		isWaiting = false;
//		break;
//	case SDLK_DOWN:
//			isCrouching = true;
//			isWaiting = false;
//		break;
//	case SDLK_SPACE:
//			isAttacking = true;
//		m_ActionState = ActionState::attacking;
//		m_NrOfFrames = m_NrFrameMax[int(m_ActionState) + 1];
//		std::cout << "space down "<< '\n';
//			isWaiting = false;
//		break;
//
//	default:
//		break;
//	}
//}
//
//void Avatar::ProcessKeyUpEvent(const SDL_KeyboardEvent & e)
//{
//	switch (e.keysym.sym)
//	{
//
//	case SDLK_LEFT:
//		isMoving = false;
//		isWaiting = true;
//		break;
//	case SDLK_RIGHT:
//		isMoving = false;
//		isWaiting = true;
//		m_ActionState = ActionState::waiting;
//		m_NrOfFrames = m_NrFrameMax[int(m_ActionState) + 1];
//
//		break;
//	case SDLK_UP:
//		isJumping = false;
//		isWaiting = true;
//		break;
//	case SDLK_DOWN:
//		isCrouching = false;
//		isWaiting = true;
//		break;
//	case SDLK_SPACE:
//		std::cout << "space up " << '\n';
//		isAttacking = false;
//		isWaiting = true;
//		m_ActionState = ActionState::waiting;
//		m_NrOfFrames = m_NrFrameMax[int(m_ActionState) + 1];
//		break;
//
//	default:
//		break;
//	}
//}
//


Vector2f Avatar::GetVelocity()
{
	return m_Velocity;
}

Rectf Avatar::GetShape()
{
	return m_Shape;
}

const int Avatar::GetHp()
{
	return m_Health;
}

void Avatar::SetHp(int value)
{
	m_Health = value;
}



