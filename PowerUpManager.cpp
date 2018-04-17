#include "stdafx.h"
#include "PowerUpManager.h"

PowerUpManager::PowerUpManager()
{
}

PowerUpManager::~PowerUpManager()
{
	for (unsigned int i = 0; i < Size(); i++)
	{
		delete m_pItems[i];
		m_pItems[i] = nullptr;
	}
}

PowerUp * PowerUpManager::AddItem(const Point2f & center, PowerUp::Type type)
{

	m_pItems.push_back(new PowerUp{ center, type });
	return m_pItems[Size()-1];
}

void PowerUpManager::Update(float elapsedSec)
{
	for (unsigned int i = 0; i < Size(); i++)
	{
		m_pItems[i]->Update(elapsedSec);
	}
}

void PowerUpManager::Draw() const
{
	for (unsigned int i = 0; i < Size(); i++)
	{
		m_pItems[i]->Draw();
	}
}

size_t PowerUpManager::Size() const
{
	return m_pItems.size();
}

bool PowerUpManager::HitItem(const Rectf & rect)
{
	for (unsigned int i = 0; i < Size(); i++)
	{
		if (m_pItems[i]->IsOverlapping(rect))
		{
			PowerUp* temp1{ m_pItems[i] };
			PowerUp* temp2{ m_pItems[Size() - 1] };

			m_pItems[i] = temp2;
			m_pItems[Size() - 1] = temp1;

			delete m_pItems[Size() - 1];

			m_pItems.pop_back();
			return true;
		}
	}
	
	return false;
	
}
