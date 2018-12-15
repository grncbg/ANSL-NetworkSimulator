#ifndef INCLUDED_COMMAND_LINE_OPTION_HPP
#define INCLUDED_COMMAND_LINE_OPTION_HPP

// Forward declaration
namespace std{
    // For std::vector
    // allocator
    template <class T>
    class allocator;
    // vector
    template <class T, class Allocator>
    class vector;

    // For std::unique_ptr
    // default_delete
    template <class T>
    struct default_delete;
    // unique_ptr
    template <class T, class D>
    class unique_ptr;
}

template <class T>
class CommandLineOption {

private:
    const int argc;
    const char** argv;
    std::unique_ptr<std::vector<T, std::allocator<T>>, std::default_delete<std::vector<T, std::allocator<T>>>> options;

public:
    explicit CommandLineOption(const int argc, const char** argv);

};

#endif