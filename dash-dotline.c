#include<GL/gl.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>

void dda(float x1 , float z1 , float x2 , float z2){

    float dx , dz ,step, xin , zin , x,z;

    dx = x2 - x1;
    dz = z2 - z1;

    if(abs(dx) > abs(dz)){
        step = abs(dx) ;
    }
    else{
        step = abs(dz);
    }

    xin = dx / step;
    zin = dz /step;

    x = x1;
    z = z1;

    glBegin(GL_POINTS);
    glVertex2f(x,z);
    glEnd();
    for(int i = 0 ; i < step ; i++){
        x = xin + x;
        z = zin +z;
        
        if((i%5 == 0) || ((i/10) & 1)){
        glBegin(GL_POINTS);
        glVertex2f(x,z);
        glEnd();
        }
    }
}

float x , y ;
void display(){
    glClearColor(1.0,1.0,1.0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    // dda(x,y,x,y+100);
    // dda(x,y+100,x+100,y+100);
    // dda(x+100,y+100,x+100,y+200);
    // dda(x+100,y+200,x+200,y+200);
    // dda(x+200,y+200,x+200,y+300);
    // dda(x+200,y+300,x+300,y+300);
    // dda(x+300,y+300,x+300,y+400);
    // dda(x+300,y+400,x+400,y+400);
    // dda(x+400,y+400,x+400,y);
    // dda(x+400,y,x,y);

    dda(x,y+400,x+1400,y+400);
    dda(x+700,y,x+700,y+800);
    gluOrtho2D(0.0,1400.0,0.0,800.0);
    glFlush();
}
int main(int argc , char** argv){
    glutInit(&argc , argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1400,800);
    glutInitWindowPosition(100,100);
    printf("enter x and y coordinates :");
    scanf("%f%f",&x,&y);
    glutCreateWindow("DDA STAIRS");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}