#include "stdafx.h"
#include "Game.h"
#include "utils.h"
#include "Avatar.h"

Game::Game( const Window& window )
	:m_Window{ window },
	m_Camera{700.0f,700.0f},
	m_Splashscreen{ "Resources/pistolfrog.png" },
	m_sndStreamIntro{ "Resources/Audio/Intro.mp3" }
{	 
	Initialize( );
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	ShowTestMessage( );
	m_sndStreamIntro.Play(true);
	//system("pause");
	AddPowerUps( );
	m_Camera.SetBoundaries(m_Level.GetBoundaries());
	m_Camera.InitPos(m_Avatar.GetShape());
	
}

void Game::Cleanup( )
{
}

void Game::Update( float elapsedSec )
{
	// Update game objects
	m_ItemsManager.Update( elapsedSec );
	m_Avatar.Update( elapsedSec, m_Level );
	m_Tiger.Update(elapsedSec, m_Level);
	m_Dino.Update(elapsedSec, m_Level);
	m_Pengu.Update(elapsedSec, m_Level);
	m_Eagle.Update(elapsedSec, m_Level);
	m_Camera.Update(m_Avatar.GetShape(), elapsedSec, m_Avatar.GetVelocity());
	// Do collision
	DoCollisionTests( );
}

void Game::Draw( )
{
	ClearBackground( );
	glPushMatrix();
	glTranslatef(-m_Camera.GetPosition().x, -m_Camera.GetPosition().y, 0.0f);
	m_Level.DrawBackground( );
	m_Avatar.Draw( );
	m_Tiger.Draw();
	m_Eagle.Draw();
	m_Pengu.Draw();
	m_Dino.Draw();
	
	m_ItemsManager.Draw();
	
	m_Level.DrawForeground( );
	glPopMatrix();
	//m_Splashscreen.Draw((Rectf{ 0 , 0, m_Window.width,  m_Window.height }));
	


}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	switch (e.keysym.sym)
	{

	case SDLK_LEFT:
		DoCollisionTests();
		break;
	case SDLK_RIGHT:
		
		break;
	case SDLK_p:
		
		break;
	case SDLK_DOWN:
	DoCollisionTests();
		break;
	case SDLK_SPACE:
		break;

	default:
		break;
	}


}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
	
}

void Game::ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e )
{
}

void Game::ProcessMouseDownEvent( const SDL_MouseButtonEvent& e )
{
}

void Game::ProcessMouseUpEvent( const SDL_MouseButtonEvent& e )
{
}

void Game::ClearBackground( )
{
	glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}


void Game::ShowTestMessage( )
{


}

void Game::AddPowerUps( )
{
	m_ItemsManager.AddItem( { 450.0f, 1200 - 183.0f }, Item::Type::burger );
	m_ItemsManager.AddItem( { 735.0f, 1250 - 113.0f }, Item::Type::hambone );
	m_ItemsManager.AddItem( { 585.0f, 850 - 183.0f }, Item::Type::fridge);
	m_ItemsManager.AddItem({ 665.0f, 850 - 183.0f }, Item::Type::donut);
	m_ItemsManager.AddItem({ 885.0f, 850 - 183.0f }, Item::Type::icecream);
	m_ItemsManager.AddItem({ 985.0f, 1150 - 183.0f }, Item::Type::banana);
	m_ItemsManager.AddItem({ 1085.0f, 850 - 183.0f }, Item::Type::fries);
	m_ItemsManager.AddItem({ 825.0f, 850 - 183.0f }, Item::Type::grape);
	m_ItemsManager.AddItem({ 625.0f, 850 - 183.0f }, Item::Type::hammer);
	m_ItemsManager.AddItem({ 785.0f, 850 - 183.0f }, Item::Type::pot);
	/*m_ItemsManager.AddItem({ 600.0f, 1200 - 183.0f }, Item::Type::oneUp);
	m_ItemsManager.AddItem({ 600.0f, 1000.f }, Item::Type::heart);
	m_ItemsManager.AddItem({ 555.0f, 1000.f }, Item::Type::spikes);*/
	

}

void Game::DoCollisionTests( )
{
	int avatarHp{};

	if ( m_ItemsManager.HitItem( m_Avatar.GetShape( ) ) )
	{
		m_Avatar.PowerUpHit( );



	}
	if (utils::IsOverlapping(m_Tiger.GetShape(), m_Avatar.GetShape()))
	{
		
		avatarHp = m_Avatar.GetHp();
		avatarHp -= 1;
		m_Avatar.SetHp(avatarHp);
		std::cout << m_Avatar.GetHp();
	}
	else if (utils::IsOverlapping(m_Dino.GetShape(), m_Avatar.GetShape()))
	{

		avatarHp = m_Avatar.GetHp();
		avatarHp -= 1;
		m_Avatar.SetHp(avatarHp);
		std::cout << m_Avatar.GetHp();
	}
	else if (utils::IsOverlapping(m_Pengu.GetShape(), m_Avatar.GetShape()))
	{

		avatarHp = m_Avatar.GetHp();
		avatarHp -= 1;
		m_Avatar.SetHp(avatarHp);
		std::cout << m_Avatar.GetHp();
	}
	else if (utils::IsOverlapping(m_Eagle.GetShape(), m_Avatar.GetShape()))
	{

		avatarHp = m_Avatar.GetHp();
		avatarHp -= 1;
		m_Avatar.SetHp(avatarHp);
		std::cout << m_Avatar.GetHp();
	}
	


}

void Game::SetScore(int value)
{
	m_Score += value;

}

const int Game::GetScore()
{
	return m_Score;
}

