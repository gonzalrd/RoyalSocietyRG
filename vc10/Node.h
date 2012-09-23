#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#include "cinder/Surface.h"
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

	~Node(void);
};
