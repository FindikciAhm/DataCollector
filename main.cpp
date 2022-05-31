#include <chrono>
#include <getopt.h>
#include <iostream>
#include <string>
#include <thread>

#include "DataCollector.hpp"
#include "File.hpp"

using std::cout;

std::string directoryPath = "./DataCollector";
std::regex regex("(core.)[a-zA-Z_0-9]+.([0-9a-fA-F]+.)+(lz4)");
uint sleepTime = 20;
std::error_code err;

/**
 * @brief Method that implements an argument list for the command line program.
 * @return uint The number of argument-list options passed.
 */
uint parsingArguments(int, char *[]);

int main(int argc, char *argv[]) {
    if(1 == argc || argc <= parsingArguments(argc, argv)) {
        cout << "The path of the directory in which to search for data is missing.\n";
        return 1;
    }
    if(!filesystem::exists(directoryPath))
        if(!filesystem::create_directories(directoryPath, err)) {
            cout << "Could not create the directories: " << directoryPath << " Error: " << err.message() << "\n";
            return 1;
        }
    DataCollector dir = DataCollector::getInstance(directoryPath, argv[optind++], regex);
    if(!filesystem::exists(dir.getDataPath())) {
        cout << "The path of the directory in which to search for data is not valid\n";
        return 1;
    }
    while(true) {
        for(const auto &file : filesystem::recursive_directory_iterator(dir.getDataPath())) {
            std::unique_ptr<File> f(new File(file));
            dir.collectData(*f);
        }
        dir.createJSONFile();
        dir.createTarFile();
        std::this_thread::sleep_for(std::chrono::seconds(sleepTime));
    }
    return 0;
}

uint parsingArguments(int argc, char *argv[]) {
    uint optionc;
    int option;
    for(optionc = 0; (option = getopt(argc, argv, "t:d:r:h")) != -1; optionc++) {
        switch(option)  {
            case 'd':
                directoryPath = optarg;
                break;
            case 'r':
                regex = std::regex(optarg);
                break;
            case 't':
                sleepTime = atoi(optarg);
                break;
            default:
                cout << "main [options] data directory\n"
                << "example:\n"
                << "main -r \"(File)(*)\" -t 60 ./Testing/test/\n"
                << "possible options:\n"
                << "\t-r \t\tCustomize the regular expression on which data is searched. (default: (core.)[a-zA-Z_0-9]+.([0-9a-fA-F]+.)+(lz4) )\n"
                << "\t-d \t\tCustomize the data collector's directory where it stores the data. (default: ./DataCollector)\n"
                << "\t-t \t\tAdjust the Data Collector sleep time in seconds. (default: 20 seconds)\n"
                << "\t-h \t\tShow the help.\n";
                exit(1);
        }
    }
    return 2*optionc+1;
}
