#include <iostream>
#include <stdlib.h>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "Settings.h"
#include "Camera.h"
#include "Screens.h"
#include "KeyboardHandler.h"
#include "MouseHandler.h"

int time = 0, timebase = 0;
int dt, totaldt, frames;
float f_dt;

ScreenManager* screenManager;

// Initialize all of the various objects that are to be used
void Init(char **argv)
{
	screenManager = ScreenManager::GetInstance();
	screenManager->ChangeScreen(new ScreenMenu());
}

// Render the scene
void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // normal transparency
	glLoadIdentity();

	screenManager->Draw();

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
		Settings::View::FOV,	// fov
		(GLfloat)w / (GLfloat)h,	// width/height ratio
		0.01, 1000.0	// near/far draw distances
	);
	Settings::View::Width = w;
	Settings::View::Height = h;
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
		std::cout << "FPS: " << (int)(1000 / ((float)totaldt / 100)) << std::endl;
		totaldt = 0;
	}
	else
	{
		totaldt += dt;
	}

	screenManager->Update(f_dt);

	if (KeyboardHandler::KeyState(27)) // Esc Key
	{
		exit(0);
	}

	if (KeyboardHandler::KeyState('1'))
	{
		screenManager->ChangeScreen(new ScreenMenu());
	}
	if (KeyboardHandler::KeyState('2'))
	{
		screenManager->ChangeScreen(new ScreenChoiceStage1());
	}
	if (KeyboardHandler::KeyState('3'))
	{
		screenManager->ChangeScreen(new ScreenStage1Asteroid());
	}

	if (KeyboardHandler::KeyState('q'))
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glDisable(GL_CULL_FACE);
	}
	if (KeyboardHandler::KeyState('e'))
	{
		glPolygonMode(GL_FRONT, GL_FILL);
		glEnable(GL_CULL_FACE);
	}

	if (KeyboardHandler::SpecialKeyState(GLUT_KEY_F11))
	{
		if (Settings::View::Fullscreen)
		{
			Reshape(Settings::View::Width, Settings::View::Height);
			glutPositionWindow(100, 100);
			Settings::View::Fullscreen = false;
		}
		else
		{
			glutFullScreen();
			Settings::View::Fullscreen = true;
		}
	}

	glutPostRedisplay();
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
	bool bState;
	if (state == 0)
	{
		bState = true;
	}
	else
	{
		bState = false;
	}
	MouseHandler::SetState(button, bState);
	MouseHandler::SetPosition(x, y);
}

// Called when the mouse is moved while a button is held down
void Motion(int x, int y)
{
	MouseHandler::SetPosition(x, y);
}

// Called when the mouse is moved without a button held down
void PassiveMotion(int x, int y)
{
	MouseHandler::SetPosition(x, y);
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
	Reshape(Settings::View::Width, Settings::View::Height);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);
	
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_CULL_FACE);
	glEnable(GL_NORMALIZE);

	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);

	glEnable(GL_TEXTURE_2D);

	GLfloat DiffuseLight[] = {1.0, 1.0, 1.0};
	GLfloat AmbientLight[] = {0.0, 0.0, 0.0};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, DiffuseLight);
	glLightfv(GL_LIGHT0, GL_AMBIENT, AmbientLight);
	GLfloat LightPosition[] = {0.0, 1.0, 1.0, 0.0};
	glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
}

// Initialize (free)glut settings, registers the callback functions,
// enters the opengl event loop
int main(int argc, char **argv)
{
	Settings::Load(".\\settings.ini");

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(Settings::View::Width, Settings::View::Height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("MarsRTS");
	glewInit();
	
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

	glutIgnoreKeyRepeat(true);
	//glutSetCursor(GLUT_CURSOR_NONE);

	InitGL();

	Init(argv);

	//FreeConsole();
	
	glutMainLoop();

	return 0;
}