#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed {
	public:
		//constructors
		Fixed();
		Fixed(const Fixed &f);
		Fixed(const int i);
		Fixed(const float i);
		~Fixed();

		//operator overloads
		Fixed	& operator= (const Fixed &f);

		bool operator< (const Fixed &f) const;
		bool operator> (const Fixed &f) const;
		bool operator<= (const Fixed &f) const;
		bool operator>= (const Fixed &f) const;
		bool operator== (const Fixed &f) const;
		bool operator!= (const Fixed &f) const;

		Fixed operator+ (const Fixed &f);
		Fixed operator- (const Fixed &f);
		Fixed operator* (const Fixed &f);
		Fixed operator/ (const Fixed &f);

		Fixed operator++ (int);
		Fixed operator++ ();
		Fixed operator-- (int);
		Fixed operator-- ();

		//functions
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		static Fixed min(Fixed &f1, Fixed &f2);
		static Fixed min(const Fixed &f1, const Fixed &f2);
		static Fixed max(Fixed &f1, Fixed &f2);
		static Fixed max(const Fixed &f1, const Fixed &f2);

	private:
		int					fpnv;
		static const int	nofb = 8;
};

//so lonely all by himself...why is this one here and not in the class ?????
std::ostream	& operator<< (std::ostream &out, const Fixed &f);

#endif
