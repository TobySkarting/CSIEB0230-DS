#include <iostream>

enum Boolean { FALSE, TRUE };

template <typename T>
class Tree;

template <typename T>
class TreeNode {
	template <typename U>
	friend class Tree;

	template <typename U>
	friend int equal(TreeNode<U>*, TreeNode<U>*);
public:
	TreeNode() { LeftChild = RightChild = 0; };
	TreeNode(T ch) : TreeNode(ch, NULL, NULL) {	};
	TreeNode(T ch, TreeNode<T> *Lefty, TreeNode<T> *Righty)
	{
		data = ch;
		LeftChild = Lefty;
		RightChild = Righty;
	}
public:
	TreeNode<T> *LeftChild;
	T data;
	TreeNode<T> *RightChild;
};

template <typename T>
class Tree {
	friend int operator==(const Tree<T>&, const Tree<T>&);
private:
	void inorder(TreeNode<T> *);
	void preorder(TreeNode<T> *);
	void postorder(TreeNode<T> *);
	TreeNode<T>* copy(TreeNode<T> *);
public:
	TreeNode<T> *root;
	void setup();
	void inorder();
	void preorder();
	void postorder();
	Tree(const Tree<T>&);
	Tree() { root = 0; };
	Boolean Tree<T>::Insert(const TreeNode<T>& x);
};

template <typename T>
Boolean Tree<T>::Insert(const TreeNode<T>& x)
{
	TreeNode<T> *p = root;  TreeNode<T> *q = 0;
	while (p) {
		q = p;
		if (x.data == p->data) return FALSE; //x.key is already in t
		if (x.data < p->data) p = p->LeftChild;
		else p = p->RightChild;
	};

	p = new TreeNode<T>(x);
	if (!root) 
		root = p;
	else if (x.data < q->data)
		q->LeftChild = p;
	else 
		q->RightChild = p;
	return TRUE;
}

template <typename T>
void Tree<T>::setup()
{
	/*root = new TreeNode('+', 0, 0);
	root->LeftChild = new TreeNode('*', 0, 0);
	root->RightChild = new TreeNode('E', 0, 0);
	root->LeftChild->LeftChild = new TreeNode('*', 0, 0);
	root->LeftChild->RightChild = new TreeNode('D', 0, 0);
	root->LeftChild->LeftChild->LeftChild = new TreeNode('/', 0, 0);
	root->LeftChild->LeftChild->RightChild = new TreeNode('C', 0, 0);
	root->LeftChild->LeftChild->LeftChild->LeftChild = new TreeNode('A', 0, 0);
	root->LeftChild->LeftChild->LeftChild->RightChild = new TreeNode('B', 0, 0);*/
}

template <typename T>
void Tree<T>::inorder()
{
	inorder(root);
}

template <typename T>
void Tree<T>::preorder()
{
	preorder(root);
}

template <typename T>
void Tree<T>::postorder()
{
	postorder(root);
}

template <typename T>
void Tree<T>::inorder(TreeNode<T> *CurrentNode)
{
	if (CurrentNode) {
		inorder(CurrentNode->LeftChild);
		std::cout << CurrentNode->data;
		inorder(CurrentNode->RightChild);
	}
}

template <typename T>
void Tree<T>::preorder(TreeNode<T> *CurrentNode)
{
	if (CurrentNode) {
		std::cout << CurrentNode->data;
		preorder(CurrentNode->LeftChild);
		preorder(CurrentNode->RightChild);
	}
}

template <typename T>
void Tree<T>::postorder(TreeNode<T> *CurrentNode)
{
	if (CurrentNode) {
		postorder(CurrentNode->LeftChild);
		postorder(CurrentNode->RightChild);
		std::cout << CurrentNode->data;
	}
}

template <typename T>
Tree<T>::Tree(const Tree<T>& s)
{
	root = copy(s.root);
}

template <typename T>
TreeNode<T>* Tree<T>::copy(TreeNode<T> *orignode)
{
	if (orignode) {
		TreeNode *temp = new TreeNode;
		temp->data = orignode->data;
		temp->LeftChild = std::copy(orignode->LeftChild);
		temp->RightChild = std::copy(orignode->RightChild);
		return temp;
	}
	else return 0;
}

// Driver
template <typename T>
int operator==(const Tree<T>& s, const Tree<T>& t)
{
	return equal(s.root, t.root);
}

// Workhorse
template <typename T>
int equal(TreeNode<T> *a, TreeNode<T> *b)
/* This function returns 0 if the subtrees at @a@ and @b@ are not
equivalent. Otherwise, it will return 1 */
{
	if ((!a) && (!b)) return 1;  // both @a@ and @b@ are 0
	if (a && b &&                // both @a@ and @b@ are non-0
		(a->data == b->data)      // @data@ is the same
		&& equal(a->LeftChild, b->LeftChild) // left subtrees are the same
		&& equal(a->RightChild, b->RightChild)) // right subtrees are the same
		return 1;
	return 0;
}
