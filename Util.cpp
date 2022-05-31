#include "Util.hpp"

const bool Util::str_starts_with(const string &str, const string &prefix) {
    return str.find(prefix) == 0;
}

const bool Util::str_ends_with(const string &str, const string &suffix) {
    return str.find(suffix) == str.length() - suffix.length();
}

const vector<string> Util::str_split(string str, const string &regex) {
    vector<string> strings = {};
    auto pos = str.find_first_of(regex);
    while(pos != string::npos) {
        strings.push_back(str.substr(0, pos));
        str.erase(0, pos + regex.length());
        pos = str.find_first_of(regex);
    }
    strings.push_back(str);
    return strings;
}

