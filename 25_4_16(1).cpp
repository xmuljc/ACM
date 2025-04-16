//Á´±íºÏ²¢

#include <iostream>

using namespace std;

struct node

{

	int val;

	node* next;

};

node* createList()
{
	struct node* head = NULL, * r = NULL;
	int x;
	cin >> x;
	while (x != -1)
	{
		struct node* p = new (struct node);
		p->val = x;
		p->next = NULL;
		if (head == NULL)
		{
			head = p;
			r = p;
		}
		else
		{
			r->next = p;
			r = p;
		}
		cin >> x;
	}
	if (r != NULL)
	{
		r->next = NULL;
	}
	return head;
}

node* merge(node* head1, node* head2)
{

	if (head1 == NULL && head2 == NULL)
	{
		return NULL;
	}
	if (head1 == NULL)
	{
		return head2;
	}
	if (head2 == NULL)
	{
		return head1;
	}
	node* head = NULL, * r = NULL;
	while (head1 != NULL && head2 != NULL)
	{
		struct node* p = new node;
		if (head1->val < head2->val)
		{
			p->val = head1->val;
			head1 = head1->next;
		}
		else
		{
			p->val = head2->val;
			head2 = head2->next;
		}
		p->next = NULL;
		if (head == NULL)
		{
			head = p;
			r = p;
		}
		else
		{
			r->next = p;
			r = p;
		}
	}
	while (head1 != NULL)
	{
		struct node* p = new node;
		p->val = head1->val;
		p->next = NULL;
		r->next = p;
		r = p;
		head1 = head1->next;
	}
	while (head2 != NULL)
	{
		struct node* p = new node;
		p->val = head2->val;
		p->next = NULL;
		r->next = p;
		r = p;
		head2 = head2->next;
	}
	return head;

}

int main()

{

	node* head1, * head2, * head3;

	head1 = createList();

	head2 = createList();

	head3 = merge(head1, head2);

	if (head3 == NULL)

	{

		cout << "-1 ";

	}

	else

	{

		node* p = head3;

		while (p != NULL)

		{

			cout << p->val << " ";

			p = p->next;

		}

	}

	return 0;

}