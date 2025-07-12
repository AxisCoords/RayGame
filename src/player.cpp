#include "player.hpp"
#include "keyInput.hpp"
#include <fmt/core.h>

namespace entt {
    const float SPEED = 300.0f;

    Player::Player(Vector2 pos) : Entity("player", pos, 4, (Rectangle){0, 0, 24, 24}, gfx::BOTTOM_CENTER) {
        this->rectPosOffset = (Vector2){31, 29}; //  Rect offset
        this->rect = (Rectangle){0, 0, 33, 66}; // New rect size
    }

    void Player::Update() {
        Vector2 input = GetVector2(KEY_RIGHT, KEY_LEFT, KEY_UP, KEY_DOWN);
        
        move(input);
        Entity::sprite->m_flipH = (velocity.x < 0) ? true : (velocity.x > 0) ? false : Entity::sprite->m_flipH;

        if (velocity != (Vector2){0, 0}) fmt::print("X: {}, Y: {}, W: {}, H: {}\n", rect.x, rect.y, rect.width, rect.height);

        Entity::Update();
    }

    void Player::move(Vector2 input) {
        velocity = input * SPEED * GetFrameTime();
    }
}
