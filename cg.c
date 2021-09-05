#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float pos = 0, pos1 = 0, x = 0, col = 0, i, p, c, pr, pl = 0;
int screen = 0;

//Introduction Page
char college[100] = "Cambridge Institute Of Technology";
char dept[100] = "Department of Computer Science & Engineering";
char heading[100] = "Made by                                                                            Guides";
char row1[100] = "Sumit Anand (1CD18CS177)                              Prof.Priyadarshini M.";
char row2[100] = "Rishav Raj (1CD18CS128)                             Dr.Jospehine Prem Kumar.";
char emsg[100] = "Press ENTER to start";
char title[50] = "Sailing of Ship Day And Night...!";
char dash[100] = "--------------------------------------------------------------------------------------";

void frontscreen(void) //the instruction page the staring one
{
    glPushMatrix();
    glTranslatef(50, 100, 0);
    glClearColor(0.0, 0.0, 0.0, 1.0); //background color of begining instuction page
    int s;
    glClear(GL_COLOR_BUFFER_BIT);
    //displays college name
    glRasterPos2i(154, 480); //college name text position

    //displays department name
    for (s = 0; college[s] != '\0'; s++)
    {
        glColor3f(1.0, 1.0, 1.0); //color of the department text
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, college[s]);
    }
    glRasterPos2i(154, 450); //position of the department text

    //displays project name
    for (s = 0; dept[s] != '\0'; s++)
    {
        glColor3f(1.0, 1.0, 1.0); //color of the project title
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, dept[s]);
    }
    glRasterPos2i(254, 380); //position of the project title

    //display the dooted line below the project topic
    for (s = 0; title[s] != '\0'; s++)
    {
        glColor3f(1.0, 1.0, 1.0); //color of the dotted line below project topic
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, title[s]);
    }
    glRasterPos2i(155, 370); //position of the dotted line

    //display heading line of the table
    for (s = 0; dash[s] != '\0'; s++)
    {
        glColor3f(1.0, 1.0, 1.0); //color of the heading line of the table
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, dash[s]);
    }
    glRasterPos2i(170, 340); //position of the heading line of teh table

    //display dotted line below thw heading
    for (s = 0; heading[s] != '\0'; s++)
    {
        glColor3f(1.0, 1.0, 1.0); //color of the dotted line below heading of the table
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, heading[s]);
    }
    glRasterPos2i(155, 330); //position of the dotted line below the heading

    //displaying 1st row of the table
    for (s = 0; dash[s] != '\0'; s++)
    {
        glColor3f(1.0, 1.0, 1.0); //color of the 1st row of the table
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, dash[s]);
    }
    glRasterPos2i(170, 310); //position of 1st row in table

    //displaying 2nd row of the table
    for (s = 0; row1[s] != '\0'; s++)
    {
        glColor3f(1.0, 1.0, 1.0); //color of the 2nd row of the table
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, row1[s]);
    }
    glRasterPos2i(170, 290); //position of 2nd row in table

    //display the dotted line below the table
    for (s = 0; row2[s] != '\0'; s++)
    {
        glColor3f(1.0, 1.0, 1.0); //color of the dotted line
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, row2[s]);
    }
    glRasterPos2i(155, 270); //position of the dotted line

    //displaying the press enter line
    for (s = 0; dash[s] != '\0'; s++)
    {
        glColor3f(1.0, 1.0, 1.0); //color of the press enter line
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, dash[s]);
    }
    glRasterPos2i(200, 100); //position of the press enter message

    //displaying the college name
    for (s = 0; emsg[s] != '\0'; s++)
    {
        glColor3f(1.0, 1.0, 1.0); //color of the college name
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, emsg[s]);
    }

    glPopMatrix();
    glFlush();
}

//sun/moon
void Drawarc(float sa, float ea, float cx, float cy, float rd)
{
    float PI = 3.14;
    float step = 1.0;
    float angle, x = 0, y = 0, centerX = cx, centerY = cy, radius = rd;

    glBegin(GL_POLYGON);
    for (angle = sa; angle < ea; angle += step)
    {
        float rad;
        rad = PI * angle / 180;
        x = centerX + radius * cos(rad);
        y = centerY + radius * sin(rad);
        glVertex2f(x, y);
    }
    glEnd();
    glFlush();
}

//drawing smoke from the chimney of the ship
void cloud(int m, int n)
{
    for (c = p = 0; c < 31; c += 10, p -= 1) //this loop displays 4 arc in the cloud for 0,10,20 and30
    {
        glColor3f(0.5, 0.5, 0.5);          //color of the smoke from the chimney
        Drawarc(0, 360, m + c, n, 10 + p); //calling the Drawarc function to make the arc of the smoke
    }
}

void ship(float x)
{
    glPushMatrix();
    glTranslatef(x, 0, 0);

    //base
    glColor3f(0.2 + col, 0.2 + col, 0.2 + col);
    glBegin(GL_POLYGON);
    glVertex2f(10, 119);
    glVertex2f(10, 110);
    glVertex2f(41, 70);
    glColor3f(0.3 + col, 0.3 + col, 0.8 + col);
    glVertex2f(219, 42);
    glVertex2f(292, 98);
    glVertex2f(300, 110);
    glEnd();

    //p1
    glColor3f(1.0 + col, 1.0 + col, 1.0 + col);
    glBegin(GL_POLYGON);
    glVertex2f(35, 118);
    glVertex2f(35, 128);
    glColor3f(0.5 + col, 0.5 + col, 0.5 + col);
    glVertex2f(239, 131);
    glVertex2f(239, 111);
    glVertex2f(35, 119);
    glEnd();

    //side
    glBegin(GL_POLYGON);
    glColor3f(0.8 + col, 0.8 + col, 0.8 + col);
    glVertex2f(239, 131);
    glVertex2f(239, 111);
    glVertex2f(257, 110);
    glVertex2f(257, 127);
    glEnd();

    //p2
    glColor3f(0.0 + col, 0.0 + col, 0.5 + col);
    glBegin(GL_POLYGON);
    glVertex2f(45, 129);
    glVertex2f(45, 140);
    glVertex2f(233, 149);
    glVertex2f(233, 131);
    glEnd();

    //side
    glBegin(GL_POLYGON);
    glColor3f(0.1 + col, 0.1 + col, 0.8 + col);
    glVertex2f(233, 149);
    glVertex2f(233, 131);
    glVertex2f(254, 128);
    glVertex2f(254, 145);
    glEnd();

    //p3
    glColor3f(0.2 + col, 0.5 + col, 0.2 + col);
    glBegin(GL_POLYGON);
    glVertex2f(51, 151);
    glVertex2f(51, 140);
    glVertex2f(221, 149);
    glColor3f(0.9 + col, 0.6 + col, 0.3 + col);
    glVertex2f(221, 165);
    glVertex2f(51, 151);

    glEnd();
    //side
    glBegin(GL_POLYGON);
    glColor3f(0.1 + col, 0.4 + col, 0.1 + col);
    glVertex2f(221, 164);
    glVertex2f(221, 149);
    glVertex2f(247, 147);
    glVertex2f(247, 162);
    glEnd();

    //p4
    //pipe1
    glColor3f(0.48 + col, 0.27 + col, 0.44 + col);
    glBegin(GL_POLYGON);
    glVertex2f(79, 152);
    glVertex2f(79, 194);
    glVertex2f(94, 194);
    glColor3f(0.0 + col, 0.0 + col, 0.0 + col);
    glVertex2f(94, 155);
    glEnd();
    cloud(59, 194);

    //pipe2
    glColor3f(0.44 + col, 0.48 + col, 0.27 + col);
    glBegin(GL_POLYGON);
    glVertex2f(112, 156);
    glVertex2f(112, 198);
    glVertex2f(127, 198);
    glColor3f(0.0 + col, 0.0 + col, 0.0 + col);
    glVertex2f(127, 158);
    glEnd();
    cloud(92, 198);

    //pipe3
    glColor3f(0.27 + col, 0.48 + col, 0.44 + col);
    glBegin(GL_POLYGON);
    glVertex2f(159, 161);
    glVertex2f(159, 203);
    glVertex2f(179, 203);
    glColor3f(0.0 + col, 0.0 + col, 0.0 + col);
    glVertex2f(179, 160);
    glEnd();
    cloud(144, 203);
    glPopMatrix();
}

void ship1(float x)
{
    glPushMatrix();
    glTranslatef(-x, 0, 0);

    glTranslatef(1100.0, 190.0, 0.0);
    glScalef(-0.3, 0.3, 1.0);
    //base
    glColor3f(0.2 + col, 0.2 + col, 0.2 + col);
    glBegin(GL_POLYGON);
    glVertex2f(710, 319);
    glVertex2f(710, 310);
    glVertex2f(741, 270);
    glColor3f(0.3 + col, 0.3 + col, 0.8 + col);
    glVertex2f(919, 242);
    glVertex2f(992, 298);
    glVertex2f(1000, 310);
    glEnd();

    //p1
    glColor3f(1.0 + col, 1.0 + col, 1.0 + col);
    glBegin(GL_POLYGON);
    glVertex2f(735, 318);
    glVertex2f(735, 328);
    glColor3f(0.5 + col, 0.5 + col, 0.5 + col);
    glVertex2f(939, 331);
    glVertex2f(939, 311);
    glVertex2f(935, 319);
    glEnd();

    //side
    glBegin(GL_POLYGON);
    glColor3f(0.8 + col, 0.8 + col, 0.8 + col);
    glVertex2f(939, 331);
    glVertex2f(939, 311);
    glVertex2f(957, 310);
    glVertex2f(957, 327);
    glEnd();

    //p2
    glColor3f(0.0 + col, 0.0 + col, 0.5 + col);
    glBegin(GL_POLYGON);
    glVertex2f(745, 329);
    glVertex2f(745, 340);
    glVertex2f(933, 349);
    glVertex2f(933, 331);
    glEnd();

    //side
    glBegin(GL_POLYGON);
    glColor3f(0.1 + col, 0.1 + col, 0.8 + col);
    glVertex2f(933, 349);
    glVertex2f(933, 331);
    glVertex2f(954, 328);
    glVertex2f(954, 345);
    glEnd();

    //p3
    glColor3f(0.2 + col, 0.5 + col, 0.2 + col);
    glBegin(GL_POLYGON);
    glVertex2f(751, 351);
    glVertex2f(751, 340);
    glVertex2f(921, 349);
    glColor3f(0.9 + col, 0.6 + col, 0.3 + col);
    glVertex2f(921, 365);
    glVertex2f(751, 351);

    glEnd();
    //side
    glBegin(GL_POLYGON);
    glColor3f(0.1 + col, 0.4 + col, 0.1 + col);
    glVertex2f(921, 364);
    glVertex2f(921, 349);
    glVertex2f(947, 347);
    glVertex2f(947, 362);
    glEnd();

    //p4
    //pipe1
    glColor3f(0.48 + col, 0.27 + col, 0.44 + col);
    glBegin(GL_POLYGON);
    glVertex2f(779, 352);
    glVertex2f(779, 394);
    glVertex2f(794, 394);
    glColor3f(0.0 + col, 0.0 + col, 0.0 + col);
    glVertex2f(794, 355);
    glEnd();
    cloud(759, 394);

    //pipe2
    glColor3f(0.44 + col, 0.48 + col, 0.27 + col);
    glBegin(GL_POLYGON);
    glVertex2f(812, 356);
    glVertex2f(812, 398);
    glVertex2f(827, 398);
    glColor3f(0.0 + col, 0.0 + col, 0.0 + col);
    glVertex2f(827, 358);
    glEnd();
    cloud(792, 398);

    //pipe3
    glColor3f(0.27 + col, 0.48 + col, 0.44 + col);
    glBegin(GL_POLYGON);
    glVertex2f(859, 361);
    glVertex2f(859, 403);
    glVertex2f(879, 403);
    glColor3f(0.0 + col, 0.0 + col, 0.0 + col);
    glVertex2f(879, 360);
    glEnd();
    cloud(844, 403);
    glPopMatrix();
}

void water()
{
    glBegin(GL_POLYGON);
    glColor3f(0.2 + col, 0.2 + col, 0.6 + col);
    glVertex2f(00, 00);
    glVertex2f(00, 300);
    glVertex2f(1024, 300);
    glVertex2f(1024, 00);
    glEnd();
}

void mountain2()
{
    float a, b;
    glColor3f(0.6 + col, 0.4 + col, 0.2 + col);
    for (a = 0, b = 300; a < 1025; a = a + 250)
    {
        glBegin(GL_POLYGON);
        glVertex2f(-40 + a, b);
        glVertex2f(60 + a, b + 130);
        glVertex2f(160 + a, b);
        glEnd();
    }
}

void mountain()
{
    float a, b;
    glColor3f(0.09 + col, 0.286 + col, 0.054 + col);
    for (a = 0, b = 300; a < 1025; a = a + 150)
    {
        glBegin(GL_POLYGON);
        glVertex2f(0 + a, b);
        glVertex2f(100 + a, b + 100);
        glVertex2f(200 + a, b);
        glEnd();
    }
}

void mountain3()
{
    float a, b;
    glColor3f(0.4 + col, 0.2 + col, 0.0 + col);
    for (a = 0, b = 350; a < 1025; a = a + 300)
    {
        glBegin(GL_POLYGON);
        glVertex2f(0 + a, b);
        glVertex2f(110 + a, b + 180);
        glVertex2f(260 + a, b);
        glEnd();
    }
}

void flag(float x)
{
    int s;
    glPushMatrix();
    glTranslatef(x, 0, 0);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(245, 160);
    glVertex2f(245, 250);
    glVertex2f(242, 250);
    glVertex2f(242, 160);
    glEnd();
    glColor3f(0.8, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(245, 250);
    glVertex2f(275, 215);
    glVertex2f(245, 180);
    glEnd();
    glRasterPos2i(50, 80); //displays college name
    glPopMatrix();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glLoadIdentity();
    gluOrtho2D(0, 1024, 0, 768);
}

void plane()
{
    glPushMatrix();
    glScalef(1.2, 1.0, 1.0);
    glTranslatef(0 + pl, 700, 0);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON); //rectangular body
    glVertex2f(0.0, 30.0 / 3);
    glVertex2f(0.0, 55.0 / 3);
    glVertex2f(135.0 / 3, 55.0 / 3);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(135.0 / 3, 30.0 / 3);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON); //upper triangle construction plane
    glVertex2f(135.0 / 3, 55.0 / 3);
    glVertex2f(150.0 / 3, 50.0 / 3);
    glVertex2f(155.0 / 3, 45.0 / 3);
    glVertex2f(160.0 / 3, 40.0 / 3);
    glVertex2f(135.0 / 3, 40.0 / 3);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP); //outline of upper triangle plane
    glVertex2f(135.0 / 3, 55.0 / 3);
    glVertex2f(150.0 / 3, 50.0 / 3);
    glVertex2f(155.0 / 3, 45.0 / 3);
    glVertex2f(160.0 / 3, 40.0 / 3);
    glVertex2f(135.0 / 3, 40.0 / 3);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON); //lower triangle
    glVertex2f(135.0 / 3, 40.0 / 3);
    glVertex2f(160.0 / 3, 40.0 / 3);
    glVertex2f(160.0 / 3, 37.0 / 3);
    glVertex2f(145.0 / 3, 30.0 / 3);
    glVertex2f(135.0 / 3, 30.0 / 3);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON); //back wing
    glVertex2f(0.0, 55.0 / 3);
    glVertex2f(0.0, 80.0 / 3);
    glVertex2f(10.0 / 3, 80.0 / 3);
    glVertex2f(40.0 / 3, 55.0 / 3);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON); //left side wing
    glVertex2f(65.0 / 3, 55.0 / 3);
    glVertex2f(50.0 / 3, 70.0 / 3);
    glVertex2f(75.0 / 3, 70.0 / 3);
    glVertex2f(90.0 / 3, 55.0 / 3);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON); //rightside wing
    glVertex2f(70.0 / 3, 40.0 / 3);
    glVertex2f(100.0 / 3, 40.0 / 3);
    glVertex2f(80.0 / 3, 15.0 / 3);
    glVertex2f(50.0 / 3, 15.0 / 3);
    glEnd();
    glPopMatrix();
}

void plane1()
{
    glPushMatrix();
    glScalef(-0.6, 0.6, 1.0);
    glTranslatef(-1400 + pl, 700, 0);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON); //rectangular body
    glVertex2f(0.0, 30.0 / 3);
    glVertex2f(0.0, 55.0 / 3);
    glVertex2f(135.0 / 3, 55.0 / 3);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(135.0 / 3, 30.0 / 3);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON); //upper triangle construction plane
    glVertex2f(135.0 / 3, 55.0 / 3);
    glVertex2f(150.0 / 3, 50.0 / 3);
    glVertex2f(155.0 / 3, 45.0 / 3);
    glVertex2f(160.0 / 3, 40.0 / 3);
    glVertex2f(135.0 / 3, 40.0 / 3);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP); //outline of upper triangle plane
    glVertex2f(135.0 / 3, 55.0 / 3);
    glVertex2f(150.0 / 3, 50.0 / 3);
    glVertex2f(155.0 / 3, 45.0 / 3);
    glVertex2f(160.0 / 3, 40.0 / 3);
    glVertex2f(135.0 / 3, 40.0 / 3);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON); //lower triangle
    glVertex2f(135.0 / 3, 40.0 / 3);
    glVertex2f(160.0 / 3, 40.0 / 3);
    glVertex2f(160.0 / 3, 37.0 / 3);
    glVertex2f(145.0 / 3, 30.0 / 3);
    glVertex2f(135.0 / 3, 30.0 / 3);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON); //back wing
    glVertex2f(0.0, 55.0 / 3);
    glVertex2f(0.0, 80.0 / 3);
    glVertex2f(10.0 / 3, 80.0 / 3);
    glVertex2f(40.0 / 3, 55.0 / 3);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON); //left side wing
    glVertex2f(65.0 / 3, 55.0 / 3);
    glVertex2f(50.0 / 3, 70.0 / 3);
    glVertex2f(75.0 / 3, 70.0 / 3);
    glVertex2f(90.0 / 3, 55.0 / 3);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON); //rightside wing
    glVertex2f(70.0 / 3, 40.0 / 3);
    glVertex2f(100.0 / 3, 40.0 / 3);
    glVertex2f(80.0 / 3, 15.0 / 3);
    glVertex2f(50.0 / 3, 15.0 / 3);
    glEnd();
    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    if (screen == 0)
    {
        frontscreen();
        glFlush();
    }
    else if (screen == 1)
    {
        glPushMatrix();
        glTranslatef(-25.0, -50.0, 0.0);
        mountain3();
        glPopMatrix();
        mountain2();
        mountain();
        water();

        ship(pos);
        ship1(pos1);
        flag(pos);
        plane();
        plane1();
        pl += 2;
        if (pl == 1200)
            pl = 0;
        if (i == 1)
        {
            glColor3f(0.9, 0.9, 0.5);
            Drawarc(0, 360, 200, 700, 10);
        }
        if (i == 2)
        {
            glColor3f(0.8, 0.7, 0.4);
            Drawarc(0, 360, 400, 700, 10);
        }
        if (i == 3)
        {
            glColor3f(1.0, 1.0, 1.0);
            Drawarc(0, 360, 600, 700, 10);
        }
        if (i == 4)
        {
            glColor3f(1.0, 1.0, 1.0);
            Drawarc(0, 360, 800, 700, 10);
        }
        glFlush();
    }
    glutPostRedisplay();
    glutSwapBuffers();
    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 13:
        if (screen == 0)
        {
            screen = 1;
            glutPostRedisplay();
        }
        break;
    case 27:
        exit(0);
        break;
    case 'y':
        glClearColor(0.8, 0.5, 0.4, 1.0);
        col = -0.1;
        i = 0;
        glutPostRedisplay();
        break;
    case 'm':
        glClearColor(0.5, 0.5, 1.0, 1.0);
        i = 1;
        col = 0.2;
        glutPostRedisplay();
        break;
    case 'a':
        glClearColor(0.9, 0.9, 0.3, 1.0);
        i = 2;
        col = 0.3;
        glutPostRedisplay();
        break;
    case 'e':
        glClearColor(0.8, 0.5, 0.4, 1.0);
        col = -0.1;
        i = 0;
        glutPostRedisplay();
        break;
    case 'n':
        glClearColor(0.5, 0.5, 0.5, 1.0);
        i = 3;
        glutPostRedisplay();
        col = -0.2;
        break;
    case 'd':
        glClearColor(0.0, 0.0, 0.0, 0.0);
        i = 4;
        col = -0.3;
        glutPostRedisplay();
        break;
    case '6':
        pos += 2;
        break;
    case '4':
        pos -= 2;
        break;
    case '8':
        pos1 += 2;
        break;
    case '9':
        pos1 -= 2;
        break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Moving Ship");
    glutSwapBuffers();
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}
