/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:22:15 by jvalkama          #+#    #+#             */
/*   Updated: 2026/04/10 10:54:46 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

typedef struct s_conversions	t_conversions;

class ScalarConverter {
	public:
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter& other) = delete;
		~ScalarConverter() = delete;
		ScalarConverter&	operator=(const ScalarConverter& other) = delete;

		static t_conversions		convert(std::string& target);
};

struct	s_conversions {
	char	c;
	int		i;
	float	f;
	double	d;
};