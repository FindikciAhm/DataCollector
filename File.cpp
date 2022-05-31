#include "File.hpp"

File::File(const filesystem::path &path) : directory_entry(path) {
    is_Directory = filesystem::is_directory(path);
    if(!is_Directory)
        fileSize = filesystem::file_size(path);
}

uintmax_t File::getFileSize() const {
    return fileSize;
}

bool File::isDirectory() const {
    return is_Directory;
}