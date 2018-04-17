#include "stdafx.h"
#include "ItemsManager.h"
#include <memory>


ItemsManager::ItemsManager()
	:m_ScorePerItem{ 2000,2500,3500,10000,15000,25000, 27500, 30000, 35000,1000 },
	m_CollectedItemsScore{}
{
}


ItemsManager::~ItemsManager()
{
	for (unsigned int i = 0; i < Size(); i++)
	{
		delete m_pItems[i];
		m_pItems[i] = nullptr;
	}
}

Item* ItemsManager::AddItem(const Point2f & center, Item::Type type)
{
	m_pItems.push_back(new Item{ center, type });
	return m_pItems[Size() - 1];
}

void ItemsManager::Update(float elapsedSec)
{
	for (unsigned int i = 0; i < Size(); i++)
	{
		m_pItems[i]->Update(elapsedSec);
	}
}

void ItemsManager::Draw() const
{
	for (unsigned int i = 0; i < Size(); i++)
	{
		m_pItems[i]->Draw();
	}
}

size_t ItemsManager::Size() const
{
	return m_pItems.size();
}

bool ItemsManager::HitItem(const Rectf & rect)
{
	for (unsigned int i = 0; i < Size(); i++)
	{
		if (m_pItems[i]->IsOverlapping(rect))
		{
			Item* temp1{ m_pItems[i] };
			Item* temp2{ m_pItems[Size() - 1] };

			m_pItems[i] = temp2;
			m_pItems[Size() - 1] = temp1;

			delete m_pItems[Size() - 1];

			m_pItems.pop_back();
			return true;
		}
	}

	return false;
}
