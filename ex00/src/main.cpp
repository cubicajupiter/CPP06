/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:21:30 by jvalkama          #+#    #+#             */
/*   Updated: 2026/04/16 16:15:21 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"
#include <iostream>
#include <iomanip>

int	main(int ac, char **av) {
	if (ac == 2) {
		std::string		argument{av[1]};
		t_conversions	result = ScalarConverter::convert(argument);

		if (!result.valid)
			return 1;

		std::cout << std::fixed << std::showpoint << std::setprecision(1);
		std::cout << "char: ";
		if (!result.c)
			std::cout << "impossible" << std::endl;
		else if (result.i >= 32 && result.i <= 126)
			std::cout	<< *result.c << std::endl;
		else
			std::cout	<< "Non displayable" << std::endl;
		std::cout << "int: ";
		if (!result.i)
			std::cout << "impossible" << std::endl;
		else
			std::cout	<< *result.i << std::endl;
		std::cout << "float: ";
		if (!result.f)
			std::cout << "impossible" << std::endl;
		else
			std::cout << *result.f << "f" << std::endl;
		std::cout << "double: ";
		if (!result.d)
			std::cout << "impossible" << std::endl;
		else
			std::cout << *result.d << std::endl;
		std::cout << std::endl;
	}
	else {
		std::cout << "Usage: ./convert [argument]" << std::endl;
	}
	return 0;
}