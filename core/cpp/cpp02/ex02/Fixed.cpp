#include "Fixed.hpp"


/* Constructors */
Fixed::Fixed()
{
	// std::cout << "Fixed is alive" << std::endl;
	fpnv = 0;
}

Fixed::Fixed(const Fixed &f)
{
	// std::cout << "Fixed is printing money" << std::endl;
	*this = f;
}

Fixed::Fixed(const int i)
{
	// std::cout << "Fixed is printing money in ints" << std::endl;
	fpnv = i * (1 << nofb);
}

Fixed::Fixed(const float i)
{
	// std::cout << "Fixed is printing money in floats" << std::endl;
	fpnv = roundf(i * (1 << nofb));
}

Fixed::~Fixed()
{
	// std::cout << "Fixed was caught by the police,";
	// std::cout << " in an attempt to escape ";
	// std::cout << "he was shot 7 times" << std::endl;
}



/* operator overloads */
Fixed	&Fixed:: operator= (const Fixed &f)
{
	// std::cout << "Fixed is getting cash to print" << std::endl;
	if (this != &f)
		fpnv = f.getRawBits();
	return (*this);
}

std::ostream	& operator<< (std::ostream &out, const Fixed &f)
{
	out << f.toFloat();
	return (out);
}



/* comparisons */
bool Fixed::operator< (const Fixed &f) const
{
	// std::cout << "Fixed has lesser" << std::endl;
	return (fpnv < f.fpnv);
}

bool Fixed::operator> (const Fixed &f) const
{
	// std::cout << "Fixed has more" << std::endl;
	return (fpnv > f.fpnv);
}

bool Fixed::operator<= (const Fixed &f) const
{
	// std::cout << "Fixed has less than equal" << std::endl;
	return (fpnv <= f.fpnv);
}

bool Fixed::operator>= (const Fixed &f) const
{
	// std::cout << "Fixed has more than equal" << std::endl;
	return (fpnv >= f.fpnv);
}

bool Fixed::operator== (const Fixed &f) const
{
	// std::cout << "Fixed has equal" << std::endl;
	return (fpnv == f.fpnv);
}

bool Fixed::operator!= (const Fixed &f) const
{
	// std::cout << "Fixed has inequal" << std::endl;
	return (fpnv != f.fpnv);
}



/* arithmetic */
Fixed Fixed::operator+ (const Fixed &f)
{
	// std::cout << "Fixed has added" << std::endl;
	float	i = toFloat();
	float	j = f.toFloat();
	return (i + j);
}

Fixed Fixed::operator- (const Fixed &f)
{
	// std::cout << "Fixed has subtracted" << std::endl;
	float	i = toFloat();
	float	j = f.toFloat();
	return (i - j);
}

Fixed Fixed::operator* (const Fixed &f)
{
	// std::cout << "Fixed has multiplied" << std::endl;
	float	i = toFloat();
	float	j = f.toFloat();
	return (i * j);
}

Fixed Fixed::operator/ (const Fixed &f)
{
	// std::cout << "Fixed has divided" << std::endl;
	float	i = toFloat();
	float	j = f.toFloat();
	return (i / j);
}



/* increment.decrement */
Fixed Fixed::operator++ (int)
{
	// std::cout << "Fixed has pre-incremented" << std::endl;
	Fixed f(*this);
	++this->fpnv;
	return (f);
}

Fixed Fixed::operator++ ()
{
	// std::cout << "Fixed has post-incremented" << std::endl;
	++this->fpnv;
	return (*this);
}

Fixed Fixed::operator-- (int)
{
	// std::cout << "Fixed has pre-decremented" << std::endl;
	Fixed f(*this);
	--this->fpnv;
	return (f);
}

Fixed Fixed::operator-- ()
{
	// std::cout << "Fixed has post-decremented" << std::endl;
	--this->fpnv;
	return (*this);
}



/* Functions */
int		Fixed::getRawBits(void) const
{
	// std::cout << "Fixed is mugging some poor bloke on the street" << std::endl;
	return (fpnv);
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "Fixed is back with cash" << std::endl;
	fpnv = raw;
}

float	Fixed::toFloat(void) const
{
	// std::cout << "Fixed has converted to float" << std::endl;
	float	i = (float)fpnv / (float)(1 << nofb);
	return (i);
}

int		Fixed::toInt(void) const
{
	// std::cout << "Fixed has converted to int" << std::endl;
	int	i = (int)fpnv / (int)(1 << nofb);
	return (i);
}

Fixed Fixed::min(Fixed &f1, Fixed &f2)
{
	// std::cout << "Fixed has minimum" << std::endl;
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed Fixed::min(const Fixed &f1, const Fixed &f2)
{
	// std::cout << "Fixed has constant minimum" << std::endl;
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed Fixed::max(Fixed &f1, Fixed &f2)
{
	// std::cout << "Fixed has maximum" << std::endl;
	if (f1 > f2)
		return (f1);
	return (f2);
}

Fixed Fixed::max(const Fixed &f1, const Fixed &f2)
{
	// std::cout << "Fixed has constant maximum" << std::endl;
	if (f1 > f2)
		return (f1);
	return (f2);
}
