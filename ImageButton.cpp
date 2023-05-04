#include "ImageButton.h"
ImageButton::ImageButton()
{

}

ImageButton::ImageButton(function <void(ImageButton* sender)> _callbackFunction, Vector2 _size, Widget* _parent,string _graphicFileName):Sprite(_size, _parent,_graphicFileName)
{
    callbackFunction = _callbackFunction;
}
void ImageButton::Handle(event ev)
{
    Widget::Handle(ev);
    if(ev.button==1&&IsOver(Vector2(ev.pos_x,ev.pos_y)))
    {
        Trigger();
    }
}
void ImageButton::Trigger()
{
    callbackFunction(this);
}
