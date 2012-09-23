#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/Surface.h"
#include "cinder/rect.h"
#pragma once
#include "cinder/ImageIo.h"

using namespace std;
using namespace ci;
using namespace ci::app;

class rectangle
{
public:
		rectangle();
		rectangle(Color8u c, int x , int y , int width, int height);
		void setX(int x);
		void setY(int y);
		void draw();

		~rectangle(void);
private:
	//Defines the colors to put in the rectangle.
	Color8u c;
	int x;
	int y;
	int width;
	int height;

};