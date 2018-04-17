#include "stdafx.h"
#include "Item.h"
#include "utils.h"
#include "Matrix2x3.h"
#include "Game.h"
const float Item::radius = 30.0f;
 



Item::~Item()
{
}

Item::Item(const Point2f & center, Item::Type type)
	:m_Type{ type }
	, m_Shape{ center, radius }
	, m_Texture{ "Resources/Items.png" }
	, m_Angle{}
	, m_Heart{ "Resources/heart.png" }
	, m_oneUp{ "Resources/oneUp.png" }
	, m_Spikes{ "Resources/spikes.png" }
{
	switch (Item::Type(m_Type))
	{
	case Item::Type(1):
		// Burger
		m_TextClip = Rectf{ 0.0f, m_Texture.GetHeight() * 1 / 10, m_Texture.GetWidth(), m_Texture.GetHeight() * 1 / 10 };
		break;
	case Item::Type(2):
		//hambone
		m_TextClip = Rectf{ 0.0f, m_Texture.GetHeight() * 2 / 10, m_Texture.GetWidth(), m_Texture.GetHeight() * 1 / 10 };
		break;
	case Item::Type(3):
		//fries
		m_TextClip = Rectf{ 0.0f,(m_Texture.GetHeight() * 3 / 10),m_Texture.GetWidth(),(m_Texture.GetHeight() * 1 / 10) };
		break;
	case Item::Type(4):
		//fridge
		m_TextClip = Rectf{ 0.0f,m_Texture.GetHeight() * 4 / 10,m_Texture.GetWidth(),m_Texture.GetHeight() * 1 / 10 };
		break;
	case Item::Type(5):
		//icecream
		m_TextClip = Rectf{ 0.0f,m_Texture.GetHeight() * 5 / 10,m_Texture.GetWidth(),m_Texture.GetHeight() * 1 / 10 };
		break;
	case Item::Type(6):
		//donut
		m_TextClip = Rectf{ 0.0f,m_Texture.GetHeight() * 6 / 10,m_Texture.GetWidth(),m_Texture.GetHeight() * 1 / 10 };
		break;
	case Item::Type(7):
		// hammer
		m_TextClip = Rectf{ 0.0f,m_Texture.GetHeight() * 7 / 10,m_Texture.GetWidth(),m_Texture.GetHeight() * 1 / 10 };
		break;
	case Item::Type(8):
		// pot 
		m_TextClip = Rectf{ 0.0f,m_Texture.GetHeight() * 8 / 10,m_Texture.GetWidth(),m_Texture.GetHeight() * 1 / 10 };
		break;
	case Item::Type(9):
		// grape
		m_TextClip = Rectf{ 0.0f,m_Texture.GetHeight() * 9 / 10,m_Texture.GetWidth(),m_Texture.GetHeight() * 1 / 10 };
		break;
	case Item::Type(10):
		//banana
		m_TextClip = Rectf{ 0.0f,m_Texture.GetHeight() * 10 / 10,m_Texture.GetWidth(),m_Texture.GetHeight() * 1 / 10 };
		break;
	case Item::Type(11):
		m_Heart.Draw(Rectf{ 0, 0 , m_Heart.GetWidth(),  m_Heart.GetHeight() });
		
		break;
	case Item::Type(12):
		m_oneUp.Draw(Rectf{ 0, 0 , m_oneUp.GetWidth(),  m_oneUp.GetHeight() });
		
		break;
	case Item::Type(13):
		m_Spikes.Draw(Rectf{ 0, 0 , m_Spikes.GetWidth(),  m_Spikes.GetHeight() });
		
		break;
	default:
		break;
	}	
	
}

void Item::Update(float elapsedSec)
{
}

void Item::Draw() const
{
	glPushMatrix();
	glTranslatef(m_Shape.center.x, m_Shape.center.y, 0);
	//glRotatef(m_Angle, 0, 0, 1);
	glTranslatef(-m_Shape.center.x, -m_Shape.center.y, 0);
	m_Texture.Draw(Rectf{ m_Shape.center.x - m_Shape.radius, m_Shape.center.y - m_Shape.radius, m_Shape.radius * 2, m_Shape.radius * 2 }, m_TextClip);
	glPopMatrix();
}

bool Item::IsOverlapping(const Rectf & rect) const
{
	bool result{ false };
	if (utils::IsOverlapping(rect, m_Shape))
	{
		result = true;
	}
	return result;
}












