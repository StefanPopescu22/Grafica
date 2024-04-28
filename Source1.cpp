#include <GL/glut.h>
#include <vector>

std::vector<std::vector<float>> vertices = {
    {1, -1, -1}, 
    {1, -1, 1},  
    {-1, -1, 1},  
    {-1, -1, -1},
    {0, 1, 0}    
};


std::vector<std::pair<int, int>> edges = {
    {0, 1}, {1, 2}, {2, 3}, {3, 0}, 
    {0, 4}, {1, 4}, {2, 4}, {3, 4}  
};

float front_color[3] = { 1, 1, 1 };   
float back_color[3] = { 0.5, 0.5, 0.5 };


void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -5.0f); 
    glRotatef(1, 1, 1, 1); 

    
    glColor3fv(front_color);
    glBegin(GL_LINES);
    for (auto edge : edges) {
        glVertex3fv(&vertices[edge.first][0]);
        glVertex3fv(&vertices[edge.second][0]);
    }
    glEnd();

    
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0xF0F0);
    glColor3fv(back_color);
    glBegin(GL_LINES);
    for (auto edge : edges) {
        glVertex3fv(&vertices[edge.first][0]);
        glVertex3fv(&vertices[edge.second][0]);
    }
    glEnd();
    glDisable(GL_LINE_STIPPLE);

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)w / (GLfloat)h, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Square Pyramid Wireframe");

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
