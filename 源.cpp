#include <iostream>
#include <string>
#include <fstream>
//#define INT 0;
//#define STRING 1;
//#define BOOL 2;
//#define ARRAY 3;
using namespace std;

int i, j=0, k=0, l=0,n=0, t = 0, state = 0;
int p1[100], p2[100], p3[100] = { 0 };

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
			else if (_c[i] == ',' && _c[i - 1] == '"')
				cout << _c[i] << endl;
			else if (_c[i] == ':' && _c[i + 1] == '"')
			{
				cout << ':' << '"';
				if (_c[i + 2] == 'i')
					Int(i + 2);
				/*if ( _c[i + 2] == 's')
					String();
				if (_c[i + 2] == 'b')
					Bool();*/
			}
			/*else if (_c[i] == ':' && _c[i + 1] == '[')
					Array();*/
			else
				cout << _c[i];
		}
	}
	void Int(int p)
	{
		int begin=0,end=0;
		int range_int[10] = { 0 };
		int len = 0;
		if (_c[p + 3] == '(')
		{
			t = p + 3;
			i = 0;
			while (_c[t++] != ')')
				len++;
			while(_c[t++]!='"')
			{
				if (_c[t + 1] == ',')
				{
					range_int[i++] = _c[t] - '0';
				}
				if (_c[t + 1] == '-')
				{
					begin =_c[t] - '0';
					range_int[i++] = begin ;
					end = _c[t + 2] - '0';
					for (;i < (end - begin);i++)
						range_int[i] = ++begin;
				}
					

			}

		}
		

	}
	void String();
	void Bool();
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
	/*for (int j = 0; j < i - 1; j++)
		cout << c[j];*/
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

