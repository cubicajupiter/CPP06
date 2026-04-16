/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:23:40 by jvalkama          #+#    #+#             */
/*   Updated: 2026/04/16 19:56:36 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.h"
#include "A.h"
#include "B.h"
#include "C.h"
#include <random>
#include <iostream>

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

int main() {
	Base* object0 = generate();
	Base* object1 = generate();
	Base* object2 = generate();
	Base* object3 = generate();
	Base* object4 = generate();
	std::cout << std::endl;

	identify(object0);
	identify(object1);
	identify(object2);
	identify(object3);
	identify(object4);
	std::cout << std::endl;

	identify(*object0);
	identify(*object1);
	identify(*object2);
	identify(*object3);
	identify(*object4);

	return 0;
}

Base*	generate(void) {
	std::random_device				rd;
	std::mt19937					engine(rd());
	std::uniform_int_distribution<>	distribution(1, 3);
	
	int		random_choice = distribution(engine);
	switch (random_choice) {
		case 1:
			std::cout << "A generated" << std::endl;
			return new A();
		case 2:
			std::cout << "B generated" << std::endl;
			return new B();
		case 3:
			std::cout << "C generated" << std::endl;
			return new C();
	}
	return nullptr;
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "type: A" << std::endl;
		return;
	}
	if (dynamic_cast<B*>(p)) {
		std::cout << "type: B" << std::endl;
		return;
	}
	if (dynamic_cast<C*>(p)) {
		std::cout << "type: C" << std::endl;
		return;
	}
}

void	identify(Base& p) {
	{
		try {
			dynamic_cast<A&>(p);
			std::cout << "type: A" << std::endl;
			return;
		} catch (std::bad_cast& e) {}
	}
	{
		try {
			dynamic_cast<B&>(p);
			std::cout << "type: B" << std::endl;
			return;
		} catch (std::bad_cast& e) {}
	}
	{
		try {
			dynamic_cast<C&>(p);
			std::cout << "type: C" << std::endl;
			return;
		} catch (std::bad_cast& e) {}
	}
}