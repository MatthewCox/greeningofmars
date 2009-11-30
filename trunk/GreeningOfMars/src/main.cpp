#include <iostream>
#include <windows.h>

#include <GL/GL.h>
#include <GL/GLU.h>
#include <GL/freeglut.h>

#include "Map.h"
#include "Camera.h"
#include "KeyboardHandler.h"
#include "HUD.h"
#include "SwishyButton.h"

using namespace std;

bool fullscreen = false;
int screenWidth = 1024, screenHeight = 768;

int time = 0, timebase = 0;
int dt, totaldt, frames;
float f_dt;

bool mouseLook = false;
float mouseLookMovementRatio = 0.3f;
float moveSpeed = 10.0f;

Map* map;
Camera* camera;
SwishyButton* buttonTest;

// Initialize all of the various objects that are to be used
void Init(char **argv)
{
	map = new Map();
	map->Load("land.txt");
	camera = new Camera(Vector3f(7.5, 4, 7), 0, 0);
	buttonTest = new SwishyButton(0.0f, (float)(screenHeight / 2) - 25.0f, 200.0f, 50.0f, "Test", "C:\\Windows\\Fonts\\tahoma.ttf", 1);
}

// Render the scene
void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // normal transparency
	glLoadIdentity();

	camera->Display();
	
	map->Draw();

	HUD::Start(screenWidth, screenHeight);
	buttonTest->Draw();
	HUD::End();

	glutSwapBuffers();
}

// Called when the window is resized in some way
// eg, borders dragged, going to fullscreen, etc
void Reshape(int w, int h)
{
	glViewport(
		0, 0,
		(GLsizei)w, (GLsizei)h
	);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(
		90,	// fov
		(GLfloat)w / (GLfloat)h,	// width/height ratio
		0.01, 1000.0	// near/far draw distances
	);
	screenWidth = w;
	screenHeight = h;
	glMatrixMode(GL_MODELVIEW);
}

// Called when the program is idle
void Idle(void)
{
	time = glutGet(GLUT_ELAPSED_TIME);
	
	dt = (time - timebase);
	f_dt = (float)dt / 1000;
	timebase = time;

	frames++;
	if (frames == 100)
	{
		frames = 0;
		cout << "FPS: " << (int)(1000 / ((float)totaldt / 100)) << endl;
		totaldt = 0;
	}
	else
	{
		totaldt += dt;
	}
	
	glutPostRedisplay();

	buttonTest->Update(f_dt);

	if (KeyboardHandler::KeyState('w'))
	{
		camera->MoveForwards(moveSpeed * f_dt);
	}
	if (KeyboardHandler::KeyState('s'))
	{
		camera->MoveBackwards(moveSpeed * f_dt);
	}
	if (KeyboardHandler::KeyState('a'))
	{
		camera->MoveLeft(moveSpeed * f_dt);
	}
	if (KeyboardHandler::KeyState('d'))
	{
		camera->MoveRight(moveSpeed * f_dt);
	}
	if (KeyboardHandler::KeyState(27)) // Esc key
	{
		exit(0);
	}

	if (KeyboardHandler::SpecialKeyState(GLUT_KEY_F11))
	{
		if (fullscreen)
		{
			Reshape(screenWidth, screenHeight);
			glutPositionWindow(100, 100);
			fullscreen = false;
		}
		else
		{
			glutFullScreen();
			fullscreen = true;
		}
	}
}

// Called when a regular (character-producing) key is pressed
void KeyboardDown(unsigned char key, int x, int y)
{
	KeyboardHandler::KeyDown(key);
}
// Called when a regular (character-producing) key is released
void KeyboardUp(unsigned char key, int x, int y)
{
	KeyboardHandler::KeyUp(key);
}

// Called when a special (non character-producing) key is pressed
void SpecialKeyboardDown(int key, int x, int y)
{
	KeyboardHandler::SpecialKeyDown(key);
}
// Called when a special (non character-producing) key is released
void SpecialKeyboardUp(int key, int x, int y)
{
	KeyboardHandler::SpecialKeyUp(key);
}

// Called when the mouse is clicked
void Mouse(int button, int state, int x, int y)
{
	if (buttonTest->CheckClicked(x, y, button, state))
	{
		cout << "Clicked" << endl;
	}
}

// Called when the mouse is moved while a button is held down
void Motion(int x, int y)
{
	if (mouseLook)
	{
		camera->MouseLook(x, y, mouseLookMovementRatio);
	}
}

// Called when the mouse is moved without a button held down
void PassiveMotion(int x, int y)
{
	if (mouseLook)
	{
		camera->MouseLook(x, y, mouseLookMovementRatio);
	}
}

// Called when the mouse enters or leaves the window
void EnterLeave(int state)
{
	if (state == GLUT_LEFT)
	{
		glutWarpPointer(
			glutGet(GLUT_WINDOW_WIDTH) / 2,
			glutGet(GLUT_WINDOW_HEIGHT) /2
		);
	}
}

// Initialize OpenGL settings
void InitGL()
{
	Reshape(screenWidth, screenHeight);

	glClearColor(0.0, 0.0, 0.0, 1.0);
	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_NORMALIZE);

	//glPolygonMode(GL_FRONT, GL_LINE);

	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);

    //glEnable(GL_LIGHTING);
}

// Initialize (free)glut settings, registers the callback functions,
// enters the opengl event loop
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("MarsRTS");
	
	glutDisplayFunc(Display);
	glutIdleFunc(Idle);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(KeyboardDown);
	glutKeyboardUpFunc(KeyboardUp);
	glutSpecialFunc(SpecialKeyboardDown);
	glutSpecialUpFunc(SpecialKeyboardUp);
	glutMouseFunc(Mouse);
	glutMotionFunc(Motion);
	glutPassiveMotionFunc(PassiveMotion);
	//glutEntryFunc(EnterLeave);

	glutIgnoreKeyRepeat(true);
	//glutSetCursor(GLUT_CURSOR_NONE);

	InitGL();

	Init(argv);

	//FreeConsole();
	
	glutMainLoop();
	
	return 0;
}