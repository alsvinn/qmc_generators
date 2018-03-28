#pragma once
#include <boost/dll.hpp>

std::string get_generator_libfile(const std::string& generator_name) {
    return generator_name + "/lib" + generator_name + ".so";
}

std::string get_generator_create(const std::string& generator_name) {
    return generator_name + "_create";
}

std::string get_generator_delete(const std::string& generator_name) {
    return generator_name + "_delete";
}

std::string get_generator_generate(const std::string& generator_name) {
    return generator_name + "_generate";
}

std::string get_generator_make_parameters(const std::string& generator_name) {
    return generator_name + "_make_parameters";
}

std::string get_generator_set_parameter(const std::string& generator_name) {
    return generator_name + "_set_parameter";
}

std::string get_generator_delete_parameters(const std::string& generator_name) {
    return generator_name + "_delete_parameters";
}


class Generator {
public:
    using create_t = void*(int, int, void*);
    using delete_t = void(void*);
    using make_parameters_t = void*();
    using delete_parameters_t = void(void*);
    using set_parameter_t = void(void*, const char*, const char*);
    using generate_t = double(void*, int, int, int, int, void*);

    Generator(const std::string& generator) {
        const auto filename = get_generator_libfile(generator);
        create_function = boost::dll::import<create_t>(filename,
                                                       get_generator_create(generator));

        delete_function = boost::dll::import<delete_t>(filename,
                                                       get_generator_delete(generator));

        make_parameters_function = boost::dll::import<make_parameters_t>(filename,
                                                       get_generator_make_parameters(generator));

        delete_parameters_function = boost::dll::import<delete_parameters_t>(filename,
                                                       get_generator_delete_parameters(generator));

        set_parameter_function = boost::dll::import<set_parameter_t>(filename,
                                                       get_generator_set_parameter(generator));

        generate_function = boost::dll::import<generate_t>(filename,
                                                       get_generator_generate(generator));
    }

    std::function<create_t> create_function;
    std::function<delete_t> delete_function;
    std::function<make_parameters_t> make_parameters_function;
    std::function<delete_parameters_t> delete_parameters_function;
    std::function<set_parameter_t> set_parameter_function;
    std::function<generate_t> generate_function;

};
