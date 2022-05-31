#include <gtest/gtest.h>

#include "../DataCollector.hpp"

TEST(ComponentTest, TestDirectory) {
    EXPECT_TRUE(filesystem::exists("DataCollector"));
    EXPECT_TRUE(filesystem::exists("DataCollector/core.ahahahahah.57dd721409bc4ab4b38a3c33a36a608a.lz4"));
    EXPECT_TRUE(filesystem::exists("DataCollector/core.ahahahahah.57dd721409bc4ab4b38a3c33a36a608a.lz4/libversion"));
    EXPECT_TRUE(filesystem::exists("DataCollector/core.ahahahahah.57dd721409bc4ab4b38a3c33a36a608a.lz4/BUILD.txt"));
    EXPECT_TRUE(filesystem::exists("DataCollector/DiskUsage.json"));
    EXPECT_TRUE(filesystem::exists("DataCollector/core.ahmet.57dd721409bc4ab4b38a3c33a36a608a.lz4"));
    EXPECT_TRUE(filesystem::exists("DataCollector/core.hadhs.57dd721409bc4ab4b38a3c33a36a608a.lz4"));
    EXPECT_TRUE(filesystem::exists("DataCollector/core.testService.4849.lz4"));

    EXPECT_FALSE(filesystem::exists("DataCollector/REGEX"));
    EXPECT_FALSE(filesystem::exists("DataCollector/core.dhdhdh.lz4"));
    EXPECT_FALSE(filesystem::exists("DataCollector/test1.txt"));
}

TEST(ComponentTest, TestTar) {
    EXPECT_TRUE(filesystem::exists("DataCollector.tar"));
    system("mkdir unTar");
    EXPECT_TRUE(filesystem::exists("unTar"));
    system("tar -xf DataCollector.tar -C unTar");
    EXPECT_TRUE(filesystem::exists("unTar/DataCollector"));
    EXPECT_TRUE(filesystem::exists("unTar/DataCollector/core.ahahahahah.57dd721409bc4ab4b38a3c33a36a608a.lz4"));
    EXPECT_TRUE(filesystem::exists("unTar/DataCollector/core.ahahahahah.57dd721409bc4ab4b38a3c33a36a608a.lz4/libversion"));
    EXPECT_TRUE(filesystem::exists("unTar/DataCollector/core.ahahahahah.57dd721409bc4ab4b38a3c33a36a608a.lz4/BUILD.txt"));
    EXPECT_TRUE(filesystem::exists("unTar/DataCollector/DiskUsage.json"));
    EXPECT_TRUE(filesystem::exists("unTar/DataCollector/core.ahmet.57dd721409bc4ab4b38a3c33a36a608a.lz4"));
    EXPECT_TRUE(filesystem::exists("unTar/DataCollector/core.hadhs.57dd721409bc4ab4b38a3c33a36a608a.lz4"));
    EXPECT_TRUE(filesystem::exists("unTar/DataCollector/core.testService.4849.lz4"));

    EXPECT_FALSE(filesystem::exists("unTar/DataCollector/REGEX"));
    EXPECT_FALSE(filesystem::exists("unTar/DataCollector/core.dhdhdh.lz4"));
    EXPECT_FALSE(filesystem::exists("unTar/DataCollector/test1.txt"));
}