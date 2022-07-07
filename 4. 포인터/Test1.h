#pragma once
#include<iostream>
using namespace std;

void Test_1();

void Test_2();

void Test_3();

void Test_1()
{
	Test_2();
}

void Test_2()
{
	cout << "Hello world" << endl;
}