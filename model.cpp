#include "model.h"

model::model() : new_file(nullptr){}

model::model(our_file* file) : new_file(file);

our_file* model::File(){
    return new_file;
}

void model::File(our_file* file){
    new_file = file;
}