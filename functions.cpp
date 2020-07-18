#include "Header.h"


// граф


void graphs::print()
{
	cout << "количество вершин: " << number_vertex << endl << endl;

	cout << "исходный граф" << endl;
	for (int i = 0; i < number_vertex; i++)
	{
		cout << i << ":" << " ";
		for (int j : source_graph[i])
		{
			cout << j << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "дополнение" << endl;
	for (int i = 0; i < number_vertex; i++)
	{
		cout << i << ":" << " ";
		for (int j : addition[i])
		{
			cout << j << " ";
		}
		cout << endl;
	}
	cout << endl;
	
}


void write_file(int max, list<int> R)
{
	ofstream fout; fout.open("output.txt");

	fout << max <<"\n";

	for (int t : R)
	{
		fout << t << " ";
	}
	cout << endl << endl;

	fout.close();

}


void graphs::create_from_file(const char *filename)
{
	ifstream fin;

	fin.open(filename);
	if (!fin.is_open())
	{
		cout << "Ошибка чтения файла" << endl;
	}
	else
	{
		empty = false;
		fin >> number_vertex;

		source_graph.resize(number_vertex); addition.resize(number_vertex);

		int t;
		for (int i = 0; i < number_vertex; i++)
		{
			for (int j = 0; j < number_vertex; j++)
			{
				fin >> t;
				if ( (i!=j) && (t == 0) ) addition[i].push_back(j);
				else source_graph[i].push_back(j);
			}
		}

		

	}

	fin.close();
}


void print_list(list<int> &l)
{
	cout << "[ ";
	for (int t : l) {
		std::cout << t << " ";
	}
	cout <<"]"<< endl;
}


// операции с множествами

list<int> union_vertex(list<int> &l_a, list<int> &l_b)
{
	list<int> l_c;

	set_union(l_a.begin(), l_a.end(), l_b.begin(), l_b.end(), back_inserter(l_c));

	return l_c;
}


list<int> intersection_vertex(list<int> &l_a, list<int> &l_b)
{
	list<int> l_c;

	set_intersection(l_a.begin(), l_a.end(), l_b.begin(), l_b.end(), back_inserter(l_c));

	return l_c;
}


list<int> difference_vertex(list<int> &l_a, list<int> &l_b)
{
	list<int> l_c;

	set_difference(l_a.begin(), l_a.end(), l_b.begin(), l_b.end(), back_inserter(l_c));

	return l_c;
}


// алгоритм

void BronKerbosch(list<int> R, list<int> P, list<int> X, graphs &G, int &max, list<int> &R_max)
{
	if (P.empty() && X.empty())
	{
		print_list(R);
		if (R.size() > max)
		{
			R_max = R; max = R.size();
		}
	}

	auto t = P.begin();
	while (!P.empty() && (t != P.end()))
	{
		list<int> vertex = { *t };

		BronKerbosch(union_vertex(R, vertex), intersection_vertex(P, G.addition[*t]), intersection_vertex(X, G.addition[*t]), G, max, R_max);

		P = difference_vertex(P, vertex);
		X = union_vertex(X, vertex);
		t = P.begin();
	}

}


// основная функция

void func()
{
	int max = 0; list<int> R_max;

	graphs G;
	G.create_from_file("test3.txt");
	G.print();

	list<int> R, P, X;

	for (int i = 0; i < G.number_vertex; i++)
	{
		P.push_back(i);
	}

	BronKerbosch(R, P, X, G, max, R_max);
	//cout << endl << endl;
	//print_list(R_max);

	write_file(max, R_max);
}


