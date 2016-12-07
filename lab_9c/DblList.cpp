#include "DblList.h"

std::ostream & operator<<(std::ostream & os, const DblList<int> & list)
{
	DblListNode<int> *node = list.m_First->rlink;
	while (node != list.m_First)
	{
		os << node->data << " ";
		node = node->rlink;
	}
	return os;
}
