//
// Created by Simon on 15.03.2019.
//

#include <cmath>
#include "ActivationFunction.h"

double ActivationFunction::IdentityActivation(double &Input)
{
    return Input;
}

double ActivationFunction::IdentityDerivativeActivation(double &Input)
{
    return 0;
}

double ActivationFunction::SigmoidActivation(double &Input)
{
    return (double) (1.0 / (1.0 + std::pow(std::exp(1.0), -Input)));
}

double ActivationFunction::SigmoidDerivativeActivation(double &Input)
{
    return 0;
}

double ActivationFunction::BooleanActivation(double &Input)
{
    if (Input < 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

double ActivationFunction::BooleanDerivativeActivation(double &Input)
{
    return 0;
}

double ActivationFunction::HyperbolicTangentActivation(double &Input)
{
    double Epx = std::pow(std::exp(1.0), Input);
    double Enx = std::pow(std::exp(1.0), -Input);

    return (Epx - Enx) / (Epx + Enx);
}

double ActivationFunction::HyperbolicTangentDerivativeActivation(double &Input)
{
    return 0;
}
