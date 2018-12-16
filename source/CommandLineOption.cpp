#include <memory>
#include <vector>

#include "CommandLineOption.hpp"

// parse<int>
template <>
bool CommandLineOption<unsigned int>::parse() {
    if(argc <= 1) {
        return 0;
    }
    options.reset(new std::vector<unsigned int>(argc - 1));
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

// move
template <class T>
std::unique_ptr<std::vector<T>>&& CommandLineOption<T>::move() {
    return std::move(options);
}