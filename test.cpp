#include <GL/gl.h> 
#include <GL/glu.h> 
#include <GL/glut.h> 
void init(void) { 
     GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 }; 
     GLfloat mat_shininess[] = { 100.0 }; //parameter shininess 
     GLfloat light_position[] = { 1.0, 0.5, 1.0, 1.0 }; 
     glClearColor (0.0, 0.0, 0.0, 0.0); glShadeModel (GL_SMOOTH); 
     glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular); 
     glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess); 
     glLightfv(GL_LIGHT0, GL_POSITION, light_position); 
     glEnable(GL_LIGHTING); 
     glEnable(GL_LIGHT0); 
     glEnable(GL_NORMALIZE); glShadeModel(GL_SMOOTH); //add positioned light 
     GLfloat lightColor0[] = {0.7f, 0.7f, 0.7f, 1.0f}; GLfloat lightPos0[] = {5.0f, 7.0f, 5.0f, 1.0f}; 
     glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0); glLightfv(GL_LIGHT0, GL_POSITION, lightPos0); glPopMatrix(); 
     glEnable(GL_DEPTH_TEST); } 
void display(void) { 
     const double t= glutGet(GLUT_ELAPSED_TIME) /1000.0; 
     const double a = t*90.0, b = t/2, c = t/10; glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glEnable(GL_COLOR_MATERIAL); 
     glColorMaterial(GL_FRONT, GL_DIFFUSE); //parameter-parameter fungsi warna material 
     glPushMatrix(); glColor3f(0.2, 1.0, 0.7); 
     glRotatef(90.0, 1.0, 0.0, 0.0); 
     glutSolidSphere (0.4, 100, 16); 
     glPopMatrix(); glPushMatrix(); 
     glColor3f(0.5, 1.0, 0.5); //
     glScalef(1.5, 0.5, 0.0); 
     glTranslatef(0.5, 0.5, -5.0); 
     glRotatef(45.0, 0.0, 1.0, 0.7); 
     glutSolidCube (0.6); 
     glPopMatrix(); 
     glPushMatrix(); 
     glColor3f(0.5, 0.5, 1.0); 
     glTranslatef(1.0, 0.0, 0.0); 
     glRotatef(10.0, 0.0, 1.0, 0.7); 
     glutWireCube (0.5); 
     glPopMatrix(); 
     glPushMatrix(); 
     glColor3f(1.0, 1.0, 0.5); 
     glTranslatef(-1.0, 1.0, 0.0); 
     glRotatef(0.0, 0.0, 1.0, 0.7); 
     glutWireTeapot (0.4); 
     glPopMatrix(); 
     glPushMatrix();
     glColor3f(1.0, 0.0, 0.5); 
     glTranslatef(1.0, 1.0, 0.0); 
     glRotatef(-a, 0.0, 1.0, 0.0); 
     glutSolidTeapot (0.4); 
     glPopMatrix(); 
     glPushMatrix(); 
     glColor3f(1.0, 0.0, 0.5); 
     glTranslatef(-1.0, -1.0, 0.0); 
     glRotatef(45.0, -0.5, 0.5, 0.2); 
     glScaled(0.5,0.5,0.5); 
     glutSolidTorus (0.1, 0.3, 50, 50); 
     glPopMatrix(); glPushMatrix(); 
     glColor3f(0.5, 1.0, 0.5); 
     glTranslatef(1.0, -1.0, 0.0); 
     glRotatef(45.0, 0.5, 0.5, 0.2); 
     glutWireTorus (0.1, 0.3, 50, 50); 
     glPopMatrix(); 
     glPushMatrix(); 
     glColor3f(0.2, 0.8, 1.0); 
     glTranslatef(0.0, -1.0, 0.0); 
     glRotatef(105.0, -0.5, 0.5, 0.2); 
     glutSolidCone (0.2, 0.5, 50, 50); 
     glPopMatrix(); 
     glPushMatrix(); 
     glColor3f(0.5, 0.2, 1.0); 
     glTranslatef(0.0, 1.0, 0.0); 
     glRotatef(-45.0, -0.5, 0.5, 0.2);
     glutWireCone (0.2, 0.5, 50, 50); 
     glPopMatrix(); 
     glPopMatrix(); 
     glDisable(GL_COLOR_MATERIAL); //menonaktifkan fungsi untuk memberikan warna pada material 
     glFlush (); 
     glutPostRedisplay(); } 
void reshape (int w, int h) { 
     glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
     glMatrixMode (GL_PROJECTION); 
     glLoadIdentity(); 
     if (w <= h) glOrtho (-1.5, 1.5, -1.5*(GLfloat)h/(GLfloat)w, 1.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0); 
     else glOrtho (-1.5*(GLfloat)w/(GLfloat)h, 1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0, 10.0); 
     glMatrixMode(GL_MODELVIEW); 
     glLoadIdentity(); 
     gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); } 
int main(int argc, char** argv) { 
    glutInit(&argc, argv); 
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); 
    glutInitWindowSize (1024, 700); 
    glutInitWindowPosition (100, 70); 
    glutCreateWindow ("Program Pencahayaan dan Shading"); init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape); 
    glutMainLoop(); return 0; 
}
