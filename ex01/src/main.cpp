/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:06:50 by jvalkama          #+#    #+#             */
/*   Updated: 2026/04/16 18:19:30 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.h"
#include <iostream>

int	main() {
	Data	test_before{.stuff = "stuff and things"};
	Data	*test_after;

	uintptr_t serialized_ptr = Serializer::serialize(&test_before);
	test_after = Serializer::deserialize(serialized_ptr);

	std::cout << std::boolalpha;
	std::cout << "Pointers are same after operations: " << (&test_before == test_after) << std::endl;

	std::cout << test_after->stuff << std::endl;

	return 0;
}