#include <iostream>
#include <locale>
#include <string>

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
	while (b != 0)
	{
		unsigned long long temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int main()
{
	std::cout.imbue(std::locale(""));

	std::cout << "유리수로 변환할 순환 소수를 입력하세요." << std::endl;

	std::string from_dec;
	std::getline(std::cin, from_dec);
	std::string from_dec_num = from_dec.substr(0, from_dec.find('.'));
	std::string from_dec_dec = from_dec.substr(from_dec.find('.') + 1);

	for (unsigned long long i = 0; i <= from_dec_num.length(); ++i)
		std::cout << '.';
	for (unsigned long long i = 1; i <= from_dec_dec.length(); ++i)
		std::cout << i;

	std::cout << std::endl << "순환 구간을 입력해 주세요. (1개만 입력합니다. 만약 순환 구간의 길이가 2 이상이면 가장 앞쪽에 있는 구간의 시작점 하나만 적습니다.)" << std::endl;
	std::string loop;
	std::getline(std::cin, loop);

	unsigned long long first = std::stoull(loop);

	std::string deno, num;
	for (unsigned long long i = 0; i < from_dec_dec.length() - first + 1; ++i)
		deno += '9';
	for (unsigned long long i = 0; i < first - 1; ++i)
		deno += '0';

	std::string full = from_dec_num + from_dec_dec;
	std::string loop_del = first - 1 == 0 ? std::string("0") : full.substr(0, first);
	unsigned long long full_int = std::stoull(full) - std::stoull(loop_del);

	unsigned long long gcd = ::gcd(full_int, std::stoull(deno));
	unsigned long long deno_int = std::stoull(deno);

	deno_int /= gcd;
	full_int /= gcd;
	deno = std::to_string(deno_int);
	num = std::to_string(full_int);
	std::cout << "변환 결과: " << num << '/' << deno << '(' << deno << "분의 " << num << ')' << std::endl;
	return 0;
}