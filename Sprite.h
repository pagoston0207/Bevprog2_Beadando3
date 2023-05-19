#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED
#include "Widget.h"
using genv::canvas;
using std::string;
class Sprite:public Widget
{
protected:
    canvas _canvas;
    string graphicFileName;
    virtual void InitializeSprite();
public:
    Sprite(Vector2 _size=Vector2(10,10), Widget* _parent=0,string _graphicFileName="");
    void SetGraphic(string path);
    virtual void Print()override;
};

#endif // SPRITE_H_INCLUDED
