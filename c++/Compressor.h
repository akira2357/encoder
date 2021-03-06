#ifndef COMPRESSOR_H_
#define COMPRESSOR_H_

#include "Model.h"
#include "Write_bit.h"
#include <cmath>

class Compressor{
    private:
        std::string fileName;
        Model model;
        std::ifstream input_stream;
        Write_bit output_stream;
    public:
        Compressor(const std::string &fileName, const Model &model):
            fileName(fileName),
            model(model),
            input_stream(fileName),
            output_stream(fileName.substr(0,fileName.find_last_of('.'))+".code")
            {};
        void compress();
        void output_bit(const bool &);
        void output_bits(const bool &, int pending_bytes);
};

#endif
