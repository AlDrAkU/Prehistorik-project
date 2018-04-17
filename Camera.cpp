#include "stdafx.h"
#include "Camera.h"
#include "utils.h"


Camera::Camera(float width, float height) :
	m_Width{ width },
	m_Height{ height },
	m_Boundaries{ 0,0,width/2,height/2 },
	m_Pos{ 0.0f,0.0f }
{
}

void Camera::SetBoundaries(const Rectf & boundaries)
{
	m_Boundaries =  boundaries;
}

void Camera::Draw()
{
	utils::DrawRect(Rectf{ m_Pos.x,m_Pos.y,m_Width,m_Height });
	Rectf deadzone{ m_Pos.x + (m_Width / 3.0f) , m_Pos.y + (m_Height / 3.0f) , m_Width / 3.0f, m_Height / 3.0f };
	utils::DrawRect(deadzone);
}

Point2f Camera::GetPosition() const
{
	return m_Pos;
}

void Camera::InitPos(const Rectf & toTrack)
{
	m_Pos = Point2f{ toTrack.left + (toTrack.width / 2) - (m_Width / 2.0f),toTrack.bottom + (toTrack.height / 2) - (m_Height / 2.0f) };
	Clamp(m_Pos);
}

void Camera::Update(const Rectf & toTrack, float elapsedSec, Vector2f velocity)
{
	Track(toTrack, velocity);
	m_Pos.x += m_Velocity.x * elapsedSec;
	m_Pos.y += m_Velocity.y * elapsedSec;
	Clamp(m_Pos);
}

void Camera::Track(const Rectf & toTrack, Vector2f velocity)
{
	if ((toTrack.left + toTrack.width) > (m_Pos.x + m_Width))
	{
		m_Pos.x += ((toTrack.left + toTrack.width) - (m_Pos.x + m_Height));
	}
	else if(toTrack.left < m_Pos.x)
	{
		m_Pos.x += (toTrack.left - m_Pos.x);
	}
	else if ((toTrack.left) > (m_Pos.x + m_Width/2) || (toTrack.left < (m_Pos.x + m_Width / 2)))
	{
		m_Velocity.x = (toTrack.left - (m_Pos.x + (m_Width / 2)));
	}
	else
	{
		m_Velocity.x = 0.0f;
	}

	if ((toTrack.bottom + toTrack.height) >= (m_Pos.y + m_Height))
	{
		m_Velocity.y = velocity.y;
	}
	else if(toTrack.bottom < m_Pos.y)
	{
		m_Pos.y += (toTrack.bottom - m_Pos.y);
	}
	else if ((toTrack.bottom) > (m_Pos.y + m_Height/2) || (toTrack.bottom < (m_Pos.y + m_Height / 2)))
	{
		m_Velocity.y = (toTrack.bottom - (m_Pos.y + (m_Height / 2)));
	}
	else
	{
		m_Velocity.y = 0.0f;
	}
}

void Camera::Clamp(Point2f& bottomLeft)
{
	if (bottomLeft.x > (m_Boundaries.width-m_Width))
	{
		bottomLeft.x = m_Boundaries.width - m_Width ;
	}
	else if (bottomLeft.x < m_Boundaries.left)
	{
		bottomLeft.x = m_Boundaries.left;
	}
	if ( bottomLeft.y > (m_Boundaries.height - m_Height ))
	{
		bottomLeft.y = m_Boundaries.height - m_Height ;
	}
	else if (bottomLeft.y <m_Boundaries.bottom)
	{
		bottomLeft.y = m_Boundaries.bottom;
	}
}

