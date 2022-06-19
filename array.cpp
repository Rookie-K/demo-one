void Array(int p)
	{
		cout << ":[" << endl;
		int num = 0;
		i = p;
		if (_c[i + 1] == '"' && _c[i + 2] == 'r')//repeat需要进行判断！
		{
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
							cout << ',' << endl;
						else cout << endl << ']';
					}
					while (_c[i] != ']')
						i++;
					index = i;
				}
				else if (_c[i + 1] = 's')
				{
					index = 1;
					int first = 0;
					for (index = 1;index <= num;index++)
					{
						String(i + 1);
						if (index != num)
							cout << ',' << endl;
						else cout << endl;
					}
					cout << ']' << ',';
					while (_c[i] != ']')
						i++;
					index = i+1;
				}
			}
			else if (_c[i] == '{')
			{
				cout << '{' << endl;
				index = 1;
				int first = 0;
				for (index = 1;index <= num;index++)
				{
					 t= i;
					while (_c[t++] != '}')
					{
						if (_c[t] == ':' && _c[t + 1] == '"')
						{
							cout << ':';
							if (_c[t + 2] == 'i')
							{
								Int(t + 2);
								cout << ',' << endl;
								t += 2;
								while (_c[t] != '"')
									t++;
								t += 1;
							}
							else if (_c[t + 2] == 's')
							{
								String(t + 2);
								cout << ',' << endl;
								t += 2;
								while (_c[t] != '"')
									t++;
								t += 1;
							}
						}
						else
						{
							cout << _c[t];
							if (_c[t] != '}')
							{
								for (t+=1;_c[t] != '"';t++)
									cout << _c[t];
								cout << '"';
							}
						}
							
					}

				}
			}
			cout << '}';
		}
		else
		{
			j = 0;
			string* s = new string[10];//_c[i]='['
			while (_c[i++] != ']')
			{
				while ( _c[i] != ','&& _c[i] != ']')
				{
					s[j] = s[j] + _c[i];
					i++;
				}
				j++;
			}
			random = rand() % (j + 1);
			cout << s[random] << endl;
			index = i;
		}
	}
