#include "view.h"

#include <iostream>
#include <tuple>

#include "file_system_helper.h"
#include "controller.h"

void view::create_GUI(){
    /// тут типа появляется окошко (создается)
    ///появляется кнопочки
    std::cout << "imagine beautiful interface" << std::endl;
}


void view::change_image_and_text_for_view(const std::string& view_id, const std::string& file_name) {

    std::cout << "we change icon and name for vies with id=" << view_id << "to" << file_name << std::endl;
}

void  view::adjust_space_to_n_views(const std::vector<std::string>& views_id){
    std::cout << "here we creating " << views_id.size() << "view resized composed in screen acording to number" << std::endl;
    std::cout << "and give every one an id equal ids from vector"  << std::endl;
}

void view::create_n_views(std::vector<std::string>& views_id, unsigned int recent_edited_files_number){
    for (int i = 0; i < recent_edited_files_number; ++i) {
        views_id.emplace_back(std::string("view_id_" + std::to_string(i)));
    }
    adjust_space_to_n_views(views_id);
}

void view::fill_squears_with_recent_files_names_view(const std::vector<std::string>& vector1, std::vector<std::string>& views_id) {

    create_n_views(views_id, vector1.size());
    for (int i = 0; i < vector1.size(); ++i) {

        change_image_and_text_for_view(views_id[i], vector1[i]);
    }

}

void view::get_starter_interface(std::vector<std::string>& recently_edited_files, std::vector<std::string>& recently_edited_file_views_id){
    create_GUI();
    controller::get_recent_files(recently_edited_files);
    fill_squears_with_recent_files_names_view(recently_edited_files, recently_edited_file_views_id);
}


void view::create_buttons_for_treat_fle(model* model_ptr){
    ///тут я имитирую работу кнопочек так же как в старт гуи
    ///в приниципе кнопку клоуз надо было заделать ещё в старт гуи но сделаем вид что появляется у нас она только тут (не повторять в реальной жизни)
    ///1 - типа редактируем файл
    ///2 - сохраняем текущие изменения
    ///3 - сохраняем на диск
    ///4 - откатываем изменения до предидущей сохраненной версии
    ///5 - закрываем файл
    int button_pushed;

    std::cin >> button_pushed;
    switch (button_pushed) {
        case 1:
            model_ptr->File()->Content()->treat_content();
            break;
        case 2:
            model_ptr->File()->save_current_changes();
            break;
        case 3:
            model_ptr->File()->save_current_changes_on_disk();
            break;
        case 4:
            model_ptr->File()->roll_back_changes();
            break;
        case 5:
            model_ptr->File()->close();
            break;
    }
}

void view::invoke_GUI_for_search_file_in_file_system(std::unique_ptr<model> model_ptr){
    ///тут я упрощу и сделаю вид что пользователь типа обязом выберет какой-то файл, хотя в реальности такой функционал не прокатил бы)
    std::tuple<std::string, std::string> folder_file_name;
    folder_file_name = file_system_helper::open_file();
    controller::create_file(model_ptr.get(), std::get<0>(folder_file_name), std::get<1>(folder_file_name));
}

void view::startGUI(std::unique_ptr<model> model_ptr){
    std::vector<std::string> recently_edited_files;
    std::vector<std::string> recently_edited_file_views_id;
    get_starter_interface(recently_edited_files, recently_edited_file_views_id);
    ///ну поскольку редактор у нас воображаемый то мы вместо реализации сделаем штуку типа вводим из консоли
    /// 0 - создаем новый
    /// 1 - значит последний редактированный файл
    //// 2 - предпоследний и т д (чтоб сильно не изгалялись оставим 4 последних)
    //// и вариант 5 типа идем выбирать файл на компе
    ///тут типа должны быть нормальные листенеры на кнопках/иконках но по скольку у меня комманды из коммандной строки то будет иф елсе
    int button_pushed;
    ///никаких проверок типа ж это не реальные действия
    /// ну только у нас будет квадратиков с возможностью жмякать в файл который мы редактируем сколько придет из базы (не больше 5ти)
    //и по идее все стринги нужно в отдельный неймспейс но это стринги-заглушки так что будут жить прям в коде
    std::cout << "for imaginary open recent files choose number grater than 0 and less then " << recently_edited_files.size() << std::endl;
    std::cin >> button_pushed;
    if (button_pushed == 0){
        controller::create_new_file(model_ptr.get());
    } else if (button_pushed == 5) {
        invoke_GUI_for_search_file_in_file_system(move(model_ptr));
    } else {
        ///помним поскольку это имитация тут только корректное число
        controller::open_recent_file(model_ptr.get(), recently_edited_files[button_pushed-1]);
    }
}

graphic_primitive* create_graphic_primitive(){
    graphic_primitive* pr_ptr = new graphic_primitive();
    return pr_ptr;
}

void delete_graphic_primitive(graphic_primitive* primitive_ptr){
    delete primitive_ptr;
}