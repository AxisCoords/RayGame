#pragma once

#include "raylib.h"

namespace gfx {
    enum Origins {
        TOP_LEFT,
        TOP_CENTER,
        TOP_RIGHT,
        CENTER_RIGHT,
        BOTTOM_RIGHT,
        BOTTOM_CENTER,
        BOTTOM_LEFT,
        CENTER_LEFT,
        CENTER
    };
    
    class Sprite {
        public:
            Texture2D m_texture;
            Vector2 m_pos;
            Rectangle m_frame;
            int m_scale = 1;
            float m_rotation = 0;
            unsigned short m_alpha = 255;
            Vector2 m_origin = (Vector2){0, 0};
            bool m_flipH = false, m_flipV = false;

            Sprite(const char* name, Vector2 pos, int scale);
            Sprite(const char* name, Vector2 pos, int scale, Origins origins);
            void SetOrigin(Origins origin);
            virtual void Draw(Color color);
            void Unload();
        
        private:
            const char* DEFAULT_PATH = "assets/sprites/";
            const char* EXTENTION = ".png";

            const char* getPath(const char* spriteName) {
                return TextFormat("%s%s%s", DEFAULT_PATH, spriteName, EXTENTION);
            }
    };
}
