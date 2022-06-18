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
			srand(time(0));
			random = rand() % (j - 1);
			cout << '"' << s[random] << '"';
		}
		else
		{
			cout << '"';
			char t;//97 122
			cout << number << endl;
			for (k = 1;k < number + 10;k++)
			{
				t = rand() % (122 - 97 + 1) + 97;
				cout << t;
			}
			cout<<'.' << '"' << endl;
		}
	}
