#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED
#include <vector>
#include "Layer.h"


class Scene
{
protected:
    vector<Layer> layers;
    vector <Widget> widgets;
    Widget* selected;
public:
    Scene();
    Scene(const Layer &baseLayer);
    void Add( Widget* _widget);
    void Print();
    void Handle(event ev);
};

#endif // SCENE_H_INCLUDED
