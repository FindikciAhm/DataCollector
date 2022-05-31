#ifndef UTIL_HPP
#define UTIL_HPP

#include <filesystem>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

namespace filesystem = std::filesystem;
using std::string; using std::vector; using std::cout; using std::regex;

class Util {
    public:
        /**
         * @brief Static method to implement string starts-with.
         * To do this, the passed string is searched for the prefix and whether the position found has the position 0.
         * @param str the string to search for.
         * @param prefix The prefix to find.
         * @return true The prefix was found and has position 0.
         * @return false otherwise.
         */
        static const bool str_starts_with(const string &str, const string &prefix);
        /**
         * @brief Static method to implement string ends-with.
         * To do this, the passed string is searched for the suffix and whether the position found has the last position - the length of the suffix.
         * @param str the string to search for.
         * @param suffix The suffix to find.
         * @return true The suffix was found and has the last position - the length of the suffix.
         * @return false otherwise.
         */
        static const bool str_ends_with(const string &str, const string &suffix);
        /**
         * @brief Static method to implement string split.
         * To do this, the passed string is truncated at positions that correspond to the regex and saved in a list.
         * Finally, the created list of substrings is returned.
         * @param str The string to split.
         * @param regex the pattern for to split.
         * @return const vector<string> The list of substrings.
         */
        static const vector<string> str_split(string str, const string &regex);
};

#endif