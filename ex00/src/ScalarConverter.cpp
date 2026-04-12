/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:21:59 by jvalkama          #+#    #+#             */
/*   Updated: 2026/04/12 15:48:52 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"

t_token		tokenizer(std::string& str);

t_conversions		ScalarConverter::convert(std::string& target) {
	t_conversions	conv;
	t_token			input_type;

	input_type = tokenizer(target);

	switch (input_type) {
		case INVALID:
			std::cout << "Please input a value of type char, int, float, double" << std::endl;
			conv.c = std::nullopt;
			conv.i = std::nullopt;
			conv.f = std::nullopt;
			conv.d = std::nullopt;
			break;
		case T_NAN:
			conv.c = std::nullopt;
			conv.i = std::nullopt;
			conv.f = std::nanf("");
			conv.d = std::nan("");
			break;
		case T_INF:
			conv.c = std::nullopt;
			conv.i = std::nullopt;
			conv.f = INFINITY;
			conv.d = INFINITY;
			break;
		case T_NINF:
			conv.c = std::nullopt;
			conv.i = std::nullopt;
			conv.f = -INFINITY;
			conv.d = -INFINITY;
			break;
		case CHAR:
			conv.c = target[0];
			conv.i = static_cast<int>(target[0]);
			conv.f = static_cast<float>(target[0]);
			conv.d = static_cast<double>(target[0]);
			break;
		case INT:
			conv.c = static_cast<unsigned char>(std::stoi(target));
			conv.i = std::stoi(target);
			conv.f = static_cast<float>(std::stoi(target));
			conv.d = static_cast<double>(std::stoi(target));
			break;
		case FLOAT:
			conv.c = static_cast<unsigned char>(std::stof(target));
			conv.i = static_cast<int>(std::stof(target));
			conv.f = std::stof(target);
			conv.d = static_cast<double>(std::stof(target));
			break;
		case DOUBLE:
			conv.c = static_cast<unsigned char>(std::stod(target));
			conv.i = static_cast<int>(std::stod(target));
			conv.f = static_cast<float>(std::stod(target));
			conv.d = std::stod(target);
			break;
	}

	return conv;
}

static t_token	tokenizer(std::string& str) {
	std::string		specials[][2] = {{"nan", "nanf"}, {"+inf", "+inff"}, {"-inf", "-inff"}};
	bool			has_digit = false;
	bool			has_letter = false;
	bool			has_decimal = false;

	for (size_t i = 0; i < 3; ++i) {
		if (str == specials[i][0] || str == specials[i][1])
			return static_cast<t_token>(i);
	}
	if (str.length() == 1 && std::isalpha(str[0]))
		return CHAR;
	for (char c : str) {
		if (c == '.')
			has_decimal = true;
		if (std::isdigit(c))
			has_digit = true;
		if (std::isalpha(c))
			has_letter = true;
	}
	if (has_digit && !has_decimal && !has_letter)
		return INT;
	if (has_digit && has_decimal && !has_letter) {
		if (str.back() != '.' && str[0] != '.')
			return DOUBLE;
	}
	if (has_digit && has_decimal && has_letter) {
		if (str[str.length() - 1] == 'f' && str[str.length() - 2] != '.' && str[0] != '.')
			return FLOAT;
	}
	return INVALID;
}