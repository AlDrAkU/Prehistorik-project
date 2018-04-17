#include "stdafx.h"
#include "PowerUp.h"
#include "utils.h"
#include "Matrix2x3.h"

const float PowerUp::radius = 30.0f;

PowerUp::PowerUp( const Point2f& center, PowerUp::Type type)
	:m_Type{type}
	, m_Shape{center, radius}
	, m_Texture{"Resources/Items.png"}
	, m_Angle{}
	
{

	

	if (type == PowerUp::Type(1))
	{
		m_TextClip = Rectf{ 0.0f, m_Texture.GetHeight() *1/ 10, m_Texture.GetWidth(), m_Texture.GetHeight() *1 /10 };
	}
	if (type == PowerUp::Type(2))
	{
		m_TextClip = Rectf{ 0.0f, m_Texture.GetHeight() * 2 / 10, m_Texture.GetWidth(), m_Texture.GetHeight() *1/ 10 };
	}
	if (type == PowerUp::Type(3))
	{
		m_TextClip = Rectf{ 0.0f,(m_Texture.GetHeight()*3 / 10),m_Texture.GetWidth(),(m_Texture.GetHeight()* 1 / 10) };
	}
	if (type == PowerUp::Type(4))
	{
		m_TextClip = Rectf{ 0.0f,m_Texture.GetHeight() *4 / 10,m_Texture.GetWidth(),m_Texture.GetHeight()*1 / 10 };
	
	}
	if (type == PowerUp::Type(5))
	{
		m_TextClip = Rectf{ 0.0f,m_Texture.GetHeight() * 5 / 10,m_Texture.GetWidth(),m_Texture.GetHeight() * 1 / 10 };

	}
	if (type == PowerUp::Type(6))
	{
		m_TextClip = Rectf{ 0.0f,m_Texture.GetHeight() * 6 / 10,m_Texture.GetWidth(),m_Texture.GetHeight() * 1 / 10 };

	}
	if (type == PowerUp::Type(7))
	{
		m_TextClip = Rectf{ 0.0f,m_Texture.GetHeight() * 7 / 10,m_Texture.GetWidth(),m_Texture.GetHeight() * 1 / 10 };

	}
	if (type == PowerUp::Type(8))
	{
		m_TextClip = Rectf{ 0.0f,m_Texture.GetHeight() * 8 / 10,m_Texture.GetWidth(),m_Texture.GetHeight() * 1 / 10 };

	}
	if (type == PowerUp::Type(9))
	{
		m_TextClip = Rectf{ 0.0f,m_Texture.GetHeight() * 9 / 10,m_Texture.GetWidth(),m_Texture.GetHeight() * 1 / 10 };

	}
	if (type == PowerUp::Type(10))
	{
		m_TextClip = Rectf{ 0.0f,m_Texture.GetHeight() * 10 / 10,m_Texture.GetWidth(),m_Texture.GetHeight() * 1 / 10 };

	}
	
}

void PowerUp::Update(float elapsedSec)
{
	//m_Angle += m_RotSpeed * elapsedSec;
	/*float origPlace{ m_Shape.center.y };

	if (m_Shape.center.y == origPlace )
	{
	for (int i = 0; i < 6; i++)
	{	m_Shape.center.y += i;}
	}
	if (m_Shape.center.y == origPlace + 6)
	{
		m_Shape.center.y = origPlace;
	}*/

}

void PowerUp::Draw() const
{
	glPushMatrix();
	glTranslatef(m_Shape.center.x, m_Shape.center.y, 0);
	glRotatef(m_Angle, 0, 0, 1);
	glTranslatef(-m_Shape.center.x, -m_Shape.center.y, 0);
	m_Texture.Draw(Rectf{ m_Shape.center.x - m_Shape.radius, m_Shape.center.y - m_Shape.radius, m_Shape.radius * 2, m_Shape.radius * 2 }, m_TextClip );
	glPopMatrix();
}

bool PowerUp::IsOverlapping(const Rectf& rect) const
{
	bool result{ false };
	if (utils::IsOverlapping(rect, m_Shape))
	{
		result = true;
	}
	return result;
}
