#include <iostream>
#include <limits>

bool numbersNotCorrect(size_t a, size_t b, size_t c)
{
	bool p = a*a < a;
	p = p || b*b < b;
	p = p || c*c < c;
	p = p || a*a > std::numeric_limits<size_t>::max() - b*b;
	p = p || a*a > std::numeric_limits<size_t>::max() - c*c;
	p = p || b*b > std::numeric_limits<size_t>::max() - c*c;
	if (p){
		return 1;
	}
	return 0;
}
bool isPyth(size_t a, size_t b, size_t c)
{
	if (numbersNotCorrect(a, b, c)){
		throw std::overflow_error("Too much");
	}
	bool p = a*a == b*b + c*c;
	p = p || b*b == a*a + c*c;
	p = p || c*c == a*a + b*b;
	return p;
}
int main() {
	using u_t = unsigned;
	u_t a = 0, b = 0, c = 0;
	std::cin >> c >> b;
	size_t count = 0;
	while (std::cin >> a){
		try{
			count += isPyth(a, b, c)? 1:0;
			c = b;
			b = a;
		}
		catch (const std::overflow_error &e){
			std::cerr << e.what() << "\n";
			return 2;
		}
	}
	if (std::cin.eof()){
		std::cout << count;
		std::cout << "\n";
	}else if(std::cin.fail()){
		std::cerr << "Error\n";
		return 1;
	}
}
