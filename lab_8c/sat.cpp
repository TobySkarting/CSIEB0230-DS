#ifndef _IOSTREAM_H
#include <iostream>
#define _IOSTREAM_H
#endif

enum TypesOfData {LogicalNot, LogicalAnd, LogicalOr,
		  LogicalTrue, LogicalFalse};

class SatTree;

class SatNode {
friend class SatTree;
private:
    SatNode *LeftChild;
    TypesOfData data;
    bool value;
    SatNode *RightChild;
    SatNode() {LeftChild = RightChild = 0;};
    SatNode(TypesOfData tod, SatNode *Lefty, SatNode *Righty)
    {
	data = tod;
	LeftChild = Lefty;
	RightChild = Righty;
    }
};

class SatTree {
private:
    SatNode *root;
    void PostOrderEval(SatNode *);
public:
    void PostOrderEval();
    SatTree() {root = 0;};
    void setup();
    void rootvalue() {std::cout << root->value;};
};

void SatTree::setup()
{
    root = new SatNode(LogicalOr,0,0);
    root->LeftChild = new SatNode(LogicalOr,0,0);
    root->LeftChild->LeftChild = new SatNode(LogicalAnd, 0, 0);
	root->LeftChild->LeftChild->LeftChild = new SatNode(LogicalFalse, 0, 0);
	root->LeftChild->LeftChild->RightChild = new SatNode(LogicalNot, 0, 0);
	root->LeftChild->LeftChild->RightChild->RightChild = new SatNode(LogicalTrue, 0, 0);


	root->LeftChild->RightChild = new SatNode(LogicalAnd, 0, 0);
	root->LeftChild->RightChild->LeftChild = new SatNode(LogicalNot, 0, 0);
	root->LeftChild->RightChild->LeftChild->RightChild = new SatNode(LogicalFalse, 0, 0);
	root->LeftChild->RightChild->RightChild = new SatNode(LogicalTrue, 0, 0);


    root->RightChild = new SatNode(LogicalAnd, 0, 0);
	root->RightChild->LeftChild = new SatNode(LogicalTrue, 0, 0);
	root->RightChild->RightChild = new SatNode(LogicalNot, 0, 0);
	root->RightChild->RightChild->RightChild = new SatNode(LogicalFalse, 0, 0);
}

void SatTree::PostOrderEval()
{
    PostOrderEval(root);
}

void SatTree::PostOrderEval(SatNode *s)
{
    if(s) {
	PostOrderEval(s->LeftChild);
	PostOrderEval(s->RightChild);
	switch (s->data) {
		case LogicalNot: s->value = ! s->RightChild->value; break;
		case LogicalAnd: s->value = s->LeftChild->value && s->RightChild->value;
				 break;
		case LogicalOr: s->value = s->LeftChild->value || s->RightChild->value;
				break;
		case LogicalTrue: s->value = true; break;
		case LogicalFalse: s->value = false;
	}
    }
}

int main()
{
	SatTree t;
	t.setup();
	t.PostOrderEval();
	t.rootvalue();
	return 0;
}

