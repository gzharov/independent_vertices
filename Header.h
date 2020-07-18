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

// ����

struct graphs
{
	// ���������� ������
	int number_vertex = 0;

	// �������� ����
	vector<list<int>> source_graph;

	// ���������� ��������� �����
	vector<list<int>> addition;

	// ������� �� �������
	bool empty = true;

	// �������� �����
	void create_from_file(const char *filename);

	// ������ ����� � ��� ����������
	void print();
};

// ������ �����������
void write_file(int max, list<int> R);

// ���������

// �����������
list<int> union_vertex(list<int> &l_a, list<int> &l_b);

// �����������
list<int> intersection_vertex(list<int> &l_a, list<int> &l_b);

// ���������
list<int> difference_vertex(list<int> &l_a, list<int> &l_b);

// ��������
//R - ��������� ������ ������������ �����.
//P - ��������� ��������� ������ ������������ �����.
//X - ��������� ����������� ������.
void BronKerbosch(list<int> R, list<int> P, list<int> X, graphs &G, int &max, list<int> &R_max);

// �������� �������
void func();







