#include "CommandLineOption.hpp"

#include <memory>
#include <vector>

// CommandLineOption<T>
// Constructor
template <class T>
CommandLineOption<T>::CommandLineOption(const int argc, const char** argv) {
    this->argc = argc;
    this->argv = argv;
    this->options = nullptr;
}

// parse<int>
template <>
bool CommandLineOption<int>::parse() {
    if(argc <= 1) {
        return 0;
    }
    options.reset(new vector<int>(argc - 1));
    for(unsigned int i = 0; i < options->size(); i++){
        (*options)[i] = atoi(argv[i + 1]);
    }
    return 0;
}

// get
template <class T>
const T& CommandLineOption<T>::get(const unsigned int index) const {
    return options->at(index);
}

// operator[]
template <class T>
const T& CommandLineOption<T>::operator[](const unsigned int index) const {
    return this->get(index);
}