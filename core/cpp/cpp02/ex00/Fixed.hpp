#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed {
	public:
		Fixed();
		Fixed(const Fixed &f);
		Fixed	& operator= (const Fixed &f);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	private:
		int					fpnv;
		static const int	nofb = 8;
};

#endif
