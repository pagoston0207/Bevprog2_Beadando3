#ifndef PROJECT_H_INCLUDED
#define PROJECT_H_INCLUDED
#include "vector"
#include"Scene.h"
#include"TextButton.h"
#include "Widget.h"

class Project
{
protected:
vector<Scene> scenes;
Scene* currentScene;
public:
    Project();
    Project(const Scene &baseScene);
    void Add( Widget* _widget);
    void Update();
    void Handle(event ev);
};

#endif // PROJECT_H_INCLUDED
