#include "CommandLineOption.hpp"

#include <memory>
#include <vector>

// CommandLineOption<T>
// Constructor
template <class T>
CommandLineOption<T>::CommandLineOption(const int argc, const char** argv) {
    this->argc = argc;
    this->argv = argv;
    this->options = new unique_ptr<vector<T>>();
}

// parse<int>
template <>
bool CommandLineOption<int>::parse() const {
    if(argc <= 1) {
        return 0;
    }
    options->resize(argc - 1);
    for(unsigned int i = 0; i < options->size(); i++){
        (*options)[i] = atoi(argv[i + 1]);
    }
    return 0;
}