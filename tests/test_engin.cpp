#include <gtest/gtest.h>
#include "engine.hpp"

TEST(EngineTest, StartsWithZeroRPM) {
    Engine engine;
    engine.start();
    EXPECT_EQ(engine.getRpm(), 1000);
}
