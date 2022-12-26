/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:49:34 by alefranc          #+#    #+#             */
/*   Updated: 2022/12/26 20:41:00 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>

#ifdef FT
	#include "map.hpp"
	namespace ns = ft;
#endif
#ifdef STD
	#include <map>
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

template <typename T, typename U>
static void	print_map(const ns::map<T, U>& m)
{
	std::cout << "size = " << m.size() << std::endl;
	for (typename ns::map<T, U>::const_iterator it = m.begin(); it != m.end(); it++)
		std::cout << it->first << " -> " << it->second << std::endl;
	std::cout << std::endl;
}

static void	test_map_capacity()
{
	print_title("MAP CAPACITY");
	std::cout << std::boolalpha;

	ns::map<char, int> m;

	std::cout << "m.empty() = " << m.empty() << std::endl;
	std::cout << "m.size() = " << m.size() << std::endl;
}

static void	test_map_iterator()
{
	print_title("MAP ITERATOR");

	ns::map<char, int> m;
	m.insert(ns::pair<char, int>('m', 13));
	m.insert(ns::pair<char, int>('a', 1));
	m.insert(ns::pair<char, int>('z', 26));

	std::cout << "      ['m', 13]       " << std::endl;
	std::cout << "      /       \\      " << std::endl;
	std::cout << "['a', 1]     ['z', 26]" << std::endl;
	std::cout << std::endl;



	ns::map<char, int>::iterator it;
	ns::map<char, int>::iterator ite;
	ns::map<char, int>::iterator tmpit;
	
	it = m.begin();
	ite = m.end();
	
	std::cout << "it = m.begin()" << std::endl;
	std::cout << "it    = ['" << it->first << "', " << it->second << "]" << std::endl;
	std::cout << std::endl;
	
	std::cout << "tmpit = ++it" << std::endl;
	tmpit = ++it;
	std::cout << "tmpit = ['" << tmpit->first << "', " << tmpit->second << "]" << std::endl;
	std::cout << "it    = ['" << it->first << "', " << it->second << "]" << std::endl;
	std::cout << std::endl;

	std::cout << "tmpit = it++" << std::endl;
	tmpit = it++;
	std::cout << "tmpit = ['" << tmpit->first << "', " << tmpit->second << "]" << std::endl;
	std::cout << "it    = ['" << it->first << "', " << it->second << "]" << std::endl;
	std::cout << std::endl;

	std::cout << "++it" << std::endl;
	++it;
	std::cout << "--it" << std::endl;
	--it;

	std::cout << "tmpit = --it" << std::endl;
	tmpit = --it;
	std::cout << "tmpit = ['" << tmpit->first << "', " << tmpit->second << "]" << std::endl;
	std::cout << "it    = ['" << it->first << "', " << it->second << "]" << std::endl;
	std::cout << std::endl;

	std::cout << "tmpit = it--" << std::endl;
	tmpit = it--;
	std::cout << "tmpit = ['" << tmpit->first << "', " << tmpit->second << "]" << std::endl;
	std::cout << "it    = ['" << it->first << "', " << it->second << "]" << std::endl;
	std::cout << std::endl;

	print_map(m);

	std::cout << "Implicit conversion from iterator to const_iterator" << std::endl;
	it = m.begin();

	ns::map<char, int>::const_iterator cit;
	cit = it;
}

static void	test_map_reverse_iterator()
{
	print_title("MAP REVERSE ITERATOR");

	ns::map<char, int> m;
	m.insert(ns::pair<char, int>('m', 13));
	m.insert(ns::pair<char, int>('a', 1));
	m.insert(ns::pair<char, int>('z', 26));

	std::cout << "      ['m', 13]       " << std::endl;
	std::cout << "      /       \\      " << std::endl;
	std::cout << "['a', 1]     ['z', 26]" << std::endl;
	std::cout << std::endl;

	ns::map<char, int>::reverse_iterator rit;
	ns::map<char, int>::reverse_iterator rite;

	for (rit = m.rbegin(); rit != m.rend(); rit++)
		std::cout << rit->first << " -> " << rit->second << std::endl;
}

static void	test_map_copy()
{
	print_title("MAP COPY");

	ns::map<char, int> m;
	m.insert(ns::pair<char, int>('m', 13));
	m.insert(ns::pair<char, int>('a', 1));
	m.insert(ns::pair<char, int>('z', 26));

	std::cout << "      ['m', 13]       " << std::endl;
	std::cout << "      /       \\      " << std::endl;
	std::cout << "['a', 1]     ['z', 26]" << std::endl;
	std::cout << std::endl;

	{
		std::cout << "Const copy by assignation" << std::endl;
		const ns::map<char, int> m2 = m;
		print_map(m2);
	}

	{
		std::cout << "Const copy by copy" << std::endl;
		const ns::map<char, int> m2(m);
		print_map(m2);
	}

	{
		std::cout << "Double copy" << std::endl;
		ns::map<char, int> m2 = m;
		m2 = m;
		print_map(m2);
	}
}

static void	test_map_erase()
{
	print_title("MAP ERASE");

	ns::map<char, int> m;

	m['c']=30;
	m['e']=50;
	m['f']=60;
	m['b']=20;
	m['d']=40;
	m['a']=10;

	print_map(m);

	std::cout << "Erase 2nd element via iterator" << std::endl;
	m.erase((++m.begin()));
	print_map(m);

	std::cout << "Erase 'c' via key" << std::endl;
	m.erase('c');
	print_map(m);

	std::cout << "Erase begin() to end() via range iterator" << std::endl;
	m.erase(m.begin(), m.end());
	print_map(m);

}

static void	test_map_lookup()
{
	print_title("MAP DONT LOOK UP");

	ns::map<char, int> m;

	m['c']=30;
	m['e']=50;
	m['f']=60;
	m['d']=40;
	m['a']=10;

	print_map(m);

	for (char c = 'a'; c < 'h'; c++)
	{
		std::cout << "count '" << c << "'" << std::endl;
		std::cout << m.count(c) << std::endl;
	}

	std::cout << std::endl;

	ns::map<char, int>::const_iterator	cit;
	cit = m.find('c');
	std::cout << "find 'c'" << std::endl;
	std::cout << cit->first << " -> " << cit->second << std::endl << std::endl;

	cit = m.find('z');
	std::cout << "find 'z'" << std::endl;
	if (cit == m.end())
		std::cout << "iterator is end()" << std::endl;
	else
		std::cout << "iterator is not end()" << std::endl;

	std::cout << std::endl;
	
	ns::pair<ns::map<char, int>::iterator, ns::map<char, int>::iterator> range;
	for (char c = 'a'; c < 'h'; c++)
	{
		std::cout << "equal_range('" << c << "')" << std::endl;
		range = m.equal_range(c);
		if (range.first != m.end())
			std::cout << "lower_bound=" << range.first->first << std::endl;
		else
			std::cout << "lower_bound is end()" << std::endl;

		if (range.second != m.end())
			std::cout << "upper_bound=" << range.second->first << std::endl;
		else
			std::cout << "upper_bound is end()" << std::endl;
		
		std::cout << std::endl;
	}
	
}

static void	test_map_swap()
{
	print_title("MAP SWAP");

	ns::map<char, int> m1;

	m1['c']=30;
	m1['e']=50;
	m1['f']=60;
	m1['d']=40;
	m1['a']=10;

	ns::map<char, int> m2;

	m2['y']=654;
	m2['z']=122;
	m2['t']=78;
	m2['u']=1231;
	m2['p']=165456;

	std::cout << "m1" << std::endl;
	print_map(m1);
	std::cout << "m2" << std::endl;
	print_map(m2);

	m1.swap(m2);

	std::cout << "m1" << std::endl;
	print_map(m1);
	std::cout << "m2" << std::endl;
	print_map(m2);
}

static void	test_map_test()
{
	ns::map<char,int> foo,bar;

	foo['x']=100;
	foo['y']=200;

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;


	ns::map<char, int>::const_iterator tmp = foo.begin(); //tmp iterates through foo
	ns::map<char, int>::const_iterator tmp2 = bar.begin(); //tmp2 iterates through bar

	foo.swap(bar); //tmp iterates through bar
				//tmp2 iterates through foo


	ns::map<char, int>	other;

	other['1'] = 73;
	other['2'] = 173;
	other['3'] = 763;
	other['4'] = 73854;
	other['5'] = 74683;
	other['6'] = 753;

	ns::map<char, int>::const_iterator tmp3 = other.begin(); // tmp3 iterates through other

	std::cout << "foo contains:\n";
	for (ns::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << std::endl;

	std::cout << "bar contains:\n";
	for (ns::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << std::endl;

	while(tmp != bar.end())
	{
		std::cout << tmp->first << " => " << tmp->second << '\n';
		tmp++;
	}
	tmp--;

	while(tmp2 != foo.end())
	{
		std::cout << tmp2->first << " => " << tmp2->second << '\n';
		tmp2++;
	}
	tmp2--;

	other.swap(foo); //tmp2 iterates through other
					//tmp3 iterates throught foo
	print_map(other);
	print_map(foo);
	print_map(bar);
	while(tmp != bar.begin())
	{
		std::cout << tmp->first << " => " << tmp->second << '\n';
		tmp--;
	}
	std::cout << tmp->first << " => " << tmp->second << '\n';

	while(tmp2 != other.begin())
	{
		std::cout << tmp2->first << " => " << tmp2->second << '\n';
		tmp2--;
	}
	std::cout << tmp2->first << " => " << tmp2->second << '\n';

	while(tmp3 != foo.end())
	{
		std::cout << tmp3->first << " => " << tmp3->second << '\n';
		tmp3++;
	}
	tmp3--;

	bar.swap(foo); //tmp3 iterates through bar
				//tmp iterates through foo

	print_map(other);
	print_map(foo);
	print_map(bar);

	while(tmp != foo.end())
	{
		std::cout << tmp->first << " => " << tmp->second << '\n';
		tmp++;
	}

	while(tmp2 != other.end())
	{
		std::cout << tmp2->first << " => " << tmp2->second << '\n';
		tmp2++;
	}

	while(tmp3 != bar.begin())
	{
		std::cout << tmp3->first << " => " << tmp3->second << '\n';
		tmp3--;
	}
	std::cout << tmp3->first << " => " << tmp3->second << '\n';
}

void	main_map()
{
	test_map_capacity();
	test_map_iterator();
	test_map_reverse_iterator();
	test_map_copy();
	test_map_erase();
	test_map_lookup();
	test_map_swap();
	test_map_test();
}