/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:37:51 by alefranc          #+#    #+#             */
/*   Updated: 2022/11/24 15:23:05 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifdef FT
	#include "stack.hpp"
	namespace ns = ft;
#endif
#ifdef STD
	#include <stack>
	namespace ns = std;
#endif

static void	print_title(const std::string& title)
{
	std::cout << std::endl;
	std::cout << "=============================================================\n";
	std::cout << title << std::endl;
	std::cout << "=============================================================\n";
	std::cout << std::endl;
}

template <typename T>
static void	print_stack(T stack)
{
	size_t	size = stack.size();
	for (size_t i = 0; i < size; i++)
	{
		std::cout << stack.top() << " ";
		stack.pop();
	}
	std::cout << std::endl;
}

static void	test_stack_constructor()
{
	print_title("STACK - CONSTRUCTORS");

	ns::stack<int> stack1;

	for (int i = 0; i < 5; i++)
	{
		std::cout << "Pushing " << i << std::endl;
		stack1.push(i);
	}
	print_stack(stack1);
	
	ns::stack<int> stack2 = stack1;
	print_stack(stack2);
}

static void	test_stack_access()
{
	print_title("STACK - ELEMENT ACCESS");

	{
		ns::stack<int> stack1;

		for (int i = 0; i < 5; i++)
		{
			std::cout << "Pushing " << i << std::endl;
			stack1.push(i);
		}

		print_stack(stack1);
		std::cout << "Replacing top element with 42" << std::endl;
		stack1.top() = 42;
		print_stack(stack1);
	}
	std::cout << std::endl;
	{
		ns::stack<int> stack1;
		for (int i = 0; i < 5; i++)
		{
			std::cout << "Pushing " << i << std::endl;
			stack1.push(i);
		}

		const ns::stack<int> stack2 = stack1;
		print_stack(stack2);
		std::cout << "Top element = " << stack2.top() << std::endl;
	}
}

static void	test_stack_capacity_modifiers()
{
	print_title("STACK - CAPACITY");

	ns::stack<int> stack1;
	std::cout << std::boolalpha
		<< "Empty ? " << stack1.empty() << "\t"
		<< "Size ? " << stack1.size()
		<< std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Pushing " << i << std::endl;
		stack1.push(i);
	}
	
	std::cout << std::boolalpha
		<< "Empty ? " << stack1.empty() << "\t"
		<< "Size ? " << stack1.size()
		<< std::endl;

	for (int i = 0; i < 5; i++)
	{
		std::cout << "Poping" << std::endl;
		stack1.pop();
	}
	std::cout << std::boolalpha
		<< "Empty ? " << stack1.empty() << "\t"
		<< "Size ? " << stack1.size()
		<< std::endl;
}

static void	test_stack_operators()
{
	print_title("STACK - RELATIONAL OPERATORS");
	std::cout << std::boolalpha;

	ns::stack<int> stack1;
	ns::stack<int> stack2;
	for (int i = 0; i < 5; i++)
	{
		stack1.push(i);
	}

	for (int i = 0; i < 5; i++)
	{
		stack2.push(i);
	}

	print_stack(stack1);
	print_stack(stack2);
	std::cout << "stack1 == stack2 is " << (stack1 == stack2) << std::endl;
	std::cout << "stack1 != stack2 is " << (stack1 != stack2) << std::endl;
	std::cout << "stack1 >  stack2 is " << (stack1 >  stack2) << std::endl;
	std::cout << "stack1 >= stack2 is " << (stack1 >= stack2) << std::endl;
	std::cout << "stack1 <  stack2 is " << (stack1 <  stack2) << std::endl;
	std::cout << "stack1 <= stack2 is " << (stack1 <=  stack2) << std::endl;
	std::cout << std::endl;

	stack1.top() = 42;
	print_stack(stack1);
	print_stack(stack2);
	std::cout << "stack1 == stack2 is " << (stack1 == stack2) << std::endl;
	std::cout << "stack1 != stack2 is " << (stack1 != stack2) << std::endl;
	std::cout << "stack1 >  stack2 is " << (stack1 >  stack2) << std::endl;
	std::cout << "stack1 >= stack2 is " << (stack1 >= stack2) << std::endl;
	std::cout << "stack1 <  stack2 is " << (stack1 <  stack2) << std::endl;
	std::cout << "stack1 <= stack2 is " << (stack1 <=  stack2) << std::endl;
	std::cout << std::endl;

}

void	main_stack()
{
	test_stack_constructor();
	test_stack_access();
	test_stack_capacity_modifiers();
	test_stack_operators();
}