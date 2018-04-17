#pragma once
#include "PowerUp.h"
#include <vector>


class PowerUpManager
{
public:
	PowerUpManager( );
	~PowerUpManager( );
	PowerUpManager( const PowerUpManager& ) = delete;
	PowerUpManager& operator=( const PowerUpManager& ) = delete;

	PowerUp* AddItem( const Point2f &center, PowerUp::Type type );
	void Update( float elapsedSec );
	void Draw( ) const;

	size_t Size( ) const;
	bool HitItem( const Rectf& rect ) ;

private:
	std::vector<PowerUp*> m_pItems;

	// Your helper functions
};
