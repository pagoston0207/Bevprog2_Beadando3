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
void Project::ClearScene()
{
    scenes.clear();
    scenes.push_back(Scene(Layer()));
    currentScene = &scenes[0];
}
void Project::LoadScene(int index)
{
    if(index<scenes.size()&&index>=0)
    currentScene = &scenes[index];
}
void Project::AddScene(const Scene &scene, bool load)
{
    scenes.push_back(scene);
    if(load)
    {
        currentScene = &scenes.back();
    }
}
