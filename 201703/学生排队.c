#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
	int score;
	struct node *next;
};
int main()
{
	int i;
	int n, m;
	scanf("%d %d", &n, &m);
	struct node *head, *q, *pre, *p;
	head = (struct node*)malloc(sizeof(struct node));
	head->next = NULL;
	pre = head;
	for(i = 1; i <= n; i++)
	{
		q = (struct node*)malloc(sizeof(struct node));
		q->score = i;
		q->next = NULL;
		pre->next = q;
		pre = q;
	}
	pre = head->next;
	q = pre;
	int j, k;
	int score;
	int count;
	for(i=0; i<m; i++)
	{
		scanf("%d %d", &j, &k);
		count = 1;
		pre = head->next;
		p = (struct node*)malloc(sizeof(struct node));
		p->score = j;
		p->next = NULL;
		while(pre->score!=j)
		{
			q = pre;
			pre = pre->next;
			count++;
		}
		q->next = pre->next;//删除结点 
		if(k > 0)
		{
			k++;
			while(k--)
			{
				q = pre;
				pre = pre->next;
			}
			p->next = q->next;//插入节点 
			q->next = p;
		}
		else{
			count = count + k;
			pre = head->next;
			while(count--)
			{
				q = pre;
				pre = pre->next;
			}
			p->next = q->next;
			q->next = p;
		}
	}
	pre = head->next;
	while(pre->next!=NULL)
	{
		printf("%d ", pre->score);
		pre = pre->next;
	}
	printf("%d", pre->score);
	return 0;
}
