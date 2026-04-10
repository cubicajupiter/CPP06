/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:21:30 by jvalkama          #+#    #+#             */
/*   Updated: 2026/04/10 10:54:47 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"
#include <iostream>

//int	main(int ac, char **av) {	converts actual program arguments eventually
int	main() {
	t_conversions	result;
	std::string		a = "K";
	std::string		b = "42";
	std::string		c = "24.2";
	std::string		d = "0";
	std::string		e = "a";
	std::string		f = "4.2";

	result = ScalarConverter::convert(a);
	std::cout << result.c << " " << result.i << " " << result.f << " " << result.d << std::endl;
	result = ScalarConverter::convert(b);
	std::cout << result.c << " " << result.i << " " << result.f << " " << result.d << std::endl;
	result = ScalarConverter::convert(c);
	std::cout << result.c << " " << result.i << " " << result.f << " " << result.d << std::endl;
	result = ScalarConverter::convert(d);
	std::cout << result.c << " " << result.i << " " << result.f << " " << result.d << std::endl;
	result = ScalarConverter::convert(e);
	std::cout << result.c << " " << result.i << " " << result.f << " " << result.d << std::endl;
	result = ScalarConverter::convert(f);
	std::cout << result.c << " " << result.i << " " << result.f << " " << result.d << std::endl;

	return 0;
}