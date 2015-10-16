#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iterator>

int main(int argc, char const *argv[])
{
	std::string a;
	std::getline(std::cin,a);
	std::cout << "Ready" << std::endl ;
	while(a != "  ")
	{
		switch(a[0])
		{
			case 'q':
				if (a[1] == 'p')
					std::cout << "Mirrored pair" << std::endl ;
				else
					std::cout << "Ordinary pair" << std::endl ;
				break;
			case 'p':
				if (a[1] == 'q')
					std::cout << "Mirrored pair" << std::endl ;
				else
					std::cout << "Ordinary pair" << std::endl ;
				break;
			case 'b':
				if (a[1] == 'd')
					std::cout << "Mirrored pair" << std::endl ;
				else
					std::cout << "Ordinary pair" << std::endl ;
				break;
			case 'd':
				if (a[1] == 'b')
					std::cout << "Mirrored pair" << std::endl ;
				else
					std::cout << "Ordinary pair" << std::endl ;
				break;
			default :	
					std::cout << "Ordinary pair" << std::endl ;
				break;
		}
		std::getline(std::cin, a);
	}
	return 0;
}