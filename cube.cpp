#include <iostream>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

using namespace std;

float derece = 0.0;


void displayCube(float size)
{
	 float difamb[]={0.3,0.3,0.30,1.0};
	 glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,difamb);

	 glBegin(GL_QUADS);
	   //ön k?s?m
	   glNormal3f(0.0,0.0,1.0);
	   glVertex3f(size/2,size/2,size/2);
	   glVertex3f(-size/2,size/2,size/2);
	   glVertex3f(-size/2,-size/2,size/2);
	   glVertex3f(size/2,-size/2,size/2);
	   //sol k?s?m
	   glNormal3f(-1.0,0.0,0.0);
	   glVertex3f(-size/2,size/2,size/2);
	   glVertex3f(-size/2,size/2,-size/2);
	   glVertex3f(-size/2,-size/2,-size/2);
	   glVertex3f(-size/2,-size/2,size/2);
	   //üst k?s?m
	   glNormal3f(0.0,1.0,0.0);
	   glVertex3f(size/2,size/2,size/2);
	   glVertex3f(size/2,size/2,-size/2);
	   glVertex3f(-size/2,size/2,-size/2);
	   glVertex3f(-size/2,size/2,size/2);
 	   //sað k?s?m
	   glNormal3f(1.0,0.0,0.0);
	   glVertex3f(size/2,size/2,size/2);
	   glVertex3f(size/2,size/2,-size/2);
	   glVertex3f(size/2,-size/2,-size/2);
	   glVertex3f(size/2,-size/2,size/2);
	   //arka k?s?m
	   glNormal3f(0.0,0.0,-1.0);
	   glVertex3f(size/2,size/2,-size/2);
	   glVertex3f(size/2,-size/2,-size/2);
       glVertex3f(-size/2,-size/2,-size/2);
	   glVertex3f(-size/2,size/2,-size/2);
	   //alt k?s?m
	   glNormal3f(0.0,-1.0,0.0);
	   glVertex3f(size/2,-size/2,size/2);
	   glVertex3f(size/2,-size/2,-size/2);
	   glVertex3f(-size/2,-size/2,-size/2);
	   glVertex3f(-size/2,-size/2,size/2);
	 glEnd();
}
void init(){
	 glClearColor(0.0,0.0,0.0,1.0);//arkaplan rengi...
	 glMatrixMode(GL_PROJECTION);
	 glLoadIdentity(); 
	 gluPerspective(45,640.0/480.0,1.0,500.0);
     glMatrixMode(GL_MODELVIEW);
	 glEnable(GL_DEPTH_TEST);
	 glEnable(GL_LIGHTING);
	 glEnable(GL_LIGHT0);
	 //glEnable(GL_COLOR_MATERIAL);//renkleri aktif etmek için ama suan materialfv kulland???m?z için buna gerek duymuyoruz...

	 float dif[]={1.0,1.0,1.0,1.0};
	 glLightfv(GL_LIGHT0,GL_DIFFUSE,dif);
	 float amb[]={0.3,0.3,0.3,1.0};
	 glLightfv(GL_LIGHT0,GL_AMBIENT,amb);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	float pos[]={-2.0,2.0,-3.0,1.0};
	glLightfv(GL_LIGHT0,GL_POSITION,pos);

	glTranslatef(0.0,0.0,-6.0);
	glRotatef(derece,1.0,1.0,1.0); 
	displayCube(2.0);
}

int main(int argc, char* argv[])
{   
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_WM_SetCaption("OpenGL Light Cube",NULL);//ba?l?k ayar?(ba?l?k,ikon)...
	SDL_Surface* screen = SDL_SetVideoMode(640,480,32,SDL_SWSURFACE | SDL_OPENGL);

	SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

	cout<<"OpenGL successfully activated..."<<endl;
    cout<<"\nEnter ESC for Exit."<<endl;

    Uint32 start;
	SDL_Event event;
	init();
    bool isRunning = true;

	while(isRunning)
	{
		start=SDL_GetTicks();
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT){
				isRunning=false;
				break;
			}
			if(event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE){
				isRunning=false;
				break;
			}
		}

	    display();
		derece+=0.5;
		if(derece>360)
		derece-=360;
		SDL_GL_SwapBuffers();
		if(1000/30>(SDL_GetTicks()-start))
			SDL_Delay(1000/30-(SDL_GetTicks()-start));
	}

	SDL_Quit();
	return 0;
}

