#include "FilledText.h"
#include <iostream>
#include "graphics.hpp"
using genv::move_to;
using genv::color;
using genv::box;
using genv::gout;
using genv::text;
FilledText::FilledText()
{
    _canvas.open(size.x,size.y);
    value="Default Text";
    InitializeSprite();
}
FilledText::FilledText(string _text, Vector2 _size,Widget* _parent):Text(_text, _size, _parent)
{
    InitializeSprite();
}
void FilledText::InitializeSprite()
{
    _canvas.open(size.x,size.y);
    _canvas.set_antialias(true);
    _canvas<<move_to(0,0)<<color(255,255,255)<<box(size.x,size.y);
    _canvas<<move_to(size.x/2-gout.twidth(value)/3>0?size.x/2-gout.twidth(value)/3:0,size.y/2+gout.cdescent())<<color(0,0,0)<<text(value);
}
