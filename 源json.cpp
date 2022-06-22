#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h >
using namespace std;


int i, j = 0, k = 0, l = 0, n = 0, number = 0, t = 0, state = 0, random, m, index;
int temp_i = 0, temp_index = 0;
int range_int[100] = { 0 };
int temp_int[100] = { 0 };
ofstream ofs("json作业.txt", ios::out);

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
		for (int i = 0; i < _len - 1; i++)
		{
			if (_c[i] == '{')
			{
				ofs << _c[i] << endl;
				i++;
			}
			if (_c[i] == ',' && _c[i + 1] == '"')
			{
				ofs << ',' << endl;
				i++;
			}
			if (_c[i] == '}')
			{
				ofs << "}," << endl;
				i += 2;
			}
			if (_c[i] == ':' && _c[i + 1] == '"')
			{
				ofs << ':';
				if (_c[i + 2] == 'i')
					Int(i + 2);
				else if (_c[i + 2] == 's')
					String(i + 2);
				else if (_c[i + 2] == 'b')
					Bool(i + 2);
				for (i += 2;i < _len;i++)
				{
					if (_c[i] == '"')
						break;
				}
			}
			else if (_c[i] == ':' && _c[i + 1] == '[')
			{
				Array(i + 1);
				i = temp_index;
			}
			else
				ofs << _c[i];
		}
		ofs << '}';
	}


	void Int(int p)
	{
		int n = 0, temp = 0;
		int value = 0;
		if (_c[p + 3] == '(')
		{
			t = p + 4;
			j = 0;
			k = 0;
			while (_c[t] != ')')
			{
				while (_c[t] != ',' && _c[t] != '-' && _c[t] != ')')
				{
					temp *= 10;//0  20
					n = _c[t] - '0';
					temp += n;//2  23
					t += 1;
				}
				range_int[j++] = temp;
				if (_c[t] == ',')
					t += 1;

				else if (_c[t] == '-')
				{
					t += 1;
					temp = 0;
					while (_c[t] != ',' && _c[t] != ')')
					{
						temp *= 10;//0  20
						n = _c[t] - '0';
						temp += n;//2  23
						t++;
					}
					value = temp - range_int[j - 1];//i=3
					for (;value > 0;j++, k++)
					{
						range_int[j] = range_int[j - 1] + 1;
						value--;
					}
				}
				state = 0;
				temp = 0;
			}
			for (k = 0;k < j;k++)
				temp_int[k] = range_int[k];
			random = rand() % (j - 1);//i=7
			number = j;
			m = random;
			ofs << range_int[random];//3,4,5,6,7,8,9
			memset(range_int, 0, sizeof(range_int));
		}
		else
			ofs << temp_int[m];
	}


	void String(int p)
	{
		char c;
		string* s = new string[10];
		t = p + 6;
		j = 0;
		if (_c[p + 6] == '(')
		{
			while (_c[t++] != ')')
			{
				if (_c[t] == '\'' && _c[t + 1] != ',')
				{
					for (t = t + 1;_c[t] != '\'';t++)
					{
						c = _c[t];
						s[j] = s[j] + c;
					}
					j++;
				}
			}
			random = rand() % (j - 1);
			ofs << '"' << s[random] << '"';
		}
		else
		{
			ofs << '"';
			char t;
			t = rand() % (90 - 65 + 1) + 65;//大写
			ofs << t;
			j = rand() % (6 - 2 + 1) + 2;//空格
			for (k = 1;k < temp_int[number - 1] + 10;k++)
			{
				t = rand() % (122 - 97 + 1) + 97;//小写
				ofs << t;
				p = k;
				if (p == j)
				{
					ofs << ' ';
					j = rand() % (6 - 2 + 1) + 2;
					j += p;
				}
			}
			ofs << '.' << '"' << endl;
		}
	}


	void Bool(int p)
	{
		string s1 = "true";
		string s2 = "false";
		random = rand() % 1 + 1;
		if (random == 1)
			ofs << s1;
		else
			ofs << s2;
	}


	void Array(int p)
	{
		ofs << ":";
		int num = 0;
		i = p;
		if (_c[i + 1] == '"' && _c[i + 2] == 'r')//repeat需要进行判断！
		{
			ofs << '[' << endl;
			i = i + 8;
			while (_c[i] != ']')
			{
				num *= 10;
				num = _c[i] - '0';
				i++;
			}
			i += 3;
			if (_c[i] == '"')
			{
				if (_c[i + 1] == 'i')
				{
					index = 1;
					int first = 0;
					for (index = 1;index <= num;index++)
					{
						Int(i + 1);
						if (index != num)
							ofs << ',' << endl;
						else ofs << endl << ']' << ',' << endl;;
					}
					while (_c[i] != ']')
						i++;
					temp_index = i + 1;
				}
				else if (_c[i + 1] = 's')
				{
					index = 1;
					int first = 0;
					for (index = 1;index <= num;index++)
					{
						String(i + 1);
						if (index != num)
							ofs << ',' << endl;
						else ofs << endl;
					}
					ofs << ']' << ',' << endl;;
					while (_c[i] != ']')
						i++;
					temp_index = i + 1;
				}
			}
			else if (_c[i] == '{')
			{
				ofs << '{' << endl;
				index = 1;
				int first = 0;
				for (index = 1;index <= num;index++)
				{
					temp_i = i;
					while (_c[temp_i++] != '}')
					{
						if (_c[temp_i] == ':' && _c[temp_i + 1] == '"')
						{
							ofs << ':';
							if (_c[temp_i + 2] == 'i')
							{
								Int(temp_i + 2);
								ofs << ',' << endl;
								temp_i += 2;
								while (_c[temp_i] != '"')
									temp_i++;
								temp_i += 1;
							}
							else if (_c[temp_i + 2] == 's')
							{
								String(temp_i + 2);
								ofs << ',' << endl;
								temp_i += 2;
								while (_c[temp_i] != '"')
									temp_i++;
								temp_i += 1;
							}
						}
						else
						{
							ofs << _c[temp_i];
							if (_c[temp_i] != '}')
							{
								for (temp_i += 1;_c[temp_i] != '"';temp_i++)
									ofs << _c[temp_i];
								ofs << '"';
							}
						}
					}
					ofs << '}' << endl;
				}
				ofs << ']' << endl;
				i = temp_i;
				temp_index = temp_i;
			}
		}
		else
		{
			j = 0;
			string* s = new string[10];//_c[i]='['
			while (_c[i++] != ']')
			{
				while (_c[i] != ',' && _c[i] != ']')
				{
					s[j] = s[j] + _c[i];
					i++;
				}
				j++;
			}
			random = rand() % (j + 1);
			ofs << s[random] << ',' << endl;
			temp_index = i;
		}
	}
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

	if (!ofs)
	{			//判断文件打开是否成功
		cout << "写文件时，文件打开失败" << endl;
		return 0;
	}
	else
		cout << "json作业.json生成成功" << endl;
	Model m(c, i);
	m.solve();
	ifs.close();
	return 0;
}

