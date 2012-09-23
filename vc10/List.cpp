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
}

//Adds a node at the end of the list right before it reaches the sentinal again.
void List::add(Node* toAdd){

	//condition that nothing is currently in the list.
	if(num_items ==0){
		sentinal_->next_ = toAdd;
		sentinal_->prev_ = toAdd;

		//the nodes toAdd pointers go to sential because its currently the only item in the list
		toAdd->next_ = sentinal_;
		toAdd->prev_ = sentinal_;

		num_items += 1;
	}

	else{
		
		//sets the next pointers to the correct node.
		Node*temp = sentinal_->next_;
		sentinal_->next_ = toAdd;
		toAdd->next_ = temp;
		
		//set the prev pointers to the correct node.
		temp->prev_ = toAdd;
		toAdd->prev_ = sentinal_;

		num_items +=1;
	}

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


void List::reverse(){

	Node*mov = sentinal_->next_; 

	do{
		Node*temp = mov->next_;
		mov->next_ = mov->prev_;
		mov->prev_ = temp;
		mov = mov->prev_;
	} while(mov!=sentinal_);
}
