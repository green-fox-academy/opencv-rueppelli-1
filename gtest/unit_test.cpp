#include <gtest/gtest.h>
#include "initial.h"


TEST(test_check, test_cuccok){
    EXPECT_EQ(initialFunction(1, 1), 2);
}