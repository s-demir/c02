#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;

	public:
		Fixed();
		//const reference almalı, çünkü kaynağı değiştirmemeliyiz ve kopyalamadan okumalıyız
		Fixed(const Fixed& other);
		// 3. Copy Assignment Operator
		// (Geriye kendisine referans döndürmeli ki a = b = c yapılabilsin)
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int a;

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif