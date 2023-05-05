#include "Scene.h"
#include "iostream"
using genv::ev_mouse;
using std::cout;
using std::endl;

Scene::Scene()
{
    selected=0;

}
Scene::Scene(const Layer &baseLayer)
{
    layers.push_back(baseLayer);
    selected=0;
}
void Scene::Add( Widget* _widget)
{
    widgets.push_back(*_widget);
    layers[layers.size()-1].Add(_widget);
}


void Scene::Print()
{
    for(Layer &l : layers)
    {
        l.Print();
    }
}
void Scene::Handle(event ev)
{
    for(Layer &l : layers)
    {
        if(ev.type == ev_mouse&&ev.button ==1)
        {
                selected=0;
            if(l.GetHovered(Vector2(ev.pos_x,ev.pos_y)))
            {
                selected=l.GetHovered(Vector2(ev.pos_x,ev.pos_y));
            }
        }
        if(selected)
        selected->Handle(ev);
    }

}
