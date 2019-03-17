//
// Created by Simon on 15.03.2019.
//

#ifndef MNISTTEST_CONNECTION_H
#define MNISTTEST_CONNECTION_H

class Neuron;

class Connection {
public:
    Connection(Neuron* N, double &Weight);
    ~Connection();

    /**
     * Multiplies the Value of Neuron with Weight
     * @return The Value of the multiplication
     */
    double GetValue();

    /**
     * Adds WeightDelta to the existing Weight
     * @param WeightDelta will be added to the existing Weight of the Connection
     */
    void AddWeight(double &WeightDelta);

    /**
     * Get the Neuron of this Connection
     * @return The Neuron of this Connection
     */
    Neuron* GetNeuron();

private:
    Neuron* Neuron;
    double Weight;
};


#endif //MNISTTEST_CONNECTION_H
