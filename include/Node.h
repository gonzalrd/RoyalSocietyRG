#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/rect.h"
#include "rectangle.h"
#pragma once 

class Node
{
public:
	Node();

	Node*next_;

	Node*prev_;

	rectangle*data_;
};
