/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:21:59 by jvalkama          #+#    #+#             */
/*   Updated: 2026/04/10 15:45:27 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"

t_conversions		ScalarConverter::convert(std::string& target) {
	t_conversions	conv;

	
	//characters case
	if (target.length() == 1 && target[0] <= 'z' && target[0] >= 'a') {
		conv.c = static_cast<char>(target[0]);
	}

	//numbers case
	if (target.length() > 1) {
		if ()
	}


	conv.c = static_cast<char>(std::stoi(target));
	conv.i = std::stoi(target);
	conv.f = std::stof(target);
	conv.d = std::stod(target);
	return conv;
}