#include"Colectie.h"
#include"IteratorColectie.h"
#include<iostream>

bool rel(TElem A, TElem B)
{
	return A <= B;
}

void Colectie::checkCapacity() {
	if (num == cap)
	{
		TElem *p = new TElem[2 * cap];
		for (int i = 0; i < num; i++)
			p[i] = elems[i];
		delete elems;
		elems = p;
		cap += 10;
	}
}
Colectie::Colectie() {
	num = 0;
	cap = 10;
	elems = new TElem[cap];
}
void Colectie::adauga(TElem e)
{
	checkCapacity();
	if (num == 0)
	{
		elems[0] = e;
	}
	else
	{
		for (int i = 0; i < num; i++)
			if (rel(e, elems[i]))
			{
				for (int j = num; j > i; j--)
					elems[j] = elems[j - 1];
				elems[i] = e;
				num++;
			}
	}
}
bool Colectie::sterge(TElem e)
{
	if (rel(e, elems[0]))
		return false;
	if (rel(elems[num - 1], e))
		return false;
	for (int i = num - 1; i >= 0; i--)
		if (rel(elems[i], e) && rel(e, elems[i]))
		{
			for (int j = i; j < num - 1; j++)
				elems[j] = elems[j + 1];
			num--;
			return true;
		}
		else if (rel(elems[i], e))
			break;
	return false;
}
bool Colectie::cauta(TElem e) const
{
	for (int i = 0; i < num; i++)
		if (rel(elems[i], e) && rel(e, elems[i]))
			return true;
		else if (rel(elems[i], e))
			break;
	return false;
}

int Colectie::nrAparitii(TElem e) const
{
	int contor = 0;
	for (int i = 0; i < num; i++)
		if (rel(elems[i], e) && rel(e, elems[i]))
			contor++;
		else if (rel(elems[i], e))
			break;
	return contor;
}

int Colectie::dim() const
{
	return num;
}

bool Colectie::vida() const
{
	if (num == 0)
		return true;
	return false;
}

IteratorColectie Colectie::iterator() const {
	return IteratorColectie::IteratorColectie(*this);
}

Colectie::~Colectie() {
	delete(elems);
}
