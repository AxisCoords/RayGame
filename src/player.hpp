#pragma once

#include "entity.hpp"

namespace entt {
    class Player : public Entity {
        public:
            Player(Vector2 pos);
            void Update() override;
    };
}
