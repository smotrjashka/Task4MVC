#ifndef TASK4_MODEL_H
#define TASK4_MODEL_H


#include "our_file.h"

class model {

public:
    model();
    model(our_file* file);

    our_file* File();
    void File(our_file* file);

private:
    our_file* new_file;


};


#endif //TASK4_MODEL_H
