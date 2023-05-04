#include "SelectingWidget.h"
#include <iostream>
using genv::btn_wheelup;
using genv::btn_wheeldown;
using genv::key_up;
using genv::key_down;
using std::cerr;
using std::endl;
SelectingWidget::SelectingWidget(vector<string> initialValues,Vector2 _elementSize, int _maxItemsDisplayed):elementSize(_elementSize),maxItemsDisplayed(_maxItemsDisplayed)
{
    values= initialValues;
    listOpen=false;
    firstItemDisplayedIndex=0;
    butDropdown = ImageButton([this](ImageButton* sender){switchState();},Vector2(elementSize.y,elementSize.y),this,"ExpandDown.bmp.kep");
    butDropdown.MoveTo(Vector2(elementSize.y/2,0));
    children.push_back(&butDropdown);
    for(string v :  values)
    {
        _list.push_back(TextButton([this](TextButton* sender){setCurrent(sender);switchState();},v,Vector2(elementSize.x,elementSize.y),this));
        _list[_list.size()-1].SetActive(false);
    }
    for(TextButton &tb :_list)
    {
        children.push_back(&tb);

    }
    setCurrent(values[0]);
    current->MoveTo(Vector2(-elementSize.x/2,0));
    current->SetActive(true);
}
void SelectingWidget::displayList()
{
    if(_list.size()<maxItemsDisplayed)
            firstItemDisplayedIndex=0;
    if(firstItemDisplayedIndex<_list.size())
    {
        current->SetActive(false);
        int start = firstItemDisplayedIndex<_list.size()-maxItemsDisplayed?firstItemDisplayedIndex:_list.size()-maxItemsDisplayed;
        if (start>_list.size()-maxItemsDisplayed)
            start= _list.size()-maxItemsDisplayed;
        for(TextButton &e : _list)
        {
            e.SetActive(false);
        }
        for(int i=start; i< _list.size()&&i<start +maxItemsDisplayed;i++)
        {
            _list[i].SetActive(true);
            _list[i].MoveTo(Vector2(-elementSize.x/2,(i-start)*elementSize.y));
        }
        listOpen=true;
    }
    else
    {
        cerr<<"Index out of range exception"<<endl;
    }
}
void SelectingWidget::switchState()
{
    if(listOpen)
    {
        for(TextButton &e: _list)
        {
            e.SetActive(false);
        }
        if(current)
        {
            current->MoveTo(Vector2(-elementSize.x/2,0));
            current->SetActive(true);
        }
        listOpen=false;

    }
    else
    {
        displayList();
    }
}
void SelectingWidget::setCurrent(TextButton* newCurrentElement)
{
    for(int i =0; i<_list.size();i++)
    {
        if(&_list[i]==newCurrentElement)
        {
            firstItemDisplayedIndex=i;
        }
    }
    current = newCurrentElement;
}
void SelectingWidget::setCurrent(string _value)
{
    for(TextButton &e : _list)
    {
        if(e.GetValue()==_value)
        {
            current = &e;
        }
    }
}
void SelectingWidget::Handle(event ev)
{
    Widget::Handle(ev);
    if(ev.button==btn_wheelup||ev.keycode==key_up)
    {
        if(firstItemDisplayedIndex>0&&listOpen)
        {
            firstItemDisplayedIndex --;
            displayList();
        }
    }
    if(ev.button==btn_wheeldown||ev.keycode==key_down)
    {
        if(firstItemDisplayedIndex<(_list.size()-maxItemsDisplayed)&&listOpen)
        {
            firstItemDisplayedIndex ++;
            displayList();

        }
    }
}
string SelectingWidget::GetCurrentValue()
{
    return current->GetValue();
}
