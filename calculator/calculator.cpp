#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	float sum = 0, fact = 1;
	float first_num, second_num;
	char operation;
	char operations[] = { '+', '-', '*', '/', '^', 'v', '%', '!', 'q' };

	while (true)
	{
		cout << "Введите операцию (+, -, *, /, ^, v, %, !) или выйдите из программы (q): ";
		cin >> operation;

		int flag = 0;

		for (int i = 0; i < sizeof(operations); i++)
		{
			if (operation != operations[i])
				flag++;
		}
			
		if (flag == sizeof(operations))
		{
			cout << "Вы ввели неверный оператор! Попробуйте снова\n";
			continue;
		}

		if (operation == 'q')
		{
			cout << "Итоговое значение: " << sum << "\n";
			return 0;
		}
	
		cout << "Введите число: ";
		cin >> first_num;

		if (operation != '%' && operation != 'v' && operation != '!')
		{
			cout << "Введите второе число: ";
			cin >> second_num;
		}

		switch (operation)
		{
		case '+':
			sum += first_num + second_num;
			break;
		case '-':
			sum += first_num - second_num;
			break;
		case '*':
			sum += first_num * second_num;
			break;
		case '/':
			if (second_num == 0) cout << "На ноль делить нельзя\n"; break;
			sum += first_num / second_num;
			break;
		case '^':
			sum += std::pow(first_num, second_num);
			break;
		case 'v':
			sum += std::sqrt(first_num);
			break;
		case '%':
			sum += first_num / 100;
			break;
		case '!':
			for (int i = 1; i <= first_num; i++) fact *= i;
			sum += fact;
			break;
		default:
			break;
		}

		cout << "Ответ: " << sum << "\n\n";
		sum = 0;
		fact = 1;
	}	
}