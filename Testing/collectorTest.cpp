#include <gtest/gtest.h>

#include "../DataCollector.hpp"

//std::unique_ptr<DataCollector> collector = std::make_unique<DataCollector>(DataCollector::getInstance("DataCollector", "test", std::regex("(core.)[a-zA-Z_0-9]+.([0-9a-fA-F]+.)+(lz4)")));;

TEST(CollectorTest, getPath) {
    EXPECT_TRUE(filesystem::exists("DataCollector"));
    EXPECT_TRUE(filesystem::exists("test"));
    /*EXPECT_STREQ(collector->getDataPath().c_str(), "test");
    EXPECT_STREQ(collector->path().c_str(), "DataCollector");
    EXPECT_STRNE(collector->path().c_str(), collector->getDataPath().c_str());*/
}

/*TEST(CollectorTest, )

TEST(CollectorTest, )

TEST(CollectorTest, )

TEST(CollectorTest, )*/