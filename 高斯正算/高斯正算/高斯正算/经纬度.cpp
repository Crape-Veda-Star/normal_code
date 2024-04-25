//类实现：经纬度.cpp
#include"经纬度类.h"

double func_s(double x)//中央经线长度计算公式（投影后无变形）
{
	return a*(1 - pow(e_, 2)) / pow((1 - pow(e_, 2)*pow(sin(x), 2)), 3 / 2);//x=[0,angle.m_jiao_hu()]
}

JW::JW(){}

JW::JW(Angle &angJ, Angle &angW)//构造函数：初始化 经度，纬度，子午圈半径，卯酉圈半径，纬圈半径
{
	//初始化：经度，纬度
	int Jd, Jf; double Jm;
	int Wd, Wf; double Wm;


	bool flag = true;
	while (flag)
	{
		cout << "请输入经度的度、分、秒" << endl;
		cin >> Jd >> Jf >> Jm;
		this->m_J = angJ.Set_Angle(Jd, Jf, Jm);
		cout << "请输入纬度的度、分、秒" << endl;
		cin >> Wd >> Wf >> Wm;
		this->m_W = angW.Set_Angle(Wd, Wf, Wm);
		cout << "该点的经纬度为： " << endl;
		cout << "经度： ";
		m_J.m_show_Angle(m_J);
		cout << "纬度：";
		m_W.m_show_Angle(m_W);

		//初始化子午圈半径M，卯酉圈半径N，纬圈半径r
		this->M = a*(1 - pow(e_, 2)) / pow((1 - pow(e_, 2)*pow(sin(m_W.m_jiao_hu()), 2)), 3 / 2);//子午圈半径
		this->N = a / sqrt((1 - pow(e_, 2)*pow(sin(m_W.m_jiao_hu()), 2)));//卯酉圈半径
		//this->r = N*cos(m_W.m_jiao_hu());//纬圈半径

		this->nl = e__*cos(m_W.m_jiao_hu());


		cout << "请输入您所求的分带投影（3°或6°）：";
		cin >> this->m_m;
		cout << ((m_m == 3) ? "3°" : "6°") << "带时该点的带号为： " << solution_dai(this->m_J) << endl;
		this->Center_J = solution_center_J(this->m_J);
		cout << ((m_m == 3) ? "3°" : "6°") << "带时该点的中央子午线经度为： ";
		this->Center_J.m_show_Angle(solution_center_J(this->m_J));
		cout << ((m_m == 3) ? "3°" : "6°") << "该点经度与中央经线的经差为： ";
		this->m_JC = (this->m_J - this->Center_J);
		m_JC.m_show_Angle(m_JC);


		cout << "该点在高斯————克吕格投影下的直角坐标系坐标为(x,y)：";
		this->solution_x_y();
		cout << "(" << setprecision(20) << this->m_x << "," << setprecision(20) << this->m_y << ")" << endl;

		cout << endl;



		bool flag2 = true;
		while (flag2)
		{
			cout << "请输入您的选项： 1 继续计算;  2 退出程序;  3 清空页面" << endl;
			int choice; cin >> choice;
			cout << endl;

			switch (choice)
			{
			case 1:
				flag2 = false;
				break;
			case 2:
				flag = false;
				flag2 = false;
				break;
			case 3:
				flag2 = false;
				system("cls");
				break;
			default:
				cout << "输入错误，请重新输入： " << endl;
				break;
			}
		}
	}
}



int JW::solution_dai(Angle &J)//求3或6度带带号(J——经度，m——3或6度带)
{
	Angle ang1;
	Angle ang2;
	if (this->m_m == 3)
	{
		this->n = (m_J.m_jiao_hu() + ang1.Set_Angle(1, 30, 0).m_jiao_hu()) / ang2.Set_Angle(3, 0, 0).m_jiao_hu();
		return n;
	}
	else if (this->m_m == 6)
	{
		this->n = (int)(m_J.m_jiao_hu() / ang1.Set_Angle(6, 0, 0).m_jiao_hu()) + 1;
		return n;
	}

}

Angle JW::solution_center_J(Angle &J)//求中央子午线经度(m——3或6度带)
//为什么Angle为引用类型时返回的值不是正确的值，而是乱码？？？？？？？？？？？？？？？
//Angle& JW::solution_center_J(Angle &J,int m)
{
	int n = solution_dai(J);

	if (this->m_m == 3)
	{
		int nn = 3 * n;
		this->Center_J.Set_Angle(nn, 0, 0);
		//m_show_Angle(Center_J);
	}
	else if (this->m_m == 6)
	{
		int nn = 6 * n - 3;
		this->Center_J.Set_Angle(nn, 0, 0);
		//m_show_Angle(Center_J);
	}

	return this->Center_J;
}

double JW::A_definite_integral_s(double(*function)(double), double a, double b, int n)//复化梯形求积法数值积分
//function：被积函数；a：积分下限，b：积分上限，n：区间划分的段数
{
	double h = (b - a) / n;//h：每一段区间划分的距离长度
	double sum = 0;
	//或sum=(func(a) + func(b)) / 2.0;
	for (int i = 0; i < n; i++)
	{
		//或sum += func(a + h*i);
		sum += h*(func_s(a + h*i) + func_s(a + h*(i + 1))) / 2.0;
	}

	return sum;
}

void JW::solution_x_y()//求高斯投影后的平面直角坐标
{
	double a0 = this->m_s = A_definite_integral_s(func_s, 0, this->m_W.m_jiao_hu(), 1000000);  //高斯——克吕格投影的直角坐标公式：积分求s的值
	double a1 = N*cos(m_W.m_jiao_hu());
	double a2 = (1.0 / 2) * N*sin(m_W.m_jiao_hu())*cos(m_W.m_jiao_hu());
	double a3 = (1.0 / 6) * N*pow(cos(m_W.m_jiao_hu()), 3)*(1 - pow(tan(m_W.m_jiao_hu()), 2) + pow(nl, 2));
	double a4 = (1.0 / 24) * N*sin(m_W.m_jiao_hu())*pow(cos(m_W.m_jiao_hu()), 3)*(5 - pow(tan(m_W.m_jiao_hu()), 2) + 9 * pow(nl, 2) + 4 * pow(nl, 4));
	double a5 = (1.0 / 120) * N*sin(m_W.m_jiao_hu())*pow(cos(m_W.m_jiao_hu()), 5)*(5 - 18 * pow(tan(m_W.m_jiao_hu()), 2) + pow(tan(m_W.m_jiao_hu()), 4) /*+ 14 * pow(nl, 2) - 58 * pow(tan(m_W.m_jiao_hu()), 2)*pow(nl, 2)*/);
	double a6 = (1.0 / 720) * N*sin(m_W.m_jiao_hu())*pow(cos(m_W.m_jiao_hu()), 5)*(61 - 58 * pow(tan(m_W.m_jiao_hu()), 2) + pow(tan(m_W.m_jiao_hu()), 4));
	//注：公式中出现常量分数型小数时，一定要在比值的分子或分母中任意一个设置为*小数*，否则会变成该分数会转换为整数！！！！！！！！


	double JC_second = this->m_JC.m_jiao_hu()*ppp / ppp;//经差单位换算为秒
	//注：秒转弧度：除以p；弧度转秒：乘以p

	this->m_x = this->m_s + a2*pow(JC_second, 2) + a4 * pow(JC_second, 4) + a6*pow(JC_second, 6);
	this->m_y = a1*pow(JC_second, 1) + a3*pow(JC_second, 3) + a5*pow(JC_second, 5) + 5e5;
}
