//
// Created by Simon on 15.03.2019.
//

#include "WorkingNeuron.h"
#include "Connection.h"
#include "ActivationFunctions/ActivationFunction.h"

WorkingNeuron::WorkingNeuron() = default;

WorkingNeuron::~WorkingNeuron() = default;

double WorkingNeuron::GetValue()
{
    double Sum = 0.0;

    for (unsigned int i = 0; i < Connections.size(); ++i)
    {
        Sum += Connections[i]->GetValue();
    }

    return ActivationFunction::IdentityActivation(Sum);
}

void WorkingNeuron::AddConnection(Connection *C)
{
    Connections.push_back(C);
}

void WorkingNeuron::DeltaLearning(double &Epsilon, double &SmallData)
{
    for (unsigned int i = 0; i < Connections.size(); ++i)
    {
        double BigDelta = Epsilon * SmallData * Connections[i]->GetNeuron()->GetValue();
        Connections[i]->AddWeight(BigDelta);
    }
}

