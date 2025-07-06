#pragma once

#include "raylib.h"
#include "raymath.h"

float GetKey(int key) {
    return IsKeyDown(key) ? 1.0f : 0.0f;
}

float GetAxis(int right, int left) {
    return GetKey(right) - GetKey(left);
}

Vector2 GetVector2(int right, int left, int up, int down) {
    Vector2 res = (Vector2){GetAxis(right, left), GetAxis(down, up)};
    res = (Vector2LengthSqr(res) > 1) ? Vector2Normalize(res) : res;

    return res;
}
