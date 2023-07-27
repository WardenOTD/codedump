#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Fixed is alive" << std::endl;
	fpnv = 0;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Fixed is printing money" << std::endl;
	*this = f;
}

Fixed	&Fixed:: operator= (const Fixed &f)
{
	std::cout << "Fixed is getting cash to print" << std::endl;
	if (this != &f)
		fpnv = f.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Fixed was caught by the police,";
	std::cout << " in an attempt to escape ";
	std::cout << "he was shot 7 times" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "Fixed is mugging some poor bloke on the street" << std::endl;
	return (fpnv);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "Fixed is back with cash" << std::endl;
	fpnv = raw;
}
