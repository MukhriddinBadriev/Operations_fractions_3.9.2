#include <iostream>
using namespace std;

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		if (denominator == 0) {
			cout << "ОШИБКА: ПОПЫТКА ДЕЛИТЬ НА НОЛЬ" << endl;
			exit(0);
		}
		else denominator_ = denominator;
	}
	//double fract() { return double(numerator_ / denominator_); }
	double operator +(Fraction other) {
		return double(numerator_ * other.denominator_ + denominator_ * other.numerator_) / 
			(denominator_ * other.denominator_);
	}
	double operator -(Fraction other) {
		return double(numerator_ * other.denominator_ - denominator_ * other.numerator_) /
			(denominator_ * other.denominator_);
	}
	double operator *(Fraction other) {
		return double(numerator_ * other.numerator_) / (denominator_ * other.denominator_);
	}
	double operator /(Fraction other) {
		return double(numerator_ *other.denominator_ ) / double(other.numerator_ * denominator_);
	}
	Fraction& operator++() { numerator_+denominator_; denominator_; return *this; }
	Fraction operator++(int)
	{
		Fraction temp = *this;
		++(*this);
		return temp;
	}
	Fraction& operator--() { numerator_- denominator_; denominator_; return *this; }
	Fraction operator--(int)
	{
		Fraction temp = *this;
		--(*this);
		return temp;
	}
	friend ostream& operator<<(ostream& os, const Fraction& dt);
};

ostream& operator<<(ostream& os, const Fraction& fr)
{
	os << fr.numerator_ <<"/"<<fr.denominator_;
	return os;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int numerator_1;
	int denominator_1;
	int numerator_2;
	int denominator_2;
	cout << "Введите числитель дроби 1: ";
	cin >> numerator_1;
	cout << "Введите знаменатель дроби 1: ";
	cin >> denominator_1;
	cout << "Введите числитель дроби 2: ";
	cin >> numerator_2;
	cout << "Введите знаменатель дроби 2: ";
	cin >> denominator_2;

	Fraction f1(numerator_1, denominator_1);
	Fraction f2(numerator_2, denominator_2);

	cout << numerator_1 << "/" << denominator_1 << " + " << numerator_2 << "/" << denominator_2 << " = "; cout << f1 + f2 << endl;
	cout << numerator_1 << "/" << denominator_1 << " - " << numerator_2 << "/" << denominator_2 << " = " << (f1 - f2) << endl;
	cout << numerator_1 << "/" << denominator_1 << " * " << numerator_2 << "/" << denominator_2 << " = " << (f1 * f2) << endl;
	cout << numerator_1 << "/" << denominator_1 << " / " << numerator_2 << "/" << denominator_2 << " = " << (f1 / f2) << endl;
	cout << "++" << numerator_1 << "/" << denominator_1 << " * " << numerator_2 << "/" << denominator_2 << " = " << (++f1 * f2) << endl;
	cout << "Значение дроби 1 = " << f1<<endl;
	cout  << numerator_1 << "/" << denominator_1 << " -- * " << numerator_2 << "/" << denominator_2 << " = " << ((f1--) * f2) << endl;
	cout << "Значение дроби 1 = " << f1<<endl;
	return 0;
}