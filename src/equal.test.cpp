/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:04:03 by alefranc          #+#    #+#             */
/*   Updated: 2022/11/08 15:58:57 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>     // std::cout, std::boolalpha
#include <cctype>       // std::tolower
#include <vector>
#include <string>

#ifdef FT
    #include "equal.hpp"
	namespace ns = ft;
#endif
#ifdef STD
	namespace ns = std;
#endif


void	print_title(const std::string& title)
{
	std::cout << std::endl;
	std::cout << "=============================================================\n";
	std::cout << title << std::endl;
	std::cout << "=============================================================\n";
	std::cout << std::endl;
}

// a case-insensitive comparison function:
bool mycomp (char c1, char c2)
{
    return (std::tolower(c1) < std::tolower(c2));
}

bool mypredicate (int i, int j)
{
    return (i == j);
}

bool is_palindrome(const std::string& s)
{
    return ns::equal(s.begin(), s.begin() + s.size()/2, s.rbegin());
}

void    test_equal()
{
    print_title("EQUAL");

    int                 myints[] = {20,40,60,80,100};  //   myints: 20 40 60 80 100
    std::vector<int>    myvector(myints,myints+5);     // myvector: 20 40 60 80 100

    // using default comparison:
    if (ns::equal (myvector.begin(), myvector.end(), myints))
        std::cout << "The contents of both sequences are equal.\n";
    else
        std::cout << "The contents of both sequences differ.\n";

    myvector[3]=81;                                 // myvector: 20 40 60 81 100

    // using predicate comparison:
    if (ns::equal (myvector.begin(), myvector.end(), myints, mypredicate))
        std::cout << "The contents of both sequences are equal.\n";
    else
        std::cout << "The contents of both sequences differ.\n";
}

void    test_equal2()
{
    print_title("EQUAL2");

    std::string s("radar");
    std::cout   << "\"" << s << "\" "
                << (is_palindrome(s) ? "is" : "is not")
                << " a palindrome\n";
                
    s = "hello";
    std::cout   << "\"" << s << "\" "
                << (is_palindrome(s) ? "is" : "is not")
                << " a palindrome\n";
    
}

void    test_lexicographical_compare()
{
    print_title("LEXICOGRAPHICAL COMPARE");

    char foo[]="Apple";
    char bar[]="apartment";

    std::cout << std::boolalpha;

    std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

    std::cout << "Using default comparison (operator<): ";
    std::cout << ns::lexicographical_compare(foo,foo+5,bar,bar+9);
    std::cout << '\n';

    std::cout << "Using mycomp as comparison object: ";
    std::cout << ns::lexicographical_compare(foo,foo+5,bar,bar+9,mycomp);
    std::cout << '\n';  
}

int main_equal()
{
    test_equal();
    test_equal2();
    test_lexicographical_compare();

    return 0;
}