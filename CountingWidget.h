#ifndef COUNTINGWIDGET_H_INCLUDED
#define COUNTINGWIDGET_H_INCLUDED
#include "Widget.h"
#include "TextButton.h"
#include "FilledText.h"
class CountingWidget:public Widget
{
protected:
    TextButton butUp;
    TextButton butDown;
    int maxValue;
    int minValue;
    int step;
    FilledText display;
    int value;
public:
    CountingWidget(int _minValue=0, int _maxValue=100, int step=1);
    virtual void Handle(event ev)override;
    int GetCurrentValue();
};

#endif // COUNTINGWIDGET_H_INCLUDED
