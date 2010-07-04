// --------------------------
// projects/date/TestDate.c++
// Copyright (C) 2010
// Glenn P. Downing
// --------------------------

/*
To test the program:
    % g++ -ansi -pedantic -lcppunit -ldl -Wall TestDate.c++ -o TestDate.app
    % valgrind TestDate.app >& TestDate.out
*/

// --------
// includes
// --------

#include <cstring>   // strcmp
#include <sstream>   // ostringstream
#include <stdexcept> // invalid_argument
#include <string>    // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TestSuite.h"               // TestSuite
#include "cppunit/TextTestRunner.h"          // TestRunner

#include "Date.h"

// --------
// TestDate
// --------

struct TestDate : CppUnit::TestFixture {
    // ----------------
    // test_constructor
    // ----------------

    void test_constructor_1 () {
        try {
            const Date<int> x(0, 1, 1600);
            CPPUNIT_ASSERT(false);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(std::strcmp(e.what(), "Date::Date()") == 0);}}

    void test_constructor_2 () {
        try {
            const Date<int> x(1, 0, 1600);
            CPPUNIT_ASSERT(false);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(std::strcmp(e.what(), "Date::Date()") == 0);}}

    void test_constructor_3 () {
        try {
            const Date<int> x(1, 1, 1599);
            CPPUNIT_ASSERT(false);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(std::strcmp(e.what(), "Date::Date()") == 0);}}

    void test_constructor_4 () {
        try {
            const Date<int> x(29, 2, 2001);
            CPPUNIT_ASSERT(false);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(std::strcmp(e.what(), "Date::Date()") == 0);}}

    void test_constructor_5 () {
        try {
            const Date<int> x(32, 1, 1600);
            CPPUNIT_ASSERT(false);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(std::strcmp(e.what(), "Date::Date()") == 0);}}

    void test_constructor_6 () {
        try {
            const Date<int> x(1, 13, 1600);
            CPPUNIT_ASSERT(false);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(std::strcmp(e.what(), "Date::Date()") == 0);}}

    void test_constructor_7 () {
        try {
            const Date<int> x(1, 1, 1600);
            CPPUNIT_ASSERT(true);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_constructor_8 () {
        try {
            const Date<long> x(1, 1, 1600);
            CPPUNIT_ASSERT(true);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_constructor_9 () {
        try {
            const Date<double> x(1, 1, 1600);
            CPPUNIT_ASSERT(true);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_constructor_10 () {
        try {
            const Date<float> x(1, 1, 1600);
            CPPUNIT_ASSERT(true);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // -------------
    // test_equal_to
    // -------------

    void test_equal_to_1 () {
        try {
            const Date<int> x(28, 2, 2000);
            const Date<int> y(28, 2, 2000);
            CPPUNIT_ASSERT(x == y);
            CPPUNIT_ASSERT(!(x != y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_equal_to_2 () {
        try {
            const Date<int> x(28, 3, 2000);
            const Date<int> y(28, 2, 2000);
            CPPUNIT_ASSERT(x != y);
            CPPUNIT_ASSERT(!(x == y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_equal_to_3 () {
        try {
            const Date<int> x(29, 2, 2000);
            const Date<int> y(29, 2, 2000);
            CPPUNIT_ASSERT(x == y);
            CPPUNIT_ASSERT(!(x != y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_equal_to_4 () {
        try {
            const Date<int> x(14, 9, 1986);
            const Date<int> y(4, 9, 1986);
            CPPUNIT_ASSERT(x != y);
            CPPUNIT_ASSERT(!(x == y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_equal_to_5 () {
        try {
            const Date<int> x(1, 1, 2193);
            const Date<int> y(1, 1, 2000);
            CPPUNIT_ASSERT(x != y);
            CPPUNIT_ASSERT(!(x == y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // ---------
    // test_less
    // ---------

    void test_less_1 () {
        try {
            const Date<int> x(27, 2, 2000);
            const Date<int> y(28, 2, 2000);
            CPPUNIT_ASSERT(x <  y);
            CPPUNIT_ASSERT(x <= y);
            CPPUNIT_ASSERT(!(x >  y));
            CPPUNIT_ASSERT(!(x >= y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_less_2 () {
        try {
            const Date<int> x(27, 2, 2000);
            const Date<int> y(28, 2, 2000);
            CPPUNIT_ASSERT(!(y <  x));
            CPPUNIT_ASSERT(!(y <= x));
            CPPUNIT_ASSERT(y >  x);
            CPPUNIT_ASSERT(y >= x);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_less_3 () {
        try {
            const Date<int> x(28, 2, 2000);
            const Date<int> y(28, 2, 2000);
            CPPUNIT_ASSERT(!(x <  y));
            CPPUNIT_ASSERT(x <= y);
            CPPUNIT_ASSERT(!(x >  y));
            CPPUNIT_ASSERT(x >= y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_less_4 () {
        try {
            const Date<int> x(28, 2, 2000);
            const Date<int> y(28, 3, 2000);
            CPPUNIT_ASSERT(x <  y);
            CPPUNIT_ASSERT(x <= y);
            CPPUNIT_ASSERT(!(x >  y));
            CPPUNIT_ASSERT(!(x >= y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_less_5 () {
        try {
            const Date<int> x(28, 3, 2000);
            const Date<int> y(28, 2, 2000);
            CPPUNIT_ASSERT(!(x <  y));
            CPPUNIT_ASSERT(!(x <= y));
            CPPUNIT_ASSERT(x >  y);
            CPPUNIT_ASSERT(x >= y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_less_6 () {
        try {
            const Date<int> x(28, 2, 1999);
            const Date<int> y(28, 2, 2000);
            CPPUNIT_ASSERT(x <  y);
            CPPUNIT_ASSERT(x <= y);
            CPPUNIT_ASSERT(!(x >  y));
            CPPUNIT_ASSERT(!(x >= y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_less_7 () {
        try {
            const Date<int> x(28, 2, 2001);
            const Date<int> y(28, 2, 2000);
            CPPUNIT_ASSERT(!(x <  y));
            CPPUNIT_ASSERT(!(x <= y));
            CPPUNIT_ASSERT(x >  y);
            CPPUNIT_ASSERT(x >= y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // ---------
    // test_plus
    // ---------

    void test_plus_1 () {
        try {
            const Date<int> x(1, 1, 2000);
            const Date<int> y(1, 1, 2001);
            CPPUNIT_ASSERT(x + 366 == y);
	}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_plus_2 () {
        try {
            const Date<int> x(1, 1, 2000);
            const Date<int> y(31, 1, 2000);
            CPPUNIT_ASSERT(x + 30 == y);
	}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_plus_3 () {
        try {
            const Date<int> x(1, 1, 2000);
            const Date<int> y(1, 2, 2000);
            CPPUNIT_ASSERT(x + 31 == y);
	}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_plus_4 () {
        try {
            const Date<int> x(1, 1, 2001);
            const Date<int> y(1, 1, 2002);
            CPPUNIT_ASSERT(x + 365 == y);
	}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_plus_5 () {
        try {
            const Date<int> x(1, 2, 2000);
            const Date<int> y(1, 3, 2000);
            CPPUNIT_ASSERT(x + 29 == y);
	}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_plus_6 () {
        try {
            const Date<int> x(1, 2, 2001);
            const Date<int> y(1, 3, 2001);
            CPPUNIT_ASSERT(x + 28 == y);
	}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_plus_7 () {
        try {
            const Date<int> x(1, 1, 1600);
            const Date<int> y = x + -1;
            CPPUNIT_ASSERT(false);
	}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(std::strcmp(e.what(), "Date::Date()") == 0);}}

    void test_plus_8 () {
        try {
            const Date<int> x(1, 2, 2001);
            const Date<int> y(31, 1, 2001);
            CPPUNIT_ASSERT(x + -1 == y);
	}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_plus_9 () {
        try {
            const Date<int> x(1, 3, 2000);
            const Date<int> y(29, 2, 2000);
            const Date<int> z(1, 3, 2000);
            CPPUNIT_ASSERT(x + -1 == y);
            CPPUNIT_ASSERT(x == z);
	}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_plus_10 () {
        try {
            const Date<int> x(1, 3, 2001);
            const Date<int> y(28, 2, 2001);
            const Date<int> z(1, 3, 2001);
            CPPUNIT_ASSERT(x + -1 == y);
            CPPUNIT_ASSERT(x == z);
	}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // ---------------
    // test_plus_equal
    // ---------------

    void test_plus_equal_1 () {
        try {
            Date<int> x(1, 1, 1600);
            const Date<int> y = (x += -1);
            CPPUNIT_ASSERT(false);
	}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(std::strcmp(e.what(), "Date::Date()") == 0);}}

    void test_plus_equal_2 () {
        try {
            Date<int> x(1, 2, 2001);
            const Date<int> y(31, 1, 2001);
            CPPUNIT_ASSERT((x += -1) == y);
            CPPUNIT_ASSERT(x == y);
	}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_plus_equal_3 () {
        try {
            Date<int> x(1, 3, 2000);
            const Date<int> y(29, 2, 2000);
            CPPUNIT_ASSERT((x += -1) == y);
            CPPUNIT_ASSERT(x == y);
	}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_plus_equal_4 () {
        try {
            Date<int> x(1, 3, 2001);
            const Date<int> y(28, 2, 2001);
            CPPUNIT_ASSERT((x += -1) == y);
            CPPUNIT_ASSERT(x == y);
	}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_plus_equal_5 () {
        try {
            Date<int> x(1, 1, 2000);
            const Date<int> y(1, 1, 2001);
            CPPUNIT_ASSERT((x += 366) == y);
            CPPUNIT_ASSERT(x == y);
	}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_plus_equal_6 () {
        try {
            Date<int> x(1, 1, 2000);
            const Date<int> y(31, 1, 2000);
            CPPUNIT_ASSERT((x += 30) == y);
            CPPUNIT_ASSERT(x == y);
	}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_plus_equal_7 () {
        try {
            Date<int> x(1, 1, 2000);
            const Date<int> y(1, 2, 2000);
            CPPUNIT_ASSERT((x += 31) == y);
            CPPUNIT_ASSERT(x == y);
	}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}



    // ----------
    // test_minus
    // ----------

    void test_minus_1 () {
        try {
            const Date<int> x(1, 1, 2000);
            const Date<int> y(1, 1, 2001);
            CPPUNIT_ASSERT(y - 366 == x);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_minus_2 () {
        try {
            const Date<int> x(12, 1, 2000);
            const Date<int> y(1, 1, 2000);
            CPPUNIT_ASSERT(x - 11 == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}


    void test_minus_3 () {
        try {
            const Date<int> x(1, 3, 2000);
            const Date<int> y(1, 1, 2000);
            CPPUNIT_ASSERT(x - 60  == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}


    void test_minus_4 () {
        try {
            const Date<int> x(1, 3, 2000);
            const Date<int> y(1, 2, 2000);
            CPPUNIT_ASSERT(x - 29 == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}


    void test_minus_5 () {
        try {
            const Date<int> x(1, 3, 2001);
            const Date<int> y(1, 2, 2001);
            CPPUNIT_ASSERT(x - 28 == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_minus_6 () {
        try {
            const Date<int> x(1, 3, 2000);
            const Date<int> y(1, 2, 2000);
            CPPUNIT_ASSERT(x - y == 29);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_minus_7 () {
        try {
            const Date<int> x(1, 3, 2001);
            const Date<int> y(1, 2, 2001);
            CPPUNIT_ASSERT(x - y == 28);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_minus_8 () {
        try {
            const Date<int> x(1, 3, 2000);
            const Date<int> y(1, 2, 2000);
            CPPUNIT_ASSERT(y - x == -29);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_minus_9 () {
        try {
            const Date<int> x(1, 3, 2001);
            const Date<int> y(1, 2, 2001);
            CPPUNIT_ASSERT(y - x == -28);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_minus_10 () {
        try {
            const Date<int> x(1, 1, 1600);
            const Date<int> y = x - 1;
            CPPUNIT_ASSERT(false);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(std::strcmp(e.what(), "Date::Date()") == 0);}}

    // ----------------
    // test_minus_equal
    // ----------------

    void test_minus_equal_1 () {
        try {
            const Date<int> x(1, 1, 2000);
            Date<int> y(1, 1, 2001);
            y -= 366;
            CPPUNIT_ASSERT(y == x);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_minus_equal_2 () {
        try {
            Date<int> x(12, 1, 2000);
            const Date<int> y(1, 1, 2000);
            x -= 11;
            CPPUNIT_ASSERT(x == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}


    void test_minus_equal_3 () {
        try {
            Date<int> x(1, 3, 2000);
            const Date<int> y(1, 1, 2000);
            x -= 60;
            CPPUNIT_ASSERT(x == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}


    void test_minus_equal_4 () {
        try {
            Date<int> x(1, 3, 2000);
            const Date<int> y(1, 2, 2000);
            x -= 29;
            CPPUNIT_ASSERT(x == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}


    void test_minus_equal_5 () {
        try {
            Date<int> x(1, 3, 2001);
            const Date<int> y(1, 2, 2001);
            x -= 28;
            CPPUNIT_ASSERT(x == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_minus_equal_6 () {
        try {
            Date<int> x(1, 1, 1600);
            x -= 1;
            CPPUNIT_ASSERT(false);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(std::strcmp(e.what(), "Date::Date()") == 0);}}

    // -----------
    // test_output
    // -----------

    void test_output_1 () {
        try {
            const Date<int> x(16, 1, 2008);
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "16 Jan 2008");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_output_2 () {
        try {
            const Date<int> x(4, 2, 1986);
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "4 Feb 1986");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_output_3 () {
        try {
            const Date<int> x(16, 3, 2008);
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "16 Mar 2008");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_output_4 () {
        try {
            const Date<int> x(16, 4, 2008);
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "16 Apr 2008");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_output_5 () {
        try {
            const Date<int> x(16, 5, 2008);
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "16 May 2008");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_output_6 () {
        try {
            const Date<int> x(16, 6, 2008);
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "16 Jun 2008");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_output_7 () {
        try {
            const Date<int> x(4, 7, 1986);
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "4 Jul 1986");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_output_8 () {
        try {
            const Date<int> x(16, 8, 2008);
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "16 Aug 2008");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_output_9 () {
        try {
            const Date<int> x(16, 9, 2008);
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "16 Sep 2008");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_output_10 () {
        try {
            const Date<int> x(16, 10, 2008);
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "16 Oct 2008");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_output_11 () {
        try {
            const Date<int> x(16, 11, 2008);
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "16 Nov 2008");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_output_12 () {
        try {
            const Date<int> x(16, 12, 2008);
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "16 Dec 2008");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // --------------
    // test_leap_year
    // --------------

    void test_leap_year_1 () {
        try {
            CPPUNIT_ASSERT(Date<int>(1, 1, 2000).leap_year());}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_leap_year_2 () {
        try {
            CPPUNIT_ASSERT(!(Date<int>(1, 1, 2001).leap_year()));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_leap_year_3 () {
        try {
            CPPUNIT_ASSERT(!(Date<int>(4, 9, 1986).leap_year()));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_leap_year_4 () {
        try {
            CPPUNIT_ASSERT(Date<long>(1, 1, 2000).leap_year());}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_leap_year_5 () {
        try {
            CPPUNIT_ASSERT(!(Date<long>(1, 1, 2001).leap_year()));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_leap_year_6 () {
        try {
            CPPUNIT_ASSERT(Date<double>(1, 1, 2000).leap_year());}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_leap_year_7 () {
        try {
            CPPUNIT_ASSERT(!(Date<double>(1, 1, 2001).leap_year()));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_leap_year_8 () {
        try {
            CPPUNIT_ASSERT(Date<float>(1, 1, 2000).leap_year());}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_leap_year_9 () {
        try {
            CPPUNIT_ASSERT(!(Date<float>(1, 1, 2001).leap_year()));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDate);
    CPPUNIT_TEST(test_constructor_1);
    CPPUNIT_TEST(test_constructor_2);
    CPPUNIT_TEST(test_constructor_3);
    CPPUNIT_TEST(test_constructor_4);
    CPPUNIT_TEST(test_constructor_5);
    CPPUNIT_TEST(test_constructor_6);
    CPPUNIT_TEST(test_constructor_7);
    CPPUNIT_TEST(test_constructor_8);
    CPPUNIT_TEST(test_constructor_9);
    CPPUNIT_TEST(test_constructor_10);
    CPPUNIT_TEST(test_equal_to_1);
    CPPUNIT_TEST(test_equal_to_2);
    CPPUNIT_TEST(test_equal_to_3);
    CPPUNIT_TEST(test_equal_to_4);
    CPPUNIT_TEST(test_equal_to_5);
    CPPUNIT_TEST(test_less_1);
    CPPUNIT_TEST(test_less_2);
    CPPUNIT_TEST(test_less_3);
    CPPUNIT_TEST(test_less_4);
    CPPUNIT_TEST(test_less_5);
    CPPUNIT_TEST(test_less_6);
    CPPUNIT_TEST(test_less_7);
    CPPUNIT_TEST(test_plus_1);
    CPPUNIT_TEST(test_plus_2);
    CPPUNIT_TEST(test_plus_3);
    CPPUNIT_TEST(test_plus_4);
    CPPUNIT_TEST(test_plus_5);
    CPPUNIT_TEST(test_plus_6);
    CPPUNIT_TEST(test_plus_7);
    CPPUNIT_TEST(test_plus_8);
    CPPUNIT_TEST(test_plus_9);
    CPPUNIT_TEST(test_plus_10);
    CPPUNIT_TEST(test_plus_equal_1);
    CPPUNIT_TEST(test_plus_equal_2);
    CPPUNIT_TEST(test_plus_equal_3);
    CPPUNIT_TEST(test_plus_equal_4);
    CPPUNIT_TEST(test_plus_equal_5);
    CPPUNIT_TEST(test_plus_equal_6);
    CPPUNIT_TEST(test_plus_equal_7);
    CPPUNIT_TEST(test_minus_1);
    CPPUNIT_TEST(test_minus_2);
    CPPUNIT_TEST(test_minus_3);
    CPPUNIT_TEST(test_minus_4);
    CPPUNIT_TEST(test_minus_5);
    CPPUNIT_TEST(test_minus_6);
    CPPUNIT_TEST(test_minus_7);
    CPPUNIT_TEST(test_minus_8);
    CPPUNIT_TEST(test_minus_9);
    CPPUNIT_TEST(test_minus_10);
    CPPUNIT_TEST(test_minus_equal_1);
    CPPUNIT_TEST(test_minus_equal_2);
    CPPUNIT_TEST(test_minus_equal_3);
    CPPUNIT_TEST(test_minus_equal_4);
    CPPUNIT_TEST(test_minus_equal_5);
    CPPUNIT_TEST(test_minus_equal_6);
    CPPUNIT_TEST(test_output_1);
    CPPUNIT_TEST(test_output_2);
    CPPUNIT_TEST(test_output_3);
    CPPUNIT_TEST(test_output_4);
    CPPUNIT_TEST(test_output_5);
    CPPUNIT_TEST(test_output_6);
    CPPUNIT_TEST(test_output_7);
    CPPUNIT_TEST(test_output_8);
    CPPUNIT_TEST(test_output_9);
    CPPUNIT_TEST(test_output_10);
    CPPUNIT_TEST(test_output_11);
    CPPUNIT_TEST(test_output_12);
    CPPUNIT_TEST(test_leap_year_1);
    CPPUNIT_TEST(test_leap_year_2);
    CPPUNIT_TEST(test_leap_year_3);
    CPPUNIT_TEST(test_leap_year_4);
    CPPUNIT_TEST(test_leap_year_5);
    CPPUNIT_TEST(test_leap_year_6);
    CPPUNIT_TEST(test_leap_year_7);
    CPPUNIT_TEST(test_leap_year_8);
    CPPUNIT_TEST(test_leap_year_9);
    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
    cout << "TestDate.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestDate::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}
