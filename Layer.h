#ifndef LAYER_H_INCLUDED
#define LAYER_H_INCLUDED
#include<vector>
#include "Widget.h"
using genv::event;
class Layer
{
protected:

    std::vector<Widget*>roots;
    bool enabled;
public:
    Layer();
    void Add(Widget* _widget);
    void Print();
    void Handle(event ev);
    Widget* GetHovered(Vector2 _pos);
};

#endif // LAYER_H_INCLUDED
