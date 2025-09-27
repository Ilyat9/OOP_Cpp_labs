#include <gtest/gtest.h>
#include "count_days.h"

TEST(Days_NormalCases, ExampleFromTask) {
    int days = days(100, 10, 910);
    EXPECT_EQ(days, 10);
}

TEST(CountDays_NormalCases, ReachesInOneDay) {
    EXPECT_EQ(days(10, 5, 7), 1);
    EXPECT_EQ(days(20, 0, 15), 1);
}

TEST(Days_NormalCases, SeveralDaysNeeded) {
    EXPECT_EQ(days(5, 2, 8), 2); 
    EXPECT_EQ(days(3, 1, 7), 3);  
}

TEST(Days_ErrorCases, NegativeHeight) {
    EXPECT_EQ(days(5, 2, 0), 0); 
    EXPECT_EQ(days(5, 2, -10), -1);
}

TEST(Days_ErrorCases, UpspeedLessOrEqualDownspeed) {
    EXPECT_EQ(days(5, 5, 20), -1);
    EXPECT_EQ(days(4, 6, 30), -1);
}

TEST(Days_ErrorCases, ZeroOrNegativeSpeeds) {
    EXPECT_EQ(days(0, 0, 10), -1);
    EXPECT_EQ(days(-3, 1, 10), -1);
    EXPECT_EQ(days(3, -1, 10), -1); 
}

TEST(Days_Boundary, ZeroHeight) {
    EXPECT_EQ(days(5, 2, 0), 0);
}

TEST(Days_Boundary, JustEnoughBeforeNight) {
    EXPECT_EQ(days(10, 9, 10), 1);
}

TEST(Days_Boundary, LargeHeight) {
    EXPECT_EQ(days(10, 1, 100), 11);
}
