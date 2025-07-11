#include "player.hpp"
#include "keyInput.hpp"

namespace entt {
    const float SPEED = 200.0f;

    Player::Player(Vector2 pos) : Entity("player", pos, 4, (Rectangle){0, 0, 24, 24}, gfx::BOTTOM_CENTER) {}

    void Player::Update() {
        Vector2 input = GetVector2(KEY_RIGHT, KEY_LEFT, KEY_UP, KEY_DOWN);

        move(input); // Movement handling

        Entity::sprite->m_flipH = (velocity.x < 0) ? true : (velocity.x > 0) ? false : Entity::sprite->m_flipH; // Sprite flipping
        
        Entity::Update();
    }

    void Player::move(Vector2 input) {
        velocity = input * SPEED * GetFrameTime();
    }
}
