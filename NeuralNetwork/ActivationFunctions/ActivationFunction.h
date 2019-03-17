//
// Created by Simon on 15.03.2019.
//

#ifndef MNISTTEST_ACTIVATIONFUNCTION_H
#define MNISTTEST_ACTIVATIONFUNCTION_H


class ActivationFunction {
public:
    static double IdentityActivation(double &Input);
    static double IdentityDerivativeActivation(double &Input);
    static double SigmoidActivation(double &Input);
    static double SigmoidDerivativeActivation(double &Input);
    static double BooleanActivation(double &Input);
    static double BooleanDerivativeActivation(double &Input);
    static double HyperbolicTangentActivation(double &Input);
    static double HyperbolicTangentDerivativeActivation(double &Input);
};


#endif //MNISTTEST_ACTIVATIONFUNCTION_H
