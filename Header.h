#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <iterator>
#include <ctime>
using namespace std;

// граф

struct graphs
{
	// количество вершин
	int number_vertex = 0;

	// исходный граф
	vector<list<int>> source_graph;

	// дополнение исходного графа
	vector<list<int>> addition;

	// провека на пустоту
	bool empty = true;

	// создание графа
	void create_from_file(const char *filename);

	// печать графа и его дополнения
	void print();
};

// запись результатов
void write_file(int max, list<int> R);

// множества

// объединение
list<int> union_vertex(list<int> &l_a, list<int> &l_b);

// пересечение
list<int> intersection_vertex(list<int> &l_a, list<int> &l_b);

// вычитание
list<int> difference_vertex(list<int> &l_a, list<int> &l_b);

// алгоритм
//R - множество вершин максимальной клики.
//P - множество возможных вершин максимальной клики.
//X - множество исключенных вершин.
void BronKerbosch(list<int> R, list<int> P, list<int> X, graphs &G, int &max, list<int> &R_max);

// основная функция
void func();







