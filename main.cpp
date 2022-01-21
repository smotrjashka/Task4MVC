#include <iostream>

#include "model.h"


#include "view.h"


int main() {

    model* model_ptr = new model();
    view::startGUI(model_ptr);

    //тут надо бы сделать ещё возможность сейф клоуз программы но как?

    return 0;
}
