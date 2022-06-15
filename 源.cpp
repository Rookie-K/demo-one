#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h >

using namespace std;

int i, j=0, k=0, l=0,n=0, t = 0, state = 0,random;
int p1[100], p2[100], p3[100] = { 0 };
int range_int[100] = { 0 };

class Model
{
public:
	Model(char* c, int len) :_c(c)
	{
		_len = len - 1;
		string ans;
	}
	void solve()
	{
		for (int i = 0; i < _len; i++)
		{
			if (_c[i] == '{')
				cout << _c[i] << endl;
			if (_c[i] == ',' && _c[i - 1] == '"')
				cout << ',' << endl;
			if (_c[i] == ':' && _c[i + 1] == '"')
			{
				cout << ':';
				if (_c[i + 2] == 'i')
					Int(i + 2);
				/*if ( _c[i + 2] == 's')
					String(i+2);*/
				if (_c[i + 2] == 'b')
					Bool(i+2);
				for (i+=2;i < _len;i++)
				{
					if (_c[i] == '"')
						break;
				}
			}
			/*else if (_c[i] == ':' && _c[i + 1] == '[')
					Array();*/
			else
				cout << _c[i];
		}
	}
	void Int(int p)
	{
		
		int len = 0;
		int n=0,temp=0;
		int value = 0;
		if (_c[p + 3] == '(')
		{
			t = p + 4;
			i = 0;
			while (_c[t] != ')')
			{
				while (_c[t] != ',' && _c[t] != '-' && _c[t] !=')' )
				{
					temp *= 10;//0  20
					n = _c[t] - '0';
					temp += n;//2  23
					t += 1;
				}
				range_int[i++] = temp;

				if (_c[t] == ',')
					t += 1;

				else if (_c[t] == '-')
				{
					t += 1;
					temp = 0;
					while (_c[t] != ','  && _c[t] != ')')
					{
						temp *= 10;//0  20
						n = _c[t] - '0';
						temp += n;//2  23
						t++;
					}
					value = temp - range_int[i-1];//i=3
					for (;value>0;i++)
					{
						range_int[i] = range_int[i - 1] + 1;
						value--;
					}
				}
				state = 0;
				temp = 0;
			}
		}
		srand(time(0));
		random = rand() % (i-1);//i=7
		cout << range_int[random];//3,4,5,6,7,8,9
	}

	void String(int p)
	{
		if (_c[p + 6] == '(')
		{


		}
	}

	void Bool(int p)
	{
		string s1 = "true";
		string s2 = "false";
		random = rand() % 1 + 1;
		if (random == 1)
			cout << s1;
		else
			cout << s2;
	}
	void Array();
private:
	char* _c;
	int _len;
};


int main()
{
	cout << "请输入你想要的json模板文件名：" << endl;
	string name;
	int i = 1;
	cin >> name;
	ifstream ifs(name);
	if (!ifs)
	{
		cout << "json模板文件打开失败！";  return 0;
	}
	char c[1000];
	ifs >> c[0];
	while (!ifs.eof())
		ifs >> c[i++];
	if (c[0] != '{' || c[i - 2] != '}')
	{
		cout << "json模板不符合格式" << endl;
		return 0;
	}
	Model m(c,i);
	m.solve();
	ifs.close();
	return 0;
}

