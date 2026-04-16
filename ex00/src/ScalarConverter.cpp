/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:21:59 by jvalkama          #+#    #+#             */
/*   Updated: 2026/04/16 16:38:32 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"

static void			int_input(t_conversions& conv, std::string& target);
static void			float_input(t_conversions& conv, std::string& target);
static void			double_input(t_conversions& conv, std::string& target);
static t_token		tokenizer_parser(std::string& str);

t_conversions		ScalarConverter::convert(std::string& target) {
	t_conversions	conv;
	t_token			input_type;

	conv.valid = true;
	input_type = tokenizer_parser(target);
	switch (input_type) {
		case INVALID:
			conv.valid = false;
			std::cout << "The argument has to be a value of type char, int, float, or double!" << std::endl;
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
			conv.c = static_cast<unsigned char>(target[0]);
			conv.i = static_cast<int>(target[0]);
			conv.f = static_cast<float>(target[0]);
			conv.d = static_cast<double>(target[0]);
			break;
		case INT:
			int_input(conv, target);
			break;
		case FLOAT:
			float_input(conv, target);
			break;
		case DOUBLE:
			double_input(conv, target);
			break;
	}
	return conv;
}

static void	int_input(t_conversions& conv, std::string& target) {
	int		value;
	
	try {
		value = std::stoi(target);
	} catch (std::out_of_range& e) {
		conv.c = std::nullopt;
		conv.i = std::nullopt;
		conv.f = std::nullopt;
		conv.d = std::nullopt;
		return ;
	}
	char_guarded_assign(conv, value);
	conv.i = value;
	float_guarded_assign(conv, value);
	conv.d = static_cast<double>(value);
}

static void	float_input(t_conversions& conv, std::string& target) {
	double		value;

	try {
		value = std::stod(target);
	} catch (std::out_of_range& e) {
		conv.c = std::nullopt;
		conv.i = std::nullopt;
		conv.f = std::nullopt;
		conv.d = std::nullopt;
		return ;
	}
	if (value > std::numeric_limits<float>::max() || value < std::numeric_limits<float>::lowest()) {
		conv.c = std::nullopt;
		conv.i = std::nullopt;
		conv.f = std::nullopt;
		conv.d = std::nullopt;
		return ;
	}
	char_guarded_assign(conv, value);
	int_guarded_assign(conv, value);
	float_guarded_assign(conv, value);
	conv.d = value;
}

static void	double_input(t_conversions& conv, std::string& target) {
	long double		value;

	try {
		value = std::stold(target);
	} catch (std::out_of_range& e) {
		conv.c = std::nullopt;
		conv.i = std::nullopt;
		conv.f = std::nullopt;
		conv.d = std::nullopt;
		return ;		
	}
	if (value > std::numeric_limits<double>::max() || value < std::numeric_limits<double>::lowest()) {
		conv.c = std::nullopt;
		conv.i = std::nullopt;
		conv.f = std::nullopt;
		conv.d = std::nullopt;
		return ;
	}
	char_guarded_assign(conv, value);
	int_guarded_assign(conv, value);
	float_guarded_assign(conv, value);
	double_guarded_assign(conv, value);
}

static t_token	tokenizer_parser(std::string& str) {
	std::string		specials[][2] = {{"nan", "nanf"}, {"+inf", "+inff"}, {"-inf", "-inff"}};
	bool			has_digit = false;
	bool			has_letter = false;
	bool			has_decimal = false;

	for (size_t i = 0; i < 3; ++i) {
		if (str == specials[i][0] || str == specials[i][1])
			return static_cast<t_token>(i);
	}
	if (str.length() == 1 && std::isprint(static_cast<unsigned char>(str[0])) && !std::isdigit(str[0]))
		return CHAR;
	for (const char& c : str) {
		if (c == '.') {
			if (has_decimal == true)
				return INVALID;
			has_decimal = true;
			continue;
		}
		if (!std::isalnum(c)) {
			if ((&c - str.data()) == 0 && (c == '-' || c == '+')) {
				continue;
			}
			return INVALID;
		}
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