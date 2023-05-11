#include "graphics.hpp"
#include "iostream"
#include "TextButton.h"
#include "Project.h"
#include "Scene.h"
#include "Layer.h"
#include "CountingWidget.h"
#include "SelectingWidget.h"
#include "fstream"
#include "GameManagerController.h"
using namespace genv;
using namespace std;
const int XX=1000;
const int YY=1000;

int main()
{
    gout.open(XX,YY);
    event ev;


    bool gameOver=false;
    Project p= Project(Scene(Layer()));
    p.AddScene(Scene(Layer()),true);

    GameManagerController* GMC;

    FilledText winnerText("The winner is: lol",Vector2(300,100));
    winnerText.MoveTo(Vector2(XX/2,350));
    winnerText.SetActive(false);
    p.Add(&winnerText);

    TextButton restartButton([&restartButton,&GMC, &p,&gameOver,&winnerText](TextButton* sender)
        {
            delete GMC;
            GMC=  new GameManagerController(Vector2(10,10),Vector2(1000,1000),[XX,YY, &gameOver,&p,&restartButton, &GMC,&winnerText](GameManager* sender){gameOver = true;restartButton.SetActive(true);winnerText.SetActive(true);winnerText.SetText("The winner is:"+GMC->GetCurrentPlayerSymbol());GMC->SetActive(false);p.Update();gout<<refresh;},"X.bmp.kep","O.bmp.kep");
            restartButton.SetActive(false);
            p.Update();
            gameOver = false;
        },"Restart", Vector2(200,75));
    restartButton.SetActive(false);
    restartButton.MoveTo(Vector2(XX/2,YY/2));
     GMC = new GameManagerController(Vector2(5,5),Vector2(1000,1000),[XX,YY, &gameOver,&p,&restartButton, &GMC,&winnerText](GameManager* sender){gameOver = true;restartButton.SetActive(true);winnerText.SetActive(true);winnerText.SetText("The winner is:"+GMC->GetCurrentPlayerSymbol());GMC->SetActive(false);p.Update();gout<<refresh;},"X.bmp.kep","O.bmp.kep");
    p.Add(GMC);
    p.Add(&restartButton);
    p.LoadScene(0);
    TextButton startButton([&p](TextButton* sender){p.LoadScene(1);},"Start", Vector2(200,75));
    startButton.MoveTo(Vector2(XX/2,YY/2));
    p.Add(&startButton);
    p.Update();
    gin.timer(35);
    gout<<refresh;

    while(gin >> ev&& ev.keycode!= key_escape)
    {

            p.Handle(ev);
            if(ev.type==ev_timer)
            {
                gout<<move_to(0,0)<<color(0,0,0)<<box(XX,YY);
                p.Update();
                gout<<refresh;
            }



    }
    return 0;
}
