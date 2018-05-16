#include <GL/glut.h>
#include <iostream>
#include <unistd.h>

using namespace std ;

/*Variaveis Globais*/
int COLUNAS = 4.0;
int LINHAS = 3.0;
int sleepTime = 500000;
GLint coordx, coordy;
GLint quadranteClicado;

/*Menu de Funcoes*/
void verificaClique(int, int);
void gerenciaMouse(int, int, int, int);
void piscaQuadrado(int );
void piscaSequencia(int);
void unit(int, int, double, double, double);
void drawGrid();
void display();
void init();

/*
void verificaClique(int coordx, int coordy){ //verifica qual cor o usuario clicou
    int quadrante;
    if (COLUNAS == 2){
        if (coordx < 300 && coordy < 300){
            quadrante = 1;
        }
        if (coordx > 300 && coordy < 300){
            quadrante = 2;
        }
        if (coordx < 300 && coordy > 300){
            quadrante = 3;
        }
        if (coordx > 300 && coordy > 300){
            quadrante = 4;
        }
    }

    if (COLUNAS == 3){
        if (coordx < 200 && coordy < 200){
            quadrante = 1;
        }
        else if (coordx > 200 && coordx < 400 && coordy < 200){
            quadrante = 2;
        }
        else if (coordx > 400 && coordy < 200){
            quadrante = 3;
        }
        else if (coordx < 200 && coordy > 200 && coordy < 400){
            quadrante = 4;
        }
        else if (coordx > 200 && coordx < 400 && coordy > 200 && coordy < 400){
            quadrante = 5;
        }
        else if (coordx > 400 && coordy > 200 && coordy < 400){
            quadrante = 6;
        }
        else if (coordx < 200 && coordy > 400){
            quadrante = 7;
        }
        else if (coordx > 200 && coordx < 400 && coordy > 400){
            quadrante = 8;
        }
        else if (coordx > 400 && coordy > 400){
            quadrante = 9;
        }
    }

    quadranteClicado = quadrante;
    piscaQuadrado(quadrante);
    //cout << "Quadrante Clicado: " << quadranteClicado << endl;


    interacao[score] = quadranteClicado;
    cliques ++;

    //cout << "CLIQUES = " << cliques << "e SCORE + 1 = " << score+1 << endl;

    if(cliques == score+1){
        int flag = 0;
        for(int i=0; i<score+1; i++){
            if(interacao[i] == sequencia[i]){
                //cout << "Acertou o clique" << endl;
                flag ++;
            }
        }
        //cout << "FLAG = " << flag << "e SCORE = " << score << endl;
        if (flag-1 == score){
            score++;
            cliques = 0;
            if(score == 5){
                cout << "Velocidade atual do Genius: Medio" << endl;
            }
            if(score == 15){
                cout << "Velocidade atual do Genius: Dificil" << endl;
            }
            if(score == 25){
                cout << "Parabens, voce eh um Genio!" << endl;
            }
            else{
                cout << "Seu Score: " << score << endl;
                geniusGame();
            }
        }
        else{
            cout << "Game Over" << endl;
        }
    }
}
*/

/*
void gerenciaMouse(int button, int state, int x, int y){
  if(button==GLUT_LEFT_BUTTON && state == GLUT_DOWN){
    coordx = x;
    coordy = y;
    //cout << "valores do mouse " << coordx << " e " << coordy << endl;
    verificaClique(coordx, coordy);
  }
}
*/

/*
void verificaVelocidade(){
    if(score == 0){
        sleepTime = 300000;
    }
    else if (score == 5){
        sleepTime = 200000;
    }
    else if (score == 15){
        sleepTime = 100000;
    }
}
*/

/*
void piscaQuadrado(int quadrante){
    verificaVelocidade();
    if(COLUNAS == 2){
        if (quadrante == 1){
            unit(0,1,1,1,1);
            glFlush();
            //sleep(sleepTime);
            drawGrid();
            glFlush();
        }else if(quadrante == 2){
            unit(1,1,1,1,1);
            glFlush();
            //sleep(sleepTime);
            drawGrid();
            glFlush();
        }else if(quadrante == 3){
            unit(0,0,1,1,1);
            glFlush();
            //sleep(sleepTime);
            drawGrid();
            glFlush();
        }else if(quadrante == 4){
            unit(1,0,1,1,1);
            glFlush();
            //sleep(sleepTime);
            drawGrid();
            glFlush();
        }
    }
    if(COLUNAS == 3)
        {if (quadrante == 1){
            unit(0,2,1,1,1);
            glFlush();
            //sleep(sleepTime);
            drawGrid();
            glFlush();
        }else if(quadrante == 2){
            unit(1,2,1,1,1);
            glFlush();
            //sleep(sleepTime);
            drawGrid();
            glFlush();
        }else if(quadrante == 3){
            unit(2,2,1,1,1);
            glFlush();
            //sleep(sleepTime);
            drawGrid();
            glFlush();
        }else if(quadrante == 4){
            unit(0,1,1,1,1);
            glFlush();
            //sleep(sleepTime);
            drawGrid();
            glFlush();
        }else if(quadrante == 5){
            unit(1,1,1,1,1);
            glFlush();
            //sleep(sleepTime);
            drawGrid();
            glFlush();
        }else if(quadrante == 6){
            unit(2,1,1,1,1);
            glFlush();
            //sleep(sleepTime);
            drawGrid();
            glFlush();
        }else if(quadrante == 7){
            unit(0,0,1,1,1);
            glFlush();
            //sleep(sleepTime);
            drawGrid();
            glFlush();
        }else if(quadrante == 8){
            unit(1,0,1,1,1);
            glFlush();
            //sleep(sleepTime);
            drawGrid();
            glFlush();
        }else if(quadrante == 9){
            unit(2,0,1,1,1);
            glFlush();
            //sleep(sleepTime);
            drawGrid();
            glFlush();
        }
    }
}
*/

/*
void piscaSequencia(int score){
    for(int i=0; i<score+1; i++){
        usleep(sleepTime);
        piscaQuadrado(sequencia[i]);
        cout << "Piscou o quadrado: " << sequencia[i] << endl;
    }
}*/

/*
void geradorSequencia(){
    cout << "Gerando Sequencia do Genius" << endl;
    cout << "Sequencia Gerada: " ;
    for(int i=0; i<25; i++){
        sequencia[i] = rand()%(COLUNAS*LINHAS)+1;
        cout << sequencia[i] << " ";
    }
    cout << endl;
}*/

/*
void geniusGame(){
    cout << "Mostrando Sequencia" << endl;
    sleep(1); // Sleep pra travar na primeira tela
    piscaSequencia(score);
    if(score == 0)
        cout << "Velocidade atual do Genius: Facil" << endl;
}

    glutMouseFunc(gerenciaMouse);
    glutMainLoop();
}
*/

void unit(int x, int y,float r, float g, float b){
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
        glVertex2f(x,y);
        glVertex2f(x+1,y);
        glVertex2f(x+1,y+1);
        glVertex2f(x,y+1);
    glEnd();
}

void drawGrid(){
    for(int x=0; x<COLUNAS; x++){
        for(int y=0; y<LINHAS; y++){
            float r, g, b;
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
            unit(x,y,r,g,b);
        }
    }
}

void display(){
    //Limpa a janela
    glClear(GL_COLOR_BUFFER_BIT);
    //desenha a matriz colorida (os poligonos)
    drawGrid();
    //inicia o processamento imediatamente
    glFlush();
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
