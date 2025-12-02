#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include "C:\Users\Usuario\Desktop\Segundo\PRA\Práctica2\PRA_2324_P1\ListLinked.h"

template <typename V>
class HashTable : public Dict<V>
{

private:
	int n;
	int max;
	ListLinked<TableEntry<V>> *table;

public:
	int h(string key)
	{
		int valor = stoi(key);
		int res = valor % n;
		return res;
	}
	HashTable(int size)
	{
		ListLinked<TableEntry<V>> table = new ListLinked<TableEntry<V>>[size];
		n = 0;
		max = size;
	}
	~HashTable()
	{
		delete[] table;
	}
	int capacity()
	{
		return max;
	}
	friend ostream &operator<<(ostream &out, const HashTable<V> &th)
	{
		for (int i = 0; i < th.max; i++)
		{
			out << "Cubeta " << i << ": ";
			ListLinked<TableEntry<V>> &contenido = th.table[i];
			if (contenido.empty())
			{
				out << "Vacia";
			}
			else
			{
				out << contenido;
			}
			out << endl;
		}
		return out;
	}
	V operator[](string key)
	{
		int index = h(key);
		ListLinked<TableEntry<V>> &contenido = table[index];
		if (contenido == 0)
		{
			throw runtime_error("La cubeta esta vacía");
		}
		else
			return contenido;
	}
};

#endif
