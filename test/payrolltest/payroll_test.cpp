
#include "gtest/gtest.h"
#include "Payroll.h"
TEST(payroll_test, ovettime_test){
    EXPECT_EQ(8, ot(48));
}
TEST(payroll_test, grosspay_test){
    EXPECT_EQ(2000, grosspay(52000));
}
