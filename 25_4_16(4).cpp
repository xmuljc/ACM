//����һ������������������������·������У���������Ϊ�����Ľڵ�Ϊ��һ�飬��������Ϊż���Ľڵ�Ϊ�ڶ��顣��һ���ڵ㱻���������ڵ㣬�������к�������ڲ������˳��Ӧ��������ʱ����һ�¡�

#include <iostream>

using namespace std;

struct ListNode

{

	int val;

	ListNode* next;

};

ListNode* createList()

{

	ListNode* head = NULL;

	ListNode* p1, * p2;

	p1 = new ListNode;

	p2 = p1;

	cin >> p1->val;

	while (p1->val != -1)

	{

		if (head == NULL)

			head = p1;

		else p2->next = p1;

		p2 = p1;

		p1 = new struct ListNode;

		cin >> p1->val;

	}

	p2->next = NULL;

	delete p1;

	return head;

}

ListNode* oddEvenList(ListNode* head) {


	if (head == NULL || head->next == NULL)
		return head;
	ListNode* odd = head;
	ListNode* even = head->next;
	ListNode* evenHead = even;
	while (even != NULL && even->next != NULL) {
		odd->next = even->next;
		odd = odd->next;
		even->next = odd->next;
		even = even->next;
	}
	odd->next = evenHead;
	return head;

}

int main()

{

	ListNode* head;

	head = createList();

	ListNode* ans = oddEvenList(head);

	if (ans == NULL)

		cout << "-1";

	else

	{

		while (ans != NULL)

		{

			cout << ans->val << " ";

			ans = ans->next;

		}

	}

	return 0;

} 