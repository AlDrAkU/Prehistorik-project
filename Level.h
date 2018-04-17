#pragma once
#include "Texture.h"
#include "Vector2f.h"
class Level
{
public:
	Level();
	explicit Level(const Level& level) = delete;
	explicit Level(Level&& level)= delete;
	
	void DrawBackground() const;
	void DrawForeground() const;
	void HandleCollision(Rectf& actorShape, Vector2f& Velocity) const;
	bool IsOnGround(const Rectf& actorShape) const; 
	Rectf GetBoundaries();
	
	Level& operator=(const Level& rhs)= delete;
	Level& operator=(Level&& rhs) = delete;
private:
	std::vector<Point2f> m_Vertices;
	Texture m_BackgroundTexture;
	Rectf m_Boundaries;
	


};

