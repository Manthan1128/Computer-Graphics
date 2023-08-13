#include<GL/gl.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>

typedef struct pixel{
    float r,g,b;
}pixel;


pixel f_col , b_col;

void boundcol(int x , int y){

    pixel c;
    glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,&c);
    if((c.r != b_col.r || c.g != b_col.g || c.b != b_col.b) && (c.r != b_col.r || c.g != b_col.g || c.b != b_col.b)){
        glBegin(GL_POINTS);
        glColor3f(f_col.r , f_col.g , f_col.b);
        glVertex2f(x,y);
        glEnd();
        glFlush();
        boundcol(x,y+1);
        boundcol(x,y-1);
        boundcol(x+1,y);
        boundcol(x-1,y);
    }
    glFlush();
}

void init();
void display(int x, int y){
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
    glFlush();
}

void bcircle(int xc , int yc , int r){

    int d = 3 - 2*r;
    int x = 0 , y = r;

    while(x <= y){
        display(xc+x , yc+y);
        display(xc+x , yc-y);
        display(xc-x , yc+y);
        display(xc-x , yc-y);
        display(xc+y , yc+x);
        display(xc+y , yc-x);
        display(xc-y , yc+x);
        display(xc-y , yc-x);

        if(d < 0){
            d += 4*x + 6;
        }
        else if(d > 0){
            d+= 4*(x-y) + 10;
            y--;
        }
        x++;
    }
}

int x,y,r;

void keybo(unsigned char ch , int x ,int y){

    printf("Enter radius of circle");
    r = (ch-'0')*25;
    bcircle(x,y,r);                          //necklace pattern
    bcircle(x,y-(4*r/3),r/3);
    bcircle(x,y-(4*r/3),r/3);
    bcircle(x-2*r/3,y-1.2*r,r/3);
    bcircle(x+2*r/3,y-1.2*r,r/3);
    bcircle(x,y-(2*r),r/3);
    bcircle(x+0.9*r,y+r,r/3);
    bcircle(x-0.9*r,y+r,r/3);
}

void mouseli(int button , int state ,int cx ,int cy){
    glutKeyboardFunc(keybo);
    x = cx;
    y = cy;
    
}
void init(){
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    // bcircle(x,y,r);                    // rangoli pattern
    // bcircle(x,y,r/2);
    // bcircle(x+r/2,y,r/2);
    // bcircle(x-r/2,y,r/2);
    // bcircle(x+r/4,y+r/2.25,r/2);
    // bcircle(x-r/4,y+r/2.25,r/2);
    // bcircle(x+r/4,y+r/2.25,r/2);
    // bcircle(x+r/4,y+r/2.25,r/2);
    // bcircle(x+r/4,y-r/2.25,r/2);
    // bcircle(x-r/4,y-r/2.25,r/2);

    // bcircle(x,y,r);                          //necklace pattern
    // bcircle(x,y-(4*r/3),r/3);
    // bcircle(x,y-(4*r/3),r/3);
    // bcircle(x-2*r/3,y-1.2*r,r/3);
    // bcircle(x+2*r/3,y-1.2*r,r/3);
    // bcircle(x,y-(2*r),r/3);
    // bcircle(x+0.9*r,y+r,r/3);
    // bcircle(x-0.9*r,y+r,r/3);

    glutMouseFunc(mouseli);
    gluOrtho2D(0.0,1400.0,0.0,800.0);
    glFlush();
}

void primitive(void){

    glColor3f(0,1,0);
    glBegin(GL_LINES);
    glVertex2f(0,400);
    glVertex2f(1400,400);
    glEnd();
}

int main(int argc , char** argv){

    glutInit(&argc , argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1400,800);
    glutInitWindowPosition(100,100);
    // scanf("%d%d%d",&x,&y,&r);
    glutCreateWindow("Pattern");
    init();
    glutDisplayFunc(primitive);
    glutMainLoop();
    return 0;
}