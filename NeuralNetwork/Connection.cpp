//
// Created by Simon on 15.03.2019.
//

#include "Connection.h"
#include "Neuron.h"

Connection::Connection(class Neuron *N, double &Weight)
{
    this->Neuron = N;
    this->Weight = Weight;
}

Connection::~Connection() = default;

double Connection::GetValue() {
    return Neuron->GetValue() * Weight;
}

void Connection::AddWeight(double &WeightDelta) {
    this->Weight += WeightDelta;
}

Neuron *Connection::GetNeuron() {
    return Neuron;
}
