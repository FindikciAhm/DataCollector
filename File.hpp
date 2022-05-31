#ifndef FILE_HPP
#define FILE_HPP

#include <filesystem>

namespace filesystem = std::filesystem;

/**
 * @brief Represents a file in the file system.
 * This class contains properties and methods of the @code{directory_entry} class, which can be used to determine the file path, among other things.
 * In addition, this class contains properties about the file size and whether it is a directory.
 */

class File : public filesystem::directory_entry {

    private:
        /**
         * @brief The file size.
         * Represents the file size of the file. A directory has no direct file size and so is passed -1 by default.
         */
        uintmax_t fileSize = -1;
        /**
         * @brief The property of whether it is a directory.
         * Represents a flag that can be used to determine whether the given object represents a directory.
         */
        bool is_Directory;
    
    public:
        /**
         * @brief Construct a new File object
         * Creates an instance of a File object. A valid file path is passed as a parameter for this purpose.
         * At the same time, the file size and whether it is a directory is determined.
         * @param path The file path.
         */
        File(const filesystem::path &path);
        /**
         * @brief Get the File Size object
         * Getter method to get the file size.
         * @return uintmax_t The file size.
         */
        uintmax_t getFileSize() const; 
        /**
         * @brief Getter method to get the flag if it is a directory.
         * @return true It is a directory.
         * @return false otherwise.
         */
        bool isDirectory() const;
};

#endif