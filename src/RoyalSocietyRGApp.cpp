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
#include <vector>



using namespace ci;
using namespace ci::app;
using namespace std;

class RoyalSocietyRGApp : public AppBasic {
  public:
	void setup();
	void keyDown(KeyEvent event);
	void mouseDown( MouseEvent event );	
	void update();
	void render();
	void prepareSettings(Settings* settings);
	void dishelp();
	void draw();
	

	
private:
	 Vec2i	tSize;
	 gl::Texture texture_font_;
	 bool help;

	 //dimensions for rectangles
	 int startx;
	 int starty;
	 int width ;
	 int height ;

	 //rectangles on screen
	 rectangle* oneRect_ ;
	 rectangle* twoRect_  ;
	 rectangle* threeRect_;

	 //colors for rectangles
	ColorA8u c;
	ColorA8u c2;
	ColorA8u c3;
	 //create a nodes
	Node* one;
	Node* two;
	Node* three;
	Node* after;


//Width and height of the screen
	static const int kAppWidth=800;
	static const int kAppHeight=600;
	static const int kTextureSize=1024;

	//list
	List* lst;

	//satifies the move items requirment 1.F
	void moveItemsDown();
	void moveItemsUP();
	void moveItemsLeft();
	void moveItemsRight();

	//satifies requirement transparency requirement.
	void transparent();


};

void RoyalSocietyRGApp::prepareSettings(Settings* settings){
	(*settings).setWindowSize(kAppWidth,kAppHeight);
	(*settings).setResizable(false);
}

//satifies project requirement 1.f
void RoyalSocietyRGApp::moveItemsDown(){

	if(startx!=590 || starty!=790){
	startx = startx+20;
	starty = starty+20;
	}

	else{
		startx = 100;
		starty = 100;

	}
	
}

//satifies project requirement 1.f
void RoyalSocietyRGApp::moveItemsUP(){

		if(startx!=10|| starty!=10){
	startx = startx-100;
	starty = starty-100;
	}

	else{
		startx = 100;
		starty = 100;

	}

}

void RoyalSocietyRGApp::moveItemsRight(){

	if(startx!= 590){
	startx= startx+20;
	}

	else startx = 100;
	
}

//satifies project requirement 1.f
void RoyalSocietyRGApp::moveItemsLeft(){

	if(startx!= 60){
	startx= startx-100;
	}

	else startx = 100;
}

void RoyalSocietyRGApp::transparent(){
	
	
}
void RoyalSocietyRGApp::setup()
{

	//setup for text box
		tSize = Vec2i(590,20);
		render();
		help = false;

	
	//set up for rectangles
	 c = ColorA(0.0f, 0.0f,0.6f, 0.4f);
	 c2 = ColorA(0.0f, 0.2f,0.6f, 0.4f);
     c3 = ColorA(0.0f, 0.0f,0.9f, 0.4f);
	 //c = ColorA8u(0, 60, 120, 0);
	 //c2 = ColorA8u(30, 120, 60,220);
     //c3 = ColorA8u(150,210,210,220);
	//Color8u afterC = Color8u(100,10,200);

	//int start x, start y, used to draw the first rectangle.
	  startx = 300 ;
	  starty = 300 ;
	  width = 200;
	  height = 200; 

 	

}

//Learned to do from ajduberstien and the cinder samples Textbox and TextTest
//satifies requirement 
void RoyalSocietyRGApp::render(){

	Font ft  = Font("Times new roman",25);
	string ms = " Press the up arrow to reverse, Press down arrow to move down and Up arrow to move up.";
	TextBox tbox = TextBox().alignment( TextBox::CENTER ).font(ft).size( tSize.x, tSize.y ).text( ms );
	tbox.setColor( Color( 0.0f, 0.65f, 1.0f ) );
	tbox.setBackgroundColor( ColorA( 0.5, 0, 0, 1 ) );
	Vec2i sz = tbox.measure();
	console() << "Height: " << sz.y << endl;
	texture_font_ = gl::Texture( tbox.render() );


}

void RoyalSocietyRGApp::keyDown(KeyEvent event){
	 if(event.getChar() == '?'){//got the idea from ajduberstien
		help = true;
	}
	 else if(event.getCode() == event.KEY_r){
		 lst->reverse();
	}
	else if( event.getCode() == event.KEY_UP ){
		   moveItemsUP();
		} 
	else if( event.getCode() == event.KEY_DOWN ){
		  	moveItemsDown();
		} 
	else if( event.getCode() == event.KEY_RIGHT ){
		  	moveItemsRight();
		} 
	else if( event.getCode() == event.KEY_LEFT ){
		  	moveItemsLeft();
		} 
		} 
	
	



void RoyalSocietyRGApp::mouseDown( MouseEvent event )
{
	
}

void RoyalSocietyRGApp::update()
{

	 oneRect_ =  new rectangle(c,startx,starty,width,width);
	 twoRect_ = new rectangle(c2,startx+20,starty+20,width+20,height+20); 
	 threeRect_ = new rectangle(c3,startx+40,starty+40,width+40,height+40);
	//rectangle*aftRect_ = new rectangle(afterC, 100,100,550,550);

	//create a nodes
	 one = new Node();
	 two = new Node();
	 three = new Node();
	// after = new Node();

	//adds rectangles two nodes
	one->data_= oneRect_;
	two->data_= twoRect_;
	three->data_= threeRect_;
	//after->data_ = aftRect_;

	//creates a list
	lst =  new List();

	//adds node

	
	lst->add(three);
	lst->add(two);
	lst->add(one);

	
}


void RoyalSocietyRGApp::draw()
{
	//goes through list and draws rectangle.

	Node*nd = lst->sentinal_->next_;
	gl::enableAlphaBlending();
	gl::clear(Color(0.0f,0.0f,0.0f));

	while(nd!=lst->sentinal_){
		nd->data_->draw();
		nd= nd->next_;
	}

	if(help == true){
		gl::draw(texture_font_);
	}

}

CINDER_APP_BASIC( RoyalSocietyRGApp, RendererGl )
