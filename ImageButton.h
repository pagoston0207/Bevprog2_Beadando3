#ifndef IMAGEBUTTON_H_INCLUDED
#define IMAGEBUTTON_H_INCLUDED
#include "Sprite.h"
#include "functional"
using genv::event;
using std::function;
class ImageButton:public Sprite
{
protected:
    function <void(ImageButton* sender)> callbackFunction;
public:
    ImageButton();
    ImageButton(function <void(ImageButton* sender)> _calllbackFunction, Vector2 _size=Vector2(0,0),Widget* _parent =0,string _graphicFileName="");
    virtual void Handle(event ev)override;
    void Trigger();
};

#endif // IMAGEBUTTON_H_INCLUDED
