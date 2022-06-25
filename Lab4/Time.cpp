#include "Time.h"

int Time::count = 0;
Time::Time() {
	h = 0; m = 0; s = 0;
}

Time::Time(const Time &time)
{
	this->h = time.h; this->m = time.m; this->s = time.s;
	count++;
	this->number = count;
	
}

Time::Time(string time)
{
	count++;
	this->number = count;
	int i, j;
	i = time.find(":");
	j = time.rfind(":");
	h = stoi(time.substr(0, i));
	m = stoi(time.substr(i + 1, j));
	s = stoi(time.substr(j + 1, time.size()));
	if (h > 23 || m > 59 || s > 59 || h < 0 || m < 0 || s < 0) {
		cout << "Time " << this->number << " is wrong.\n";
		h = 0; m = 0; s = 0;
	}
	this->h = h; this->m = m; this->s = s;
}

Time::Time(int h, int m , int s)
{
	count++;
	this->number = count;
	if (h > 23 || m > 59 || s > 59 || h < 0 || m < 0 || s < 0) {
		cout << "Time " << this->number <<" is wrong\n";
		h = 0; m = 0; s = 0;
	}
	this->h = h; this->m = m; this->s = s;
}

int Time::getH()
{
	return h;
}

int Time::getM()
{
	return m;
}

int Time::getS()
{
	return s;
}

void Time::printTime()
{
	cout.fill('0');
	cout << "Time " << this->number << " is ";
	cout.width(2); cout << this->h << ":";
	cout.width(2); cout << this->m << ":";
	cout.width(2); cout << this->s << "\n";
}

string Time::strTime()
{
	string time, h, m, s;
	h = to_string(this->h);
	m = to_string(this->m);
	s = to_string(this->s);
	
	if (this->h < 10) {h.insert(0, "0");}
	if (this->m < 10) {m.insert(0, "0");}
	if (this->s < 10) {s.insert(0, "0");}
	time = h + ":" + m + ":" + s;
	return time;
}

void Time::left()
{
	int left, h, m, s, T = 86400;
	left = T - ((getH() * 60 + getM()) * 60 + getS());
	h = left / 3600;
	m = (left - h * 3600) / 60;
	s = left - h * 3600 - m * 60;
	Time obj(h, m, s);
	cout << "From " << this->strTime() << " to end of the day left " << obj.strTime() << "\n";
}

Time& Time::operator+=(int m)
{
	Time temp = *this;
	this->m += m;
	if (this->m > 60) {
		this->h += this->m / 60;
		this->m -= this->m / 60 * 60;
	}
	cout << "Time " << this->number << " " << temp.strTime() << " has been increased by " << m << " minutes\n";

	return *this;
}

Time& Time::operator-(Time obj)
{
	int T1, T2, T3, h, m, s;
	T1 = (getH() * 60 + getM()) * 60 + getS();
	T2 = (obj.getH() * 60 + obj.getM()) * 60 + obj.getS();
	if (T2 > T1) {
		cout << "Time " << obj.strTime() << " is bigger than " << this->strTime() << "\n";
		Time dif(0, 0, 0);
		return dif;
	}
	else{
		T3 = T1 - T2;
		h = T3 / 3600;
		m = (T3 - h * 3600) / 60;
		s = T3 - h * 3600 - m * 60;
		Time dif(h, m, s);
		cout << "Difference between " << this->strTime() << " and " << obj.strTime() << " is " << dif.strTime() << "\n";
		return dif;
	}
}

Time::~Time() { count--; }

