//类实现：角度.cpp
#include"角度类.h"

Angle::Angle()//初始化角度为0°0′0″
{
	this->m_degree = make_tuple(0, 0, 0);
}

Angle& Angle::operator=(Angle &angle)//重载赋值运算符
{
	get<0>(this->m_degree) = get<0>(angle.m_degree);
	get<1>(this->m_degree) = get<1>(angle.m_degree);
	get<2>(this->m_degree) = get<2>(angle.m_degree);

	return *this;
}

Angle& Angle::operator-(Angle &angle)//角度差恒为正值
{
	Angle new_angle;
	tuple<int, int, double>deg = new_angle.m_hu_jiao(abs(this->m_jiao_hu() - angle.m_jiao_hu()));
	//测试cout << abs(this->m_jiao_hu() - angle.m_jiao_hu()) << endl;
	new_angle.Set_Angle(deg);

	*this = new_angle;//为什么当直接return new_angle时，减法运算的值不正确？？？？？？？？？？？？、
	//测试this->m_show_Angle(new_angle);
	return *this;
}

Angle& Angle::Set_Angle(int d, int f, double m)//设置角度值
{
	this->m_degree = make_tuple(d, f, m);
	return *this;
}

Angle& Angle::Set_Angle(tuple<int, int, double>degree)//设置角度值
{
	this->m_degree = degree;
	return *this;
}

tuple<int, int, double> Angle::m_hu_jiao(double radian)//弧度-->角度
{
	double Ddegree;
	Ddegree = radian*(180 / PI);//弧度-->全度的角度

	int degree = (int)Ddegree;//度			
	double temp = (Ddegree - degree) * 60;
	int minute = (int)(temp);//分
	temp = (temp - minute) * 60;
	double second = temp;//秒

	this->m_degree = make_tuple(degree, minute, second);//全度的角度-->度分秒的角度

	return this->m_degree;
}

double Angle::m_jiao_hu()//角度-->弧度
{
	double all_degree = get<0>(m_degree) +get<1>(m_degree) / 60.0 + get<2>(m_degree) / 3600.0;//角度-->全度的角度
	double radian = all_degree * PI / 180;

	return radian;
}

double Angle::m_jiao_all_jiao()//角度-->全度的角度
{
	double all_degree = get<0>(m_degree) +get<1>(m_degree) / 60.0 + get<2>(m_degree) / 3600.0;//角度-->全度的角度

	return all_degree;
}

void Angle::m_show_Angle(Angle &angle)//显示经纬度
{
	int degree = get<0>(angle.m_degree);
	int minute = get<1>(angle.m_degree);
	double second = get<2>(angle.m_degree);

	cout << setprecision(20) << degree << "°" << setprecision(20) << minute << "′" << setprecision(20) << second << "″" << "	";
	cout << endl;
}