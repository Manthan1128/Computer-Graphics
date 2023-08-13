#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<math.h>

int framenumber = 0;

void drawmill(){

    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.05f,0);                          //POLL OF POLYGON
    glVertex2f(-0.05f,3);
    glVertex2f(0.05,3);
    glVertex2f(0.05,0);
    glEnd();

    glTranslatef(0,3,0);                           // Translating windmill fins

    glColor3f(1.0,0.0,0.0);
    glRotated(framenumber*(180.0/45) , 0 , 0 ,1);  //ROTATING SPEED OF FINS

    for (int i = 0 ; i < 4 ; i++){
        glRotated(90,0,0,1);                       // Drawing fins
        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(1.0f,-0.2f);
        glVertex2f(1.0f,0.2f);
        glEnd();
    }

}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    // glLoadIdentity();                           //Takes Identity Matrix

                                                //to draw farther windmill
    glPushMatrix();                             
    glTranslated(2.2,1.6,0);                    // to translate drawmill
    glScaled(0.4,0.4,1);                        // to scale drawmill
    drawmill();
    glPopMatrix();                              
                                                 // to draw nearer windmill
    glPushMatrix();                            
    glTranslated(3.7,0.8,0);                    // to translate drawmill
    glScaled(0.7,0.7,1);                        // to scale drawmill
    drawmill();
    glPopMatrix();

    glutSwapBuffers();
}

void doframe(int v){
    framenumber++;                                      //  Increment framenumber
    glutPostRedisplay(); 
    glutTimerFunc(10,doframe,0);
}

void init(){
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,7,-1,4,-1,1);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc , char** argv){
    glutInit(&argc , argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(700,500);
    glutCreateWindow("Windmill");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(200,doframe,0);
    glutMainLoop();
    return 0;
}