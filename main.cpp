#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

int main(int argc, char* argv[])
{
	char str[100];
	char letter[120] = "qwetryuiopasdfghjklzxcbvnmйцукенгшщзхъфывапрлоджэячсмитьбюёQWERTYUIOPASDFGHJKLZXCVBNMЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮЁ";
	int countW = 0, countS = 0, countSE = 0, countL = 0, countSWS = 0, len;
	if (argv[1] == NULL)
		return 0;
	FILE *fin = fopen(argv[1], "r");

	if (fin == NULL){ return 0; }

//	fin.getline(s, 100);
	//fgets(str, 100, fin);
	do
	{
		
		fgets(str, 100, fin);
		cout << str;
		len = strlen(str);
		for (int i = 0; i < len; i++)
		{
			countSWS++;
			if (str[i] == ' ')
			{
				countW++;
				countSWS--;
			}
			countS++;
			if (str[i] == '.')
				countSE++;
			else if (str[i] == '!')
				countSE++;
			else if (str[i] == '?')
				countSE++;
			for (int j = 0; j <= 119; j++)
			{
				if (str[i] == letter[j])
					countL++;
			}
		}
	} while (!feof(fin));
	cout <<"Number of words: "<< countW<< endl;
	cout << "Number of symbols: " << countS << endl;
	cout << "Number of sentences: " << countSE << endl;
	cout << "Number of letters: " << countL << endl;
	cout << "Number of symbols without spaces: " << countSWS << endl;
	_fcloseall();
	system("pause");
	return 0;
}
