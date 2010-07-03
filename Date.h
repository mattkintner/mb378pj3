// ------------------------
// projects/c++/date/Date.h
// Copyright (C) 2010
// Glenn P. Downing
// ------------------------

#ifndef Date_h
#define Date_h

// --------
// includes
// --------

#include <cassert>   // assert
#include <iostream>  // ostream
#include <stdexcept> // invalid_argument
#include <utility>   // !=, <=, >, >=
#include <cmath>

/*
namespace std     {
namespace rel_ops {

template <typename T>
inline bool operator != (const T& lhs, const T& rhs) {
    return !(lhs == rhs);}

template <typename T>
inline bool operator <= (const T& lhs, const T& rhs) {
    return !(rhs < lhs);}

template <typename T>
inline bool operator > (const T& lhs, const T& rhs) {
    return (rhs < lhs);}

template <typename T>
inline bool operator >= (const T& lhs, const T& rhs) {
    return !(lhs < rhs);}

} // rel_ops
} // std;
*/

// -----
// using
// -----

using namespace std::rel_ops;

// ----
// Date
// ----

template <typename T>
class Date {
    public:
        // ----------
        // operator +
        // ----------

        /**
         * Binary + operator on a date and a number of days
         * @throws invalid_argument if the resulting date precedes 1 Jan 1600
         */
        friend Date operator + (Date lhs, const T& rhs) {
            return lhs += rhs;}

        // ----------
        // operator -
        // ----------

        /**
         * Binary - operator on a date and a number of days
         * @throws invalid_argument if the resulting date precedes 1 Jan 1600
         */
        friend Date operator - (Date lhs, const T& rhs) {
            return lhs -= rhs;}

        // -----------
        // operator <<
        // -----------

        /**
         * @param  lhs an ostream
         * @param  rhs a date
         * @return the ostream
         * output a string representation of the date (e.g. "3 Feb 2008")
         * you can loop through an array of month names
         */
        friend std::ostream& operator << (std::ostream& lhs, const Date& rhs) {
            char* months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
            return lhs << rhs.myDay << " " << months[rhs.myMonth-1] << " " << rhs.myYear;}

    private:
        // ----
        // data
        // ----

        T numDays;
	T myDay;
	T myMonth;
	T myYear;

    private:
        // -----
        // valid
        // -----

        /**
         * Determine whether the current date is valid.
         */
        bool valid () const {
	    return numDays >= 0;
	}

        // -----------
        // constructor
        // -----------

        /**
         * @param days >= 0
         * Date(0) -> 1 Jan 1600
         * you can loop through an array of month days
         */
        Date (const T& days) {
            assert(days >= 0);
            numDays = days;
            if (!valid())
                throw std::invalid_argument("Date::Date()");}

        // -------
        // to_days
        // -------

        /**
         * @return the number of days since 1 Jan 1600, >= 0
         * 1 Jan 1600 -> 0
         */
        T to_days () const {
            T days = 0;
            days = numDays
            assert(days >= 0);
            return days;}

        // ----------
        // updateDate
        // ----------

        /**
         * Updates the current day, month, and year based on the current number of days from
	 * 1, 1, 1600.
         */
	void updateDate () {
	    T target = numDays;

	    T _day = 1;
	    T _month = 1;		
	    T _year = 1600;
            int months[] = {31,28,31,30,31,30,31,31,30,31,30,31};

	    while (target > 0) {
		if (target > 365) {
		    if (leap_year(_year)){
			target -= 366;
		    } else {
			target -= 365;
		    }
		    _year += 1;
		} else if (target > months[_month-1]) {
		    target -= months[_month-1];
		    if (_month == 12) {
			_month = 1;
		    } else {
			_month++;
		    }
		} else {
		    _day += target-1;
		    target = 0;
		}
	    }
	    myDay = _day;
	    myMonth = _month;
	    myYear = _year;

	    assert(myMonth >= 1 && myMonth <= 12);
	    assert(myYear >= 1600);
	    assert(myDay >= 1);
	    if(leap_year() && myMonth == 2) {
		assert(myDay <=29);
	    } else if (!leap_year() && myMonth == 2){
		assert(myDay <=28);
	    } else {
		assert(myDay <=months[(int)myMonth-1]);
	    }
	}

    public:
        // -----------
        // constructor
        // -----------

        /**
         * @param  day   >= 1 && <= 31
         * @param  month >= 1 && <= 12
         * @param  year  >= 1600
         * @throws invalid_argument if the resulting date is invalid
         */
        Date (const T& day, const T& month, const T& year) {
            int months[] = {31,28,31,30,31,30,31,31,30,31,30,31};

	    double _month;
	    modf(month, &_month);

            T temp = 0;
	    if ( year < 1600 ) {
		throw std::invalid_argument("Date::Date()");
	    } else if (month < 1 || month > 12) {
		throw std::invalid_argument("Date::Date()");
	    } else if (day < 1 || (day > months[(int)_month-1] + (leap_year(year) && month==2 ? 1 : 0))) {
		throw std::invalid_argument("Date::Date()");
	    } 

	    if (year > 1600) {
		for (int i = 1600; i < year; i++){
			if ((i % 4 == 0) && ( (i % 100 != 0) || (i%400 == 0))) {
				temp += 366;
			} else {
				temp += 365;
			}
	   	}
	    } 
	
	    for (int i = 0; i < month-1; i++) {
		if (i == 1 && leap_year(year)) {
		    temp += (months[i]+1);
		} else {
		    temp += months[i];
		}
	   }
	
	    temp += day-1;

	    myDay = day;
	    myMonth = _month;
	    myYear = year;

	    numDays = temp;
            if (!valid())
                throw std::invalid_argument("Date::Date()");}

        // Default copy, destructor, and copy assignment.
        // Date (const Date&);
        // ~Date ();
        // Date& operator = (const Date&);

        // -----------
        // operator ==
        // -----------

        /**
         * Compares two dates and returns true if the dates are the same
         */
        bool operator == (const Date& rhs) const {
            return numDays == rhs.numDays;
            return false;}

        // ----------
        // operator <
        // ----------

        /**
         * Compares two dates lhs,rhs and returns true of lhs is ahead of rhs
         */
        bool operator < (const Date& rhs) const {
            return numDays < rhs.numDays;
            return false;}

        // -----------
        // operator +=
        // -----------

        /**
         * Adds a number of days to the current date, and updates the date accordingly
         * @param  days the number of days to add (may be negative!)
         * @return the date resulting from adding days
         * @throws invalid_argument if the resulting date precedes 1 Jan 1600
         */
        Date& operator += (const T& days) {
            numDays += days;
	    updateDate();
            if (!valid())
                throw std::invalid_argument("Date::Date()");
            return *this;}

        // -----------
        // operator -=
        // -----------

        /**
         * Subtracts a number of days from the current date, and updates the date accordingly
         * @param  days the number of days to subtract (may be negative!)
         * @return the date resulting from subtracting days
         * @throws invalid_argument if the resulting date precedes 1 Jan 1600
         */
        Date& operator -= (const T& days) {
            numDays -= days;
	    updateDate();
            if (!valid())
                throw std::invalid_argument("Date::Date()");
            return *this;}

        // ----------
        // operator -
        // ----------

        /**
         * Subtracts the number of days between two dates, and updates the dates accordingly
         * @return the number of days between the dates (lhs - rhs)
         */
        T operator - (const Date& rhs) const {
            return numDays - rhs.numDays;}

        // ---------
        // leap_year
        // ---------

        /**
	 * Determines whether the current date is a leap year.
         * @return True if the current year of this Date object is a leap year, false if otherwise.
         */
        bool leap_year () const {
            return ((fmod(myYear,4) == 0) && ( (fmod(myYear,100) != 0) || (fmod(myYear,400) == 0)));}

        // ---------
        // leap_year
        // ---------

        /**
         * Determines if a year is a leap year.
         * @param year The year to be tested
         * @return True if the year is a leap year, false if otherwise.
         */
	bool leap_year (const T& year) {
		return ((fmod(year,4) == 0) && ( (fmod(year,100) != 0) || (fmod(year,400) == 0)));
	}};

#endif // Date_h
