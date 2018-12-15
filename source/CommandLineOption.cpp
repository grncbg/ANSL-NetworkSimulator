#include "CommandLineOption.hpp"

#include <vector>
#include <memory>

template <class T>
CommandLineOption<T>::CommandLineOption(const int argc, const char** argv) {
    this->argc = argc;
    this->argv = argv;
    this->options = new unique_ptr<vector<T>>();
}
