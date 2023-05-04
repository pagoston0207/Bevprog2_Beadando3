#include "Project.h"
#include "iostream"
Project::Project()
{

}
Project::Project(const Scene &baseScene)
{
    scenes.push_back(baseScene);
    currentScene= &scenes.back();
}
void Project::Add( Widget* _widget)
{
    if(currentScene)
    currentScene->Add(_widget);
}

void Project::Update()
{
    if(currentScene)
    currentScene->Print();
}
void Project::Handle(event ev)
{
    if(currentScene)
    currentScene->Handle(ev);
}
