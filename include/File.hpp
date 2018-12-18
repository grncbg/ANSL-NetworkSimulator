#ifndef INCLUDED_FILE_HPP
#define INCLUDED_FILE_HPP

class ReadFile {
private:
    std::ofstream ofs;
    const std::filesystem::path path;
public:
    ReadFile(std::filesystem::path path): path(path) {}
    ~ReadFile() = default;
};

#endif