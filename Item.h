#pragma once
#include "stdafx.h"
#include "Texture.h"

class Item
{

	
public:
	~Item();
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
		heart = 11,
		oneUp = 12,
		spikes = 13

	};
	Item(const Point2f& center, Item::Type type);

	void Update(float elapsedSec);
	void Draw() const;
	bool IsOverlapping(const Rectf& rect) const;
	static const float radius;
	static const std::vector<int> m_ItemsScore;
	


private:
	Type m_Type;
	Circlef m_Shape;
	Texture m_Texture;
	Texture m_Heart;
	Texture m_oneUp;
	Texture m_Spikes;
	Rectf m_TextClip;
	float m_Angle{ 0.0f };
	//const float m_RotSpeed{ 360.0f }; // degrees per second
	//std::vector<int> m_ScorePerItem{};
	

};


