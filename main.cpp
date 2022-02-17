#include <iostream>

#include "model.h"
#include "view.h"


int main() {

    std::unique_ptr<model> model_ptr = std::make_unique<model>(model());
    view::startGUI(move(model_ptr));

    //тут надо бы сделать ещё возможность сейф клоуз программы но как?

    return 0;
}
