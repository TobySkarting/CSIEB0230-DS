#pragma once
#include <iostream>
#include <map>

// Tested p + q; 0 + p; p + 0; p + p; 0 + 0; p + (-p)
enum Boolean { FALSE, TRUE };

template <class Type> class List;
template <class Type> class ListIterator;

struct Term
{
	int coef; // coefficient
	int exp;  // exponent
	void Init(int c, int e) { coef = c; exp = e; };
};

std::ostream& operator<<(std::ostream& os, Term e)
{
	os << e.coef << " " << e.exp;
	return os;
}

template <class Type>
class ListNode {
	friend class List<Type>;
	friend class ListIterator<Type>;
private:
	Type data;
	ListNode *link;
	ListNode(Type);
};

template <class Type>
ListNode<Type>::ListNode(Type Default)
{
	data = Default;
	link = 0;
}

template <class Type>
class List {
	friend class ListIterator<Type>;
public:
	List() { first = 0; };
	List(const List&);
	~List();
	void Attach(Type);
private:
	ListNode<Type> *first;
	ListNode<Type> *last;
};

template <class Type>
class ListIterator {
public:
	ListIterator(const List<Type>& l) : list(l), current(l.first) {};
	Boolean NotNull();
	Boolean NextNotNull();
	Type* First();
	Type* Next();
private:
	const List<Type> &list;  // refers to an existing list
	ListNode<Type>* current; // points to a node in list
};

template <class Type> //check that current element in list is non-null
Boolean ListIterator<Type>::NotNull()
{
	if (current) return TRUE;
	else return FALSE;
}

template <class Type>  // check that the next element in list is non-null
Boolean ListIterator<Type>::NextNotNull()
{
	if (current && current->link) return TRUE;
	else return FALSE;
}

template <class Type> // return a pointer to the first element of list
Type* ListIterator<Type>::First() {
	if (list.first) return &list.first->data;
	else return 0;
}

template <class Type> // return a pointer to the next element of list
Type* ListIterator<Type>::Next() {
	if (current) {
		current = current->link;
		return &current->data;
	}
	else return 0;
}

std::ostream& operator<<(std::ostream& os, List<Term>& l)
{
	ListIterator<Term> li(l);
	if (!li.NotNull()) return os;
	os << *li.First() << std::endl;
	while (li.NextNotNull())
		os << *li.Next() << std::endl;
	return os;
}


template <class Type>
void List<Type>::Attach(Type k)
{
	ListNode<Type> *newnode = new ListNode<Type>(k);
	if (first == 0) first = last = newnode;
	else {
		last->link = newnode;
		last = newnode;
	}
}

class Polynomial
{
	friend std::ostream& operator<<(std::ostream&, Polynomial&);
	friend Polynomial operator+(const Polynomial&, const Polynomial&);
private:
	List<Term> poly;
public:
	void Add(Term);
	Polynomial Multiply(const Polynomial &B);
};

void Polynomial::Add(Term e)
{
	poly.Attach(e);
}

inline Polynomial Polynomial::Multiply(const Polynomial & B)
{
	Polynomial r;
	std::map<int, int> m;

	ListIterator<Term> Aiter(this->poly);
	Term *p = Aiter.First();
	while (Aiter.NotNull())
	{
		ListIterator<Term> Biter(B.poly);
		Term *q = Biter.First();
		while (Biter.NotNull())
		{
			m[p->exp + q->exp] += (p->coef * q->coef);
			q = Biter.Next();
		}
		p = Aiter.Next();
	}

	Term tmp;
	for (std::map<int, int>::const_iterator i = m.begin(); i != m.end(); ++i)
	{
		tmp.Init(i->second, i->first);
		r.poly.Attach(tmp);
	}
	return r;
}


template <class Type>
List<Type>::List(const List<Type>& l)
{
	if (l.first == 0) { first = 0; return; }
	first = new ListNode<Type>(l.first->data);
	ListNode<Type> *newnode = first;
	for (ListNode<Type>* current = l.first->link; current; current = current->link)
	{
		newnode->link = new ListNode<Type>(current->data);
		newnode = newnode->link;
	}
}

template <class Type>
List<Type>::~List()
// Free all nodes in the chain
{
	ListNode<Type>* next;
	for (; first; first = next) {
		next = first->link;
		delete first;
	}
}

std::ostream& operator<<(std::ostream& os, Polynomial& p)
{
	os << p.poly;
	return os;
}

char compare(int a, int b)
{
	if (a == b) return '=';
	if (a < b) return '<';
	return '>';
}

Polynomial operator+(const Polynomial& a, const Polynomial& b)
{
	Term *p, *q, temp;
	ListIterator<Term> Aiter(a.poly);
	ListIterator<Term> Biter(b.poly);
	Polynomial c;

	p = Aiter.First();
	q = Biter.First();

	while (Aiter.NotNull() && Biter.NotNull()) {
		switch (compare(p->exp, q->exp)) {
		case '=':
		{
			int x = p->coef + q->coef;
			temp.Init(x, q->exp);
			if (x) c.poly.Attach(temp);
			p = Aiter.Next();
			q = Biter.Next(); // advance to next term
			break;
		}
		case '<':
			temp.Init(q->coef, q->exp);
			c.poly.Attach(temp);
			q = Biter.Next(); // next term of b
			break;
		case '>':
			temp.Init(p->coef, p->exp);
			c.poly.Attach(temp);
			p = Aiter.Next(); // next term of a
		}
	}
	while (Aiter.NotNull()) {  // copy rest of a
		temp.Init(p->coef, p->exp);
		c.poly.Attach(temp);
		p = Aiter.Next();
	}
	while (Biter.NotNull()) { // copy rest of b
		temp.Init(q->coef, q->exp);
		c.poly.Attach(temp);
		q = Biter.Next();
	}
	return c;
}
