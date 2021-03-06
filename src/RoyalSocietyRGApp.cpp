#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#include "cinder/Surface.h"
#include "cinder/rect.h"
#include "rectangle.h"
#include "List.h"
#include "Node.h"
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
	static const int kRectIncrement=50;

	//list
	List* lst;

	//satifies the move items requirment 1.F
	void moveItemsDown();
	void moveItemsUP();
	void moveItemsLeft();
	void moveItemsRight();

	//satifies requirement transparency requirement.
	float tranparency;
	void transparent();


};

void RoyalSocietyRGApp::prepareSettings(Settings* settings){
	(*settings).setWindowSize(kAppWidth,kAppHeight);
	(*settings).setResizable(false);
}

void RoyalSocietyRGApp::setup()
{

	//setup for text box
		tSize = Vec2i(600,30);
		render();
		help = true;

	
	//set up for rectangles
	tranparency=1;
	  startx = 300 ;
	  starty = 300 ;
	  width = 200;
	  height = 200; 

}
//satifies project requirement 1.f
void RoyalSocietyRGApp::moveItemsDown(){

	if(starty+kRectIncrement<kAppHeight){
	starty = starty+kRectIncrement;
	}	
}

//satifies project requirement 1.f
void RoyalSocietyRGApp::moveItemsUP(){

		if(starty-kRectIncrement>0){
	starty = starty-kRectIncrement;
	}
}

void RoyalSocietyRGApp::moveItemsRight(){

	if(startx+kRectIncrement<kAppWidth){
	startx= startx+kRectIncrement;
	}	
}

//satifies project requirement 1.f
void RoyalSocietyRGApp::moveItemsLeft(){

	if(startx-kRectIncrement>0){
	startx= startx-kRectIncrement;
	}
}

void RoyalSocietyRGApp::transparent(){
	
	if(tranparency>0){
		tranparency= tranparency-0.2;
	}
	else{
		tranparency=1;
	}
}

//Learned to do from ajduberstien and the cinder samples Textbox and TextTest
//satifies requirement 
void RoyalSocietyRGApp::render(){

	Font ft  = Font("Times new roman",20);
	string ms = "Press the up arrow to move Up, down arrow to move down,left to move left, right to move right and T to increase transparency";
	TextBox tbox = TextBox().alignment( TextBox::CENTER ).font(ft).size( tSize.x, tSize.y ).text( ms );
	tbox.setColor( Color( 0.0f, 0.85f, 1.0f ) );
	tbox.setBackgroundColor( ColorA( 0.5, 0, 0, 1 ) );
	Vec2i sz = tbox.measure();
	console() << "Height: " << sz.y << endl;
	texture_font_ = gl::Texture( tbox.render() );


}

void RoyalSocietyRGApp::keyDown(KeyEvent event){
	 if(event.getChar() == '?'){//got the idea from ajduberstien
		help = !help;
	}
	 else if(event.getCode() == event.KEY_t){
		 transparent();
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
	else if( event.getCode() == event.KEY_r){

		(*lst).reverse();
	}
		} 
	
	



void RoyalSocietyRGApp::mouseDown( MouseEvent event )
{
	
}

void RoyalSocietyRGApp::update()
{
	 c = ColorA(0.0f, 0.0f,0.6f, tranparency);
	 c2 = ColorA(0.0f, 0.2f,0.6f, tranparency);
     c3 = ColorA(0.0f, 0.0f,0.9f, tranparency);

	 oneRect_ =  new rectangle(c,startx,starty,width,width);
	 twoRect_ = new rectangle(c2,startx+20,starty+20,width+20,height+20); 
	 threeRect_ = new rectangle(c3,startx+40,starty+40,width+40,height+40);
	//rectangle*aftRect_ = new rectangle(afterC, 100,100,550,550);

	//create a nodes
	 one = new Node();
	 two = new Node();
	 three = new Node();
	// after = new Node();
	// console() << one << " " << two << " " << three <<endl;
	//adds rectangles two nodes
	one->data_= oneRect_;
	two->data_= twoRect_;
	three->data_= threeRect_;
	//after->data_ = aftRect_;


	//adds node

	//creates a list
	lst =  new List();

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
