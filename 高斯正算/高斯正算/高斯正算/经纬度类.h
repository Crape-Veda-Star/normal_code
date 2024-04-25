//头文件：经纬度类.h
#pragma once
#include<iostream>
#include<math.h>
#include<vector>
#include"角度类.h"
using namespace std;

const double a = 6378137.0, b = 6356752.31414;//a————长半轴（赤道半径）b————短半轴（极轴半径）(单位为km)
//double e, e_, bl;
const double e_ = sqrt((pow(a, 2) - pow(b, 2)) / pow(a, 2)); //e_————第一偏心率
const double e__ = sqrt((pow(a, 2) - pow(b, 2)) / pow(b, 2));//e__————第二偏心率
const double bl = (a - b) / a;//bl————扁度


const double ppp = 180 / PI * 3600;


class JW :public Angle
{
public:
	Angle m_J, m_W;//经度和纬度
	Angle Center_J;//中央子午线经度
	Angle m_JC;//该点经线与中央经线的经差
	int n;//n表示3或6度的带号
	double M, N;// r;//M————子午圈半径，N————卯酉圈半径，r————纬圈半径
	double nl;//nl=e'*cos(纬度)
	double m_x, m_y; //高斯投影后的平面直角坐标
	int m_m;//确定要求取多少度带
	double m_s;//中央经线长度（投影后无变形）

public:
	JW();

	JW(Angle &angJ, Angle &angW);//初始化：经度，纬度



	int solution_dai(Angle &J);//求3或6度带带号,m表示求的是3°还是6°带

	Angle solution_center_J(Angle &J);//求中央子午线经度

	//double func_s(double x);//中央经线长度计算公式（投影后无变形）

	double A_definite_integral_s(double(*function)(double), double a, double b, int n);//复化梯形求积法数值积分

	void solution_x_y();//求高斯投影后的平面直角坐标
};

