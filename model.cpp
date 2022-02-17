#include "model.h"

model::model() : new_file(nullptr){}

model::model(std::unique_ptr<our_file> file) : new_file(move(file)){}

our_file* model::File(){
    return new_file.get();
}

void model::File(std::unique_ptr<our_file> file){
    new_file = std::move(file);
}

model::~model(){
    new_file.reset();
}