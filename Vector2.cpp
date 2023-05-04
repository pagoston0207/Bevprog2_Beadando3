#include "Vector2.h"
#include <cmath>
Vector2::Vector2(float X,float Y)
{
    x=X;
    y=Y;
}
Vector2::Vector2()
{
    x=0;
    y=0;
}
void Vector2::operator+=(const Vector2 &a)
{
    x+=a.x;
    y+=a.y;
}
void Vector2::operator-=(const Vector2 &a)
{
    x-=a.x;
    y-=a.y;
}
void Vector2::operator=(const Vector2 &a)
{
    x = a.x;
    y = a.y;
}
void Vector2::operator *= (const float &a)
{
    x*=a;
    y*=a;
}
Vector2 Vector2::operator-(const Vector2 &a)
{
    Vector2 res;
    res.x = x - a.x;
    res.y = y - a.y;
    return res;
}
Vector2 Vector2::operator+(const Vector2 &a)
{
    Vector2 res;
    res.x = x + a.x;
    res.y = y + a.y;
    return res;
}
Vector2 Vector2::operator /(const float &a)
{
    Vector2 res;
    res.x = x/a;
    res.y = y/a;
    return res;
}
Vector2 Vector2::operator *(const float &a)
{
    Vector2 res;
    res.x = x*a;
    res.y = y*a;
    return res;
}
Vector2 Vector2::operator/(const Vector2 &other)
{
    return Vector2(x/other.x,y/other.y);
}
float Vector2::DistanceFrom(Vector2 other)
{
    return sqrt(pow(x-other.x,2)+pow(y-other.y,2));
}
float Vector2::GetLength()
{
    return sqrt(pow(x,2)+pow(y,2));
}
