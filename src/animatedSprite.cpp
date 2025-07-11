#include "animatedSprite.hpp"

namespace gfx {
    AnimatedSprite::AnimatedSprite(const char* name, Vector2 pos, int scale)
        : Sprite(name, pos, scale) {}
    
    AnimatedSprite::AnimatedSprite(const char* name, Vector2 pos, int scale, Origins origin)
        : Sprite(name, pos, scale, origin) {}
    
    void AnimatedSprite::AddAnimationFrame(Rectangle frame) {
        m_frames.push_back(frame);
    }

    void AnimatedSprite::AddUniformFrames(int cols, int rows) {
        float frameWidth = m_texture.width / rows;
        float frameHeight = m_texture.height / rows;

        for (int y = 0; y < rows; y++) {
            for (int x = 0; x < cols; x++) {
                AddAnimationFrame((Rectangle){
                    x * frameWidth,
                    y * frameHeight,
                    frameWidth,
                    frameHeight
                });
            }
        }
    }

    void AnimatedSprite::Pause() {
        m_isPlaying = false;
    }

    void AnimatedSprite::Stop(bool resetToFirstFrame) {
        m_isPlaying = false;

        if (resetToFirstFrame && !m_frames.empty()) {
            m_currentFrame = 0;
            m_frame = m_frames[0];
        }
    }

    void AnimatedSprite::Update(float deltaTime) {
        if (!m_isPlaying || m_frames.empty()) return;

        m_frameTime += deltaTime;
        float frameDuration = 1.0f / m_fps;

        while (m_frameTime >= frameDuration) {
            m_frameTime -= frameDuration;

            if (m_currentFrame + 1 < m_frames.size()) {
                m_currentFrame++;
            } else if (m_loop) {
                m_currentFrame = 0;
            } else {
                m_isPlaying = false;
                break;
            }

            m_frame = m_frames[m_currentFrame];
        }
    }

    void AnimatedSprite::Draw(Color color) {
        Sprite::Draw(color);
    }
}
