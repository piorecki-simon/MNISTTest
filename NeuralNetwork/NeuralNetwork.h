//
// Created by Simon on 15.03.2019.
//

#ifndef MNISTTEST_NEURALNETWORK_H
#define MNISTTEST_NEURALNETWORK_H

#include <vector>

class WorkingNeuron;
class InputNeuron;

class NeuralNetwork {
public:
    NeuralNetwork();
    ~NeuralNetwork();

    /**
     * Creates a new InputNeuron and pushes it into the InputNeurons
     * @return The new InputNeuron
     */
    InputNeuron* CreateNewInputNeuron();

    /**
     * Creates a new OutputNeuron and pushes it into the OutputNeurons
     * @return The new OutputNeuron
     */
    WorkingNeuron* CreateNewOutputNeuron();

    /**
     * Creates as much HiddenNeurons as specified in the parameter and pushes them into HiddenNeurons
     * @param Amount which specifies how many HiddenNeurons will be created
     */
    void CreateHiddenNeurons(unsigned int &Amount);

    /**
     *
     * @param Shoulds
     * @param Epsilon for the current DeltaLearning algorithm
     */
    void CreateDeltaLearning(std::vector<double> &Shoulds, double &Epsilon);

    /**
     * Creates all Connections between the InputNeurons, the HiddenNeurons and the OutputNeurons
     * @param Weights will be added to all Connections when created
     */
    void CreateFullMesh(std::vector<double> &Weights);
private:
    std::vector<InputNeuron*> InputNeurons;
    std::vector<WorkingNeuron*> OutputNeurons;
    std::vector<WorkingNeuron*> HiddenNeurons;
};


#endif //MNISTTEST_NEURALNETWORK_H
