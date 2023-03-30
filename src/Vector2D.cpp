#include "Vector2D.hpp"

Vector2D::Vector2D() {
    x = y = 0;
}

Vector2D::Vector2D(float x, float y) {
    this->x = x;
    this->y = y;
}

Vector2D& Vector2D::add(const Vector2D& v) {
    this->x += v.x;
    this->y += v.y;

    return *this;
}

Vector2D& Vector2D::substract(const Vector2D& v) {
    this->x -= v.x;
    this->y -= v.y;

    return *this;
}

Vector2D& Vector2D::multiply(const Vector2D& v) {
    this->x *= v.x;
    this->y *= v.y;

    return *this;
}

Vector2D& Vector2D::divide(const Vector2D& v) {
    this->x /= v.x;
    this->y /= v.y;

    return *this;
}


/** ==============================================================================
 *  |                          ARITHMETIC OPERATORS                              |
 *  ==============================================================================
*/

Vector2D& operator+(Vector2D& v1, const Vector2D& v2) {
    return v1.add(v2);
}

Vector2D& operator-(Vector2D& v1, const Vector2D& v2) {
    return v1.substract(v2);
}

Vector2D& operator*(Vector2D& v1, const Vector2D& v2) {
    return v1.multiply(v2);
}

Vector2D& operator/(Vector2D& v1, const Vector2D& v2) {
    return v1.divide(v2);
}

Vector2D& Vector2D::operator+=(Vector2D& v) {
    return this->add(v);
}

Vector2D& Vector2D::operator-=(Vector2D& v) {
    return this->substract(v);
}

Vector2D& Vector2D::operator*=(Vector2D& v) {
    return this->multiply(v);
}

Vector2D& Vector2D::operator/=(Vector2D& v) {
    return this->divide(v);
}

Vector2D& Vector2D::operator*(const float& f) {
    this->x *= f;
    this->y *= f;

    return *this;
}

Vector2D& Vector2D::operator*=(const float& f) {
    this->x *= f;
    this->y *= f;

    return *this;
}

Vector2D& Vector2D::zero() {
    this->x = 0;
    this->y = 0;

    return *this;
}



/** ==============================================================================
 *  |                           STREAM OPERATORS                                 |
 *  ==============================================================================
*/

std::ostream& operator<<(std::ostream& stream, const Vector2D& v) {
    stream << "[" << v.x << ", " << v.y << ")";

    return stream;
}
