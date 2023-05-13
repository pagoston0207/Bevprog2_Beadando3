#include "Text.h"
#include "graphics.hpp"
using genv::gout;
using genv::move_to;
using genv::color;
using genv::text;
using genv::stamp;
Text::Text()
{
    InitializeSprite();
}
Text::Text(string text, Vector2 _size,Widget* _parent):Sprite(_size, _parent)
{
    value=text;
    InitializeSprite();
}
void Text::SetText(string newText)
{
    value= newText;
    InitializeSprite();
}
string Text::GetValue()
{
    return value;
}
void Text::InitializeSprite()
{
    _canvas.open(size.x,size.y);
    _canvas.set_antialias(true);
    _canvas<<move_to(size.x/2-gout.twidth(value)/3>0?size.x/2-gout.twidth(value)/3:0,size.y/2+gout.cdescent())<<color(255,255,255)<<text(value);
}
void Text::Print()
{
    if(!enabled)
        return;
    for(Widget* &c:children)
    {
        c->Print();
    }
    gout<<stamp(_canvas,GetWorldPos().x-size.x/2,GetWorldPos().y-size.y/2);
}
