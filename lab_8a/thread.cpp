#ifndef _IOSTREAM_H
#include <iostream>
#define _IOSTREAM_H
#endif

enum Boolean { FALSE, TRUE};

template <typename T>
class ThreadedTree;

template <typename T>
class ThreadedNode {
 template <typename U> friend class ThreadedTree;
 template <typename U> friend class ThreadedInorderIterator;
private:
    Boolean LeftThread;
    ThreadedNode<T> *LeftChild;
    T data;
    ThreadedNode<T> *RightChild;
    Boolean RightThread;

    ThreadedNode() {LeftChild = RightChild = 0;};
	ThreadedNode(const T& ch) { data = ch; };
    ThreadedNode(const T& ch, ThreadedNode<T> *lefty, ThreadedNode<T> *righty,
		 Boolean lthread, Boolean rthread)
    { data = ch; LeftChild = lefty; RightChild = righty;
      LeftThread = lthread;  RightThread = rthread;};
};

template <typename T>
class ThreadedTree {
template <typename U> friend class ThreadedInorderIterator;
private:
    ThreadedNode<T> *root;
public:
    void setup();
    ThreadedTree() {
	root = new ThreadedNode<T>;
	root->RightChild = root->LeftChild = root;
	root->LeftThread = TRUE; root->RightThread = FALSE;
    };
    void InsertRight(ThreadedNode<T>*, T);
    ThreadedNode<T>* InorderSucc(ThreadedNode<T>*);
};

template <typename T>
ThreadedNode<T>* ThreadedTree<T>::InorderSucc(ThreadedNode<T> *current)
{
    ThreadedNode<T> *temp = current->RightChild;
    if (! current->RightThread)
       while (! temp->LeftThread) temp = temp->LeftChild;
    return temp;
}

template <typename T>
void ThreadedTree<T>::InsertRight(ThreadedNode<T> *s, T ch)
// Create node @r@; store @ch@ in @r@; insert @r@ as the right child of @s@
{
    ThreadedNode<T> *r = new ThreadedNode<T>(ch);
    r->RightChild = s->RightChild;
    r->RightThread = s->RightThread;
    r->LeftChild = s;
    r->LeftThread = TRUE; // \fILeftChild\fR is a thread
    s->RightChild = r; // attach @r@ to @s@
    s->RightThread = FALSE;
    if (! r->RightThread) {
	ThreadedNode<T> *temp = InorderSucc(r); // returns the inorder successor of @r@
	temp->LeftChild = r;
    }
}

template <typename T>
class ThreadedInorderIterator {
public:
   void Inorder();
   T *Next();
   ThreadedInorderIterator(ThreadedTree<T> tree): t (tree) {
       CurrentNode = t.root;
   };
private:
   ThreadedTree<T> t;
   ThreadedNode<T> *CurrentNode;
};

template <typename T>
T* ThreadedInorderIterator<T>::Next()
// Find the inorder successor of \fICurrentNode\fR in a threaded binary tree
{
    ThreadedNode<T> *temp = CurrentNode->RightChild;
    if (! CurrentNode->RightThread)
       while (! temp->LeftThread) temp = temp->LeftChild;
    CurrentNode = temp;
    if (CurrentNode == t.root) return 0; // all tree nodes have been traversed
    else return &CurrentNode->data;
}

template <typename T>
void ThreadedInorderIterator<T>::Inorder()
{
    for (T *ch = Next(); ch; ch = Next()) std::cout << *ch << std::endl;
}


template <typename T>
void ThreadedTree<T>::setup()
{
    ThreadedNode<T> *A, *B, *C, *D, *E, *F, *G, *H, *I;

    root->LeftChild = A = new ThreadedNode<T>('A', 0, 0, FALSE, FALSE);
    root->LeftThread = FALSE;

    A->LeftChild = B = new ThreadedNode<T>('B', 0, 0, FALSE, FALSE);
    A->RightChild = C = new ThreadedNode<T>('C', 0, 0, FALSE, FALSE);

    B->LeftChild = D = new ThreadedNode<T>('D', 0, 0, FALSE, FALSE);
    B->RightChild = E = new ThreadedNode<T>('E', 0, 0, TRUE, TRUE);

    D->LeftChild = H = new ThreadedNode<T>('H', 0, 0, TRUE, TRUE);
    D->RightChild = I = new ThreadedNode<T>('I', 0, 0, TRUE, TRUE);

    C->LeftChild = F = new ThreadedNode<T>('F', 0, 0, TRUE, TRUE);
    C->RightChild = G = new ThreadedNode<T>('G', 0, 0, TRUE, TRUE);

    H->LeftChild = root; H->RightChild = D;
    I->LeftChild = D; I->RightChild = B;
    E->LeftChild = B; E->RightChild = A;
    F->LeftChild = A; F->RightChild = C;
    G->LeftChild = C; G->RightChild = root;

    InsertRight(A, 'X');
    InsertRight(E, 'Y');
}



int main()
{
	ThreadedTree<int> t;
	t.setup();
	ThreadedInorderIterator<int> ti(t);
	ti.Inorder();
	return 0;
}

