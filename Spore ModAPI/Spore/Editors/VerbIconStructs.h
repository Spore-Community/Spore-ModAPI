#pragma once

#include <stdint.h>

struct cVerbIconLinearInterpolationValue {
    float mTargetValue;
    float mCurrentValue;
    float mElapsedTime;
    float mInitialValue;
    float mDuration;
};
//ASSERT_SIZE(cVerbIconLinearInterpolationValue, 0x14);

struct cVerbIconMiddleInterpolationValue {
    float mEndValue;
    float mMiddleValue;
    float mCurrentValue;
    float mElapsedTime;
    float mInitialValue;
    float mMiddleStart;
    float mMiddleEnd;
    float mDuration;
};
//ASSERT_SIZE(cVerbIconMiddleInterpolationValue, 0x20);

struct cVerbIconOscillatingAlpha {
    float mInitialValue;
    float mEndValue;
    float mCurrentValue;
    float mElapsedTime;
    float mDuration;
    float mSpeed;
    uint32_t mColor;
};
//ASSERT_SIZE(cVerbIconOscillatingAlpha, 0x1C);

struct cVerbIconInterpolationValue {
    float mTargetValue;
    float mCurrentValue;
    float mElapsedTime;
    float mInitialValue;
    float mDuration;
    float mOverShoot;
    float mDampenPercent;
};