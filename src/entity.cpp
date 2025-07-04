#include <iostream>
#include "entity.hpp"
#include "globals.hpp"

using namespace entt;

Entity::Entity(const char* spriteName, Vector2 pos, int size, gfx::Origins origin) {
    Entity::sprite = new gfx::Sprite(spriteName, pos, size, origin);
    Entity::pos = Entity::sprite->m_pos;
    Entity::rect = (Rectangle){
        Entity::pos.x,
        Entity::pos.y, 
        Entity::sprite->m_frame.width * size, 
        Entity::sprite->m_frame.height * size
    };
}

void Entity::Update() {
    Entity::sprite->m_pos = Entity::pos;
    Entity::rect.x = Entity::pos.x - Entity::sprite->m_origin.x;
    Entity::rect.y = Entity::pos.y - Entity::sprite->m_origin.y;
}

void Entity::Render(Color color) {
    Entity::sprite->Draw(color);

    if (showDebug)
        Entity::drawDebug();
}

void Entity::drawDebug() {
    DrawRectangleRec(Entity::rect, Entity::DEBUG_RECT_COLOR);
}

Entity::~Entity() {
    Entity::sprite->Unload();
    delete Entity::sprite;
}
