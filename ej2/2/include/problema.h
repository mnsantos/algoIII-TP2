#ifndef PROBLEMA_H
#define PROBLEMA_H

#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <cassert>
#include <algorithm>

using namespace std;

struct Problema{
	void resolver();
	Problema (istream&);
	void mostrarResultado (ostream&);
};

#endif
