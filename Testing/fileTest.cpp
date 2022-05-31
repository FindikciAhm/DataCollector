#include <gtest/gtest.h>

#include "../File.hpp"

std::unique_ptr<File> etc(new File("/etc"));
std::unique_ptr<File> passwd(new File("/etc/passwd"));

TEST(FileTest, IsDirectory) {
    EXPECT_TRUE(etc->isDirectory());
    EXPECT_FALSE(passwd->isDirectory());
}

TEST(FileTest, fileSize) {
    EXPECT_TRUE(passwd->getFileSize() > 0);
    EXPECT_TRUE(etc->getFileSize() == -1);
}