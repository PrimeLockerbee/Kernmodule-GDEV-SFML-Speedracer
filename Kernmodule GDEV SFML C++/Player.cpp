#include <SFML/Window.hpp>
#include <iostream>
#include "Player.h" 


// Constructors
Player::Player()
{
    i_lives = 3;
    i_horizontalInput = 0;
    t_InvincibleTimer = Timer(1.0f);
    LoadTexture();
    InitializeSprite();
}

Player::Player(Vector2 playerSize, sf::Color playerColor)
{
    i_lives = 3;
    v2_Size = playerSize;
    v2_StartPos = Vector2(500, 750);
    v2_Position = v2_StartPos;
    t_InvincibleTimer = Timer(1.0f);

    bc_Collider = BoxCollider(v2_Size, v2_Position);
    rr_RectRenderer = RectRenderer((int)playerSize.f_x, (int)playerSize.f_y, playerColor);
    pc_PhysicsComponent = PhysicsComponent(.65f);
}

Player& Player::operator=(const Player& player)
{
    Character::operator=(player);
    i_lives = player.i_lives;
    bc_Collider = player.bc_Collider;
    rr_RectRenderer = player.rr_RectRenderer;

    return *this;
}

void Player::OnUpdate(sf::RenderWindow& window) 
{
    i_horizontalInput = GetPlayerInput();
    pc_PhysicsComponent.AddForce(Vector2(3 * i_horizontalInput, 0));
    Character::OnUpdate(window);

    rr_RectRenderer.SetShapePosition(v2_Position);
    if (b_isInvincible)
    {
        TickInvincabilityTimer();
    }

    Draw(window);
}

void Player::Draw(sf::RenderWindow& window)
{
    rr_RectRenderer.DrawShape(window);
}

void Player::OnCollision()
{
    if (b_isInvincible) 
    {        
        return;
    }

    //Set the alpha lower for a few seconds so the player knows their invincible, some visual feedback
    rr_RectRenderer.SetAlpha(75);
    i_lives--;
    b_isInvincible = true;
}

void Player::LoadTexture()
{
    t_Texture.loadFromFile("Resources/PLAYERCAR.png");
}

void Player::InitializeSprite()
{
    s_Sprite.setTexture(t_Texture);
}

//Returns the amount of lives the player has
int Player::GetLives()
{
    return i_lives;
}

//Does the player input
int Player::GetPlayerInput()
{
    int horizontal = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        horizontal = -1;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        horizontal = 1;
    }

    return horizontal;
}

//Enables and disables the Invincible effect
void Player::TickInvincabilityTimer()
{
    t_InvincibleTimer.Tick();

    if (t_InvincibleTimer.GetTimeLeft() < 0) 
    {
        b_isInvincible = false;
        rr_RectRenderer.SetAlpha(255);
        t_InvincibleTimer.Reset();
    }
}
