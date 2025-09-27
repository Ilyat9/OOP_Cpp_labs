#include <gtest/gtest.h>
#include "count_days.h"

TEST(CountDays_NormalCases, ExampleFromTask) {
    int days = count_days(100, 10, 910);
    EXPECT_EQ(days, 10);
}

TEST(CountDays_NormalCases, ReachesInOneDay) {
    EXPECT_EQ(count_days(10, 5, 7), 1);
    EXPECT_EQ(count_days(20, 0, 15), 1);
}

TEST(CountDays_NormalCases, SeveralDaysNeeded) {
    EXPECT_EQ(count_days(5, 2, 8), 2); 
    EXPECT_EQ(count_days(3, 1, 7), 3);  
}

TEST(CountDays_ErrorCases, NegativeHeight) {
    EXPECT_EQ(count_days(5, 2, 0), 0); 
    EXPECT_EQ(count_days(5, 2, -10), -1);
}

TEST(CountDays_ErrorCases, UpspeedLessOrEqualDownspeed) {
    EXPECT_EQ(count_days(5, 5, 20), -1);
    EXPECT_EQ(count_days(4, 6, 30), -1);
}

TEST(CountDays_ErrorCases, ZeroOrNegativeSpeeds) {
    EXPECT_EQ(count_days(0, 0, 10), -1);
    EXPECT_EQ(count_days(-3, 1, 10), -1);
    EXPECT_EQ(count_days(3, -1, 10), -1); 
}

TEST(CountDays_Boundary, ZeroHeight) {
    EXPECT_EQ(count_days(5, 2, 0), 0);
}

TEST(CountDays_Boundary, JustEnoughBeforeNight) {
    EXPECT_EQ(count_days(10, 9, 10), 1);
}

TEST(CountDays_Boundary, LargeHeight) {
    EXPECT_EQ(count_days(10, 1, 100), 11);
}
