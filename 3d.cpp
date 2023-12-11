#include <GL/glut.h>

GLfloat angleX = 0.0f;
GLfloat angleY = 0.0f;
GLfloat angleZ = 0.0f;

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
}

void drawCube() {
    glutWireCube(1.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -5.0f);
    glRotatef(angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);
    glRotatef(angleZ, 0.0f, 0.0f, 1.0f);

    glColor3f(1.0f, 1.0f, 1.0f);
    drawCube();

    glutSwapBuffers();
}

void specialKeys(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_RIGHT:
        angleY += 5.0f;
        break;
    case GLUT_KEY_LEFT:
        angleY -= 5.0f;
        break;
    case GLUT_KEY_UP:
        angleX += 5.0f;
        break;
    case GLUT_KEY_DOWN:
        angleX -= 5.0f;
        break;
    }
    glutPostRedisplay();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width / height, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("3D Cube Rotation");
    glutInitWindowSize(800, 600);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys);
    init();
    glutMainLoop();
    return 0;
}
