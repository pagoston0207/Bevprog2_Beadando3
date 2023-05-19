#include "Layer.h"
using genv::event;
using genv::ev_mouse;
Layer::Layer()
{

}
void Layer::Add( Widget* _widget)
{
    roots.push_back(_widget);
}
void Layer::Print()
{
    for(Widget* &o : roots)
    {
        if(o)
        o->Print();
    }
}
void Layer::Handle(event ev)
{
    for(Widget* &o : roots)
    {
        if(o)
        {
            o->Handle(ev);
        }
    }
}
Widget* Layer::GetHovered(Vector2 _pos)
{
    Widget* highest=0;
    for(Widget* &o :roots)
    {
        if(o)
        {
            if(o->IsOver(_pos))
            {
                highest=o;
            }
        }
    }
    return highest;
}
