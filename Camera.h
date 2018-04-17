#pragma once
#include "Vector2f.h"
class Camera
{
public:
	Camera(float width, float height);
	void SetBoundaries(const Rectf& boundaries);
	void Draw();
	Point2f GetPosition() const;
	void InitPos(const Rectf& toTrack);
	void Update(const Rectf& toTrack, float ElapsedSec, Vector2f velocity);

private:
	void Track(const Rectf& toTrack, Vector2f velocity);
	void Clamp(Point2f& bottomLeft);

	Point2f m_Pos;
	Vector2f m_Velocity;
	float m_Width;
	float m_Height;
	Rectf m_Boundaries;
};

