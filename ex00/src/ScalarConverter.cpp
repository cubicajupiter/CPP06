/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:21:59 by jvalkama          #+#    #+#             */
/*   Updated: 2026/04/08 15:59:58 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"

t_conversions		ScalarConverter::convert(std::string& target) {
	t_conversions	conv;

	// if (target.length() == 1 && target[0] <= 'z' && target[0] >= 'a') {
	// 	conv.c = static_cast<char>(target[0]);
	// }
	//else {
		conv.c = static_cast<char>(std::stoi(target)); //prolly works like this too
	//}
	conv.i = std::stoi(target);
	conv.f = std::stof(target);
	conv.d = std::stod(target);
	return conv;
}