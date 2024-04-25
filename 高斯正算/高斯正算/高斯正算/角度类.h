//头文件：角度类.h
#pragma once
#include<iostream>
#include <iomanip>
#include<tuple>
using namespace std;
//radian————弧度;degree————角度

const double PI = 3.14;
const double e = 2.71828182845904523536;

class Angle
{
public:
	tuple<int, int, double>m_degree;//角度之度分秒

public:
	Angle();//初始化角度为0°0′0″ √

	Angle& operator=(Angle &angle);//重载=运算符

	Angle& operator-(Angle &angle);//重载-运算符

	Angle& Set_Angle(int d, int f, double m);//设置角度 √

	Angle& Set_Angle(tuple<int, int, double>degree);

	tuple<int, int, double> m_hu_jiao(double radian);//弧度转角度 √

	double m_jiao_hu();//角度转弧度 √

	double m_jiao_all_jiao();//角度-->全度的角度

	void m_show_Angle(Angle &angle);//显示角度 √

private:

};