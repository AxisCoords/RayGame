#include <iostream>
#include "player.hpp"
#include "keyInput.hpp"

namespace entt {
    const float SPEED = 200.0f;

    Player::Player(Vector2 pos) : Entity("image", pos, 4, gfx::BOTTOM_CENTER) {}

    void Player::Update() {
        Vector2 input = GetVector2(KEY_RIGHT, KEY_LEFT, KEY_UP, KEY_DOWN);

        // Movement handling
        move(input);

        // Sprite flipping
        Entity::sprite->m_flipH = (velocity.x < 0) ? true : (velocity.x > 0) ? false : Entity::sprite->m_flipH;
        
        Entity::Update();
    }

    void Player::move(Vector2 input) {
        velocity = input * SPEED * GetFrameTime();
    }
}
