#include "controller.h"
#include "view.h"
#include "model.h"
#include "import_helper.h"
#include "filesDAO.h"

void controller::create_new_file(model* model_ptr){
    std::unique_ptr<our_file> new_file = std::make_unique<our_file>(our_file());
    model_ptr->File(move(new_file));
    std::cout << "тут мы меняем всю гуишку на окошко с кнопочками возможности редактирования файла" << std::endl;
    view::create_buttons_for_treat_fle(model_ptr);
}

void controller::get_recent_files(std::vector<std::string>& recently_edited_files){
    filesDAO::get_recent_files_from_DB(recently_edited_files);
}

void controller::create_file(model* model_ptr, std::string& folder, std::string& file_name){

    our_file_content* file_content = import_helper::import_file(folder, file_name);
    std::unique_ptr<our_file> new_file = std::make_unique<our_file>(file_name, folder, *file_content);
    model_ptr->File(move(new_file));
    std::cout << "тут мы меняем всю гуишку на окошко с кнопочками возможности редактирования файла" << std::endl;
    view::create_buttons_for_treat_fle(model_ptr);
}

void controller::parse_full_file_name(const std::string& full_file_name, std::string& file_name, std::string& file_path){
    std::string system_delimiter = "/";
    size_t last = full_file_name.find_last_of(system_delimiter);
    file_name = full_file_name.substr(last+1);
    file_path = full_file_name.substr(0, last);
}

void controller::open_recent_file(model* model_ptr, const std::string& full_file_name){

    std::string file_name;
    std::string file_path;

    parse_full_file_name(full_file_name, file_name, file_path);

    create_file(model_ptr, file_path, file_name);
}

