//
// Created by Simon on 15.03.2019.
//

#ifndef MNISTTEST_WORKINGNEURON_H
#define MNISTTEST_WORKINGNEURON_H

#include <vector>
#include "Neuron.h"

class Connection;

class WorkingNeuron : public Neuron {
public:
    WorkingNeuron();
    ~WorkingNeuron();

    /**
     * Sums up all weights of Connections and applies the ActivationFunction
     * @return The result of the ActivationFunction
     */
    double GetValue() override;

    /**
     * Adds new Connection to the Connections of this WorkingNeuron
     * @param C will be added to the Connection of this WorkingNeuron
     */
    void AddConnection(Connection* C);

    /**
     *
     * @param Epsilon
     * @param SmallData
     */
    void DeltaLearning(double &Epsilon, double &SmallData);

private:
    std::vector<Connection*> Connections;
};


#endif //MNISTTEST_WORKINGNEURON_H
