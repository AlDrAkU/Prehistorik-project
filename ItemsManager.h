#pragma once
#include "Item.h"
#include <vector>
#include <memory>


class ItemsManager
{
public:
	ItemsManager();
	~ItemsManager();
	ItemsManager(const ItemsManager&) = delete;
	ItemsManager& operator=(const ItemsManager&) = delete;

	//std::shared_ptr<Item> AddItem(const Point2f &center, Item::Type type);
	Item* AddItem(const Point2f &center, Item::Type type);
	void Update(float elapsedSec);
	void Draw() const;
	size_t Size() const;
	bool HitItem(const Rectf& rect);

private:
	std::vector<Item*> m_pItems;
	//std::vector<std::shared_ptr<Item>> m_pItems;
	
	static const std::vector<int> m_ItemsScore;
	std::vector<int> m_ScorePerItem{};
	int m_Score;
	std::vector<int> m_CollectedItemsScore{};
};

