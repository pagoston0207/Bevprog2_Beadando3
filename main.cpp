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
const int XX=750;
const int YY=750;
int main()
{

    bool gameOver=false;
    Project p= Project(Scene(Layer()), Vector2(750,750));
    p.AddScene(Scene(Layer()),true);
    bool machinePlayerEnabled=false;

    GameManagerController* GMC;

    FilledText winnerText("The winner is: lol",Vector2(300,100));
    winnerText.MoveTo(Vector2(XX/2,200));
    winnerText.SetActive(false);
    p.Add(&winnerText);

    TextButton restartButton([&restartButton,&GMC, &p,&gameOver,&winnerText, &machinePlayerEnabled](TextButton* sender)
        {
            delete GMC;
            GMC=  new GameManagerController(Vector2(15,15),Vector2(XX,YY),[XX,YY, &gameOver,&p,&restartButton, &GMC,&winnerText](GameManager* sender){gameOver = true;restartButton.SetActive(true);winnerText.SetActive(true);sender->GetFieldCount(Empty)==0?winnerText.SetText("Draw:The field is full"):winnerText.SetText("The winner is:"+GMC->GetCurrentPlayerSymbol());GMC->SetActive(false);p.Update();},"X.bmp.kep","O.bmp.kep","NeuralNetwork.txt");
            restartButton.SetActive(false);
            p.Update();
            gameOver = false;
        },"Restart", Vector2(200,75));
    restartButton.SetActive(false);
    restartButton.MoveTo(Vector2(XX/2,YY/2));

    GMC = new GameManagerController(Vector2(15,15),Vector2(XX,YY),[XX,YY, &gameOver,&p,&restartButton, &GMC,&winnerText,&machinePlayerEnabled](GameManager* sender){gameOver = true;restartButton.SetActive(true);winnerText.SetActive(true);sender->GetFieldCount(Empty)==0?winnerText.SetText("Draw:The field is full"):winnerText.SetText("The winner is:"+GMC->GetCurrentPlayerSymbol());GMC->SetActive(false);p.Update();},"X.bmp.kep","O.bmp.kep","NeuralNetwork.txt");
    GMC->EnableMachinePlayer(false);
    p.Add(GMC);
    p.Add(&restartButton);

    p.LoadScene(0);

    TextButton startButton([&p](TextButton* sender){p.LoadScene(1);},"Start", Vector2(200,75));
    startButton.MoveTo(Vector2(XX/2,YY/2));
    p.Add(&startButton);

    TextButton machinePlayerButton([&machinePlayerEnabled,&GMC](TextButton* sender){if(machinePlayerEnabled){GMC->EnableMachinePlayer(false);machinePlayerEnabled=false; sender->SetText("Machine Player: Off");}else{ GMC->EnableMachinePlayer(true); machinePlayerEnabled=true; sender->SetText("Machine Player: On");}},"Machine Player: Off",Vector2(200,75));
    machinePlayerButton.MoveTo(Vector2(XX/2, YY/2-250));
    p.Add(&machinePlayerButton);


    p.Update();


    p.Start(35);
    return 0;
}
