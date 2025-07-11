#pragma once

#include <vector>
#include "sprite.hpp"

namespace gfx {
    class AnimatedSprite : public Sprite {
        public:
            AnimatedSprite(const char* name, Vector2 pos, int scale);
            AnimatedSprite(const char* name, Vector2 pos, int scale, Origins origin);

            void AddAnimationFrame(Rectangle frame);
            void AddUniformFrames(int cols, int rows);
            void Play(float fps, bool loop = true);
            void Pause();
            void Stop(bool resetToFirstFrame = true);
            void Update(float deltaFrame);

            void Draw(Color color) override;
            
        private:
            std::vector<Rectangle> m_frames;
            unsigned int m_currentFrame = 0;
            float m_frameTime = 0.0f;
            float m_fps = 0.0f;
            bool m_isPlaying = false;
            bool m_loop = true;
    };
}
