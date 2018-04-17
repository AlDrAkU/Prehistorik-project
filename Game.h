#pragma once
#include "stdafx.h"


class Game
{
public:
	explicit Game( const Window& window );
	Game( const Game& other ) = delete;
	Game& operator=( const Game& other ) = delete;
	~Game();

	void Update( float elapsedSec );
	void Draw( );
	void SetScore(int value);
	const int GetScore();
	// Event handling
	void ProcessKeyDownEvent( const SDL_KeyboardEvent& e );
	void ProcessKeyUpEvent( const SDL_KeyboardEvent& e );
	void ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e );
	void ProcessMouseDownEvent( const SDL_MouseButtonEvent& e );
	void ProcessMouseUpEvent( const SDL_MouseButtonEvent& e );

private:
	// DATA MEMBERS
	Window m_Window;

	Level m_Level;
	ItemsManager m_ItemsManager;
	Avatar m_Avatar;
	Tiger m_Tiger;
	Eagle m_Eagle;
	Dino m_Dino;
	Pengu m_Pengu;
	Texture m_Splashscreen;
	Camera m_Camera;
	int m_Score;
	SoundStream m_sndStreamIntro;
	// FUNCTIONS
	void Initialize( );
	void Cleanup( );
	void ClearBackground( );
	void ShowTestMessage( );
	void AddPowerUps( );
	void DoCollisionTests( );
	
};