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

	Fraction operator+(Fraction other) {
		if ((numerator_ * other.denominator_ + denominator_ * other.numerator_) <= (denominator_ * other.denominator_)) {
			for (int i = (numerator_ * other.denominator_ + denominator_ * other.numerator_); i >=2 ; i--) {
				if ((numerator_ * other.denominator_ + denominator_ * other.numerator_) % i == 0 && (denominator_ * other.denominator_) % i == 0) {
					return Fraction((numerator_ * other.denominator_ + denominator_ * other.numerator_) / i, (denominator_ * other.denominator_) / i);
				}
			}
		}
		else {
			for (int i = (denominator_ * other.denominator_); i >=2 ; i--) {
				if ((numerator_ * other.denominator_ + denominator_ * other.numerator_) % i == 0 && (denominator_ * other.denominator_) % i == 0) {
					return Fraction((numerator_ * other.denominator_ + denominator_ * other.numerator_) / i, (denominator_ * other.denominator_) / i);
				}
			}
		}
		return Fraction((numerator_ * other.denominator_ + denominator_ * other.numerator_) , (denominator_ * other.denominator_) );
	}
	Fraction operator-(Fraction other) {
		if ((numerator_ * other.denominator_ - denominator_ * other.numerator_) <= (denominator_ * other.denominator_)) {
			for (int i = (numerator_ * other.denominator_ - denominator_ * other.numerator_); i>=2; i--) {
				if ((numerator_ * other.denominator_ - denominator_ * other.numerator_) % i == 0 && (denominator_ * other.denominator_) % i == 0) {
					return Fraction((numerator_ * other.denominator_ - denominator_ * other.numerator_)/i,
						(denominator_ * other.denominator_)/i);
				}
			}
		}
		else  {
			for (int i = (denominator_ * other.denominator_); i >=2 ; i--) {
				if ((numerator_ * other.denominator_ + denominator_ * other.numerator_) % i == 0 && (denominator_ * other.denominator_) % i == 0) {
					return Fraction((numerator_ * other.denominator_ - denominator_ * other.numerator_)/i,
						(denominator_ * other.denominator_)/i);
				}
			}
		}
		return Fraction((numerator_ * other.denominator_ - denominator_ * other.numerator_),
			(denominator_ * other.denominator_));
	}
	Fraction operator*(Fraction other) {
		if ((numerator_ * other.numerator_) <= (denominator_ * other.denominator_)) {
			for (int i = (numerator_ * other.numerator_); i >=2 ; i--) {
				if ((numerator_ * other.numerator_) % i == 0 && (denominator_ * other.denominator_) % i == 0) {
					return Fraction((numerator_ * other.numerator_)/i, (denominator_ * other.denominator_)/i);
				}
			}
		}
		else {
			for (int i = (denominator_ * other.denominator_); i >=2 ; i--) {
				if ((numerator_ *other.numerator_) % i == 0 && (denominator_ * other.denominator_) % i == 0) {
					return Fraction((numerator_ * other.numerator_)/i, (denominator_ * other.denominator_) / i);
				}
			}
		}
		return Fraction((numerator_ * other.numerator_), (denominator_ * other.denominator_));
	}
	Fraction operator/(Fraction other) {
		if ((numerator_ * other.denominator_) <= (other.numerator_ * denominator_)) {
			for (int i = (numerator_ * other.denominator_); i >=2 ; i--) {
				if ((numerator_ * other.denominator_) % i == 0 && (other.numerator_ * denominator_) % i == 0) {
					return Fraction((numerator_ * other.denominator_)/i, (other.numerator_ * denominator_)/i);
				}
			}
		}
		else {
			for (int i = (other.numerator_ * denominator_); i >=2 ; i--) {
				if ((numerator_ * other.denominator_ + denominator_ * other.numerator_) % i == 0 && (denominator_ * other.denominator_) % i == 0) {
					return Fraction((numerator_ * other.denominator_)/i, (other.numerator_ * denominator_)/i);
				}
			}
		}
		return Fraction((numerator_ * other.denominator_), (other.numerator_ * denominator_));
	}
	Fraction& operator++() { numerator_ += denominator_; denominator_; return *this; }
	Fraction operator++(int)
	{
		Fraction temp(numerator_, denominator_);
		numerator_ = numerator_ + denominator_;
		//denominator_ = denominator_;
		return temp;
	}
	Fraction& operator--() { numerator_ -= denominator_; denominator_; return *this; }
	Fraction operator--(int)
	{
		Fraction temp(numerator_, denominator_);
		numerator_ = numerator_ - denominator_;
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
	
	cout << numerator_1 << "/" << denominator_1 << " + " << numerator_2 << "/" << denominator_2 << " = " << (f1 + f2) << endl;
	cout << numerator_1 << "/" << denominator_1 << " - " << numerator_2 << "/" << denominator_2 << " = " << (f1 - f2) << endl;
	cout << numerator_1 << "/" << denominator_1 << " * " << numerator_2 << "/" << denominator_2 << " = " << (f1 * f2) << endl;
	cout << numerator_1 << "/" << denominator_1 << " / " << numerator_2 << "/" << denominator_2 << " = " << (f1 / f2) << endl;
	cout << "++" << numerator_1 << "/" << denominator_1 << " * " << numerator_2 << "/" << denominator_2 << " = " << (++f1 * f2) << endl;
	cout << "Значение дроби 1 = " << f1<<endl;
	cout  << numerator_1 << "/" << denominator_1 << " -- * " << numerator_2 << "/" << denominator_2 << " = " << ((f1--) * f2) << endl;
	cout << "Значение дроби 1 = " << f1<<endl;
	return 0;
}