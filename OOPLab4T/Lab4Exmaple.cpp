#include <iostream>
#include "Lab4Exmaple.h"
#include "VectorFLoat.h"
#include "MyAssoc.h"



int mainExample1() {

	/// Задано : A,B,C,D,F  -  Вектори цілих чисел 
	///         a,b,c - задані цілі числа.
	/// Обчислити вираз : F = A+B-B*c+C/b+D*a        
	cout << "Input array size: ";
	int size = cin.get(), a, b, c;
	VectorFloat A(size, 1), B(size, 2), C(size, 3), D(size, 4), F(size, 5);
	cout << "Input a, b, c: ";
	cin >> a >> b >> c;
	cout << " A  = \n" << A;
	cout << " B  = \n" << B;
	cout << " C  = \n" << C;
	cout << " D  = \n" << D;

	F += A + B - B * c + C / b + D * a;


	cout << " \n F = \n" << F;
	cout << " ++A = \n" << ++A;
}



/// <summary>
	/// Задано : A,B,C,D,F  -  Матриці комплесних чисел
	///          a,b,c  -  Вектори комплесних чисел 
	///          _a,_b,_c - комплексні числа.
	/// Обчислити вираз : F = A+B*_a-B*_c+C/_b; 
	///                   c = F*a + D*b         
	/// </summary>
	/// <returns></returns>

int mainExample2() {
	CountyList list;
	list("Italy", "Rome");
	list("Ukraine", "Kiyv");
	cin >> list;
	cout << list;
}

