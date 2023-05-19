#include "TextButton.h"
TextButton::TextButton(function <void(TextButton* sender)> _callbackFunction, string text, Vector2 _size, Widget* _parent):FilledText(text, _size,_parent)
{
    callbackFunction = _callbackFunction;
}
TextButton::TextButton()
{

}
bool TextButton:: IsOver(Vector2 _pos)
{
    if(!enabled)
        return false;
    for(Widget* &c:children)
    {
        if(c->IsOver(_pos))
        {
            return true;
        }
    }
    return(GetWorldPos().x+size.x/2>_pos.x&&GetWorldPos().x-size.x/2<_pos.x&&GetWorldPos().y+size.y/2>_pos.y&&GetWorldPos().y-size.y/2<_pos.y);
}
void TextButton::Handle(event ev)
{
    Widget::Handle(ev);
    if(ev.button==1&&IsOver(Vector2(ev.pos_x,ev.pos_y)))
    {
        Trigger();
    }
}
void TextButton::Trigger()
{
    callbackFunction(this);
}
