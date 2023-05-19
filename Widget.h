#ifndef WIDGET_H_INCLUDED
#define WIDGET_H_INCLUDED
#include "Vector2.h"
#include <vector>
#include "graphics.hpp"
using  std::vector;
class Widget
{
protected:
    Vector2 pos;
    Vector2 size;
    vector<Widget*> children;
    Widget* parent;
    bool enabled;
public:
    Widget(Vector2 _size=Vector2(0,0),Widget* _parent=0);
    void MoveTo(Vector2 targetPos);
    Vector2 GetWorldPos();
    void SetActive(bool _value);
    virtual void Print();
    virtual void Handle(genv::event ev);
    virtual bool IsOver(Vector2 _pos);
};

#endif // WIDGET_H_INCLUDED
