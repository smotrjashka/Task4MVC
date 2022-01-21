#ifndef TASK4_VIEW_H
#define TASK4_VIEW_H

#include <vector>
#include <string>
#include "model.h"

namespace view {

    void create_GUI();
    void change_image_and_text_for_view(const std::string& view_id, const std::string& file_name);
    void  adjust_space_to_n_views(const std::vector<std::string>& views_id);
    void create_n_views(std::vector<std::string>& views_id, unsigned int recent_edited_files_number);
    void fill_squears_with_recent_files_names_view(const std::vector<std::string>& vector1, std::vector<std::string>& views_id);
    void get_starter_interface(std::vector<std::string>& recently_edited_files, std::vector<std::string>& recently_edited_file_views_id);
    void create_buttons_for_treat_fle(model::model* model_ptr);
    void invoke_GUI_for_search_file_in_file_system();
    void startGUI(model::model* model_ptr);


};


#endif //TASK4_VIEW_H
