#include "Widget.h"
using genv::event;

Widget::Widget(Vector2 _size,Widget* _parent)
{
    parent = _parent;
    pos = Vector2(0,0);
    size = _size;
    enabled = true;
}
Vector2 Widget::GetWorldPos()
{
    if(parent!=0)
    {
        return pos + parent->GetWorldPos();
    }
    else
    {
        return pos;
    }
}
void Widget::MoveTo(Vector2 targetPos)
{
    pos = targetPos;
}
void Widget::Print()
{
    if(!enabled)
        return;
    for(Widget* &c:children)
    {
        if(c)
        c->Print();
    }
}
void Widget::Handle(event ev)
{
    for(Widget* &o : children)
    {
        if(o)
        o->Handle(ev);
    }
}
bool Widget::IsOver(Vector2 _pos)
{
    if(!enabled)
        return false;
    for(Widget* &c:children)
    {
        if(c)
        if(c->IsOver(_pos))
        {
            return true;
        }
    }
    return(GetWorldPos().x+size.x/2>_pos.x&&GetWorldPos().x-size.x/2<_pos.x&&GetWorldPos().y+size.y/2>_pos.y&&GetWorldPos().y-size.y/2<_pos.y);

}
void Widget::SetActive(bool _value)
{
    enabled = _value;
}
