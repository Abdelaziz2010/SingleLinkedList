#include<iostream>
using namespace std;
template<class T>
class Node
{
public:
	T value;
	Node* next;
};
template <class L>
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
		if (head == NULL)
			return;

		while (head)
		{
			Node<L>* temp = head->next;
			delete head;
			head = temp;
		}
	}
	void Add(L value)//insert at front
	{
		Node<L>*n=new Node<L>;
		n->value = value;
		if (head == NULL)
		{
			head = n;
			n->next = NULL;
		}
		else
		{
			n->next = head;
			head = n;
		}
		
	}
	void PrintAll()
	{
		if (head == NULL)
			return;
		Node<L>* temp = head;
		while (temp)
		{
			cout << temp->value << endl;
			temp = temp->next;
		}
	}
};
int main()
{
	LinkedList<double> list;
	while (true)
	{
		cout << "please enter any number and enter -1 to terminate: " << endl;
		double n;
		cin >> n;
		if (n == -1)
			break;

		list.Add(n);
	}
	list.PrintAll();

	return 0;
}