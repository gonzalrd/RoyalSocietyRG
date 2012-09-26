#pragma once
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Surface.h"
#include "cinder/rect.h"
#include "cinder/ImageIo.h"

using namespace std;
using namespace ci;
using namespace ci::app;

class rectangle
{
public:
		rectangle();
		rectangle(ColorA c, int x , int y , int width, int height);
		void setX(int x);
		void setY(int y);
		void draw();
private:
	//Defines the colors to put in the rectangle.
	ColorA c;
	int x;
	int y;
	int width;
	int height;

};