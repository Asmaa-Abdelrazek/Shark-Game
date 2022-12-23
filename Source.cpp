#include<Windows.h>    
#include<gl/GL.h>    
#include<gl/GLU.h>    
#include<gl/glut.h> 
#include<math.h>
#include<iostream>
///////////////////////////////////Start Variables//////////////////////////////////////////////////
// coordinates for first fish///
/// for the good fish
float pointy1 = 0;
float pointx1;
int dropped = 0;
int fisheaten = 0;
int missed = 0;
//to translate the fish
int xx = 0;
//to rotate the fish
int xy = 45;
//For the bad fish
float pointy2;
float pointx2 = 0;
int badfisheaten;

float xboat;
int yboat;
/////////////////////////////////End Variables//////////////////////////////////////////////////////////
int s = 0;
/////////////////////////////////////////////start screen

/////////////////////////////////////////////////////////////////
//////////////////////////////////////////////Controlares//////////////////////////////////////////////////////
void keys(unsigned char key, int x, int y)
{
    if (key == 's' || key == 'S')
        s += 1;
}
void specialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT) {
        xx -= 1;
        if (xx <= -3)xx = -2;
    }
    else if (key == GLUT_KEY_RIGHT) {
        xx += 1;
        if (xx >= 13) xx = 12.5;
    }
    glutPostRedisplay();
}
///////////////////////////////////////////End Controllers///////////////////////////////////////////////////////
///////////////////////////////////////////Print score////////////////////////////////////////////////////////////
void print_score()
{
    printf("\nTotal No. of fish dropped = %d\n", dropped);
    printf("\nNo. of fish caught = %d\n", fisheaten);
    printf("\nNo. of fish missed= %d\n", missed);
    printf("\nNo. of fish red eaten= %d\n", badfisheaten);
    printf("\n---------------------------------");
    getchar();      //بيعمل ستوب للشاشه بعدين السطر الي بعده بيوقف اللعبه
    exit(0);
}
///////////////////////////////////////////End Pint score////////////////////////////////////////////////
void start() {
    if (missed >= 5)
    {
        printf("\n\n\t\t\t\tGAME OVER\n\n");

        printf(" \n \n \t \t \t YOUR FISH DEAD OF  STARVITION !!!\n \n");

        print_score();
    }
    else if (badfisheaten >= 3)
    {

        printf("\n\n\t\t\t\tGAME OVER\n\n");

        printf(" \n \n \t \t \t YOU ARE A CRIMINAL ! :)\n \n");

        printf(" \n \n \t \t \t YOU KILLED YOUR FHISH!!!\n \n");

        printf(" \n \n \t \t \t YOUR FISH GET POISONED!!! :)\n \n");

        print_score();
    }
    dropped++;
    switch (rand() % 6)
    {
    case 0:pointx1 = 1; break;
    case 1:pointx1 = 7; break;
    case 2:pointx1 = 9; break;
    case 3:pointx1 = 10; break;
    case 4:pointx1 = 5; break;
    case 5:pointx1 = 3; break;
    }
}
void score()
{
    if (pointy1 <= -11.5 && (pointx1 >= xx + -2 && pointx1 <= xx + 2))
    {
        fisheaten++;
        pointy1 = 0;
        start();
    }
    missed = dropped - fisheaten;
}
void score2()
{

    if (pointy1 <= -15.5 && (pointx1 >= xx + -2 && pointx1 <= xx + 2))
    {
        fisheaten++;
        pointy1 = 0;
        start();


    }
    else if (pointy2 <= -15.5 && (pointx2 >= xx + -5 && pointx2 <= xx + -1))
    {
        badfisheaten++;
        pointy2 = 0;
    }
    missed = dropped - fisheaten;
}
////////////////////////////////let the fishs drop/////////////////////////////////////

void fish()
{
    glColor3ub(255, 222, 173);
    glPushMatrix();
    glTranslatef(pointx1, pointy1, 0);
    pointy1 += -0.01;
    if (pointy1 <= -20) { pointy1 = 0; start(); }
    glBegin(GL_POLYGON);
    glVertex2f(5, 21);
    glVertex2f(6, 21);
    glVertex2f(5.5, 20.5);
    glEnd();
    glBegin(GL_POLYGON);
    for (float theta = 0; theta <= 360; theta++) {
        float d = theta * 3.14 / 180;
        glVertex2f(5.5 + 0.4 * cos(d), 20 + 0.6 * sin(d));
    }
    glEnd();
    glPopMatrix();
    glutPostRedisplay();
}

void badfish()
{
    glColor3ub(128, 0, 0);
    glPushMatrix();
    glTranslatef(pointx2, pointy2, 0);
    pointy2 += -0.01;
    if (pointy2 <= -20)pointy2 = 0;
    glBegin(GL_POLYGON);
    glVertex2f(8, 21);
    glVertex2f(9, 21);
    glVertex2f(8.5, 20.5);
    glEnd();
    glBegin(GL_POLYGON);
    for (float theta = 0; theta <= 360; theta++) {
        float d = theta * 3.14 / 180;
        glVertex2f(8.5 + 0.4 * cos(d), 20 + 0.6 * sin(d));
    }
    glEnd();
    glPopMatrix();
    glutPostRedisplay();
}

///////////////////////////////// Score Counter ///////////////////////////////////////////////////
/////////////////////////////End score Counter ////////////////////////////////////////////////////////
//////////////////////////////////////////////Drawing part start////////////////////////////////////////
void shio3ab()
{
    glBegin(GL_POLYGON);
    glColor3ub(0, 128, 0);
    glVertex2f(4.21374, 1.4036);
    glVertex2f(4.8162, 1.77434);
    glVertex2f(5.01702, 1.38815);
    glVertex2f(4.84533, 0.1213);
    glVertex2f(4.56904, 0.106);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(0, 100, 0);
    glVertex2f(5.16813, 2.18177);
    glVertex2f(5.35842, 2.2822);
    glVertex2f(5.48, 2.27692);
    glVertex2f(5.61215, 2.12362);
    glVertex2f(4.99898, 0.0727);
    glVertex2f(4.63571, 0.09456);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(0, 128, 0);
    glVertex2f(5.66595, 1.61539);
    glVertex2f(5.85773, 1.68675);
    glVertex2f(6.00936, 1.65107);
    glVertex2f(6.04504, 1.49943);
    glVertex2f(5.21104, 0.03213);
    glVertex2f(4.93453, 0.03213);
    glEnd();
}
void boat()
{
    glPushMatrix();
    glTranslatef(xboat, yboat, 0);
    xboat += -0.001;
    if (xboat <= -10)
        xboat = 15;
    glBegin(GL_POLYGON);
    glColor3ub(160, 82, 45);
    glVertex2f(5, 21);
    glVertex2f(15, 21);
    glVertex2f(16, 22);
    glVertex2f(16, 23);
    glVertex2f(4, 23);
    glVertex2f(4, 22);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(139, 69, 19);
    glVertex2f(16, 22);
    glVertex2f(4, 22);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(70, 130, 180);
    glVertex2f(4.8, 21);
    glVertex2f(15.2, 21);
    glEnd();
    glPopMatrix();
    glutPostRedisplay;
}
void Background() {
    //sky
    glBegin(GL_POLYGON);
    glColor3ub(135, 206, 235);
    glVertex2f(0, 21);
    glVertex2f(0, 25);
    glVertex2f(25, 25);
    glVertex2f(25, 21);
    glEnd();
    //sun
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    for (float theta = 0; theta <= 360; theta++) {
        float d = theta * 3.14 / 180;
        glVertex2f(20 + 2 * cos(d), 25 + 2 * sin(d));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(0, 100, 0);
    glVertex2f(8.75498, 2.22468);
    glVertex2f(8.94527, 2.32512);
    glVertex2f(9.06685, 2.31983);
    glVertex2f(9.199, 2.16654);
    glVertex2f(8.58583, 0.11561);
    glVertex2f(8.22256, 0.13748);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(238, 232, 170);
    glVertex2f(0, 0);
    glVertex2f(0, 0.3);
    glVertex2f(20, 0);
    glVertex2f(20, 0.3);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(0, 128, 0);
    glVertex2f(7.65334, 1.3833);
    glVertex2f(7.88506, 1.73859);
    glVertex2f(8.2558, 1.75404);
    glVertex2f(8.45662, 1.36785);
    glVertex2f(8.28493, 0.10102);
    glVertex2f(8.00864, 0.08569);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(0, 128, 0);
    glVertex2f(9.21918, 1.7396);
    glVertex2f(9.41096, 1.81096);
    glVertex2f(9.56259, 1.77528);
    glVertex2f(9.59827, 1.62364);
    glVertex2f(8.76427, 0.15634);
    glVertex2f(8.48776, 0.15634);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(0, 100, 0);
    glVertex2f(5.16813, 2.18177);
    glVertex2f(5.35842, 2.2822);
    glVertex2f(5.48, 2.27692);
    glVertex2f(5.61215, 2.12362);
    glVertex2f(4.99898, 0.0727);
    glVertex2f(4.63571, 0.09456);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(0, 128, 0);
    glVertex2f(5.66595, 1.61539);
    glVertex2f(5.85773, 1.68675);
    glVertex2f(6.00936, 1.65107);
    glVertex2f(6.04504, 1.49943);
    glVertex2f(5.21104, 0.03213);
    glVertex2f(4.93453, 0.03213);
    glEnd();
}
void shark() {
    glBegin(GL_POLYGON);
    glColor3ub(30, 144, 255);
    glVertex2f(3, 8);
    glVertex2f(7, 8);
    glVertex2f(7, 2);
    glVertex2f(3, 2);
    glEnd();
    //line aroude the body
    glLineWidth(4);
    glBegin(GL_LINE_LOOP);
    glColor3ub(25, 25, 112);
    glVertex2f(3, 8);
    glVertex2f(7, 8);
    glVertex2f(7, 2);
    glVertex2f(3, 2);
    glEnd();
    //the light body
    glBegin(GL_POLYGON);
    glColor3ub(135, 206, 250);
    glVertex2f(3.6, 3.97);
    glVertex2f(6.56, 3.97);
    glVertex2f(6.56176, 2.01291);
    glVertex2f(3.60378, 2.03416);
    glEnd();
    //the left fin
    glBegin(GL_POLYGON);
    glColor3ub(30, 144, 255);
    glVertex2f(2.95617, 3.83666);
    glVertex2f(2.38957, 2.60043);
    glVertex2f(2.95617, 2.58755);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(25, 25, 112);
    glVertex2f(2.95617, 3.83666);
    glVertex2f(2.38957, 2.60043);
    glVertex2f(2.95617, 2.58755);
    glEnd();
    //the right fin
    glBegin(GL_POLYGON);
    glColor3ub(30, 144, 255);
    glVertex2f(7.00986, 3.74888);
    glVertex2f(7.60489, 2.60043);
    glVertex2f(7.0086, 2.59949);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(25, 25, 112);
    glVertex2f(7.00986, 3.74888);
    glVertex2f(7.60489, 2.60043);
    glVertex2f(7.0086, 2.59949);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(30, 144, 255);
    glVertex2f(4.36746, 1.99861);
    glVertex2f(5.81952, 1.99647);
    glVertex2f(6.33032, 1.00344);
    glVertex2f(4.99894, 1.39455);
    glVertex2f(3.79175, 1.0102);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(25, 25, 112);
    glVertex2f(4.36746, 1.99861);
    glVertex2f(5.81952, 1.99647);
    glVertex2f(6.33032, 1.00344);
    glVertex2f(4.99894, 1.39455);
    glVertex2f(3.79175, 1.0102);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255, 0, 0);
    glVertex2f(4.17913, 4.49382);
    glVertex2f(5.89872, 4.49382);
    glVertex2f(5.33886, 3.51405);
    glVertex2f(4.75899, 3.51405);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(139, 0, 0);
    glVertex2f(4.17913, 4.49382);
    glVertex2f(5.89872, 4.49382);
    glVertex2f(5.33886, 3.51405);
    glVertex2f(4.75899, 3.51405);
    glEnd();
    //the right eye
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float theta = 0; theta <= 360; theta++) {
        float d = theta * 3.14 / 180;
        glVertex2f(6 + 0.8 * cos(d), 6 + 0.8 * sin(d));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    for (float theta = 0; theta <= 360; theta++) {
        float d = theta * 3.14 / 180;
        glVertex2f(5.86873 + 0.5 * cos(d), 5.99347 + 0.5 * sin(d));
    }
    glEnd();
    //the left eye
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float theta = 0; theta <= 360; theta++) {
        float d = theta * 3.14 / 180;
        glVertex2f(4 + 0.8 * cos(d), 6 + 0.8 * sin(d));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    for (float theta = 0; theta <= 360; theta++) {
        float d = theta * 3.14 / 180;
        glVertex2f(4.14914 + 0.5 * cos(d), 5.99347 + 0.5 * sin(d));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(25, 25, 112);
    for (float theta = 0; theta <= 360; theta++) {
        float d = theta * 3.14 / 180;
        glVertex2f(4.94895 + 0.4 * cos(d), 7.61309 + 0.2 * sin(d));
    }
    glEnd();
}
//////////////////////////////////drawing part end////////////////////////////////////
int k = 1;
void display() {
    glClearColor(0.4, 0.6, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    Background();
    if (pointy2 <= -11.5 && (pointx2 >= xx + -5 && pointx2 <= xx + -1))
        k = 2;
    switch (k) {
    case 1:
    {
        glPushMatrix();
        if (missed >= 5) {
            glTranslatef(7, 2, 0);
            glRotatef(xy, 0, 0, 1);
            glTranslatef(-7, -2, 0);
            xy += 1;
        }
        glTranslatef(xx, 0, 0);
        shark();
        glPopMatrix();
        score();
        break;
    }
    case 2:
    {
        glPushMatrix();
        if (missed >= 5 || badfisheaten >= 3) {
            glMatrixMode(GL_MODELVIEW);
            glTranslatef(7, 2, 0);
            glRotatef(xy, 0, 0, 1);
            glTranslatef(-7, -2, 0);
            xy += 1;

        }
        glTranslatef(xx, 0, 0);
        glScalef(1, 0.5, 1);
        shark();
        glPopMatrix();
        score2();
        break;
    }
    }
    glPushMatrix();
    glTranslatef(10, 0, 0);
    shio3ab();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(5, 0, 0);
    shio3ab();
    glPopMatrix();
    fish();
    badfish();
    boat();
    shio3ab();
    glFlush();
    glutPostRedisplay();
}
void menu(int id)
{
    switch (id)
    {
    case 1: s += 1;
        break;
    case 2:print_score();
        break;
    case 3: {
        printf("\n\n\n\t\tQUIT BY PLAYER\n");
        break;
    }
    default:exit(0);
    }
    glutPostRedisplay();
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 700);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Points");
    gluOrtho2D(0, 20, 0, 25);
    glutCreateMenu(menu);
    glutAddMenuEntry("Start game", 1);
    glutAddMenuEntry("score", 2);
    glutAddMenuEntry("Quit", 3);
    glutKeyboardFunc(keys);

    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);

    glutMainLoop();

    return 0;
}
