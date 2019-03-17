cmake_minimum_required(VERSION 3.13)
project(MNISTTest)

set(CMAKE_CXX_STANDARD 17)

add_executable(MNISTTest main.cpp NeuralNetwork/Neuron.h Decoder.cpp Decoder.h NeuralNetwork/NeuralNetwork.cpp NeuralNetwork/NeuralNetwork.h NeuralNetwork/InputNeuron.cpp NeuralNetwork/InputNeuron.h NeuralNetwork/WorkingNeuron.cpp NeuralNetwork/WorkingNeuron.h NeuralNetwork/Connection.cpp NeuralNetwork/Connection.h NeuralNetwork/ActivationFunctions/ActivationFunction.cpp NeuralNetwork/ActivationFunctions/ActivationFunction.h)