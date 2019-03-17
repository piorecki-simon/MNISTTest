#include <iostream>
#include <random>
#include <algorithm>
#include "Decoder.h"
#include "NeuralNetwork/InputNeuron.h"
#include "NeuralNetwork/NeuralNetwork.h"
#include "NeuralNetwork/WorkingNeuron.h"

extern double Learn;
extern double Learn2;

class ProbabilityDigit {
public:
    ProbabilityDigit(unsigned int Digit, double Probability)
    {
        this->Digit = Digit;
        this->Probability = Probability;
    }

    ~ProbabilityDigit() = default;

public:
    unsigned int Digit;
    double Probability;
};

static void Test(
        std::vector<Decoder::Digit*> &DigitTests,
        std::vector<std::vector<InputNeuron*>> &InputNeurons,
        std::vector<WorkingNeuron*> &OutputNeurons)
{
    unsigned int Correct = 0;
    unsigned int Incorrect = 0;

    for (unsigned int i = 0; i < DigitTests.size(); ++i)
    {
        for (unsigned int x = 0; x < 28; ++x)
        {
            for (unsigned int y = 0; y < 28; ++y)
            {
                double Z = (unsigned char) DigitTests[i]->Data[x][y] / 255.0;
                InputNeurons[x][y]->SetValue(Z);
            }
        }

        std::vector<ProbabilityDigit*> Probs(10);
        for (unsigned int k = 0; k < Probs.size(); ++k)
        {
            Probs[k] = new ProbabilityDigit(k, OutputNeurons[k]->GetValue());
        }

        // Sorts the vector in descending order by each Probability
        // Uses Lambda expression: https://en.cppreference.com/w/cpp/language/lambda
        // https://stackoverflow.com/questions/1380463/sorting-a-vector-of-custom-objects
        std::sort(Probs.begin(), Probs.end(), [] (const auto &lhs, const auto &rhs)
        {
            return lhs->Probability > rhs->Probability;
        });

        bool WasCorrect = false;

        for (unsigned int j = 0; j < 1; ++j)
        {
            if (DigitTests[i]->Label == Probs[j]->Digit)
            {
                WasCorrect = true;
            }
        }

        if (WasCorrect)
        {
            Correct++;
        }
        else
        {
            Incorrect++;
        }
    }

    double Percentage = (double) Correct / (Correct + Incorrect);
    std::cout << Percentage << std::endl;
}

int main() {
    std::vector<Decoder::Digit*> Digits;
    std::vector<Decoder::Digit*> DigitTests;
    std::vector<std::vector<InputNeuron*>> InputNeurons(28, std::vector<InputNeuron*>(28));
    NeuralNetwork* NN = new NeuralNetwork();
    std::vector<WorkingNeuron*> OutputNeurons(10);

    Digits = Decoder::LoadData(R"(C:\Users\Simon\Documents\train-images.idx3-ubyte)",
                               R"(C:\Users\Simon\Documents\train-labels.idx1-ubyte)");
    DigitTests = Decoder::LoadData(R"(C:\Users\Simon\Documents\t10k-images.idx3-ubyte)",
                                   R"(C:\Users\Simon\Documents\t10k-labels.idx1-ubyte)");

    // Creates the first layer of the NeuralNetwork (28 * 28 InputNeurons) and push them into the vector.
    for (unsigned int i = 0; i < 28; ++i)
    {
        for (unsigned int k = 0; k < 28; ++k)
        {
            InputNeurons[i][k] = NN->CreateNewInputNeuron();
        }
    }

    // Creates the last layer of the NeuralNetwork (10 OutputNeurons) and push them into the vector.
    for (unsigned int i = 0; i < 10; ++i)
    {
        OutputNeurons[i] = NN->CreateNewOutputNeuron();
    }

    // Creates random weights for each connection (28 * 28 * 10 connections).
    // https://stackoverflow.com/questions/2704521/generate-random-double-numbers-in-c
    std::vector<double> Weights(28 * 28 * 10);
    for (unsigned int r = 0; r < Weights.size(); ++r)
    {
        Weights[r] = (1.0 - 0.0) * ((double) rand() / (double) RAND_MAX) + 0.0;
    }

    NN->CreateFullMesh(Weights);

    double Epsilon = 0.01;

    while (true)
    {
        Test(DigitTests, InputNeurons, OutputNeurons);

        for (unsigned int i = 0; i < Digits.size(); ++i) {
            for (unsigned int x = 0; x < 28; ++x) {
                for (unsigned int y = 0; y < 28; ++y) {
                    double Z = (unsigned char) Digits[i]->Data[x][y] / 255.0;
                    InputNeurons[x][y]->SetValue(Z);
                }
            }

            std::vector<double> Shoulds(10);
            Shoulds[Digits[i]->Label] = 1;
            NN->CreateDeltaLearning(Shoulds, Epsilon);
        }

        Epsilon *= 0.9;
    }
}