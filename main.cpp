#include "Project.h"
#include "Scene.h"
#include "Layer.h"
#include "TextButton.h"
#include "CountingWidget.h"
#include "SelectingWidget.h"
#include "GameManagerController.h"
using namespace genv;
using namespace std;
const int XX=750;
const int YY=750;
int main()
{

    bool gameOver=false;
    Project p= Project(Scene(Layer()), Vector2(750,750));
    p.AddScene(Scene(Layer()),true);

    GameManagerController* GMC;

    FilledText winnerText("The winner is: lol",Vector2(300,100));
    winnerText.MoveTo(Vector2(XX/2,200));
    winnerText.SetActive(false);
    p.Add(&winnerText);

    TextButton restartButton([&restartButton,&GMC, &p,&gameOver,&winnerText](TextButton* sender)
        {
            delete GMC;
            GMC=  new GameManagerController(Vector2(15,15),Vector2(XX,YY),[XX,YY, &gameOver,&p,&restartButton, &GMC,&winnerText](GameManager* sender){gameOver = true;restartButton.SetActive(true);winnerText.SetActive(true);sender->GetFieldCount(Empty)==0?winnerText.SetText("Draw:The field is full"):winnerText.SetText("The winner is:"+GMC->GetCurrentPlayerSymbol());GMC->SetActive(false);p.Update();},"X.bmp.kep","O.bmp.kep");
            restartButton.SetActive(false);
            p.Update();
            gameOver = false;
        },"Restart", Vector2(200,75));
    restartButton.SetActive(false);
    restartButton.MoveTo(Vector2(XX/2,YY/2));

    GMC = new GameManagerController(Vector2(15,15),Vector2(XX,YY),[XX,YY, &gameOver,&p,&restartButton, &GMC,&winnerText](GameManager* sender){gameOver = true;restartButton.SetActive(true);winnerText.SetActive(true);sender->GetFieldCount(Empty)==0?winnerText.SetText("Draw:The field is full"):winnerText.SetText("The winner is:"+GMC->GetCurrentPlayerSymbol());GMC->SetActive(false);p.Update();},"X.bmp.kep","O.bmp.kep");
    p.Add(GMC);
    p.Add(&restartButton);

    p.LoadScene(0);

    TextButton startButton([&p](TextButton* sender){p.LoadScene(1);},"Start", Vector2(200,75));
    startButton.MoveTo(Vector2(XX/2,YY/2));
    p.Add(&startButton);
    p.Update();

    p.Start(35);
    return 0;
}
