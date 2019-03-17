//
// Created by Simon on 15.03.2019.
//

#include "InputNeuron.h"

InputNeuron::InputNeuron() = default;

InputNeuron::~InputNeuron() = default;

double InputNeuron::GetValue() {
    return Value;
}

void InputNeuron::SetValue(double &Value) {
    this->Value = Value;
}
