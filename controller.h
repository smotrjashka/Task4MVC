#ifndef TASK4_CONTROLLER_H
#define TASK4_CONTROLLER_H

#include <string>
#include <iostream>
#include <vector>
#include "model.h"

namespace controller {

    void create_new_file(model::model* model_ptr);
    void create_file(model::model* model_ptr, std::string& folder, std::string& file_name);
    void parse_full_file_name(const std::string& full_file_name, std::string& file_name, std::string& file_path);
    void open_recent_file(model::model* model_ptr, const std::string& full_file_name);
    void get_recent_files(std::vector<std::string>& recently_edited_files);

};


#endif //TASK4_CONTROLLER_H
