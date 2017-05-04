// Copyright 2017 Nesterov Alexander

#include "../include/rgb_space.h"
#include <sys/types.h>
#include <string>
#include <algorithm>

void RGBSpace::swap(RGBSpace &rgb_space) {
    std::swap(red, rgb_space.red);
    std::swap(green, rgb_space.green);
    std::swap(blue, rgb_space.blue);
}

RGBSpace::RGBSpace(const int red_,
                   const int green_,
                   const int blue_) {
    if ((red_ < 0) || (red_ > 255)) {
        throw std::string("The index of red color isn't in the range 0-255");
    } else if ((green_ < 0) || (green_ > 255)) {
        throw std::string("The index of green color isn't in the range 0-255");
    } else if ((blue_ < 0) || (blue_ > 255)) {
        throw std::string("The index of blue color isn't in the range 0-255");
    } else {
        red = (u_int8_t) red_;
        green = (u_int8_t) green_;
        blue = (u_int8_t) blue_;
    }
}

RGBSpace::RGBSpace(const RGBSpace &rgb_space) {
    if (&rgb_space == nullptr) {
        throw std::string("Copying object is nullptr");
    } else {
        red = rgb_space.red;
        green = rgb_space.green;
        blue = rgb_space.blue;
    }
}

RGBSpace& RGBSpace::operator=(const RGBSpace &rgb_space) {
    if (this != &rgb_space) {
        RGBSpace(rgb_space).swap(*this);
    }
    return *this;
}

u_int8_t RGBSpace::GetRed() const {
    return red;
}

u_int8_t RGBSpace::GetGreen() const {
    return green;
}

u_int8_t RGBSpace::GetBlue() const {
    return blue;
}

void RGBSpace::SetRed(const int red_) {
    if ((red_ < 0) || (red_ > 255)) {
        throw std::string("The index of red color isn't in the range 0-255");
    } else {
        red = (u_int8_t) red_;
    }
}

void RGBSpace::SetGreen(const int green_) {
    if ((green_ < 0) || (green_ > 255)) {
        throw std::string("The index of green color isn't in the range 0-255");
    }  else {
        green = (u_int8_t) green_;
    }
}

void RGBSpace::SetBlue(const int blue_) {
    if ((blue_ < 0) || (blue_ > 255)) {
        throw std::string("The index of blue color isn't in the range 0-255");
    } else {
        blue = (u_int8_t) blue_;
    }
}

bool operator==(const RGBSpace &rgb_space_left,
                const RGBSpace &rgb_space_right) {
    if (&rgb_space_left == &rgb_space_right) {
        return true;
    } else {
        return ((rgb_space_left.red == rgb_space_right.red) &&
            (rgb_space_left.green == rgb_space_right.green) &&
            (rgb_space_left.blue == rgb_space_right.blue));
    }
}

bool operator!=(const RGBSpace &rgb_space_left,
                const RGBSpace &rgb_space_right) {
    return !(rgb_space_left == rgb_space_right);
}
