#include "sprite.hpp"

using namespace gfx;

Sprite::Sprite(const char* name, Vector2 pos, int scale) {
    Sprite::m_texture = LoadTexture(Sprite::getPath(name));
    Sprite::m_frame = (Rectangle){0, 0, (float)Sprite::m_texture.width, (float)Sprite::m_texture.height};
    Sprite::m_pos = pos;
    Sprite::m_scale = scale;
}

Sprite::Sprite(const char* name, Vector2 pos, int scale, Origins origin) {
    Sprite::m_texture = LoadTexture(Sprite::getPath(name));
    Sprite::m_frame = (Rectangle){0, 0, (float)Sprite::m_texture.width, (float)Sprite::m_texture.height};
    Sprite::m_pos = pos;
    Sprite::m_scale = scale;

    Sprite::SetOrigin(origin);
}

void Sprite::SetOrigin(Origins origin) {
    float w = Sprite::m_frame.width;
    float h = Sprite::m_frame.height;
    Vector2* pO = &m_origin;

    switch (origin) {
        case TOP_LEFT:
            *pO = (Vector2){0, 0};
            break;
        case TOP_CENTER:
            *pO = (Vector2){w / 2 * Sprite::m_scale, 0};
            break;
        case TOP_RIGHT:
            *pO = (Vector2){w * Sprite::m_scale, 0};
            break;
        case CENTER_RIGHT:
            *pO = (Vector2){w * Sprite::m_scale, h / 2 * Sprite::m_scale};
            break;
        case BOTTOM_RIGHT:
            *pO = (Vector2){w * Sprite::m_scale, h * Sprite::m_scale};
            break;
        case BOTTOM_CENTER:
            *pO = (Vector2){w / 2 * Sprite::m_scale, h * Sprite::m_scale};
            break;
        case BOTTOM_LEFT:
            *pO = (Vector2){0, h * Sprite::m_scale};
            break;
        case CENTER_LEFT:
            *pO = (Vector2){0, h / 2 * Sprite::m_scale};
            break;
        case CENTER:
            *pO = (Vector2){w / 2 * Sprite::m_scale, h / 2 * Sprite::m_scale};
            break;
    }
}

void Sprite::Draw(Color color) {
    DrawTexturePro(
        Sprite::m_texture, 
        (Rectangle){
            Sprite::m_frame.x,
            Sprite::m_frame.y,
            Sprite::m_frame.width * (Sprite::m_flipH ? -1 : 1),
            Sprite::m_frame.height  * (Sprite::m_flipV ? -1 : 1),
        }, 
        (Rectangle){
                Sprite::m_pos.x, 
                Sprite::m_pos.y, 
                Sprite::m_frame.width * float(Sprite::m_scale), 
                Sprite::m_frame.height * float(Sprite::m_scale)
        },
        Sprite::m_origin,
        Sprite::m_rotation,
        (Color){color.r, color.g, color.b, (unsigned char)Sprite::m_alpha}
    );
}

void Sprite::Unload() {
    UnloadTexture(Sprite::m_texture);
}
