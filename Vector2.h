#ifndef VECTOR2_H_INCLUDED
#define VECTOR2_H_INCLUDED


struct Vector2
{
    float x;
    float y;

    Vector2(float X,float Y);
    Vector2();
    void operator+=(const Vector2 &a);
    void operator-=(const Vector2 &a);
    void operator=(const Vector2 &a);
    void operator *= (const float &a);
    Vector2 operator-(const Vector2 &a);
    Vector2 operator+(const Vector2 &a);
    Vector2 operator /(const float &a);
    Vector2 operator /(const Vector2 &other);
    Vector2 operator *(const float &a);
    float DistanceFrom(Vector2 other);
    float GetLength();
};
#endif // VECTOR2_H_INCLUDED
