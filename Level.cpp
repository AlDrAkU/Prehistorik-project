#include "stdafx.h"
#include "Level.h"
#include "utils.h"
#include "SVGParser.h"

Level::Level(): 
	m_BackgroundTexture{"Resources/levelh.png"},
	m_Vertices{},
	m_Boundaries{0.0f,0.0f,m_BackgroundTexture.GetWidth(),m_BackgroundTexture.GetHeight()}
{
	if (SVGParser::GetVerticesFromSvgFile("Resources/prehistorikSVGtest.svg", m_Vertices))
	{
		std::cout << "level load successful" << std::endl;
	}
	else
	{
		std::cout << "level load unsuccessful" << std::endl;
	}
	
	
	/*if (SVGParser::GetVerticesFromSvgFile("Resources/prehistorikSVGtest2.svg", m_Vertices))
	{
		std::cout << "level load successful" << std::endl;
	}
	else
	{
		std::cout << "level load unsuccessful" << std::endl;
	}*/
}

void Level::DrawBackground()const
{
	m_BackgroundTexture.Draw();
}

void Level::DrawForeground()const
{
	//m_FenceTexture.Draw(m_FenceBottomleft);
}

void Level::HandleCollision(Rectf & actorShape, Vector2f & Velocity)const
{
	utils::HitInfo actorHitInfo{};
	Point2f startRay{ actorShape.left + (actorShape.width / 2), actorShape.bottom + actorShape.height };
	Point2f endRay{ actorShape.left + (actorShape.width / 2), actorShape.bottom };

	if (utils::Raycast(m_Vertices, startRay,endRay,actorHitInfo))
	{
		Velocity.y = 0.0f;
		actorShape.bottom = actorHitInfo.intersectPoint.y;
	}

}

bool Level::IsOnGround(const Rectf & actorShape) const
{
	utils::HitInfo actorHitInfo{};
	Point2f startRay{ actorShape.left + (actorShape.width / 2), actorShape.bottom + actorShape.height };
	Point2f endRay{ actorShape.left + (actorShape.width / 2), actorShape.bottom - 1.0f };
	if (utils::Raycast(m_Vertices, startRay, endRay, actorHitInfo))
	{
		return true;
	}
	else
	{

		return false;
	}
}

Rectf Level::GetBoundaries()
{
	return m_Boundaries;
}
