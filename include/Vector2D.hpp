#ifndef Vector2D_hpp
#define Vector2D_hpp

#include <iostream>

class Vector2D {
public:
    float x, y;

    Vector2D();
    Vector2D(float x, float y);

    Vector2D& add(const Vector2D& v);
    Vector2D& substract(const Vector2D& v);
    Vector2D& multiply(const Vector2D& v);
    Vector2D& divide(const Vector2D& v);

    friend Vector2D& operator+(Vector2D& v1, const Vector2D& v2);
    friend Vector2D& operator-(Vector2D& v1, const Vector2D& v2);
    friend Vector2D& operator*(Vector2D& v1, const Vector2D& v2);
    friend Vector2D& operator/(Vector2D& v1, const Vector2D& v2);

    Vector2D& operator+=(Vector2D& v);
    Vector2D& operator-=(Vector2D& v);
    Vector2D& operator*=(Vector2D& v);
    Vector2D& operator/=(Vector2D& v);

    Vector2D& operator*(const float& f);
    Vector2D& operator*=(const float& f);
    Vector2D& zero();

    friend std::ostream& operator<<(std::ostream& stream, const Vector2D& v);


private:

};

#endif