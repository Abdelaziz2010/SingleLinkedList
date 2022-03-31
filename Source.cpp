#include <iostream>
using namespace std;

template <class T>
struct Node
{
	T Value;
	Node* Next;
};

template <typename L>
class LinkedList
{
private:
	Node<L>* head;

public:
	LinkedList()
	{
		head = NULL;
	}

	~LinkedList()
	{
		if (!head)
			return;
		
		while (head)
		{
			Node<L>* temp = head->Next;
			delete head;
			head = temp;
		}
	}

	void Add(L value)
	{
		Node<L>* n = new Node<L>;
		n->Value = value;
		if (!head)
		{
			head = n;
			n->Next = NULL;
		}
		else
		{
			n->Next = head;
			head = n;
		}
	}

	void PrintAll()
	{
		if (!head)
			return;
		Node<L>* temp = head;
		while (temp)
		{
			cout << temp->Value << endl;
			temp = temp->Next;
		}
	}
};

void main()
{
	LinkedList<double> l;
	while (true)
	{
		cout << "Please enter any number, to terminate, enter -1: ";
		double n;
		cin >> n;
		if (n == -1)
			break;
		l.Add(n);
	}

	l.PrintAll();
}