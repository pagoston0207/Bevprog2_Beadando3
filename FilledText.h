#ifndef FILLEDTEXT_H_INCLUDED
#define FILLEDTEXT_H_INCLUDED
#include"Text.h"

class FilledText:public Text
{
protected:
    virtual void InitializeSprite();
public:
    FilledText();
    FilledText(string value, Vector2 _size=Vector2(10,10),Widget* _parent=0);
};


#endif // FILLEDTEXT_H_INCLUDED
