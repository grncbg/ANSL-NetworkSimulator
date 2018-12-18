#ifndef INCLUDED_FILE_HPP
#define INCLUDED_FILE_HPP

namespace std {
    template< class CharT, class Traits = std::char_traits<CharT>>
    class basic_ofstream;
    typedef basic_ofstream<char> ofstream;
    namespace filesystem {
        class path;
    }
}

class ReadFile {
private:
    std::ofstream ofs;
    const std::filesystem::path path;
public:
    ReadFile(std::filesystem::path path): path(path) {}
    ~ReadFile() = default;
};

#endif