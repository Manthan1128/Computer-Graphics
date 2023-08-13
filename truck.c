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
void display(int x ,int z){
    glBegin(GL_POINTS);
    glVertex2f(x,z);
    glEnd();
}

void bla(int x1 , int z1 , int x2 , int z2){

    int dx ,dz,x,z,k,xin,zin;

    dx = abs(x2-x1);
    dz = abs(z2-z1);

    if(z1 > z2){
        zin = -1;
    }
    else{
        zin = 1;
    }
    if(x1 > x2){
        xin = -1;
    }
    else{
        xin = 1;
    }

    x = x1;
    z = z1;

    

    // if(dx == 0){
    //     display(x,z);
    //     for(int i = 0 ; i < dz ; i++){
    //         z = z + zin;
    //         display(x,z);
    //     }
    // }
    // else if(dz == 0){
    //     display(x,z);
    //     for(int i = 0 ; i < dx ; i++){
    //         x = x + xin;
    //         display(x,z);
    //     }
    // }
    // else{
        if(dx > dz){
            display(x,z);
            k = 2*dz - dx;
            for(int i = 0 ; i < dx ; i++){
                if(k >= 0 ){
                    k = k + 2*(dz - dx);
                    z = z + zin;
                }
                else{
                    k = k + 2*dz;
                }
                x = x + xin;
                if(i%5 == 0){
                display(x,z);
                }
            }
        }
        else{
            display(x,z);
            k = 2*dx - dz;

            for(int i = 0 ; i < dz ; i++){
                if(k > 0){
                    x = x + xin;
                    k = k + 2*(dx - dz);
                }
                else{
                    k = k + 2*dx;
                }
                z = z + zin;
                if((i/10) & 1){
                display(x,z);
                }
            }
        // }
    }

    
}

int x ,y;
void init(){
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    // bla(x,y,x,y+100);
    // bla(x,y+100,x+300,y+100);
    // bla(x+300,y+100,x+300,y);
    // bla(x+300,y,x,y);
    // bla(x-50,y,x-50,y+100);
    // bla(x-50,y+100,x-100,y+100);
    // bla(x-100,y+100,x-150,y+75);
    // bla(x-150,y+75,x-150,y);
    // bla(x-150,y,x-50,y);
    bla(x,y,x,y+50);
    bla(x,y+50,x,y+100);
    bla(x,y+100,x+50,y+100);
    bla(x+50,y+100,x+100,y+100);
    bla(x+100,y+100,x+100,y+50);
    bla(x+100,y+50,x+100,y);
    bla(x+100,y,x+50,y);
    bla(x+50,y,x,y+50);
    bla(x,y+50,x+50,y+100);
    bla(x+50,y+100,x+100,y+50);
    bla(x+100,y+50,x+50,y);
    bla(x+50,y,x,y);

    b_col.r = 1;
    b_col.g = 1;
    b_col.b = 1;

    f_col.r = 1;
    f_col.g = 0;
    f_col.b = 0;
    boundcol(x+25 , y + 25);

    gluOrtho2D(0.0,1400.0,0.0,800.0);
    glFlush();
}

int main(int argc , char** argv){

    glutInit(&argc , argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1400,800);
    glutInitWindowPosition(100,100);
    printf("enter x & y coordinates:");
    scanf("%d%d",&x,&y);
    glutCreateWindow("TRUCK");
    glutDisplayFunc(init);
    glutMainLoop();
    return 0 ;

}