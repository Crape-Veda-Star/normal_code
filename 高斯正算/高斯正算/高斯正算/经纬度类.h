//ͷ�ļ�����γ����.h
#pragma once
#include<iostream>
#include<math.h>
#include<vector>
#include"�Ƕ���.h"
using namespace std;

const double a = 6378137.0, b = 6356752.31414;//a�������������ᣨ����뾶��b���������̰��ᣨ����뾶��(��λΪkm)
//double e, e_, bl;
const double e_ = sqrt((pow(a, 2) - pow(b, 2)) / pow(a, 2)); //e_����������һƫ����
const double e__ = sqrt((pow(a, 2) - pow(b, 2)) / pow(b, 2));//e__���������ڶ�ƫ����
const double bl = (a - b) / a;//bl�����������


const double ppp = 180 / PI * 3600;


class JW :public Angle
{
public:
	Angle m_J, m_W;//���Ⱥ�γ��
	Angle Center_J;//���������߾���
	Angle m_JC;//�õ㾭�������뾭�ߵľ���
	int n;//n��ʾ3��6�ȵĴ���
	double M, N;// r;//M������������Ȧ�뾶��N��������î��Ȧ�뾶��r��������γȦ�뾶
	double nl;//nl=e'*cos(γ��)
	double m_x, m_y; //��˹ͶӰ���ƽ��ֱ������
	int m_m;//ȷ��Ҫ��ȡ���ٶȴ�
	double m_s;//���뾭�߳��ȣ�ͶӰ���ޱ��Σ�

public:
	JW();

	JW(Angle &angJ, Angle &angW);//��ʼ�������ȣ�γ��



	int solution_dai(Angle &J);//��3��6�ȴ�����,m��ʾ�����3�㻹��6���

	Angle solution_center_J(Angle &J);//�����������߾���

	//double func_s(double x);//���뾭�߳��ȼ��㹫ʽ��ͶӰ���ޱ��Σ�

	double A_definite_integral_s(double(*function)(double), double a, double b, int n);//���������������ֵ����

	void solution_x_y();//���˹ͶӰ���ƽ��ֱ������
};

