#include <gtest/gtest.h>
#include <regex>
#include <string>

#include "../Util.hpp"


TEST(RegexTest, Starts_With) {
    std::string cmp = "core";
    EXPECT_TRUE(Util::str_starts_with("core.43432.lz4", cmp));
    EXPECT_FALSE(Util::str_starts_with("lz4.2e34.core", cmp));
    cmp = "/etc";
    EXPECT_TRUE(Util::str_starts_with("/etc/passwd", cmp));
    EXPECT_FALSE(Util::str_starts_with("/usr/bin", cmp));
}

TEST(RegexTest, Ends_With) {
    std::string cmp = "lz4";
    EXPECT_TRUE(Util::str_ends_with("core.43432.lz4", cmp));
    EXPECT_FALSE(Util::str_ends_with("lz4.2e34.core", cmp));
    cmp = "passwd";
    EXPECT_TRUE(Util::str_ends_with("/etc/passwd", cmp));
    EXPECT_FALSE(Util::str_ends_with("/usr/bin", cmp));
}

TEST(RegexTest, Split) {
   auto strings = Util::str_split("core.43432.lz4", ".");
   EXPECT_STREQ(strings[0].c_str(), "core");
   EXPECT_STREQ(strings[1].c_str(), "43432");
   EXPECT_STREQ(strings[2].c_str(), "lz4");

   strings = Util::str_split("core.43432.lz4", "/");
   EXPECT_STREQ(strings[0].c_str(), "core.43432.lz4");

   strings = Util::str_split("blabla56haha", "56");
   EXPECT_STREQ(strings[0].c_str(), "blabla");
   EXPECT_STREQ(strings[1].c_str(), "haha");
}

TEST(RegexTest, Match) {
    std::string str = "core.43432.lz4";
    std::regex regex("(core.)[0-9]+.(lz4)");
    EXPECT_TRUE(std::regex_match(str, regex));
    EXPECT_FALSE(std::regex_match(str + "4", regex));

    regex = std::regex("(core.)([a-zA-Z_0-9])+.([0-9a-fA-F]+.)+(lz4)");
    str = "core.ServiceName.3057.57dd721409bc4ab4b38a3c33a36a608a.3717.1647975805000000.lz4";
    EXPECT_TRUE(std::regex_match(str, regex));
    str = "core.ServiceName.3057.57Dd721409bC4ab4B38A3c33B36a608F.3717.1647975805000000.lz4";
    EXPECT_TRUE(std::regex_match(str, regex));

    str = "ServiceName.3057.57dd72140bc4ab4L38a3c33a36a608a.3717.164797580500000.lz4";
    EXPECT_FALSE(std::regex_match(str, regex));
}