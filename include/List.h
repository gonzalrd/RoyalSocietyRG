#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/rect.h"
#include "rectangle.h"
#include "Node.h"
#pragma once // makes sure that you dont copy things twice

class List
{
public:
	List();
	void add(Node* toAdd);
	void remove(Node*toRemov);
	void reverse();
	void insertAfter(Node*where, Node*nw);//include the  data of the next node
	void insertBefore(Node*where);//include the data to put in the next node here

	Node*sentinal_;

private:
	//Node*sentinal_;
	int num_items;
	int index;
};

