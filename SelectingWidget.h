#ifndef SELECTINGWIDGET_H_INCLUDED
#define SELECTINGWIDGET_H_INCLUDED
#include<vector>
#include "TextButton.h"
#include "ImageButton.h"
#include "Widget.h"
class SelectingWidget:public Widget
{
protected:
    vector<TextButton> _list;
    TextButton* current;
    ImageButton butDropdown;
    vector<string> values;
    Vector2 elementSize;
    int maxItemsDisplayed;
    int firstItemDisplayedIndex;
    bool listOpen;
    void switchState();
    void setCurrent(TextButton* newCurrentElement);
    void setCurrent(string _value);
    void displayList();
public:
    SelectingWidget(vector<string> initialValues={"Default1","Default2"},Vector2 _elementSize=Vector2(100,30),int _maxItemsDisplayed=3);
    string GetCurrentValue();
    void AddItem(string _value);
    void RemoveItem(string _value);
    void RemoveItemAt(int index);
    virtual void Handle(event ev)override;
    void ScrollBy(int _value);
};

#endif // SELECTINGWIDGET_H_INCLUDED
