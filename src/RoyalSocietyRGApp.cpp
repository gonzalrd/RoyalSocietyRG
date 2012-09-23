#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#include "cinder/Surface.h"
#include "cinder/rect.h"
#include "../vc10/rectangle.h"
#include "../vc10/List.h"
#include "../vc10/Node.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class RoyalSocietyRGApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void prepareSettings(Settings* settings);
	void draw();

	
private:

//Width and height of the screen
	static const int kAppWidth=800;
	static const int kAppHeight=600;
	static const int kTextureSize=1024;

//list and rectangles
	List* lst;
	rectangle* oneRect_;

};

void RoyalSocietyRGApp::prepareSettings(Settings* settings){
	(*settings).setWindowSize(kAppWidth,kAppHeight);
	(*settings).setResizable(false);
}

void RoyalSocietyRGApp::setup()
{

	//creates a rectangle
	Color8u c = Color8u(0, 60, 120);
	Color8u c2 = Color8u(0, 120, 60);
	Color8u c3 = Color8u(250,210,210);
	Color8u afterC = Color8u(100,10,200);
 	oneRect_ = new rectangle(c,200,300,400,500);

	rectangle* twoRect_ = new rectangle(c2,70,90,590,490); // need to check size, adds behinds so dont see it when it shows up. 
	rectangle* threeRect_ = new rectangle(c3,60,50,500,500);
	rectangle*aftRect_ = new rectangle(afterC, 100,100, 550 , 550);

	//create a nodes
	Node* one = new Node();
	Node* two = new Node();
	Node* three = new Node();
	Node* after = new Node();

	//adds rectangles two nodes
	one->data_= oneRect_;
	two->data_= twoRect_;
	three->data_= threeRect_;
	after->data_ = aftRect_;

	//creates a list
	lst =  new List();

	//adds node

	lst->add(one);
	lst->add(two);
	lst->add(three);
	lst->insertAfter(two,after);

}

void RoyalSocietyRGApp::mouseDown( MouseEvent event )
{

	lst->reverse();
}

void RoyalSocietyRGApp::update()
{
}

void RoyalSocietyRGApp::draw()
{
	//goes through list and draws rectangle.

	Node*nd = lst->sentinal_->next_;
	
	while(nd!=lst->sentinal_){
		nd->data_->draw();

		nd= nd->next_;
	}

}

CINDER_APP_BASIC( RoyalSocietyRGApp, RendererGl )
