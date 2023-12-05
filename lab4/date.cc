#include <ctime>  // time and localtime
#include "date.h"
#include <stdexcept>
#include <iomanip>
#include <iostream>

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d)  
{
	year = y;
	if(m-1>=0 && m-1<=11){
		month = m -1;
	}else{
		std::cerr<< "invalid month"<<std::endl;
	}
	if(d<= daysPerMonth[m-1]){
		day = d;
	}else{
		std::cerr<<"invalid day"<<std::endl;
	}
}

int Date::getYear() const {
	return this->year;
}

int Date::getMonth() const {
	return this->month+1;
}

int Date::getDay() const {
	return this->day;;
}

void Date::next() {
	day+=1;
	if(day>daysPerMonth[month]){
		day=1;
		month+=1;
		if(month>11){
			month=0;
			year++;
		}
	}
}

std::ostream& operator<<(std::ostream& out,Date& d) {
	out << std::setw(4) << std::setfill('0') << d.getYear() << '-';
	out << std::setw(2) << std::setfill('0') << d.getMonth() << '-';
	out << std::setw(2) << std::setfill('0') << d.getDay();
	return out;
}

std::istream& operator>>(std::istream& in, Date& d){
	int year, month, day;
	char dash1, dash2;

	in>> year >> dash1 >> month >> dash2 >>day;
	const int* daysPerMonth = Date::getDaysPerMonth();
	if(in)
	{
		if(month>= 1 && month<=12 && day <= daysPerMonth[month-1]){
			d = Date(year,month,day);
		}
	}else 
	{
		in.setstate(std::ios::failbit);	
	}
	return in;
}

const int* Date::getDaysPerMonth(){
	return daysPerMonth;
}
