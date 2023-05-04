#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED
#include "Sprite.h"
#include "Color.h"
class Text: public Sprite
{
protected:
    string value;
    string font;
    virtual void InitializeSprite()override;
public:
    Text();
    Text(string text, Vector2 _size=Vector2(100,100),Widget* _parent=0);
    void SetText(string newText);
    void SetColor(Color textColor);
    string GetValue();
    virtual void Print()override;
};

#endif // TEXT_H_INCLUDED
