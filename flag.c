#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#define pi 3.14

int framenumber = 0;

void drawdisk(int rad){
    int i;
    glBegin(GL_POLYGON);
    for(i=0 ;i <32 ; i++){
        GLdouble angle = 2*pi*i/32;
        glVertex2d(rad*cos(angle),rad*sin(angle));
    }
    glEnd();
}

void drawflag(){
    glColor3f(0.1,1.0,0.1);
    glBegin(GL_POLYGON);
    glVertex2f(-0.25,0);  
    glVertex2f(0.75,0);
    glVertex2f(0.75,0.5);
    glVertex2f(-0.25,0.5);
    glEnd();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.25,0.5);
    glVertex2f(0.75 , 0.5);
    glVertex2f(0.75 , 1);
    glVertex2f(-0.25,1);
    glEnd();
    glColor3f(1.0,0.5,0.2);
    glBegin(GL_POLYGON);
    glVertex2f(-0.25,1);
    glVertex2f(0.75,1);
    glVertex2f(0.75,1.5);
    glVertex2f(-0.25,1.5);
    glEnd();
}

void drawpole(){
    glColor3f(0,0,0);
    glLineWidth(40);
    glBegin(GL_LINES);
    glVertex2f(3,0);
    glVertex2f(3,3);
    glEnd();
}

void drawbase(){
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(1,-1);
    glVertex2f(1,0);
    glVertex2f(6,0);
    glVertex2f(6,-1);
    glEnd();
}

void drawchukra(){
    int i = 0;
    glColor3f(0.0,0.0,1.0);
    for(i = 0 ; i < 24 ; i++){
        glRotated(360/24,0,0,1);
        glBegin(GL_LINES);
        glVertex2d(0.0,0.0);
        glVertex2d(1.5,0);
        glEnd();
    }

}

void drawsun(){
    int i ;
    glLineWidth(1);
    glColor3f(1.0,0.5,0.2);
    drawdisk(1);
    for(i = 0 ; i < 15 ; i++){
        glRotated(360/15,0,0,1);
        glBegin(GL_LINES);
        glVertex2d(0,0);
        glVertex2f(1.5,0);
        glEnd();
    }

}

void display(){

    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    drawbase();
    drawpole();

    glPushMatrix();
    glTranslated(3.2f,1.5f*(framenumber%300)/300,0);
    drawflag();
    glPopMatrix();

    glPushMatrix();
    glTranslated(5.7,3.0,0);
    glScaled(0.5,0.5,0);
    glRotated(framenumber*0.7f , 0 ,0 ,1);
    drawsun();
    glPopMatrix();

    glPushMatrix();
    glTranslated(3.5,0.75+1.5f*(framenumber%300)/300,0);
    glScaled(0.170,0.170,0);
    drawchukra();
    glPopMatrix();

    glutSwapBuffers();

}
void doframe(int v){
    framenumber++ ;
    glutPostRedisplay();
    glutTimerFunc(10,doframe,0);
}
void init(){
    glClearColor(0.5,0.5,0.8,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,7,-1,4,-1,1);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc , char** argv){
    glutInit(&argc , argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(1400,800);
    glutInitWindowPosition(100,100);
    glutCreateWindow("flag");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(100,doframe,0);
    glutMainLoop();
    return 0;
}