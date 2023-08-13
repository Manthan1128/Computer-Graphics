#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#define radian (3.14/180)

void drawcurve(float xa , float ya , float xb , float yb , int n){

    float xc ,yc ,xd ,yd , midx ,midy;

    xc = (2*xa + xb )/3;
    yc = (2*ya + yb) / 3;
    xd = (2*xb + xa) / 3;
    yd = (2*yb + ya)/3;

    midx = xc + ((xd - xc)*cos(60*radian)) + ((yd-yc)*sin(60*radian));
    midy = yc - ((xd-xc)*sin(60*radian)) + ((yd-yc)*cos(60*radian));

    if(n > 0){

        drawcurve(xa,ya,xc,yc,n-1);
        drawcurve(xc,yc,midx,midy,n-1);
        drawcurve(midx,midy,xd,yd,n-1);
        drawcurve(xd,yd,xb,yb,n-1);

    }
    else{

        glVertex2f(xa,ya);
        glVertex2f(xc,yc);

        glVertex2f(xc,yc);
        glVertex2f(midx,midy);

        glVertex2f(midx,midy);
        glVertex2f(xd,yd);

        glVertex2f(xd,yd);
        glVertex2f(xb,yb);
    }
}

void Init(){
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
    drawcurve(600,100,800,400,0);
    drawcurve(800,400,400,400,0);
    drawcurve(400,400,600,100,0);
    glEnd();
    gluOrtho2D(0.0,1400.0,0.0,900.0);
    glFlush();
}

int main(int argc , char** argv){

    glutInit(&argc , argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1400,900);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Koch Curve");
    glutDisplayFunc(Init);
    glutMainLoop();
    return 0 ;
}