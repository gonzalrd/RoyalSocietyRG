#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#include "cinder/Surface.h"
#include "cinder/rect.h"
#include "../vc10/rectangle.h"
#include "../vc10/List.h"
#include "../vc10/Node.h"
#include "cinder/Font.h"
#include "cinder/Text.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class RoyalSocietyRGApp : public AppBasic {
  public:
	void setup();
	void keyDown(KeyEvent event);
	void mouseDown( MouseEvent event );	
	void update();
	void prepareSettings(Settings* settings);
	void dishelp();
	void draw();
	

	
private:

	
	 Font master_font_;
	 int color_changer_;
	 gl::Texture master_texture_font_;
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
 	oneRect_ = new rectangle(c,80,85,400,500);

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

//Learned to do from abj
void RoyalSocietyRGApp::dishelp(){

	Font ft  = Font("Helvetica",32);
	string ms = " Press the up arrow to reverse.";
	TextBox tbox = TextBox().alignment( TextBox::CENTER ).font(ft).size( Vec2i( 512, 511) ).text( ms );
	tbox.setColor( Color( 1.0f, 0.65f, 0.35f ) );
	tbox.setBackgroundColor( ColorA( 0.5, 0, 0, 1 ) );
	gl::Texture( tbox.render() );


}

void RoyalSocietyRGApp::keyDown(KeyEvent event){
	if( event.getCode() == event.KEY_UP ){
		   lst->reverse();
		} 
	else if(event.getCode() ==event.KEY_QUESTION){
		dishelp();
	}

}

void RoyalSocietyRGApp::mouseDown( MouseEvent event )
{

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
