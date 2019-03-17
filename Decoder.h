//
// Created by Simon on 14.03.2019.
//

#ifndef MNISTTEST_DECODER_H
#define MNISTTEST_DECODER_H

#include <vector>

class Decoder {
public:
    Decoder();
    ~Decoder();

    /**
     * A class which holds the image data of one digit and its related label
     */
    class Digit {
    public:
        Digit(int &Label, std::vector<std::vector<char>> &Data);
        ~Digit();

    public:
        int Label;
        std::vector<std::vector<char>> Data;
    };

public:

    /**
     * Loads the MNIST data from the local computer
     * @param ImagePath determines the location of the image data
     * @param LabelPath determines the location of the label data
     * @return A Decoder::Digit* vector which holds all image data (28x28) and their related labels
     */
    static std::vector<Decoder::Digit*> LoadData(const char* ImagePath, const char* LabelPath);
private:

    /**
    * Reads all bytes of a given file
    * @param Filepath determines the location of the file
    * @return A char vector which holds the bytes
    */
    static std::vector<char> ReadAllBytes(const char* Filepath);
};

#endif //MNISTTEST_DECODER_H
