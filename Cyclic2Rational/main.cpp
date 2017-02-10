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

	std::cout << "�������� ��ȯ�� ��ȯ �Ҽ��� �Է��ϼ���." << std::endl;

	std::string from_dec;
	std::getline(std::cin, from_dec);
	std::string from_dec_num = from_dec.substr(0, from_dec.find('.'));
	std::string from_dec_dec = from_dec.substr(from_dec.find('.') + 1);

	for (unsigned long long i = 0; i <= from_dec_num.length(); ++i)
		std::cout << '.';
	for (unsigned long long i = 1; i <= from_dec_dec.length(); ++i)
		std::cout << i;

	std::cout << std::endl << "��ȯ ������ �Է��� �ּ���. (1���� �Է��մϴ�. ���� ��ȯ ������ ���̰� 2 �̻��̸� ���� ���ʿ� �ִ� ������ ������ �ϳ��� �����ϴ�.)" << std::endl;
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
	std::cout << "��ȯ ���: " << num << '/' << deno << '(' << deno << "���� " << num << ')' << std::endl;
	return 0;
}