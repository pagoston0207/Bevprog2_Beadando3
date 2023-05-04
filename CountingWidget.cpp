#include "CountingWidget.h"
#include "TextButton.h"
#include "iostream"
using genv:: key_pgdn;
using genv:: key_pgup;
using genv:: key_down;
using genv:: key_up;
using std::to_string;
CountingWidget::CountingWidget(int _minValue, int _maxValue,int _step):minValue(_minValue), maxValue(_maxValue), step(_step)
{
    value=(maxValue-minValue)/2+minValue;
    display= FilledText(to_string(value),Vector2(100,100),this);
    display.MoveTo(Vector2(-37.5,0));
    children.push_back(&display);
    butUp = TextButton( [this](TextButton* sender){value=value+step<=maxValue?value+step:maxValue;  display.SetText(to_string(value));},"+",Vector2(50,50),this);
    butUp.MoveTo(Vector2(37.5,-25));
    children.push_back(&butUp);
    butDown = TextButton( [this](TextButton* sender){value=value-step>=minValue?value-step:minValue;display.SetText(to_string(value));},"-",Vector2(50,50),this);
    butDown.MoveTo(Vector2(37.5,25));
    children.push_back(&butDown);
}
void CountingWidget::Handle(event ev)
{
    Widget::Handle(ev);
    if(ev.keycode== key_pgup)
    {
        for(int i=0; i<10;i++)
        {
            butUp.Trigger();
        }
    }
    if(ev.keycode== key_pgdn)
    {
        for(int i=0; i<10;i++)
        {
            butDown.Trigger();
        }
    }
    if(ev.keycode== key_down)
    {
        butDown.Trigger();
    }
    if(ev.keycode== key_up)
    {
        butUp.Trigger();
    }
}
int CountingWidget::GetCurrentValue()
{
    return value;
}
