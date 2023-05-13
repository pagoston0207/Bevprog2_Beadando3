#ifndef MACHINEPLAYER_H_INCLUDED
#define MACHINEPLAYER_H_INCLUDED
#include "../DeepLearning/TicTacToeAI/NeuralNetwork.h"
#include "Player.h"
class MachinePlayer: public Player, public NeuralNetwork
{
protected:
public:
    MachinePlayer ();
};

#endif // MACHINEPLAYER_H_INCLUDED
