#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#include "cinder/Surface.h"
#include "cinder/rect.h"
#include "rectangle.h"
#include "Node.h"
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

	Node*temp = where->next_;
	//sets the next pointers
	nw->next_ = where->next_;
	where->next_ = nw;

	//sets the prev pointers
	temp->prev_ = nw;
	nw->prev_ = where;


	}

//Satifies requirement 
void List::reverse(){

	Node*mov = sentinal_->next_; 

	do{
		Node*temp = mov->next_;
		mov->next_ = mov->prev_;
		mov->prev_ = temp;

		   
		mov = mov->prev_;

	} while(mov!=sentinal_);

	
}

void List::remove(Node*toRemov){
	


}
