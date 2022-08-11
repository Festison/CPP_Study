#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

int main()
{
	// �ڷᱸ�� (�����͸� �����ϴ� ����)
	// �˰����� (�����͸� ��� ����� ���ΰ�?)

	// find      ã�´�
	// find_if	 ���ǿ� �°� ã�´�
	// count	 ����
	// count_if	 ���ǿ� �°� ����	
	// all_of	 ��� �����Ͱ� ~~�Դϱ�?
	// any_of	 ~~�����Ͱ� �ϳ��� �ֽ��ϱ�?
	// none_of	 ��� �����Ͱ� ~~�� �ƴմϱ�?
	// for_each	 ��� �����Ϳ� �����Ѵ�.
	// remove	 �����Ѵ�
	// remove_if ������ �°� �����Ѵ�		

	srand(static_cast<unsigned int>(time(nullptr)));

	vector<int> v;

	for (int i = 0; i < 100; i++)
	{
		int num = rand() % 100;
		v.push_back(num);
	}

	// Q1) number��� ���ڰ� ���Ϳ� �ִ��� üũ�ϴ� ��� (bool, ù ���� iterator)
	{
		int number = 50;

		bool found = false;
		vector<int>::iterator it = v.end();

		for (int i = 0; i < v.size(); i++)
		{
			int data = v[i];
			if (data == number)
			{
				found = true;
				it = v.begin() + i;
				break;
			}
		}

		vector<int>::iterator itFind = find(v.begin(), v.end(), number);
		if (itFind == v.end())
		{
			cout << "��ã����" << endl;
		}
		else
		{
			cout << "ã����" << endl;
		}
	}

	// Q2) 11�� ������ ���ڰ� ���Ϳ� �ִ��� üũ�ϴ� ��� (bool, ù ���� iterator)
	{
		bool found = false;
		vector<int>::iterator it;

		for (unsigned int i = 0; i < v.size(); i++)
		{
			int data = v[i];
			if (data % 11 == 0)
			{
				found = true;
				it = v.begin() + i;
				break;
			}
		}

		struct CanDivideBy11
		{
			bool operator() (int n)
			{
				return (n % 11) == 0;
			}
		};

		vector<int>::iterator itFind = find_if(v.begin(), v.end(), CanDivideBy11());
		if (itFind == v.end())
		{
			cout << "��ã����" << endl;
		}
		else
		{
			cout << "ã����" << endl;
		}
	}

	// Q3) Ȧ���� ������ ������? (count)
	{
		int count = 0;

		for (unsigned int i = 0; i < v.size(); i++)
		{
			int data = v[i];
			if (data % 2 != 0)
			{
				count++;
			}
		}

		struct IsOdd
		{
			bool operator() (int n)
			{
				return (n % 2) != 0;
			}
		};

		int n = count_if(v.begin(), v.end(), IsOdd());

		// ��� �����Ͱ� Ȧ���Դϱ�?
		bool b1 = all_of(v.begin(), v.end(), IsOdd());
		// Ȧ���� �����Ͱ� �ϳ��� �ֽ��ϰ�?
		bool b2 = any_of(v.begin(), v.end(), IsOdd());
		// ��� �����Ͱ� Ȧ���� �ƴմϱ�?
		bool b3 = none_of(v.begin(), v.end(), IsOdd());

	}

	// Q4) ���Ϳ� �� �ִ� ��� ���ڵ鿡 3�� �����ּ���!
	{
		for (unsigned int i = 0; i < v.size(); i++)
		{
			v[i] *= 3;
		}

		struct MultiplyBy3
		{
			void operator() (int& n)
			{
				n = n * 3;
			}
		};

		for_each(v.begin(), v.end(), MultiplyBy3());
	}

	// Ȧ���� �����͸� �ϰ� ����
	{
		v.clear();

		v.push_back(1);
		v.push_back(4);
		v.push_back(3);
		v.push_back(5);
		v.push_back(8);
		v.push_back(2);

		// 1 4 3 5 8 2

		// 4 8 2 

		struct IsOdd
		{
			bool operator ()(int n)
			{
				return (n % 2) != 0;
			}
		};

		v.erase(remove_if(v.begin(), v.end(), IsOdd())); // remove_if�� erase�� �Բ����

	}

	return 0;

}