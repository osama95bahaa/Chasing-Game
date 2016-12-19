#include<glut.h>
#include<math.h>
#include<stdio.h>


void time(int);
void Anim(void);
void drawBitmapText(char *string, float x, float y, float z);
void closeWindow(char *string, float x, float y, float z);


double passX = 0; // translation of the player
double passY = 0;

double actx = 0; //translation of first chaser
double acty = 0;

double actx1 = 0; // translation of the 2nd chaser
double acty1 = 0;

double trax = (glutGet(GLUT_INIT_WINDOW_WIDTH) + 300); // translation of the first chased
double tray = (glutGet(GLUT_INIT_WINDOW_HEIGHT) - 400);


double tx = glutGet(GLUT_INIT_WINDOW_WIDTH) + 300; // translation if the 2nd chased
double ty = glutGet(GLUT_INIT_WINDOW_HEIGHT) - 400;

int score = 0;
int mode; // mode=0 is the time based game   ,    mode=1 is the one kill game 

char string[50];
char ti[50];
char ready1[50];
char active[50];
char use[50];
char mod[50];
char game[50];
char str[50];
char close[50];
char msg[50];
char msg2[100];
char msg3[100];
char msg4[100];
char msg5[100];

int doubleScore = 0;
int chaserStun = 0;
int ready = 0;
int activated = 0;
int used = 0;
int message = 0;


int checker = 0;
bool gameOver = false;
bool gameStart = false;
int check = 0;
bool moving = true;


int seconds = 0;
int stoppageTime = 300;


void drawBitmapText(char *string, float x, float y, float z)
{
	char *c;
	glRasterPos3f(x, y, z);

	for (c = string; *c != ' '; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);

	}
}


void closeWindow(char *string, float x, float y, float z)
{
	char *c;
	glRasterPos3f(x, y, z);

	for (c = string; *c != '.'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);

	}
}


void Display() {

	glClearColor(0, 0, 0, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, glutGet(GLUT_WINDOW_WIDTH), 0.0, glutGet(GLUT_WINDOW_HEIGHT));
	glMatrixMode(GL_MODELVIEW);

	//player
	glPushMatrix();
	glTranslated(passX, passY, 0);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 0);
	glVertex3f(0, 0, 0.0f);
	glVertex3f(50, 0, 0.0f);
	glVertex3f(50, 50, 0.0f);
	glVertex3f(0, 50, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(1, 0, 0);
	glVertex3f(50, 50, 0);
	glVertex3f(75, 50, 0);
	glVertex3f(50, 25, 0);
	glEnd();
	glPopMatrix();



	// chased 1
	glPushMatrix();
	glTranslated(trax, tray, 0);
	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);
	glVertex3f(0, 50, 0.0f);
	glVertex3f(50, 50, 0.0f);
	glVertex3f(50, 100, 0.0f);
	glVertex3f(0, 100, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(1, 0, 1);
	glVertex3f(50, 100, 0);
	glVertex3f(75, 75, 0);
	glVertex3f(50, 75, 0);
	glEnd();
	glPopMatrix();



	// chased 2
	glPushMatrix();
	glTranslated(tx, ty, 0);
	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);
	glVertex3f(0, 50, 0.0f);
	glVertex3f(50, 50, 0.0f);
	glVertex3f(50, 100, 0.0f);
	glVertex3f(0, 100, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(1, 0, 1);
	glVertex3f(50, 100, 0);
	glVertex3f(75, 75, 0);
	glVertex3f(50, 75, 0);
	glEnd();
	glPopMatrix();



	// chaser 1
	glPushMatrix();
	glTranslated(actx, acty, 0);
	glBegin(GL_QUADS);
	glColor3f(0.8, 0.5, 0);
	glVertex3f(0, 0, 0.0f);
	glVertex3f(50, 0, 0.0f);
	glVertex3f(50, 50, 0.0f);
	glVertex3f(0, 50, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.9, 1, 0);
	glVertex3f(50, 50, 0);
	glVertex3f(75, 50, 0);
	glVertex3f(50, 25, 0);
	glEnd();
	glPopMatrix();


	//chaser 2
	glPushMatrix();
	glTranslated(actx1, acty1, 0);
	glBegin(GL_QUADS);
	glColor3f(0.8, 0.5, 0);
	glVertex3f(0, 0, 0.0f);
	glVertex3f(50, 0, 0.0f);
	glVertex3f(50, 50, 0.0f);
	glVertex3f(0, 50, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.9, 1, 0);
	glVertex3f(50, 50, 0);
	glVertex3f(75, 50, 0);
	glVertex3f(50, 25, 0);
	glEnd();
	glPopMatrix();




	if (gameStart == true)
	{

		glColor3f(1, 1, 1);
		drawBitmapText(string, 1200, 730, 0);
		drawBitmapText(ti, 600, 730, 0);
		drawBitmapText(ready1, 20, 730, 0);
		drawBitmapText(active, 20, 700, 0);
		drawBitmapText(use, 20, 670, 0);
		drawBitmapText(mod, 1170, 700, 0);

	}


	if (gameStart == true && ready == 1)
	{
		glColor3f(1, 0, 0);
		closeWindow(msg3, 400, 700, 0);
		closeWindow(msg5, 400, 670, 0);
		closeWindow(msg4, 400, 640, 0);
	}

	if (gameOver == true)
	{
		glColor3f(1, 0, 0);
		closeWindow(game, glutGet(GLUT_WINDOW_WIDTH) / 2, glutGet(GLUT_WINDOW_HEIGHT) / 2, 0);
		closeWindow(str, (glutGet(GLUT_WINDOW_WIDTH) / 2), (glutGet(GLUT_WINDOW_HEIGHT) / 2) - 30, 0);
		closeWindow(close, (glutGet(GLUT_WINDOW_WIDTH) / 2), (glutGet(GLUT_WINDOW_HEIGHT) / 2) - 60, 0);
	}


	if (gameStart == false) {

		glColor3f(1, 0, 0);
		closeWindow(msg, (glutGet(GLUT_WINDOW_WIDTH) / 2) - 200, (glutGet(GLUT_WINDOW_HEIGHT) / 2), 0);
		closeWindow(msg2, (glutGet(GLUT_WINDOW_WIDTH) / 2) - 300, (glutGet(GLUT_WINDOW_HEIGHT) / 2) - 30, 0);

	}


	glFlush();
}


void passM(int x, int y)
{


	if (gameStart == true && gameOver == false)
	{
		passX = x;
		passY = -y + glutGet(GLUT_WINDOW_HEIGHT);

	}
	else

	{
		if (gameStart == false)
		{

			passX = (glutGet(GLUT_WINDOW_WIDTH) / 2) + 400;
			passY = (glutGet(GLUT_WINDOW_HEIGHT) / 2) - 200;

		}
	}



	glutPostRedisplay();
}


void actM(int button, int state, int x, int y)
{

	if (seconds >30)
	{


		if (button == GLUT_LEFT_BUTTON &&checker == 0)
		{
			stoppageTime = seconds;

			chaserStun = 1;
			activated = 1;
			ready = 0;
			checker = 1;
		}
		else
		{
			if (button == GLUT_RIGHT_BUTTON &&checker == 0)
			{
				stoppageTime = seconds;

				doubleScore = 1;
				activated = 1;
				ready = 0;
				checker = 1;
			}
		}
	}


	glutPostRedisplay();
}

void key(unsigned char k, int x, int y)
{
	if (k == 'q')

		exit(0);



	if ((k == 'k' || k == 'K') && check == 0)
	{
		mode = 1;
		check = 1;
		gameStart = true;

	}
	if ((k == 't' || k == 'T') && check == 0)
	{
		mode = 0;
		check = 1;
		gameStart = true;
	}




}


void Anim() {

	//choosing game mode
	sprintf_s(msg, "Please choose your desired game mode.", message);
	puts(msg);

	sprintf_s(msg2, "for OneshotKill mode type 'k' , for TimeBased mode type 't'.", message);
	puts(msg2);



	if (gameOver == false && gameStart == true)
	{


		//chaser 1

		if (activated == 1 && chaserStun == 1 && used == 0)
		{
			moving = false;
			//actx = 0;
			//acty = 0;
		}
		else
		{
			if (used == 1)
			{
				moving = true;

			}

			double xDistance = passX - actx;
			double yDistance = passY - acty;


			double distance = sqrt(xDistance*xDistance + yDistance *yDistance);

			if (distance > 60) {
				if (moving == true)
				{

					actx += (xDistance / distance) * 2;
					acty += (yDistance / distance) * 2;

				}
				else
				{

				}

			}

			else
			{
				if (mode == 1)
				{
					//exit(0);
					gameOver = true;
				}
				else
				{

					actx = 0;
					acty = 0;

					if (activated == 1 && doubleScore == 1 && used == 0)
					{
						score = score - 1;
					}
					else {
						score = score - 2;
						printf("score after chaser 1 eats me %i --- ", score);
					}


				}
			}
		}

		//////////////////////////////////////////////////////////////////////////////////////////

		//chaser 2

		if (activated == 1 && chaserStun == 1 && used == 0)
		{
			moving = false;
			//actx1 = 0;
			//acty1 = 0;
		}
		else
		{
			if (used == 1)
			{
				moving = true;

			}

			double xDistance1 = passX - actx1;
			double yDistance1 = passY - acty1;

			double distance1 = sqrt(xDistance1*xDistance1 + yDistance1 *yDistance1);

			if (distance1 > 60) {
				if (moving == true)
				{
					actx1 += (xDistance1 / distance1)*1.3;
					acty1 += (yDistance1 / distance1)*1.3;
				}
				else
				{

				}

			}
			else
			{
				if (mode == 1) {
					//exit(0);
					gameOver = true;
				}
				else
				{

					actx1 = 0;
					acty1 = 0;

					if (activated == 1 && doubleScore == 1 && used == 0)
					{
						score = score - 1;

					}
					else
					{

						score = score - 2;
						printf("score after chaser 2 eats me %i ---", score);

					}
				}
			}

		}
		//////////////////////////////////////////////////////////////////////////////////////////

		//chased 1
		double xDistance2 = passX - trax;
		double yDistance2 = passY - tray;


		double distance2 = sqrt(xDistance2*xDistance2 + yDistance2 *yDistance2);


		if (distance2 > 70) {
			trax -= (xDistance2 / distance2) * 1;
			tray -= (yDistance2 / distance2) * 1;
		}
		else
		{
			trax = glutGet(GLUT_WINDOW_WIDTH) / 2;
			tray = glutGet(GLUT_WINDOW_HEIGHT) / 2;
			if (activated == 1 && doubleScore == 1 && used == 0)
			{
				score = score + 4;
			}
			else
			{

				score = score + 2;
				printf("score after i eat chased 1 %i---", score);

			}
		}



		if (trax > glutGet(GLUT_INIT_WINDOW_WIDTH) + 1050) {
			trax = glutGet(GLUT_INIT_WINDOW_WIDTH) + 300;
			tray = glutGet(GLUT_INIT_WINDOW_HEIGHT);
		}
		if (trax < glutGet(GLUT_INIT_WINDOW_WIDTH) - 370)
		{
			trax = glutGet(GLUT_INIT_WINDOW_WIDTH) + 300;
			tray = glutGet(GLUT_INIT_WINDOW_HEIGHT);
		}

		if (tray > glutGet(GLUT_INIT_WINDOW_HEIGHT) + 450)
		{
			trax = glutGet(GLUT_INIT_WINDOW_WIDTH) + 300;
			tray = glutGet(GLUT_INIT_WINDOW_HEIGHT);

		}

		if (tray < glutGet(GLUT_INIT_WINDOW_HEIGHT) - 400)
		{
			trax = glutGet(GLUT_INIT_WINDOW_WIDTH) + 300;
			tray = glutGet(GLUT_INIT_WINDOW_HEIGHT);
		}

		//////////////////////////////////////////////////////////////////////////////////////////

		//chased 2
		double xDistance3 = passX - tx;
		double yDistance3 = passY - ty;

		double distance3 = sqrt(xDistance3*xDistance3 + yDistance3 *yDistance3);

		if (distance3 > 70) {
			tx -= (xDistance3 / distance3)*1.4;
			ty -= (yDistance3 / distance3)*1.4;
		}
		else
		{
			tx = glutGet(GLUT_WINDOW_WIDTH) / 2;
			ty = glutGet(GLUT_WINDOW_HEIGHT) / 2;

			if (activated == 1 && doubleScore == 1 && used == 0)
			{
				score = score + 4;

			}
			else
			{
				score = score + 2;
				printf("score after i eat chased 2 %i---", score);
			}

		}



		if (tx > (glutGet(GLUT_INIT_WINDOW_WIDTH) + 1050)) {
			tx = glutGet(GLUT_INIT_WINDOW_WIDTH) + 300;
			ty = glutGet(GLUT_INIT_WINDOW_HEIGHT);
		}
		if (tx < glutGet(GLUT_INIT_WINDOW_WIDTH) - 370)
		{
			tx = glutGet(GLUT_INIT_WINDOW_WIDTH) + 300;
			ty = glutGet(GLUT_INIT_WINDOW_HEIGHT);
		}

		if (ty > glutGet(GLUT_INIT_WINDOW_HEIGHT) + 450)
		{
			tx = glutGet(GLUT_INIT_WINDOW_WIDTH) + 300;
			ty = glutGet(GLUT_INIT_WINDOW_HEIGHT);

		}

		if (ty < glutGet(GLUT_INIT_WINDOW_HEIGHT) - 400)
		{
			tx = glutGet(GLUT_INIT_WINDOW_WIDTH) + 300;
			ty = glutGet(GLUT_INIT_WINDOW_HEIGHT);
		}




		//printing score
		sprintf_s(string, "Score:%i ", score);
		puts(string);

		//printing time
		sprintf_s(ti, "Time:%i ", glutGet(GLUT_ELAPSED_TIME) / 1000);
		puts(ti);

		//printing activated
		sprintf_s(active, "Activated:%i ", activated);
		puts(active);

		//printing used
		sprintf_s(use, "Used:%i ", used);
		puts(use);


		//printing ready
		sprintf_s(ready1, "Ready:%i ", ready);
		puts(ready1);


		//printing game mode
		if (mode == 0) {
			sprintf_s(mod, "Mode:TimeBased ", mode);
			puts(mod);
		}
		else
		{
			sprintf_s(mod, "Mode:OneShotKill ", mode);
			puts(mod);
		}

		//printing GameOver
		sprintf_s(game, "Game Over. ", game);
		puts(game);


		//printing score after game ends
		sprintf_s(str, "Your Score = %i. ", score);
		puts(str);




		//press q to exit 
		sprintf_s(close, "Press 'q' to exit.", score);
		puts(close);



		//ready state
		if (glutGet(GLUT_ELAPSED_TIME) > 30000 && activated == 0 && used == 0) {

			ready = 1;

		}



		//game close after 5 minutes

		if (mode == 0) {
			if (seconds >= 300) {
				//exit(0);
				gameOver = true;
			}

		}


		//printing message for using powerups
		sprintf_s(msg3, "Now your powerUps are ready!.", message);
		puts(msg3);

		sprintf_s(msg4, "for DoubleScore press Right Mouse Button.", message);
		puts(msg4);


		sprintf_s(msg5, "for ChaserStun press Left Mouse Button.", message);
		puts(msg5);

	}

	glutPostRedisplay();

}


void time(int val) {



	seconds++;

	if (seconds >30 && seconds > stoppageTime + 30)
	{
		used = 1;
		activated = 0;
	}




	glutPostRedisplay();
	glutTimerFunc(1000, time, 0);

}

void main(int argc, char** argr) {
	glutInit(&argc, argr);
	glutCreateWindow("Chase Game");
	glutDisplayFunc(Display);
	glutPassiveMotionFunc(passM);
	glutMouseFunc(actM);
	glutKeyboardFunc(key);
	glutIdleFunc(Anim);
	glutTimerFunc(0, time, 0);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glutFullScreen();


	glutMainLoop();//don't call any method after this line as it will not be reached.
}
