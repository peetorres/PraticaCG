#include <GL/glut.h>
#include <iostream>
#include <unistd.h>

using namespace std ;

/*Variaveis Globais*/
int COLUNAS = 200.0;
int LINHAS = 200.0;
int xi = 0, yi = 2;
int x0,y0,x1,y1;

/*Menu de Funcoes*/
void unit(int, int, float, float, float, float);
void display();
void init();
void line(int, int, int, int);
void setPixel(int, int);

void setPixel(int x, int y){
    unit(x, y, 0, 0, 1.0, 1.0);
    glFlush();
}

void line(int x0, int y0, int x1, int y1){
    int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
    int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1;
    int err = (dx>dy ? dx : -dy)/2, e2;

    for (;;){
        setPixel(x0,y0);
        if(x0==x1 && y0==y1) break;
        e2 = err;
        if(e2>-dx) {
            err -=dy;
            x0 += sx;
        }
        if(e2<dy){
            err += dx;
            y0 += sy;
        }
    }
}

void unit(int x, int y,float r, float g, float b, float alpha){
    glEnable (GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glColor4f(r,g,b,alpha);

    glBegin(GL_POLYGON);
        glVertex2f(x,y);
        glVertex2f(x+1,y);
        glVertex2f(x+1,y+1);
        glVertex2f(x,y+1);
    glEnd();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    line(x0, y0, x1, y1);
    //glutPostRedisplay();
}

void init(){
    //Define a cor de background da janela
    glClearColor (1.0, 1.0, 1.0, 0.0);
    //define o sistema de visualizacao de projecao
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho (0.0 , COLUNAS , 0.0 , LINHAS , -1.0, 200);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(150,150);

    glutCreateWindow("Pratica Rasterizacao");

    cout << "Entre com as coordenadas x0, y0, x1, y1, respectivamente: " ;
    cin >> x0 >> y0 >> x1 >> y1;

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
