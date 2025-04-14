#include <iostream> 
#include <ctime> 
using namespace std;
int add(int a, int b) {
	return a + b;
}
int sub(int a, int b) {
	return a - b;
}
int multiply(int a, int b) {
	return a * b;
}
int divide(int a, int b)
{
	return a / b;
}
char menu() {
	char choice;
	cout << "1) add two number\n";
	cout << "2) sub two number\n";
	cout << "3) multiply two number\n";
	cout << "4) divide two number\n";
	cout << "0) quit\n";
	cout << "Enter your choice:\n";
	cin >> choice;
	return choice;
}
bool answerQuestion(int num1, int num2, int (*f)(int, int), int answer) {
	return f(num1, num2) == answer;
}
int main() {
	srand((unsigned)time(NULL));
	int a = 0, b = 0;//a用作正确,b用作错误
	while (true) {
		if (b >= 3)
		{
			break;
		}
		char choice = menu();
		if (choice == '0')
			break;
		int num1, num2;
		do
		{
			num1 = rand() % 90 + 10;
			num2 = rand() % 90 + 10;
		} while (num1 % num2 != 0);
		//得到10~99 的整数
			decltype(add) * pf;  //函数指针，类型由decltype推断 
		char op;
		switch (choice) {
		case '1':pf = add; op = '+'; break;
		case '2':pf = sub; op = '-'; break;
		case '3':pf = multiply; op = '*'; break;
		case '4':pf = divide; op = '/'; break;
		default:continue;
		}
		int answer;
		cout << num1 << op << num2 << "=?";
		cin >> answer;
		if (answerQuestion(num1, num2, pf, answer) == true)
		{
			a = a + 1;
			cout << "Correct!" << endl;
		}
		else
		{
			b = b + 1;
			cout << "Wrong!" << endl;
		}
	}
	if (a >= 0 && b == 0)
	{
		printf("Correct sum:%i\n", a);
		printf("Wrong sum:0\n");
		printf("Correct rate:100%");
	}
	else if (a == 0 && b >= 0)
	{
		printf("Correct sum:0\n");
		printf("Wrong sum:%i\n", b);
		printf("Correct rate:0");
	}
	else
	{
		printf("Correct sum:%i\n", a);
		printf("Wrong sum:%i\n", b);
		printf("Correct rate:%lf", a * 1.0 / (b * 1.0 + a * 1.0));
	}
	return 0;
}