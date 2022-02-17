#ifndef TASK4_MODEL_H
#define TASK4_MODEL_H

#include <memory>
#include "our_file.h"

class model {

public:
    model();
    model(std::unique_ptr<our_file> file);
    ~model();

    our_file* File();
    void File(std::unique_ptr<our_file> file);

private:
    std::unique_ptr<our_file> new_file;


};


#endif //TASK4_MODEL_H
