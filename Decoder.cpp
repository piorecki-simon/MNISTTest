//
// Created by Simon on 14.03.2019.
//

#include "Decoder.h"
#include <fstream>

Decoder::Decoder() = default;

Decoder::~Decoder() = default;

std::vector<Decoder::Digit*> Decoder::LoadData(const char* ImagePath, const char* LabelPath)
{
    std::vector<char> ImageData = ReadAllBytes(ImagePath);
    std::vector<char> LabelData = ReadAllBytes(LabelPath);

    std::vector<Digit*> Digits;

    int DataHead = 16;
    int LabelHead = 8;

    // Inserts an image (28x28) into Data and the relative label into Label
    // and creates a new object of type Digit which holds the image and the related label.
    // This object is then pushed into the vector which is returned when finished
    while (DataHead < ImageData.size())
    {
        std::vector<std::vector<char>> Data(28, std::vector<char>(28));

        for (unsigned int i = 0; i < 28; ++i)
        {
            for (unsigned int k = 0; k < 28; ++k)
            {
                Data[i][k] = ImageData[DataHead++];
            }
        }

        int Label = (unsigned char) LabelData[LabelHead++];

        Digits.push_back(new Digit(Label, Data));
    }

    return Digits;
}

// https://codereview.stackexchange.com/questions/22901/reading-all-bytes-from-a-file
std::vector<char> Decoder::ReadAllBytes(const char* Filepath)
{
    std::ifstream Ifstream(Filepath, std::ios::binary | std::ios::ate);
    std::ifstream::pos_type Pos = Ifstream.tellg();

    std::vector<char> Result(Pos);

    Ifstream.seekg(0, std::ios::beg);
    Ifstream.read(&Result[0], Pos);

    return Result;
}

Decoder::Digit::Digit(int &Label, std::vector<std::vector<char>> &Data)
{
    this->Label = Label;
    this->Data = Data;
}

Decoder::Digit::~Digit() = default;
