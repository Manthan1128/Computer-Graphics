#include<GL/gl.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int length , xi ,yi , choice;
double angle , et[3][3] , etresult[3][3];

void drawet(double et[3][3]){

    int i = 0;
    glBegin(GL_LINE_LOOP);
    for (i = 0 ; i < 3 ; i ++){
        glVertex2i(et[i][0] , et[i][1]);
        
    }
    glEnd();
}

void display(){
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(-320,320,-240,240);
    glColor3f(1,1,1);
    glBegin(GL_LINES);
    glVertex2d(-320, 0);
    glVertex2d(320, 0);
    glVertex2d(0, -240);
    glVertex2d(0, 240);
    glEnd();
    glColor3f(1,0,0);
    drawet(et);
    glFlush();
}

void mult(double et[3][3] , double temp[3][3]){

    double sum ;
    int i,j,k;

    for(i = 0 ; i < 3 ;i++){
        for(j = 0 ; j < 3 ; j++){
            sum = 0 ;
            for(k = 0 ; k < 3 ; k++){
                sum = sum + et[i][k] * temp[k][j];
            }
            etresult[i][j] = sum;
        }
    }
}

void translation(){
    double tx , ty , temp[3][3];
    printf("\nEnter Tx: ");
    scanf("%lf", &tx);
    printf("\nEnter Ty: ");
    scanf("%lf", &ty);

    temp[3][3] = {0};
    temp[0][0] = 1;
    temp[1][1] = 1;
    temp[2][2] = 1;
    temp[2][0] = tx;
    temp[2][1] = ty;

    mult(et, temp);
    glColor3f(1.0, 1.0, 1.0);
    drawet(etresult);
}

void rotation(){
    
    double rx , ry , angle , temp[3][3] ;
    printf("\nAngle (in degrees) : ");
    scanf("%lf", &angle);
    angle = angle * (M_PI / 180);
    temp[3][3] = {0};
    temp[0][0] = cos(angle);
    temp[0][1] = sin(angle);
    temp[1][0] = -sin(angle);
    temp[1][1] = cos(angle);
    temp[2][0] = 0;
    temp[2][1] = 0;
    temp[0][2] = 0;
    temp[1][2] = 0;
    temp[2][2] = 1;
    mult(et, temp);
    glColor3f(0.0, 1.0, 1.0);
    drawet(etresult);
}

void scaling(){
    double sx , sy , temp[3][3];

    printf("Enter sx :");
    scanf("%lf",&sx);
    printf("Enter sy :");
    scanf("%lf",&sy);

    temp[3][3] = {0};
    temp[0][0] = sx;
    temp[1][1] = sy;
    temp[2][2] = 1;

    mult(et, temp);
    glColor3f(0,1,0);
    drawet(etresult);
}

void Menu(int item)
{
    switch (item)
    {
    case 1:
        translation();
        break;
    case 2:
        rotation();
        break;
    case 3:
        scaling();
        break;
    case 4:
        exit(0);
        break;
    }
}

int main(int argc , char** argv){

    int i,j;

    printf("enter xi coordinate");
    scanf("%d",&xi);
    printf("enter yi coordinate");
    scanf("%d",&yi);
    printf("enter length of sides");
    scanf("%d", &length);

    for(i = 0 ; i < 3 ; i++){
        for(j = 0 ; j < 3 ; j++){
            et[i][j] = 1;
        }
    }

    et[0][0] = xi;
    et[0][1] = yi;
    et[1][0] = xi + length;
    et[1][1] = yi;
    et[2][0] = length / 2 + xi;
    et[2][1] = (sqrt(3) / 2 * length) + yi;

    glutInit(&argc , argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,100);
    glutCreateWindow("tranformation");
    glutDisplayFunc(display);
    glutCreateMenu(Menu);
    glutAddMenuEntry("1.Translation",1);
    glutAddMenuEntry("2.rotation",2);
    glutAddMenuEntry("3.scaling",3);
    glutAddMenuEntry("4.exit",4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;

}

