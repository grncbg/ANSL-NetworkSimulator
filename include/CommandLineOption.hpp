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
    template <class Type>
    using vector = std::vector<Type, std::allocator<Type>>;
    template <class Type>
    using unique_ptr = std::unique_ptr<Type, std::default_delete<Type>>;

    const int argc;
    char** argv;
    unique_ptr<vector<T>> options;

public:
    explicit CommandLineOption(int argc, char** argv) : argc(argc), argv(argv), options(nullptr) {}
    virtual CommandLineOption<T>& parse();
    virtual const T& get(unsigned int index) const;
    virtual const T& operator[](unsigned int index) const;
    virtual unique_ptr<vector<T>>&& move();

};

template class CommandLineOption<unsigned int>;

#endif