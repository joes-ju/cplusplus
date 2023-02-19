#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using std::cout;
using std::endl;

//class stack
//{
//public:
//	stack()
//		:_capacity(_capacity==0?4:2*_capacity)
//		,_a(new int[_capacity])
//		,_top(0)
//	{}
//
//	void push(const stack& s);
//	void pop();
//	bool empty();
//	int top();
//	int size();
//
//	~stack()
//	{
//		delete[] _a;
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};

struct Date
{
public:
	Date(int year = 2000,int month = 10,int day = 1)
		:_year(year)
		,_month(month)
		,_day(day)
	{}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	bool operator==(const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	bool operator>(const Date& d)
	{
		if (_year > d._year)
		{
			return true;
		}
		else if (_year == d._year && _month > d._month)
		{
			return true;
		}
		else if (_year == d._year && _month == d._month && _day > d._day)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int MonthOfDay(int year, int month)
	{
		int monthArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

		if (month == 2 && (year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			return 29;
		}
		else
		{
			return monthArray[month];
		}
	}

	bool operator>=(const Date& d)
	{
		return (*this > d) || (*this == d);
	}

	bool operator<(const Date& d)
	{
		return !(*this >= d);
	}

	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

	bool operator<=(const Date& d)
	{
		return (*this < d) || (*this == d);
	}



	//d1+=10 改变d1
	Date& operator+=(int day)
	{
		if (day < 0)
		{
			*this -= -day;
			return *this;
		}
		_day += day;
		while (_day > MonthOfDay(_year, _month))
		{
			++_month;
			_day -= MonthOfDay(_year, _month);
			if (_month == 13)
			{
				++_year;
				_month = 1;
			}
		}
		return *this;
	}

	//d1+10, 不改变d1
	Date operator+(int day)
	{
		Date tmp(*this);

		*this += day;
		return tmp;
	}

	//d1-10 ,改变d1
	Date& operator-=(int day)
	{
		if (day < 0)
		{
			*this += -day;
			return *this;
		}

		_day -= day;
		while (_day < 0)
		{
			--_month;
			if (_month == 0)
			{
				--_year;
				_month = 12;
			}
			_day += MonthOfDay(_year, _month);
		}
		return *this;
	}

	//d1-10
	Date operator-(int day)
	{
		Date tmp(*this);
		*this -= day;
		return tmp;
	}

	int operator-(const Date& d)
	{
		Date max = *this;
		Date min = d;
		int flag = 1;

		if (*this < d)
		{
			max = d;
			min = *this;
			flag = -1;
		}
		int n = 0;
		while (min != max)
		{
			++min;
			++n;
		}
		return n * flag;
	}

	//++d1
	Date operator++()
	{
		*this += 1;
		return *this;
	}

	//d1++
	Date& operator++(int)
	{
		Date tmp(*this);

		*this += 1;
		return tmp;
	}

	//--d
	Date operator--()
	{
		*this -= 1;
		return *this;
	}

	//d1--
	Date& operator--(int)
	{
		Date tmp(*this);
		*this -= 1;
		return tmp;
	}

	void Print()
	{
		cout << _year << "年" << _month << "月" << _day << "日" << endl;
	}

	~Date()
	{
		_year = 0;
		_month = 0;
		_day = 0;
	}
private:
	int _year;
	int _month;
	int _day;
};

class person
{
public:
	//void add()
	//{
	//	//
	//}
private:
	int _year;
	int _sex;
	int _height;
	int _weight;
	int _tel;
};


int main()
{
	Date d1;
	cout << "d1所占空间：" << sizeof(d1) << endl;
	return 0;
}

//有没有解引用的行为，取决于访问右边东西在不在对象里。
