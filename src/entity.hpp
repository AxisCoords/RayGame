#pragma once

#include "sprite.hpp"

namespace entt {
    class Entity {
        public:
            gfx::Sprite* sprite;
            Vector2 pos;
            Rectangle rect;
            
            Entity(const char* spriteName, Vector2 pos, int size, gfx::Origins origin);
            Entity(const char* spriteName, Vector2 pos, int size, Rectangle frame, gfx::Origins origin);
            virtual void Update();
            virtual void Render(Color color);
            ~Entity();
        
        private:
            const Color DEBUG_RECT_COLOR = (Color){255, 0, 98, 120};
            int size;

            void drawDebug();
        
        protected:
            Vector2 velocity;
            void SetFrame(Rectangle frame);
    };
}
