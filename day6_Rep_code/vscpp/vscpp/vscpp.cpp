// vscpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void function() {
	vector<char> finalWord(8, '-');
	//load data
	vector<vector<char>> letters(8, vector<char>(1000, '-'));
	string line;
	ifstream f("input.txt");
	int n = 0;
	if (f.is_open()) {
		while (getline(f, line)) {
			for (int i = 0; i < line.size(); ++i) {
				letters[i][n] = line[i];
			}
			n++;
		}
	}
	f.close();
	//find most common in each line
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	int counts_old = 0;
	int counts_new = 0;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 26; ++j) {
			counts_new = count(letters[i].begin(),
				letters[i].end(),
				alphabet[j]);
			if (counts_new > counts_old) {
				finalWord[i] = alphabet[j];
				counts_old = counts_new;
			}
		}
		counts_old = 0;
	}
	//output solution
	for (int i = 0; i < 8; ++i) {
		cout << finalWord[i];
	}
	cout << endl;
}

int main()
{
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	function();
	high_resolution_clock::time_point t2 = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(t2 - t1).count();

	cout << duration << endl;
	char c;
	cin >> c;
	return 0;
}
