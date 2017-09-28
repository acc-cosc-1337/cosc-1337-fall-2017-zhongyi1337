
#include "gtest/gtest.h"
#include "Payroll.h"
TEST(payroll_test, ovettime_test){
    EXPECT_EQ(8, ot(48));
}
TEST(payroll_test, grosspay_test){
    EXPECT_EQ(2000, grosspay(52000));
}

TEST (payroll_test, getFICASSN_TEST1){
    EXPECT_EQ(124, getFICASSN(2000));
}

TEST(payroll_test, getFICASSN_test2){
    EXPECT_EQ(62, getFICASSN(1000));
}

TEST (payroll_test, grosspay_test1){
    EXPECT_EQ (410, grosspay(400,10));
}

TEST (payroll_test, grosspay_test2){
    EXPECT_EQ(860, grosspay(800, 60));
}


TEST (payroll_test, otpay_test1){
    EXPECT_EQ(60, otpay(20, 2));
}


TEST (payroll_test, otpay_test2){
    EXPECT_EQ(45, OTPAY(10, 3));
}

