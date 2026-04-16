/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:22:15 by jvalkama          #+#    #+#             */
/*   Updated: 2026/04/16 19:46:20 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <cmath>
#include <iostream>
#include <optional>
#include <cmath>
#include <limits>

typedef struct s_conversions	t_conversions;	
typedef enum e_type_spec {
	T_NAN,
	T_INF,
	T_NINF,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID
} 		t_token;

class ScalarConverter {
	public:
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter& other) = delete;
		~ScalarConverter() = delete;
		ScalarConverter&	operator=(const ScalarConverter& other) = delete;

		static t_conversions		convert(std::string& target);
};

struct	s_conversions {
	bool							valid;
	std::optional<unsigned char>	c;
	std::optional<int>				i;
	std::optional<float>			f;
	std::optional<double>			d;
};

template <typename T>
static void		char_guarded_assign(t_conversions& conv, T value) {
	if (value > std::numeric_limits<unsigned char>::max() || value < std::numeric_limits<unsigned char>::min())
		conv.c = std::nullopt;
	else
		conv.c = static_cast<unsigned char>(value);
}

template <typename T>
static void		int_guarded_assign(t_conversions& conv, T value) {
	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		conv.i = std::nullopt;
	else
		conv.i = static_cast<int>(value);
}

template <typename T>
static void		float_guarded_assign(t_conversions& conv, T value) {
	constexpr long long		max_exact = 1LL << std::numeric_limits<float>::digits;
	
	if (value > max_exact || value < -max_exact)
		conv.f = std::nullopt;
	else
		conv.f = static_cast<float>(value);
}

template <typename T>
static void		double_guarded_assign(t_conversions& conv, T value) {
	constexpr long long		max_exact = 1LL << std::numeric_limits<double>::digits;

	if (value > max_exact || value < -max_exact)
		conv.d = std::nullopt;
	else
		conv.d = static_cast<double>(value);
}