/*
    CYCLE DETECTION
    Given a linked list, detect if a cycle exists
    Print Yes if it exists, else No
*/
#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode
{
public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int node_data)
    {
        this->data = node_data;
        this->next = nullptr;
    }
};

class SinglyLinkedList
{
public:
    SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;

    SinglyLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(int node_data)
    {
        SinglyLinkedListNode *node = new SinglyLinkedListNode(node_data);

        if (!this->head)
        {
            this->head = node;
        }
        else
        {
            this->tail->next = node;
        }

        this->tail = node;
    }
};

void print_singly_linked_list(SinglyLinkedListNode *node, string sep, ofstream &fout)
{
    while (node)
    {
        fout << node->data;

        node = node->next;

        if (node)
        {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode *node)
{
    while (node)
    {
        SinglyLinkedListNode *temp = node;
        node = node->next;

        free(temp);
    }
}

string Has_Cycle(SinglyLinkedListNode *head)
{
    SinglyLinkedListNode *slow = head;
    SinglyLinkedListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return " Yes, Cycle exists!";
        }
    }
    return " No, Cycle doesn't exist!";
}

int main()
{
    cout << " Enter the number of linked lists : ";
    int tests;
    cin >> tests;

    for (int tests_itr = 0; tests_itr < tests; tests_itr++)
    {
        cout<<" Enter the number of nodes : ";
        int index;
        cin >> index;
        
         

        SinglyLinkedList *llist = new SinglyLinkedList();

        cout << " For every LL enter the list count : ";
        int llist_count;
        cin >> llist_count;
    
        cout << " Then enter the nodes starting from the head in sequential order,\n every node pointing to the next one : ";

        for (int i = 0; i < llist_count; i++)
        {
            int llist_item;
            cin >> llist_item;

            llist->insert_node(llist_item);
        }

        SinglyLinkedListNode *extra = new SinglyLinkedListNode(-1);
        SinglyLinkedListNode *temp = llist->head;

        for (int i = 0; i < llist_count; i++)
        {
            if (i == index)
            {
                extra = temp;
            }

            if (i != llist_count - 1)
            {
                temp = temp->next;
            }
        }

        temp->next = extra;

        string result = Has_Cycle(llist->head);

        cout << result << "\n";
    }
    return 0;
}

/* This code is contributed by Shruti Avhad */
