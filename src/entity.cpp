#include "entity.hpp"
#include "globals.hpp"

namespace entt {
    Entity::Entity(const char* spriteName, Vector2 pos, int size, gfx::Origins origin) {
        Entity::sprite = new gfx::Sprite(spriteName, pos, size, origin);
        Entity::pos = Entity::sprite->m_pos;
        Entity::size = size;
        Entity::rect = (Rectangle){
            Entity::pos.x,
            Entity::pos.y, 
            Entity::sprite->m_frame.width * size, 
            Entity::sprite->m_frame.height * size
        };
    }

    Entity::Entity(const char* spriteName, Vector2 pos, int size, Rectangle frame, gfx::Origins origin) {
        Entity::sprite = new gfx::Sprite(spriteName, pos, size, origin);
        Entity::pos = Entity::sprite->m_pos;
        Entity::size = size;
        Entity::rect = (Rectangle){
            Entity::pos.x,
            Entity::pos.y, 
            Entity::sprite->m_frame.width * size, 
            Entity::sprite->m_frame.height * size
        };

        // this->SetFrame(frame);
        Entity::SetFrame(frame);

        Entity::sprite->SetOrigin(origin);
    }

    void Entity::SetFrame(Rectangle frame) {
        Entity::rect = (Rectangle){Entity::pos.x, Entity::pos.y, frame.width * Entity::size, frame.height * Entity::size};
        Entity::sprite->m_frame = frame;
    }

    void Entity::Update() {
        pos.x += velocity.x;
        pos.y += velocity.y;

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
}
