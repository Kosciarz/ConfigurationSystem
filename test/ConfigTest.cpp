#include <gtest/gtest.h>

#include "Config.hpp"

#include <map>
#include <string>

TEST(ConfigTest, InitializesMapWithZero)
{
    Config cfg{};
    EXPECT_EQ(cfg.Data().size(), 0);
}

TEST(ConfigTest, InitliazesMapWithValue)
{
    std::map<std::string, std::string> config = {
        {"foo", "42"},
        {"bar", "3.14"},
        {"bazz", "string"}
    };

    Config cfg{config};
    EXPECT_EQ(cfg.Data().size(), 3);
}