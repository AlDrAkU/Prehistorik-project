#include "stdafx.h"
#include "Texture.h"

class PowerUp 
{
public:
	enum class Type
	{
		burger = 1,
		hambone = 2,
		fries = 3,
		fridge = 4,
		icecream = 5,
		donut = 6,
		hammer = 7,
		pot = 8,
		grape = 9,
		banana = 10,
		rockwheel = 11


	};
	PowerUp( const Point2f& center, PowerUp::Type type );

	void Update( float elapsedSec );
	void Draw( ) const;
	bool IsOverlapping(const Rectf& rect ) const;
	static const float radius;

private:
	Type m_Type;
	Circlef m_Shape;
	Texture m_Texture;
	Rectf m_TextClip;
	float m_Angle{ 0.0f };
	const float m_RotSpeed{ 360.0f }; // degrees per second
};


