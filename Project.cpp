#include "Project.h"
using genv::gout;
using genv::gin;
using genv::event;
using genv::key_escape;
using genv::ev_timer;
using genv::move_to;
using genv::color;
using genv::box;
using genv::refresh;
Project::Project()
{

}
Project::Project(const Scene &baseScene, Vector2 screenSize):_screenSize(screenSize)
{
    scenes.push_back(baseScene);
    currentScene= &scenes.back();
    gout.open(_screenSize.x,_screenSize.y);
}
void Project::Start(int timeInterval)
{
    gin.timer(timeInterval);
    while(gin >> ev&& ev.keycode!= key_escape)
    {
            Handle(ev);
            if(ev.type==ev_timer)
            {
                gout<<move_to(0,0)<<color(0,0,0)<<box(_screenSize.x,_screenSize.y);
                Update();
                gout<<refresh;
            }
    }
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
