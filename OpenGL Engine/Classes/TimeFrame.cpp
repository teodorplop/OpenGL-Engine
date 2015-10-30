#include "TimeFrame.h"
#include "Engine.h"
#include <GL/freeglut.h>

#define DELAY 16.666666f

bool TimeFrame::running = false;
int TimeFrame::lastUpdate = 0;

void TimeFrame::Start() {
	if (!running) {
		running = true;
		glutIdleFunc(IdleFunction);
	}
}
void TimeFrame::Stop() {
	if (running) {
		running = false;
		glutIdleFunc(NULL);
	}
}

void TimeFrame::IdleFunction() {
	int now = glutGet(GLUT_ELAPSED_TIME);
	float timeElapsed = (float)now - lastUpdate;

	if (timeElapsed >= DELAY) {
		while (timeElapsed >= DELAY) {
			timeElapsed -= DELAY;

			Engine::Update();
			glutPostRedisplay();
		}

		lastUpdate = now;
	}
}