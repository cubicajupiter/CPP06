/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 16:40:15 by jvalkama          #+#    #+#             */
/*   Updated: 2026/04/16 19:46:24 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <cstdint>

typedef struct s_Data	Data;

class Serializer {
	public:
		Serializer() = delete;
		Serializer(const Serializer& other) = delete;
		~Serializer() = delete;
		Serializer&	operator=(const Serializer& other) = delete;

		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

struct	s_Data {
	std::string		stuff;
};
