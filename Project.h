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
event ev;
Vector2 _screenSize;
public:
    Project();
    Project(const Scene &baseScene, Vector2 screenSize= Vector2(750,750));
    void Start(int timeInterval);
    void Add( Widget* _widget);
    void Update();
    void Handle(event ev);
    void ClearScene();
    void LoadScene(int index);
    void AddScene(const Scene &scene, bool load=false);
};

#endif // PROJECT_H_INCLUDED
