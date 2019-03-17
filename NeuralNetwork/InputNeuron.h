//
// Created by Simon on 15.03.2019.
//

#ifndef MNISTTEST_INPUTNEURON_H
#define MNISTTEST_INPUTNEURON_H

#include "Neuron.h"

class InputNeuron : public Neuron {
public:
    InputNeuron();
    ~InputNeuron();

    double GetValue() override;
    void SetValue(double &Value);

private:
    double Value = 0;
};


#endif //MNISTTEST_INPUTNEURON_H
