#include <GL/glut.h>
#include <iostream>
#include <unistd.h>

using namespace std ;

/*Variaveis Globais*/
int matRaster[200][200];
GLfloat angle = 0, fAspect;
int smooth = 0;

/*Menu de Funcoes*/
void unit(int, int, float, float, float, float);
void display();
void init();
void line(int, int, int, int);
void setPixel(int, int);
void preenchimentoAlastramento();
void EspecificaParametrosVisualizacao();
void AlteraTamanhoJanela(GLsizei, GLsizei);
void gerenciaMouse(int,int, int, int);
void drawPolygonLine();
void drawLine();
void drawBaleia();
void drawCube();

void preenchimentoAlastramento(int x, int y){
    if(matRaster[x-1][y]!=1){
        unit(x-1,y,0, 0, 1.0, 1.0);
        matRaster[x-1][y]=1;
        preenchimentoAlastramento(x-1, y);
    }
    if(matRaster[x][y-1]!=1){
        unit(x,y-1,0, 0, 1.0, 1.0);
        matRaster[x][y-1]=1;
        preenchimentoAlastramento(x, y-1);
    }
    if(matRaster[x+1][y]!=1){
        unit(x+1,y,0, 0, 1.0, 1.0);
        matRaster[x+1][y]=1;
        preenchimentoAlastramento(x+1, y);
    }
    if(matRaster[x][y+1]!=1){
        unit(x,y+1,0, 0, 1.0, 1.0);
        matRaster[x][y+1]=1;
        preenchimentoAlastramento(x, y+1);
    }
    else{
        return;
    }
}

void drawBaleia(){
    int x0=50, y0=50, x1=50, y1=75, x2=75, y2=90;
    int x3=130, y3=50, x4=130, y4=70, x5=100, y5=50;
    line(x0,y0,x1,y1);
    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);
    line(x3,y3,x4,y4);
    line(x4,y4,x5,y5);
    line(x5,y5,x0,y0);

    preenchimentoAlastramento(60,60);
    preenchimentoAlastramento(125,65);
}

void drawPolygonLine(){
    int x0 = 50, y0 = 50, x1 = 50, y1 = 150;
    int x2 = 150, y2 = 150, x3 = 150, y3 = 50;
    line(x0,y0,x1,y1);
    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);
    line(x3,y3,x0,y0);
    preenchimentoAlastramento(60,60);
}

void drawLine(){
    int x0 = 1, y0 = 1;
    int x1 = 199, y1 = 199;
    line(x0,y0,x1,y1);
}

void drawCube(){
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);

    glRotatef(angle, 0, 1, 0);
    glColor3f(0.0f,0.0f,1.0f);
    glutSolidCube(100);
    glutSwapBuffers();
}

void setPixel(int x, int y){
    matRaster[x][y] = 1;
    unit(x, y, 0, 0, 1.0, 1.0);
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

    glPointSize(2);
    glBegin(GL_POINTS);
        glVertex2f(x,y);
    glEnd();
    glFlush();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    //drawLine(); // Descomente essa para mostrar o resultado do exercicio 1
    //drawPolygonLine(); // Descomente essa linha para mostrar o resultado do exercicio 2
    //drawBaleia(); // Descomente essa linha para mostrar o resultado do exercicio 3
    drawCube(); //Descomente essa linha para mostrar o resultado do exercicio 4
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h){
    if(h==0) h = 1;
    glViewport(0,0,w,h);
    fAspect = (GLfloat)w/(GLfloat)h;
    EspecificaParametrosVisualizacao();
}

void EspecificaParametrosVisualizacao(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, fAspect, 0.1, 500);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(-150,80,200,0,0,0,0,1,0);
}

void gerenciaMouse(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON)
            angle -= 10;
    if (button == GLUT_RIGHT_BUTTON)
            angle += 10;
    EspecificaParametrosVisualizacao();
    glutPostRedisplay();
}

void init(){
    //Define a cor de background da janela
    glClearColor (1.0, 1.0, 1.0, 0.0);
    //define o sistema de visualizacao de projecao
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho (0.0 , 200 , 0.0 , 200 , 0, 200);
    glMatrixMode(GL_MODELVIEW);

    for(int i=0; i<200; i++){
        for(int j=0; j<200 ;j++){
            matRaster[i][j] = 0;
        }
    }

    /*Funcoes Exercicio 4*/
    angle = 45;
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(150,150);

    glutCreateWindow("Pratica Rasterizacao");

    init();
    glutDisplayFunc(display);

    //glRotatef(angle, 0, 0, 1);
    glutMouseFunc(gerenciaMouse);
    glutReshapeFunc(AlteraTamanhoJanela);

    glutMainLoop();
    return 0;
}
