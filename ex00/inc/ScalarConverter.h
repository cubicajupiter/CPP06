/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:22:15 by jvalkama          #+#    #+#             */
/*   Updated: 2026/04/12 15:48:47 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cmath>
#include <iostream>
#include <optional>
#include <cmath>

typedef struct s_conversions	t_conversions;
typedef enum e_type_spec		t_token;

class ScalarConverter {
	public:
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter& other) = delete;
		~ScalarConverter() = delete;
		ScalarConverter&	operator=(const ScalarConverter& other) = delete;

		static t_conversions		convert(std::string& target);
};

struct	s_conversions {
	std::optional<unsigned char>	c;
	std::optional<int>				i;
	std::optional<float>			f;
	std::optional<double>			d;
};

//might benefit from a negative/positive specifier. but not strictly needed.
enum e_type_spec {
	T_NAN,
	T_INF,
	T_NINF,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID
};