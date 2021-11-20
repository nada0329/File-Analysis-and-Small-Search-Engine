#include "linked_list.h"


LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
   // current = NULL;
}
LinkedList::~LinkedList()
{
    int num,i =0;
    for(i=1;i<=num;i++)
        delete_node(i);
}

bool LinkedList::add_node( ListElemType& item, int& line)
{
    Node* addedNode = new Node;
    if (addedNode == NULL) {
        return false; // allocation failed
    }
    else {
        addedNode->element = item;
		addedNode->line_num = line;
        addedNode->next = NULL;
        if (head == NULL) {
            // check when the list is  empty
            head = addedNode;
			head ->next=NULL;
        }
        else {
            tail->next = addedNode;
        }
        tail = addedNode;
        return true;
    }
}

bool LinkedList::add_node_at_position( ListElemType& item, int& line, int& pos)
{
	Node  *ptr , *s;   int counter=0;
	Node* addedNode = new Node;
    if (addedNode == NULL) {
        return false; // allocation failed
    }
	else
	{
		addedNode->element = item;
		addedNode->line_num = line;
        addedNode->next = NULL;
		s=head;
		while(s != NULL)
		{
			s=s ->next;
			counter++;
		}
		if(pos ==1)
		{
			if(head ==NULL)
			{
				head= addedNode;
				head ->next=NULL;
			}
			else
			{
				ptr=head;
				head= addedNode;
				head ->next= ptr;
			}

		}
		else if (pos > 1  && pos <= counter)
		{
			s=head;
			for(int i=1; i<pos ;i++)
			{
				ptr = s;
				s = s->next;
			}
			ptr->next = addedNode;
			addedNode->next = s;
			if(pos == counter)
			{
				tail= addedNode;
			}
		}
		else
		{
			cout<<"Incorrect Number of Arguments"<<endl;
		}
	}
	return true;
}

int LinkedList::find_node( ListElemType& item , int *rep_pos )
{
	int counter=0;
	int rep_times=0;
	Node  *s;
	s=head;
	while(s != NULL)
	{
		s=s ->next;
		counter++;
	}
	s=head;
	int j=0;
	for(int i=0; i<counter; i++ )
	{
		//if(strcmp(s-> element , item)==0)
		if(s-> element == item)
		{
			rep_pos[j]=s-> line_num;
			j++;
			rep_times++;
		}
		s = s->next;
	}
	if(rep_times ==0)
		return 0;
	else
		return rep_times;
}

bool LinkedList::delete_node(int& pos  )
{
	Node *s, *ptr, *temp;
	int num=numof_node();
	int i=1; int flag=0;
	if(pos != 1)
	{
		s=head;
		for(int i=1; i<pos ;i++)
		{
			ptr = s;
			s = s->next;
		}
		temp=s->next;
		ptr->next=temp;
		if(pos== num)
			tail=ptr;
		flag=1;
	}
	else
	{
		head= head->next;
		flag=1;
	}
	return flag;
}

ListElemType LinkedList::display_node(int& pos)
{
	Node *s;
	int i=1;
	s=head;
	while(i!= pos)
	{
		s = s->next;
		i++;
	}
	return s->element;

}

int LinkedList::numof_node(  )
{
	int num=0;
	Node  *s;
	s=head;
	while(s != NULL)
	{
		s=s ->next;
		num++;
	}
	return num;
}

void LinkedList::sort_node()
{
	Node  *s , *ptr;
	string temp;  int t,l;
	ptr= head;
	while(ptr != NULL)
	{
		for(s=ptr->next; s !=NULL; s=s->next )
		{
			if (ptr->element >= s->element)
            {
                temp = ptr->element;
                ptr->element = s->element;
                s->element = temp;

				t = ptr->line_num;
                ptr->line_num= s->line_num;
                s->line_num = t;

				l = ptr->countt;
                ptr->countt= s->countt;
                s->countt = l;

            }

		}
		ptr = ptr->next;
	}


}

void LinkedList::update_val(const ListElemType& item, int& pos)
{
	Node *s;
	int i=1;
	s=head;
	while(i!= pos)
	{
		s = s->next;
		i++;
	}
	s->element=item;


}


void LinkedList::access_count( int& pos , int counnt)
{
	Node *s;
	int i=1;
	s=head;
	while(i!= pos)
	{
		s = s->next;
		i++;
	}
	s->countt=counnt;
}

int LinkedList::get_count(int pos)
{
	Node *s;
	int i=1;
	s=head;
	while(i!= pos)
	{
		s = s->next;
		i++;

	}



	return s->countt;
}

int LinkedList::get_linenum(int pos)
{
	Node *s;
	int i=1;
	s=head;
	while(i!= pos)
	{
		s = s->next;
		i++;

	}



	return s->line_num;

}




