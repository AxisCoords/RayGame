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
            break;
        case TOP_CENTER:
            break;
        case TOP_RIGHT:
            break;
        case CENTER_RIGHT:
            break;
        case BOTTOM_RIGHT:
            break;
        case BOTTOM_CENTER:
            break;
        case BOTTOM_LEFT:
            break;
        case CENTER_LEFT:
            break;
        case CENTER:
            break;
        default:
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
