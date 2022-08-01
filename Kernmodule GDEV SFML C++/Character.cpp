#include <IOStream>
#include "Character.h"

using namespace std;

Character::Character()
{
    bc_Collider = BoxCollider();
    pc_PhysicsComponent = PhysicsComponent(1);
    v2_StartPos = Vector2();
    v2_Position = v2_StartPos;
}

Character& Character::operator=(const Character& character)
{
    v2_Size = character.v2_Size;
    v2_StartPos = character.v2_StartPos;
    v2_Position = character.v2_Position;
    pc_PhysicsComponent = character.pc_PhysicsComponent;

    return *this;
}

//Update for characters
void Character::OnUpdate(sf::RenderWindow& window)
{
    sf::Vector2u windowSizeSFML = window.getSize();
    Vector2 windowSize = Vector2(windowSizeSFML.x, windowSizeSFML.y);

    pc_PhysicsComponent.OnUpdate();
    v2_Position = CalculateNewPosition();
    v2_Position.f_x = Math::Clamp(v2_Position.f_x, 0, windowSize.f_x - v2_Size.f_x);
    bc_Collider.UpdatePosition(v2_Position);
}

//Calculates the new position
Vector2 Character::CalculateNewPosition() 
{
    return v2_Position + pc_PhysicsComponent.v2_Velocity;
}


