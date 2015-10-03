#ifndef ANGLE_HPP
#define ANGLE_HPP

#include "neo.hpp"

namespace neo {

inline angle angle::radians(float radians) {
    return angle(radians);
}

inline angle angle::degrees(float degrees) {
    return angle(degrees * PI / 180.0f);
}

inline float angle::as_radians() const {
    return radians_;
}

inline float angle::as_degrees() const {
    return radians_ * 180.0f / PI;
}

inline float angle::cos() const {
    return std::cos(radians_);
}

inline float angle::sin() const {
    return std::sin(radians_);
}

}

#endif
