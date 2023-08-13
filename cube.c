#include<GL/gl.h>
#include<GL/glut.h>

GLfloat xrotated , yrotated , zrotated;

void drawcube(){

    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0 , 0.0 , -10.5);
    glRotatef(xrotated , 1.0, 0.0, 0.0);
    glRotatef(yrotated , 0.0, 1.0, 0.0);
    glRotatef(zrotated , 0.0, 0.0, 1.0);
    
    glBegin(GL_QUADS);
    
        glColor3f(0.0,1.0,0.0);
    glVertex3f(1.0,1.0,-1.0);
    glVertex3f(-1.0,1.0,-1.0);
    glVertex3f(-1.0,1.0,1.0);
    glVertex3f(1.0,1.0,1.0);
     glColor3f(1.0,0.0,0.0);
    glVertex3f(1.0,-1.0,-1.0);
    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);
     glColor3f(0.0,0.0,1.0);
    glVertex3f(-1.0,1.0,1.0);
    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(1.0,1.0,1.0);
     glColor3f(1.0,1.0,0.0);
    glVertex3f(-1.0,1.0,-1.0);
    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(1.0,-1.0,-1.0);
    glVertex3f(1.0,1.0,-1.0);
     glColor3f(0.0,1.0,1.0);
    glVertex3f(1.0,1.0,-1.0);
    glVertex3f(1.0,-1.0,-1.0);
    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(1.0,1.0,1.0);
     glColor3f(1.0,1.0,1.0);
    glVertex3f(-1.0,1.0,-1.0);
    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,1.0,1.0);

    glEnd();
    glFlush();
    

}

void animated(){
    // yrotated += 0.02;
    // xrotated += 0.01;
    zrotated += 0.01;
    drawcube();
}

void reshape(int x ,int y){
    if(x == 0 || y == 0) return;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0,(GLdouble)x/(GLdouble)y , 0.5 , 20.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x , y);
}

void init(){
    glClearColor(0.0,0.0,0.0,0.0);
}

int main(int argc , char** argv){
    glutInit(&argc , argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutCreateWindow("cube");
    init();
    glutDisplayFunc(drawcube);
    glutReshapeFunc(reshape);
    glutIdleFunc(animated);
    glutMainLoop();
    return 0;
}