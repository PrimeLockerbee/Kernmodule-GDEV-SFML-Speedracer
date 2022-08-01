#include "Character.h"
#include <IOStream>
using namespace std;

Character::Character()
{
    collider = BoxCollider();
    physicsComponent = PhysicsComponent(1);
    startPos = Vector2();
    position = startPos;
}

Character& Character::operator=(const Character& character)
{
    size = character.size;
    startPos = character.startPos;
    position = character.position;
    physicsComponent = character.physicsComponent;

    return *this;
}

void Character::onUpdate(sf::RenderWindow& window)
{
    sf::Vector2u windowSizeSFML = window.getSize();
    Vector2 windowSize = Vector2(windowSizeSFML.x, windowSizeSFML.y);

    physicsComponent.onUpdate();
    position = calculateNewPosition();
    position.x = Math::Clamp(position.x, 0, windowSize.x - size.x);
    collider.updatePosition(position);
}

Vector2 Character::calculateNewPosition() {
    return position + physicsComponent.velocity;
}


