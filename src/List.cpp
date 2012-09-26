#include "List.h"

//contructor for the list. creates an empty list only containing the sentinal.
List::List()
{
	num_items = 0;
	sentinal_ = new Node();
	sentinal_ ->prev_ = sentinal_->next_ = sentinal_;
}

//Adds a node at the end of the list right before it reaches the sentinal again.
void List::add(Node* toAdd){

	toAdd -> prev_ = sentinal_-> prev_;
	sentinal_->prev_ = toAdd;
	toAdd -> next_ = sentinal_;
	toAdd -> prev_ ->next_ = toAdd;

	num_items +=1;
}

//inserts a new node named nw after the nw node.
void List::insertAfter(Node*where, Node*nw){

	nw ->next_ = where->next_;
	where ->next_ = nw;

	nw -> prev_ = where;
	nw -> next_ ->prev_ = nw;
	}

//Satifies requirement 
void List::reverse(){

	Node* temp = sentinal_;
	Node* temp2 = NULL;

	do{
		temp2 = temp->next_;
		temp->next_ = temp->prev_;
		temp->prev_ = temp2;
		temp = temp2;
	}while(temp!=sentinal_);
}

void List::remove(Node*toRemove){
	delete toRemove->data_;
	delete toRemove;
	num_items--;
}
