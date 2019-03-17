//
// Created by Simon on 15.03.2019.
//

#include <chrono>
#include "NeuralNetwork.h"
#include "InputNeuron.h"
#include "WorkingNeuron.h"
#include "Connection.h"

NeuralNetwork::NeuralNetwork() = default;

NeuralNetwork::~NeuralNetwork() = default;

InputNeuron *NeuralNetwork::CreateNewInputNeuron() {
    InputNeuron* IN = new InputNeuron();
    InputNeurons.push_back(IN);
    return IN;
}

WorkingNeuron *NeuralNetwork::CreateNewOutputNeuron() {
    WorkingNeuron* ON = new WorkingNeuron();
    OutputNeurons.push_back(ON);
    return ON;
}

void NeuralNetwork::CreateHiddenNeurons(unsigned int &Amount)
{
    for (unsigned int i = 0; i < Amount; ++i)
    {
        HiddenNeurons.push_back(new WorkingNeuron());
    }
}

void NeuralNetwork::CreateDeltaLearning(std::vector<double> &Shoulds, double &Epsilon)
{
    if (Shoulds.size() != OutputNeurons.size())
    {
        throw "The amount of OutputNeurons does not match with the parameter 'Shoulds'";
    }

    if (!HiddenNeurons.empty())
    {
        throw "HiddenNeurons exists! DeltaLearning not possible!";
    }

    for (unsigned int i = 0; i < Shoulds.size(); ++i)
    {
        double SmallData = Shoulds[i] - OutputNeurons[i]->GetValue();

        OutputNeurons[i]->DeltaLearning(Epsilon, SmallData);
    }
}

void NeuralNetwork::CreateFullMesh(std::vector<double> &Weights)
{
    if (HiddenNeurons.empty())
    {
        if (Weights.size() != InputNeurons.size() * OutputNeurons.size())
        {
            throw "CreateFullMesh: Weight count and number of InputNeurons multiplied with OutputNeurons do not match!";
        }

        unsigned int Index = 0;

        for (unsigned int i = 0; i < OutputNeurons.size(); ++i)
        {
            for (unsigned int k = 0; k < InputNeurons.size(); ++k)
            {
                OutputNeurons[i]->AddConnection(new Connection(InputNeurons[k], Weights[Index++]));
            }
        }
    }
    else
    {
        if (Weights.size() != InputNeurons.size() * HiddenNeurons.size() + OutputNeurons.size() * HiddenNeurons.size())
        {
            throw "CreateFullMesh: Weight count and number of InputNeurons multiplied with HiddenNeurons added to the multiplication of HiddenNeurons and OutputNeurons do not match!";
        }

        unsigned int Index = 0;

        for (unsigned int i = 0; i < HiddenNeurons.size(); ++i)
        {
            for (unsigned int k = 0; k < InputNeurons.size(); ++k)
            {
                HiddenNeurons[i]->AddConnection(new Connection(InputNeurons[k], Weights[Index++]));
            }
        }

        for (unsigned int i = 0; i < OutputNeurons.size(); ++i)
        {
            for (unsigned int k = 0; k < HiddenNeurons.size(); ++k)
            {
                OutputNeurons[i]->AddConnection(new Connection(HiddenNeurons[k], Weights[Index++]));
            }
        }
    }
}


