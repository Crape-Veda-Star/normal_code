//ͷ�ļ����Ƕ���.h
#pragma once
#include<iostream>
#include <iomanip>
#include<tuple>
using namespace std;
//radian������������;degree���������Ƕ�

const double PI = 3.14;
const double e = 2.71828182845904523536;

class Angle
{
public:
	tuple<int, int, double>m_degree;//�Ƕ�֮�ȷ���

public:
	Angle();//��ʼ���Ƕ�Ϊ0��0��0�� ��

	Angle& operator=(Angle &angle);//����=�����

	Angle& operator-(Angle &angle);//����-�����

	Angle& Set_Angle(int d, int f, double m);//���ýǶ� ��

	Angle& Set_Angle(tuple<int, int, double>degree);

	tuple<int, int, double> m_hu_jiao(double radian);//����ת�Ƕ� ��

	double m_jiao_hu();//�Ƕ�ת���� ��

	double m_jiao_all_jiao();//�Ƕ�-->ȫ�ȵĽǶ�

	void m_show_Angle(Angle &angle);//��ʾ�Ƕ� ��

private:

};