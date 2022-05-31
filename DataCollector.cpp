#include "DataCollector.hpp"

DataCollector* DataCollector::instance = nullptr;

DataCollector::DataCollector(const filesystem::path &path, const filesystem::path &dataPath, const std::regex &regex) : File(path) {
    this->dataPath = dataPath;
    this->regex = regex;
}

DataCollector& DataCollector::getInstance(const filesystem::path &path, const filesystem::path &dataPath, const std::regex &regex) {
    if(instance == nullptr)
        instance = new DataCollector(path, dataPath, regex);
    return *instance;
}

void DataCollector::collectData(const File& file) const {
    if(match(file.path().filename().string())) {
        copyFile(file);
    }
}

bool DataCollector::match(const std::string &filename) const {
    return std::regex_match(filename, regex);
}

void DataCollector::copyFile(const File &from, filesystem::copy_options options) const {
    filesystem::path to = this->path();
    if(from.isDirectory())
        to = to.string() + filesystem::path::preferred_separator + from.path().filename().string();
    filesystem::copy(from.path(), to, options | filesystem::copy_options::update_existing | filesystem::copy_options::recursive);
}

filesystem::path DataCollector::getDataPath() const {
    return dataPath;
}

std::regex DataCollector::getRegex() const {
    return regex;
}

void DataCollector::createTarFile() {
    std::string filename = this->path().filename().string();
    std::string command = filename + ".tar " + filename;
    if(filesystem::exists(this->path().filename().string() + ".tar"))
        command = "tar -uf " + command;
    else
        command = "tar -cf" + command;
    system(command.c_str());
}

void DataCollector::createJSONFile() {
    std::string command = "tree -h -D -J -o " + this->path().string() + filesystem::path::preferred_separator + "DiskUsage.json " + this->path().string();
    system(command.c_str());
}