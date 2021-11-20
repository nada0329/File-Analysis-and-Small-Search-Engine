#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
#include<string>
#include<string.h>
using namespace std;

typedef string ListElemType;
class LinkedList {
public:
    LinkedList();
    bool add_node( ListElemType& item,int& line);
	bool add_node_at_position(ListElemType& item,int& line,int& pos);
	int find_node( ListElemType& item , int *rep_pos );
    int numof_node();
	ListElemType display_node(int& pos);
	bool delete_node(int& pos);
	void sort_node();
	void update_val(const ListElemType& item, int& pos) ; 
	void access_count( int& pos , int counnt);
	int get_count(int pos);
	int get_linenum(int pos);
	~LinkedList();

private:
    struct Node; // Forward declaration of structure
   // typedef Node* Link;
    struct Node {
        ListElemType element;
		int line_num;
		int countt;
        Node* next;
    };
    Node* head;
    Node* tail;
    //Node* current;
};


#endif
