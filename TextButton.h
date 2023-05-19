#ifndef TEXTBUTTON_H_INCLUDED
#define TEXTBUTTON_H_INCLUDED
#include "FilledText.h"
#include"functional"
using genv::event;
using std::function;
class TextButton:public FilledText
{
protected:
    function <void(TextButton* sender)> callbackFunction;
public:
    TextButton();
    TextButton(function <void(TextButton* sender)> _callbackFunction, string _text,Vector2 _size = Vector2(10,10), Widget* _parent=0);
    virtual bool IsOver(Vector2 _pos)override;
    virtual void Handle(event ev)override;
    void Trigger();
};


#endif // TEXTBUTTON_H_INCLUDED
