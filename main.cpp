#include <GL/glut.h>
#include <iostream>
#include <unistd.h>

using namespace std ;

/*Variaveis Globais*/
int COLUNAS = 4.0;
int LINHAS = 3.0;
int xi = 0, yi = 2;

/*Menu de Funcoes*/
void pegaCor(int, int, float&, float&, float&);
void unit(int, int, float, float, float, float);
void drawGrid(int, int );
void display();
void init();


void pegaCor(int x, int y, float &r, float &g, float &b){
    if(y == 2){
        r = 1.0 - 0.2*x;
        g = 0.0;
        b = 0.0;
    }
    if(y == 1){
        r = 0.0;
        g = 1.0 - 0.2*x;
        b = 0.0;
    }
    if(y == 0){
        r = 0.0;
        g = 0.0;
        b = 1.0 - 0.2*x;
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

void drawGrid(int i, int j){
    for(int x=0; x<COLUNAS; x++){
        for(int y=0; y<LINHAS; y++){
            float r, g, b, alpha;
            if (x == i && y == j){
                alpha = 0.2;
            }
            else {
                alpha = 1.0;
            }
            pegaCor(x, y, r, g, b);
            unit(x,y,r,g,b,alpha);
        }
    }
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid(xi, yi);
    sleep(1);
    glFlush();
    xi++;
    if (xi == 4){
        xi = 0;
        yi--;
    }

    if( yi == -1){
        yi = 2;
    }
    glutPostRedisplay();
}

void init(){ //substitui o init dos slides
    //Define a cor de background da janela
    glClearColor (1.0, 1.0, 1.0, 0.0);
    //define o sistema de visualizacao de projecao
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho (0.0 , COLUNAS , 0.0 , LINHAS , -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(150,150);
    glutCreateWindow("Pratica Cores");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
