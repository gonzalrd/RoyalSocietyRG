#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#include "cinder/Surface.h"
#include "cinder/rect.h"
#include "rectangle.h"

using namespace std;
using namespace ci;
using namespace ci::app;


rectangle::rectangle(){
	c = Color8u(0,0,0);
	x = 0;
	y = 0;
	width = 0;
	height = 0;
}

rectangle::rectangle(Color8u c, int x , int y , int width, int height){
	this->c = c;
	this->x = x;
	this->y = y;
	this->height = height;
	this->width = width;
	
}

void rectangle::setX(int x){
	this->x = x;
}

void rectangle::setY(int y){
	this->y = y;
}

void rectangle::draw(){

	//red then blue then green
	gl::color(c);
	gl::drawSolidRect(Rectf(x,y,width,height) , false);
	}
