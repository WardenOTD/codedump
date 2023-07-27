#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed {
	public:
		//___structors
		Fixed();
		Fixed(const Fixed &f);
		Fixed(const int i);
		Fixed(const float i);
		~Fixed();

		//operator overloads
		Fixed	& operator= (const Fixed &f);

		//functions
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
	private:
		int					fpnv;
		static const int	nofb = 8;
};

std::ostream	& operator<< (std::ostream &out, const Fixed &f);

#endif
