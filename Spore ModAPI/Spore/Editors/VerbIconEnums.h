#pragma once

#include <stdint.h>

enum eVerbIconState {
    kVerbIconHiding = 0,
    kVerbIconHidden = 1,
    kVerbIconShowing = 2,
    kVerbIconVisible = 3,
    kVerbIconUpgrading = 4,
    kVerbIconDowngrading = 5,
    kVerbIconUninitialized = 6
};
enum eResizeStyle {
    kNone = 0,
    kScale = 1,
    kResize = 2
};
enum eLayoutJustification {
    kJustificationNONE = 0,
    kJustificationLeft = 4109362,
    kJustificationTop = 1080872010,
    kJustificationRight = 3893817417,
    kJustificationBottom = 3898915424
};

enum eLayoutStyle {
    kCentered = 1926514641,
    kFill = 3047988258,
    kJustified = 4271967848
};