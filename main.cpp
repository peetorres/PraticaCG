#include <GL/glut.h>
#include <iostream>
#include <unistd.h>

using namespace std ;

/*Variaveis Globais*/
int COLUNAS = 200.0;
int LINHAS = 200.0;
int x0,y0,x1,y1;
int x2,y2,x3,y3;
int matRaster[200][200];


/*Menu de Funcoes*/
void unit(int, int, float, float, float, float);
void display();
void init();
void line(int, int, int, int);
void setPixel(int, int);
void preenchimentoAlastramento();
void drawPolygonLine();

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
    x0=50; y0=50;x1=50;y1=75;x2=75;y2=90;x3=130;y3=50;
    int x4=130; int y4=70;int x5=100;int y5=50;
    line(x0,y0,x1,y1);
    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);
    line(x3,y3,x4,y4);
    line(x4,y4,x5,y5);
    line(x5,y5,x0,y0);
}

void drawPolygonLine(){
    line(x0,y0,x1,y1);
    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);
    line(x3,y3,x0,y0);
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
    //line(x0, y0, x1, y1);
    drawBaleia();
    //drawPolygonLine();
    preenchimentoAlastramento(60,60);
    preenchimentoAlastramento(125,65);
}

void init(){
    //Define a cor de background da janela
    glClearColor (1.0, 1.0, 1.0, 0.0);
    //define o sistema de visualizacao de projecao
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho (0.0 , COLUNAS , 0.0 , LINHAS , -1.0, 200);
    glMatrixMode(GL_MODELVIEW);
    for(int i=0; i<200; i++){
        for(int j=0; j<200 ;j++){
            matRaster[i][j] = 0;
        }
    }
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(150,150);

    glutCreateWindow("Pratica Rasterizacao");

    cout << "Entre com as coordenadas x0, y0, x1, y1, respectivamente: " ;
    //cin >> x0 >> y0 >> x1 >> y1;
    x0 = 1; y0 = 1; x1 = 1 ; y1 = 100;
    cout << "Entre com as coordenadas x2, y2, x3, y3, respectivamente: " ;
    //cin >> x2 >> y2 >> x3 >> y3;
    x2 = 100; y2 = 100; x3 = 100; y3 = 1;

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
