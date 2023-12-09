#include <windows.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

static int planet1=0, planet2=0, planet3=0, planet4=0, planet5=0, planet6=0, planet7=0, planet8=0;
static int pplanet1=0, pplanet2=0, pplanet3=0, pplanet4=0, pplanet5=0, pplanet6=0, pplanet7=0, pplanet8=0;
float x=0.0f, z=5.0f, lx=0.0f,lz=-1.0f, angle = 0.0f;
bool bird_eye = false;

void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    GLfloat mat_specular[]={1.0,1.0,1.0,1.0};
    GLfloat mat_shininess[]={50.0};
    GLfloat light_position0[]={1.0,1.0,1.0,0.0};
    glClearColor(0.0,0.0,0.0,0.0);
    glShadeModel(GL_SMOOTH);
    glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
    glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
    glLightfv(GL_LIGHT0,GL_POSITION,light_position0);
    GLfloat light_position1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
    glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_NORMALIZE);
    glEnable(GL_DEPTH_TEST);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    ///matahari
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f); //kuning
    glPushMatrix();
    glutSolidSphere(0.5,20,16);

    // planet 1
    glColor3f(0.7f, 0.7f, 0.7f); //grey
    glPushMatrix();
    glRotatef((GLfloat)planet1,0.0,1.0,0.0);
    glTranslatef(0.8,0.0,0.0);
    glRotatef((GLfloat)pplanet1,0.0,1.0,0.0);
    glutSolidSphere(0.1,20,8);
    glPopMatrix();

    // planet 2
    glColor3f(0.3f, 0.2f, 0.0f);// brown
    glPushMatrix();
    glRotatef((GLfloat)planet2,0.0,1.0,0.0);
    glTranslatef(1.3,0.0,0.0);
    glRotatef((GLfloat)pplanet2,0.0,1.0,0.0);
    glutSolidSphere(0.2,20,8);
    glPopMatrix();

    // planet 3
    glColor3f(0.0f, 0.5f, 0.5f);// blue
    glPushMatrix();
    glRotatef((GLfloat)planet3,0.0,1.0,0.0);
    glTranslatef(1.9,0.0,0.0);
    glRotatef((GLfloat)pplanet3,0.0,1.0,0.0);
    glutSolidSphere(0.2,20,8);
    glPopMatrix();

    //planet 4
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glPushMatrix();
    glRotatef((GLfloat)planet4,0.0,1.0,0.0);
    glTranslatef(2.5,0.0,0.0);
    glRotatef((GLfloat)pplanet4,0.0,1.0,0.0);
    glutSolidSphere(0.2,20,8);
    glPopMatrix();

    //planet 5
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glPushMatrix();
    glRotatef((GLfloat)planet5,0.0,1.0,0.0);
    glTranslatef(3.2,0.0,0.0);
    glRotatef((GLfloat)pplanet5,0.0,1.0,0.0);
    glutSolidSphere(0.3,20,8);
    glPopMatrix();

    //planet 6
    glColor3f(1.0f, 0.0f, 1.0f);// ungu
    glPushMatrix();
    glRotatef((GLfloat)planet6,0.0,1.0,0.0);
    glTranslatef(3.9,0.0,0.0);
    glRotatef((GLfloat)pplanet6,0.0,1.0,0.0);
    glutSolidSphere(0.2,20,8);
    glutSolidTorus(0.02,0.3,6,20);
    glPopMatrix();

    //planet 7
    glColor3f(0.0f, 0.5f, 0.5f);// blue
    glPushMatrix();
    glRotatef((GLfloat)planet7,0.0,1.0,0.0);
    glTranslatef(4.5,0.0,0.0);
    glRotatef((GLfloat)pplanet7,0.0,1.0,0.0);
    glutSolidSphere(0.2,20,8);
    glPopMatrix();

    //planet 8
    glColor3f(0.0f, 0.5f, 1.0f);// baby blue
    glPushMatrix();
    glRotatef((GLfloat)planet8,0.0,1.0,0.0);
    glTranslatef(5.2,0.0,0.0);
    glRotatef((GLfloat)planet1,0.0,1.0,0.0);
    glutSolidSphere(0.2,20,8);
    glPopMatrix();

    //bintang
    for(int i = -5; i < 5; i++) {
        for(int j= -5; j < 5; j++) {
            glPushMatrix();
            glColor3f(7.5, 9.5, 2.0);
            glTranslatef(i*3.0,0,j * 5.0);
            glutSolidSphere(0.03,20,8);
            glPopMatrix();
        }
    }

    glutSwapBuffers();
}

void changeSize(int w, int h)
{
    if (h == 0)
    h = 1;
    float ratio = w * 1.0 / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(50.0f, ratio, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

void renderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    if(bird_eye == true)
    {
        gluLookAt(0.0f, 15 , 0.0f, 0.0f, 0, 0.0f, 0, 0.0f, -1.0f);
    }
    else
    {
        gluLookAt( x, 1.2f, z, x+lx, 1.0f, z+lz, 0.0f, 1.0f, 0.0f);
    }
    display();
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key) {
        case 'b':
            if(bird_eye == true)
            {
                bird_eye = false;
            }
            else
            {
                bird_eye = true;
            }
        break;
        case '1':
            planet1=(planet1+7)%360; glutPostRedisplay();
            pplanet1=(planet1+7)%360; glutPostRedisplay();
        break;
        case '2':
            planet2=(planet2+6)%360; glutPostRedisplay();
            pplanet2=(planet2+6)%360; glutPostRedisplay();
        break;
        case '3':
            planet3=(planet3+5)%360; glutPostRedisplay();
            pplanet3=(planet3+5)%360; glutPostRedisplay();
        break;
        case '4':
            planet4=(planet4+8)%360; glutPostRedisplay();
            pplanet4=(planet4+8)%360; glutPostRedisplay();
        break;
        case '5':
            planet5=(planet5+4)%360; glutPostRedisplay();
            pplanet5=(planet5+4)%360; glutPostRedisplay();
        break;
        case '6':
            planet6=(planet6+3)%360; glutPostRedisplay();
            pplanet6=(planet6+3)%360; glutPostRedisplay();
        break;
        case '7':
            planet7=(planet7+2)%360; glutPostRedisplay();
            pplanet7=(planet7+2)%360; glutPostRedisplay();
        break;
        case '8':
            planet8=(planet8+1)%360; glutPostRedisplay();
            pplanet8=(planet8+1)%360; glutPostRedisplay();
        break;
        case 'r':
            pplanet1=(pplanet1+7)%360; glutPostRedisplay();
            pplanet2=(pplanet2+6)%360; glutPostRedisplay();
            pplanet3=(pplanet3+5)%360; glutPostRedisplay();
            pplanet4=(pplanet4+8)%360; glutPostRedisplay();
            pplanet5=(pplanet5+4)%360; glutPostRedisplay();
            pplanet6=(pplanet6+3)%360; glutPostRedisplay();
            pplanet7=(pplanet7+2)%360; glutPostRedisplay();
            pplanet8=(pplanet8+1)%360; glutPostRedisplay();
        break;
        case 'y':
            planet1=(planet1+7)%360; glutPostRedisplay();
            planet2=(planet2+6)%360; glutPostRedisplay();
            planet3=(planet3+5)%360; glutPostRedisplay();
            planet4=(planet4+8)%360; glutPostRedisplay();
            planet5=(planet5+4)%360; glutPostRedisplay();
            planet6=(planet6+3)%360; glutPostRedisplay();
            planet7=(planet7+2)%360; glutPostRedisplay();
            planet8=(planet8+1)%360; glutPostRedisplay();
        break;
        case 'z':
            pplanet1=(pplanet1+7)%360; glutPostRedisplay();
            pplanet2=(pplanet2+6)%360; glutPostRedisplay();
            pplanet3=(pplanet3+5)%360; glutPostRedisplay();
            pplanet4=(pplanet4+8)%360; glutPostRedisplay();
            pplanet5=(pplanet5+4)%360; glutPostRedisplay();
            pplanet6=(pplanet6+3)%360; glutPostRedisplay();
            pplanet7=(pplanet7+2)%360; glutPostRedisplay();
            pplanet8=(pplanet8+1)%360; glutPostRedisplay();
            planet1=(planet1+7)%360; glutPostRedisplay();
            planet2=(planet2+6)%360; glutPostRedisplay();
            planet3=(planet3+5)%360; glutPostRedisplay();
            planet4=(planet4+8)%360; glutPostRedisplay();
            planet5=(planet5+4)%360; glutPostRedisplay();
            planet6=(planet6+3)%360; glutPostRedisplay();
            planet7=(planet7+2)%360; glutPostRedisplay();
            planet8=(planet8+1)%360; glutPostRedisplay();
        break;
    }
}

void processSpecialKeys(int key, int xx, int yy)
{

    float fraction = 0.1f;

    switch (key) {
        case GLUT_KEY_LEFT :
            angle -= 0.01f;
            lx = sin(angle);
            lz = -cos(angle);
        break;
            case GLUT_KEY_RIGHT :
            angle += 0.01f;
            lx = sin(angle);
            lz = -cos(angle);
        break;
            case GLUT_KEY_UP :
            x += lx * fraction;
            z += lz * fraction;
        break;
            case GLUT_KEY_DOWN :
            x -= lx * fraction;
            z -= lz * fraction;
        break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(1000,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Grafikom - Kelompok 8 - C2");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(processSpecialKeys);
    glutMainLoop();

    return 0;
}
