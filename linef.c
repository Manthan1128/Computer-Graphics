#include<GL/gl.h>
#include<GL/glut.h>


GLfloat xmin = -0.5 , ymin = -0.5 , xmax = 0.5 , ymax = 0.5;
GLfloat x1 = 0.0, Y1 = 0.2 , x2 = 0.0 , y2 = 0.5 ;

int left = 1 , right = 2 , bot = 4 , top = 8;
int c1 , c2;

int get_code(GLfloat x , GLfloat y){

    int code = 0;

    if(x < xmin){
        code = code | left;
    }
    if(x > xmax){
        code = code | right;
    }
    if(y < ymin){
        code = code | bot;
    }
    if(y > ymax){
        code = code | top;
    }

    return code;

}

void clip(){
    int c ;
    GLfloat x , y;
    if(c1){
        c = c1;
    }
    else{
        c = c2;
    }

    if(c & left){
        x = xmin;
        y = Y1 + (y2 -Y1) * ((xmin-x1)/(x2-x1));
    }
    if(c & right){
        x = xmax;
        y = Y1 + (y2-Y1) * ((xmax - x1)/(x2-x1));
    }
    if(c & bot){
        y = ymin;
        x = x1 + (x2-x1) * ((ymin - Y1)/(y2 - Y1));
    }
    if(c & top){
        y = ymax;
        x = x1 + (x2-x1)* ((ymax - Y1)/(y2 - Y1));
    }

    if(c == c1){
        x1 = x;
        Y1 = y;
    }
    else{
        x2 = x;
        y2 = y;
    }
}

void draw(){
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINE_LOOP);
    glVertex2f(xmin,ymin);
    glVertex2f(xmax,ymin);
    glVertex2f(xmax,ymax);
    glVertex2f(xmin,ymax);
    glEnd();

    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(x1,Y1);
    glVertex2f(x2,y2);
    glEnd();

    while (1)
    {
        c1 = get_code(x1,Y1);
        c2 = get_code(x2,y2);

        if((c1|c2) == 0){
            break;
        }
        else if((c1&c2) != 0){
            clip();
            break;
        }
        else{
            clip();
        }
    }

    glFlush();
    
}

void kkey(unsigned char ch , int x ,int y){
    if(ch == 'c'){
        glutPostRedisplay();
        glFlush();
    }
}

int main(int argc , char** argv){
    glutInit(&argc , argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1400,800);
    glutInitWindowPosition(100,100);
    glutCreateWindow("LineClip");
    glutDisplayFunc(draw);
    glutKeyboardFunc(kkey);
    glutMainLoop();
    return 0 ;
}