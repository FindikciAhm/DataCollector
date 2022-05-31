#ifndef DATACOLLECTOR_HPP
#define DATACOLLECTOR_HPP

#include <filesystem>
#include <regex>
#include <string>

#include "File.hpp"

namespace filesystem = std::filesystem;

/**
 * @brief Represents the data collector and its functionalities.
 * This class contains properties and methods used to collect and store the data.
 * This class implements the singleton pattern and therefore has no public constructor.
 * Next to the path where the collector will store the data.
 * This class contains properties about the file path, which is searched for data and a regular expression, which gives a pattern of which data should be collected.
 */
class DataCollector : public File {
    private:
        /**
         * @brief The file path where to look for data.
         * Represents the file path where the collector looks for data.
         */
        filesystem::path dataPath;
        /**
         * @brief The regular expression that provides a pattern of what data to collect.
         */
        std::regex regex;
        /**
         * @brief A static pointer to the single DataCollector instance
         */
        static DataCollector* instance;

        /**
         * @brief The private constructor for creating a DataCollector object.
         * In the constructor, the properties, such as the file paths, are set via the parameter list.
         * @param path The file path of the collectors where it stores the data.
         * @param dataPath The file path of the directory that the collector will search for data.
         * @param regex The regular expression for which the collector should search.
         */
        DataCollector(const filesystem::path &path, const filesystem::path &dataPath, const std::regex &regex);


    public:
        /**
         * @brief Static method used to instantiate the singleton or to return the instance.
         * @param path The file path of the collectors where it stores the data.
         * @param dataPath The file path of the directory that the collector will search for data.
         * @param regex The regular expression for which the collector should search.
         * @return DataCollector& The only instance of the data collector.
         */
        static DataCollector& getInstance(const filesystem::path &path, const filesystem::path &dataPath, const std::regex &regex);
        /**
         * @brief Method that collects the data from the specified file, should the filename match the regular expression.
         * @param file The file to collect data about.
         */
        void collectData(const File &file) const;
        /**
         * @brief Method that checks if the passed filename matches the regular expression.
         * @param filename The file name to be checked
         * @return true The file name corresponds to the regular expression.
         * @return false otherwise.
         */
        bool match(const std::string &filename) const;
        /**
         * @brief Method that allows copying files to the data collector directory.
         * @param from The file to be copied.
         * @param options Copy options to consider.
         */
        void copyFile(const File &from, filesystem::copy_options options = filesystem::copy_options::none) const;
        /**
         * @brief Getter method, which returns the file path where the collector is currently collecting data.
         * @return filesystem::path The filepath.
         */
        filesystem::path getDataPath() const;
        /**
         * @brief Getter method, which queries the regular expression,
         * @return std::regex The regular expression.
         */
        std::regex getRegex() const;
        /**
         * @brief Method that packs the directory in which the data collector has collected the data into a tar archive.
         * For this purpose, a tar archive with the file name of the collector is created or updated if it already exists.
         * An update occurs for newly collected files or files that have been revised since the last collection.
         */
        void createTarFile();
        /**
         * @brief Method that writes a structured representation of the collector's directory and all file sizes of all files to a JSON file.
         */
        void createJSONFile();
};

#endif