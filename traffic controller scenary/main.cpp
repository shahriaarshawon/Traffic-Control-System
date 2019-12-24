#include<stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<GL/glut.h>
#include <GL/gl.h>
#include <iostream>

#define SPEED 20.0      //speed of traffic

float s =0.0;
float i = 0.0;    //movement of car
float m = 0.0;    //movement of clouds
float n = 0.0;    //movement of plane along x-axis
float o = 0.0;    //  and y-axis
float c = 0.0;    //movement of comet	SS

int light = 1;      //1 for green-light, 0 for red-light
int day = 1;        //1 for day ,0 for night
int plane = 0;      //1 for plane
int comet = 0;      //1 for comet


void draw_pixel(GLint cx, GLint cy)
{

	glBegin(GL_POINTS);
	glVertex2i(cx, cy);
	glEnd();
}

void plotpixels(GLint h, GLint k, GLint x, GLint y)
{
	draw_pixel(x + h, y + k);
	draw_pixel(-x + h, y + k);
	draw_pixel(x + h, -y + k);
	draw_pixel(-x + h, -y + k);
	draw_pixel(y + h, x + k);
	draw_pixel(-y + h, x + k);
	draw_pixel(y + h, -x + k);
	draw_pixel(-y + h, -x + k);
}

void draw_circle(GLint h, GLint k, GLint r)
{
	GLint d = 1 - r, x = 0, y = r;
	while (y>x)
	{
		plotpixels(h, k, x, y);
		if (d<0) d += 2 * x + 3;
		else
		{
			d += 2 * (x - y) + 5;
			--y;
		}
		++x;
	}
	plotpixels(h, k, x, y);
}

void tree()
{
	glColor3f(0.545098, 0.270588, 0.0745098);
	glBegin(GL_POLYGON);
	glVertex2f(350, 325);
	glVertex2f(350, 395);
	glVertex2f(365, 395);
	glVertex2f(365, 325);
	glEnd();

	glColor3f(0.0, 0.5, 0.0);
	glBegin(GL_POLYGON);
	glVertex2i(300 - 10, 395);
	glVertex2i(420 + 10, 395);
	glVertex2i(390, 440);
	glVertex2i(330, 440);
	glEnd();
	glColor3f(0.0, 0.5, 0.0);
	glBegin(GL_POLYGON);
	glVertex2i(300, 395 + 40);
	glVertex2i(420, 395 + 40);
	glVertex2i(390 - 10, 440 + 40);
	glVertex2i(330 + 10, 440 + 40);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(300 + 10, 395 + 75);
	glVertex2i(420 - 10, 395 + 75);
	glVertex2i(360, 440 + 90);

	glEnd();



    //tree2
    glColor3f(0.545098, 0.270588, 0.0745098);
	glBegin(GL_POLYGON);
	glVertex2f(500, 360);
	glVertex2f(500, 475);
	glVertex2f(520, 475);
	glVertex2f(520, 360);
	glEnd();

    glColor3f(0.0, 0.5, 0.0);
	glBegin(GL_POLYGON);
	glVertex2i(420, 440);
	glVertex2i(580, 440);
	glVertex2i(510, 500);
	glEnd();

  glColor3f(0.0, 0.5, 0.0);
	glBegin(GL_POLYGON);
	glVertex2i(420, 460);
	glVertex2i(590, 460);
	glVertex2i(510, 515);
	glEnd();

	glColor3f(0.0, 0.5, 0.0);
	glBegin(GL_POLYGON);
	glVertex2i(420, 480);
	glVertex2i(600, 480);
	glVertex2i(510, 515);
	glEnd();


	//tree 3
	glColor3f(0.545098, 0.270588, 0.0745098);
	glBegin(GL_POLYGON);
	glVertex2f(350 + 600, 325 + 15);
	glVertex2f(350 + 600, 395 + 15);
	glVertex2f(365 + 600, 395 + 15);
	glVertex2f(365 + 600, 325 + 15);
	glEnd();
	int l;

	for (l = 0; l <= 25; l++)
	{
		glColor3f(0.0, 0.5, 0.0);
		draw_circle(340 + 600, 400 + 15, l);
		draw_circle(380 + 600, 400 + 15, l);
	}

	for (l = 0; l <= 20; l++)
	{
		glColor3f(0.0, 0.5, 0.0);
		draw_circle(350 + 600, 440 + 10, l);
		draw_circle(370 + 600, 440 + 10, l);
	}

	for (l = 0; l <= 15; l++)
	{
		glColor3f(0.0, 0.5, 0.0);
		draw_circle(360 + 600, 469 + 5, l);
	}
}

void draw_object()
{
	int l;
	if (day == 1)
	{
		//sky
		glColor3f(0.52734375, 0.8046878, 0.99765625);
		glBegin(GL_POLYGON);
		glVertex2f(0, 450);
		glColor3f(0.52734375, 0.8046878, 0.99765625);
		glVertex2f(0, 700);
		glColor3f(0.980392, 0.980392, 0.823529);
		glVertex2f(1100, 700);
		glColor3f(0.498039, 1, 0.831373);
		glVertex2f(1100, 450);
		glEnd();

		//sun
		for (l = 0; l <= 35; l++)
		{
			glColor3f(1.0, 1, 0.0);
			draw_circle(1050+s, 650-o, l);
		}


		//plane
		if (plane == 1)
		{
			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_POLYGON);
			glVertex2f(925 + n, 625 + o);
			glVertex2f(950 + n, 640 + o);
			glVertex2f(1015 + n, 640 + o);
			glVertex2f(1030 + n, 650 + o);
			glVertex2f(1050 + n, 650 + o);
			glVertex2f(1010 + n, 625 + o);
			glEnd();

			glColor3f(0.8, 0.8, 0.8);
			glBegin(GL_LINE_LOOP);
			glVertex2f(925 + n, 625 + o);
			glVertex2f(950 + n, 640 + o);
			glVertex2f(1015 + n, 640 + o);
			glVertex2f(1030 + n, 650 + o);
			glVertex2f(1050 + n, 650 + o);
			glVertex2f(1010 + n, 625 + o);
			glEnd();

		}

		//cloud1
		for (l = 0; l <= 20; l++)
		{
			glColor3f(1.0, 1.0, 1.0);
			draw_circle(160 + m - 400, 625, l);

		}


		for (l = 0; l <= 35; l++)
		{
			glColor3f(1.0, 1.0, 1.0);
			draw_circle(200 + m - 400, 625, l);
			draw_circle(225 + m - 400, 625, l);
		}

		for (l = 0; l <= 20; l++)
		{
			glColor3f(1.0, 1.0, 1.0);
			draw_circle(265 + m - 400, 625, l);
		}

		//cloud2
		for (l = 0; l <= 20; l++)
		{
			glColor3f(1.0, 1.0, 1.0);
			draw_circle(370 + m - 400, 615, l);
		}

		for (l = 0; l <= 35; l++)
		{

			glColor3f(1.0, 1.0, 1.0);
			draw_circle(410 + m - 400, 615, l);
			draw_circle(435 + m - 400, 615, l);
			draw_circle(470 + m - 400, 615, l);
		}

		for (l = 0; l <= 20; l++)
		{
			glColor3f(1.0, 1.0, 1.0);
			draw_circle(500 + m - 400, 615, l);
		}



       //hill
       glColor3f(0.50196, 0.25098, 0.0);
		glBegin(GL_POLYGON);
		glColor3f(0.95686, 0.54901, 0.25882);
		glVertex2f(0, 450);
		glVertex2f(80, 500);
		glVertex2f(120+35, 450);

		glColor3f(0.50196, 0.25098, 0.0);
		glBegin(GL_POLYGON);

		glVertex2f(150, 500);
		glVertex2f(220, 450);

		glColor3f(0.50196, 0.25098, 0.0);
		glBegin(GL_POLYGON);

		glVertex2f(200, 500);
		glVertex2f(270, 450);

		glColor3f(0.50196, 0.25098, 0.0);
		glBegin(GL_POLYGON);

		glVertex2f(270, 500);
		glVertex2f(400, 450);

		glEnd();





		//grass
		glColor3ub(0, 204, 0);
		glBegin(GL_POLYGON);
		glVertex2f(0, 160);
		glVertex2f(0, 450);
		glVertex2f(1100, 450);
		glVertex2f(1100, 160);
		glEnd();

		//pond
		glColor3f(0.0, 0.9, 0.9);
		glBegin(GL_POLYGON);
		glVertex2f(25, 350);
		glVertex2f(25, 375);
		glVertex2f(50, 400);
		glVertex2f(75, 410);
		glVertex2f(100, 420);
		glVertex2f(200, 420);
		glVertex2f(225, 410);
		glVertex2f(250, 405);
		glVertex2f(275, 390);
		glVertex2f(300, 375);
		glVertex2f(310, 350);
		glVertex2f(300, 320);
		glVertex2f(275, 300);
		glVertex2f(250, 295);
		glVertex2f(225, 290);
		glVertex2f(200, 285);
		glVertex2f(175, 280);
		glVertex2f(150, 280);
		glVertex2f(125, 280);
		glVertex2f(100, 290);
		glVertex2f(75, 300);
		glVertex2f(50, 310);
		glEnd();

		//Lamp post
		glColor3f(0.18, 0.30, 0.30);
		glBegin(GL_POLYGON);
		glVertex2i(950, 75 + 80);
		glVertex2i(900, 75 + 80);
		glVertex2i(910, 100 + 80);
		glVertex2i(940, 100 + 80);
		glEnd();
		glColor3f(0.56, 0.56, 0.73);
		glBegin(GL_POLYGON);
		glVertex2i(950, 75 + 80);
		glVertex2i(900, 75 + 80);
		glVertex2i(905, 80 + 80);
		glVertex2i(945, 80 + 80);
		glEnd();
		glColor3f(0.18, 0.30, 0.30);
		glBegin(GL_POLYGON);
		glVertex2i(940, 100 + 80);
		glVertex2i(910, 100 + 80);
		glVertex2i(910, 150 + 80);
		glVertex2i(940, 150 + 80);
		glEnd();
		glColor3f(0.56, 0.56, 0.73);
		glBegin(GL_POLYGON);
		glVertex2i(940, 125 + 80);
		glVertex2i(910, 125 + 80);
		glVertex2i(910, 130 + 80);
		glVertex2i(940, 130 + 80);
		glEnd();
		glColor3f(0.56, 0.56, 0.73);
		glBegin(GL_POLYGON);
		glVertex2i(940, 100 + 80);
		glVertex2i(910, 100 + 80);
		glVertex2i(910, 105 + 80);
		glVertex2i(940, 105 + 80);
		glEnd();
		glColor3f(0.18, 0.30, 0.30);
		glBegin(GL_POLYGON);
		glVertex2i(940, 150 + 80);
		glVertex2i(935, 150 + 80);
		glVertex2i(935, 155 + 80);
		glVertex2i(940, 155 + 80);
		glEnd();
		glColor3f(0.18, 0.30, 0.30);
		glBegin(GL_POLYGON);
		glVertex2i(910, 150 + 80);
		glVertex2i(915, 150 + 80);
		glVertex2i(915, 155 + 80);
		glVertex2i(910, 155 + 80);
		glEnd();
		glColor3f(0.56, 0.56, 0.73);
		glBegin(GL_POLYGON);
		glVertex2i(935, 150 + 80);
		glVertex2i(915, 150 + 80);
		glVertex2i(915, 155 + 80);
		glVertex2i(935, 155 + 80);
		glEnd();
		glColor3f(0.18, 0.30, 0.30);
		glBegin(GL_POLYGON);
		glVertex2i(940, 155 + 80);
		glVertex2i(910, 155 + 80);
		glVertex2i(890, 200 + 80);
		glVertex2i(960, 200 + 80);
		glEnd();

	}


	else
	{

		//sky
		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(0, 450);
		glVertex2f(0, 700);
		glVertex2f(1100, 700);
		glVertex2f(1100, 450);
		glEnd();

		//moon
		int l;

		for (l = 0; l <= 20; l++)
		{
			glColor3f(0.839216, 0.839216, 0.839216);
			draw_circle(100, 625, l);
		}

		//star1
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_TRIANGLES);
		glVertex2f(575, 653);
		glVertex2f(570, 645);
		glVertex2f(580, 645);
		glVertex2f(575, 642);
		glVertex2f(570, 650);
		glVertex2f(580, 650);
		glEnd();

		//star2
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_TRIANGLES);
		glVertex2f(975, 643);
		glVertex2f(970, 635);
		glVertex2f(980, 635);
		glVertex2f(975, 632);
		glVertex2f(970, 640);
		glVertex2f(980, 640);
		glEnd();

		//star3
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_TRIANGLES);
		glVertex2f(875, 543);
		glVertex2f(870, 535);
		glVertex2f(880, 535);
		glVertex2f(875, 532);
		glVertex2f(870, 540);
		glVertex2f(880, 540);
		glEnd();

		//star4
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_TRIANGLES);
		glVertex2f(375, 598);
		glVertex2f(370, 590);
		glVertex2f(380, 590);
		glVertex2f(375, 587);
		glVertex2f(370, 595);
		glVertex2f(380, 595);
		glEnd();

		//star5
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_TRIANGLES);
		glVertex2f(750, 628);
		glVertex2f(745, 620);
		glVertex2f(755, 620);
		glVertex2f(750, 618);
		glVertex2f(745, 625);
		glVertex2f(755, 625);
		glEnd();


      //hill
       glColor3f(0.50196, 0.25098, 0.0);
		glBegin(GL_POLYGON);
		glColor3f(0.95686, 0.54901, 0.25882);
		glVertex2f(0, 450);
		glVertex2f(80, 500);
		glVertex2f(120+35, 450);

		glColor3f(0.50196, 0.25098, 0.0);
		glBegin(GL_POLYGON);

		glVertex2f(150, 500);
		glVertex2f(220, 450);

		glColor3f(0.50196, 0.25098, 0.0);
		glBegin(GL_POLYGON);

		glVertex2f(200, 500);
		glVertex2f(270, 450);

		glColor3f(0.50196, 0.25098, 0.0);
		glBegin(GL_POLYGON);

		glVertex2f(270, 500);
		glVertex2f(400, 450);

		glEnd();





		//comet
		if (comet == 1)
		{
			for (l = 0; l <= 7; l++)
			{
				glColor3f(1.0, 1.0, 1.0);
				draw_circle(300 + c, 675 - c, l);
			}

			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_TRIANGLES);
			glVertex2f(240 + c, 749 - c);
			glVertex2f(300 + c, 682 - c);
			glVertex2f(300 + c, 668 - c);
			glEnd();
		}

		//Plane
		if (plane == 1)
		{

			for (l = 0; l <= 1; l++)
			{
				glColor3f(1.0, 0.0, 0.0);
				draw_circle(950 + n, 625 + o, l);
				glColor3f(1.0, 1.0, 0.0);
				draw_circle(954 + n, 623 + o, l);

			}

		}

		//grass
		glColor3ub(0, 128, 0);
		glBegin(GL_POLYGON);
		glVertex2f(0, 160);
		glVertex2f(0, 450);
		glColor3f(0.0, 0.4, 0.0);
		glVertex2f(1100, 450);
		glVertex2f(1100, 160);
		glEnd();

		//pond
		glColor3f(0.0, 0.0, 0.1);
		glBegin(GL_POLYGON);
		glVertex2f(25, 350);
		//glVertex2f(25, 375);
		glVertex2f(50, 400);
		glVertex2f(75, 410);
		glVertex2f(100, 420);
		glVertex2f(200, 420);
		glVertex2f(225, 410);
		glVertex2f(250, 405);
		glVertex2f(275, 390);
		glVertex2f(300, 375);
		glVertex2f(310, 350);
		glVertex2f(300, 320);
		glVertex2f(275, 300);
		glVertex2f(250, 295);
		glVertex2f(225, 290);
		glVertex2f(200, 285);
		glVertex2f(175, 280);
		glVertex2f(150, 280);
		glVertex2f(125, 280);
		glVertex2f(100, 290);
		glVertex2f(75, 300);
		glVertex2f(50, 310);
		glEnd();

		//lamp post
		glColor3f(0.18, 0.30, 0.30);
		glBegin(GL_POLYGON);
		glVertex2i(950, 155);
		glVertex2i(900, 155);
		glVertex2i(910, 180);
		glVertex2i(940, 180);
		glEnd();
		glColor3f(0.56, 0.56, 0.73);
		glBegin(GL_POLYGON);
		glVertex2i(950, 155);
		glVertex2i(900, 155);
		glVertex2i(905, 160);
		glVertex2i(945, 160);
		glEnd();
		glColor3f(0.18, 0.30, 0.30);
		glBegin(GL_POLYGON);
		glVertex2i(940, 180);
		glVertex2i(910, 180);
		glVertex2i(910, 230);
		glVertex2i(940, 230);
		glEnd();
		glColor3f(0.56, 0.56, 0.73);
		glBegin(GL_POLYGON);
		glVertex2i(940, 205);
		glVertex2i(910, 205);
		glVertex2i(910, 210);
		glVertex2i(940, 210);
		glEnd();
		glColor3f(0.56, 0.56, 0.73);
		glBegin(GL_POLYGON);
		glVertex2i(940, 180);
		glVertex2i(910, 180);
		glVertex2i(910, 185);
		glVertex2i(940, 185);
		glEnd();
		glColor3f(0.18, 0.30, 0.30);
		glBegin(GL_POLYGON);
		glVertex2i(940, 230);
		glVertex2i(935, 230);
		glVertex2i(935, 235);
		glVertex2i(940, 235);
		glEnd();
		glColor3f(0.18, 0.30, 0.30);
		glBegin(GL_POLYGON);
		glVertex2i(910, 230);
		glVertex2i(915, 230);
		glVertex2i(915, 235);
		glVertex2i(910, 235);
		glEnd();
		glColor3f(0.56, 0.56, 0.73);
		glBegin(GL_POLYGON);
		glVertex2i(935, 230);
		glVertex2i(915, 230);
		glVertex2i(915, 235);
		glVertex2i(935, 235);
		glEnd();
		glColor3f(0.18, 0.30, 0.30);
		glBegin(GL_POLYGON);
		glVertex2i(940, 235);
		glVertex2i(910, 235);
		glVertex2i(890, 280);
		glVertex2i(960, 280);
		glEnd();

		glColor3f(1, 1, 1);
		glBegin(GL_POLYGON);
		glVertex2i(935, 240);
		glVertex2i(915, 240);
		glVertex2i(900, 275);
		glVertex2i(950, 275);
		glEnd();

		glColor4f(1, 1, 1, 0.5);
		glBegin(GL_POLYGON);
		glVertex2f(940, 235);
		glVertex2f(955, 280);
		glVertex2f(1040, 305);
		glVertex2f(1040, 205);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex2f(910, 235);
		glVertex2f(895, 280);
		glVertex2f(810, 305);
		glVertex2f(810, 205);
		glEnd();

	}


	//road boundary
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(0, 150);
	glVertex2f(0, 160);
	glVertex2f(1100, 160);
	glVertex2f(1100, 150);
	glEnd();

	//road
	glColor3f(0.2, 0.2, 0.2);
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(0, 150);
	glVertex2f(1100, 150);
	glVertex2f(1100, 0);
	glEnd();

	//tree
	tree();

	//Basement
	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex2f(590, 375);
	glVertex2f(590, 345);
	glColor3f(0.7, 0.7, 0.7);
	glVertex2f(680, 295);
	glVertex2f(680, 325);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);

	glVertex2f(680, 295);
	glVertex2f(680, 325);
	glColor3f(0.7, 0.7, 0.7);
	glVertex2f(880, 375);
	glVertex2f(880, 345);
	glEnd();
	//Body
	glBegin(GL_POLYGON);
	glColor3f(0.85686, 0.89803, 0.25882);
	glVertex2f(590, 375);
	glVertex2f(590, 475);
	glColor3f(0.772549, 0.972549, 1);
	glVertex2f(635, 495);
	glVertex2f(680, 425);
	glVertex2f(680, 325);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.95686, 0.89803, 0.25882);
	glVertex2f(680, 325);
	glVertex2f(680, 425);

	glColor3f(0.972549, 0.972549, 1);
	glVertex2f(880, 475);
	glVertex2f(880, 375);
	glEnd();


	//Roof
	glBegin(GL_POLYGON);
	glColor3f(0.95686, 0.54901, 0.25882);
	glVertex2f(620, 515);
	glVertex2f(830, 545);
	glColor3f(1, 0.54902, 0);
	glVertex2f(880, 475);
	glVertex2f(680, 425);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.10, 0.10, 0.1);
	glVertex2f(620, 515);
	glVertex2f(635, 495);
	glColor3f(0.2, 0.2, 0.2);
	glVertex2f(600 - 10, 465);
	glVertex2f(570 - 10, 465);
	glEnd();


	//Doors

	glBegin(GL_POLYGON);
	glColor3f(0.0980392, 0.0980392, 0);
	glVertex2f(805, 355);
	glVertex2f(805, 387 + 40);
	//glColor3f(0.482353, 0.407843, 0.933333);
	glVertex2f(762, 415);
	glVertex2f(762, 345);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0980392, 0.0980392, 0);
	glVertex2f(647, 378);
	glVertex2f(647, 418);
	//glColor3f(0.482353, 0.407843, 0.933333);
	glVertex2f(617, 433);
	glVertex2f(617, 392);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.0980392, 0.0980392, 0);
	glVertex2f(647 + 90, 378 - 7);
	glVertex2f(647 + 90, 418 - 7);
	//glColor3f(0.482353, 0.407843, 0.933333);
	glVertex2f(617 + 90, 433 - 22 - 7);
	glVertex2f(617 + 90, 392 - 22 - 7);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0980392, 0.0980392, 0);
	glVertex2f(647 + 210, 378 - 7 + 25);
	glVertex2f(647 + 210, 418 - 7 + 25);
	//glColor3f(0.482353, 0.407843, 0.933333);
	glVertex2f(617 + 210, 433 - 22 - 7 + 25);
	glVertex2f(617 + 210, 392 - 22 - 7 + 25);
	glEnd();

	//signal

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(1060, 160);
	glVertex2f(1060, 350);
	glVertex2f(1070, 350);
	glVertex2f(1070, 160);
	glEnd();


	glColor3f(0.7, 0.7, 0.7);
	glBegin(GL_POLYGON);
	glVertex2f(1040, 350);
	glVertex2f(1040, 500);
	glVertex2f(1090, 500);
	glVertex2f(1090, 350);
	glEnd();

	for (l = 0; l <= 20; l++)
	{
		glColor3f(0.0, 0.0, 0.0);
		draw_circle(1065, 475, l);
		glColor3f(1.0, 1.0, 0.0);
		draw_circle(1065, 425, l);
		glColor3f(0.0, 0.0, 0.0);
		draw_circle(1065, 375, l);
	}

	//car 1
	glColor3f(0.9, 0.2, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(25 + i - 500, 50);
	glColor3f(0.88, 0.72, 0.0);
	glVertex2f(25 + i - 500, 125);
	glVertex2f(75 + i - 500, 200);
	glColor3f(0.7, 0.2, 0.0);
	glVertex2f(175 + i - 500, 200);
	glVertex2f(200 + i - 500, 125);
	glColor3f(0.6, 0.24, 0.0);
	glVertex2f(250 + i - 500, 115);
	glVertex2f(250 + i - 500, 50);
	glEnd();


	//windows_car1
	glColor3f(0.3, 0.4, 0.4);
	glBegin(GL_POLYGON);
	glVertex2f(35 + i - 500, 125);
	glColor3f(0.3, 0.3, 0.3);
	glVertex2f(80 + i - 500, 190);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(115 + i - 500, 190);
	glVertex2f(115 + i - 500, 125);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.4, 0.4, 0.4);
	glVertex2f(125 + i - 500, 125);
	glVertex2f(125 + i - 500, 190);

	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(170 + i - 500, 190);
	glVertex2f(190 + i - 500, 125);
	glEnd();


	for (l = 0; l<20; l++)
	{
		glColor3f(0.0, 0.0, 0.0);
		draw_circle(75 + i - 500, 50, l);
		draw_circle(175 + i - 500, 50, l);
	}




	//car2

	glColor3f(0.95686, 0.79607, 0.25882);
	glBegin(GL_POLYGON);
	glVertex2f(-1070+i, 50);
	glVertex2f(-1070+i, 112);
	glVertex2f(-1000+i, 125);
	glVertex2f(-972+i, 210);
	glVertex2f(-810+i, 210);
	glVertex2f(-780+i, 125);
	glVertex2f(-735+i, 125);
	glVertex2f(-710+i, 50);
	glEnd();


	//windows

	glBegin(GL_POLYGON);
	glColor3f(0.4, 0.4, 0.4);
	glVertex2f(-410 + i - 100 - 500, 125);
	glVertex2f(-364 + i - 100 - 500, 200);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-300 + i - 100 - 500, 200);
	glVertex2f(-300 + i - 100 - 500, 125);
	glEnd();

	glColor3f(0.1, 0.1, 0.1);
	glBegin(GL_POLYGON);
	glColor3f(0.4, 0.4, 0.4);
	glVertex2f(-290 + i - 100 - 500, 125);
	glVertex2f(-290 + i - 100 - 500, 200);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-217 + i - 100 - 500, 200);
	glVertex2f(-192 + i - 100 - 500, 125);
	glEnd();


	for (l = 0; l<30; l++)
	{
		glColor3f(0.0, 0.0, 0.0);
		draw_circle(-350 + i - 120 - 500, 50, l);
		draw_circle(-200 + i - 120 - 500, 50, l);
	}

	//bus

	glBegin(GL_POLYGON);
	//glColor3f(0.95686, 0.25882, 0.5373);
	glVertex2f(350 + i - 500, 50);
	glVertex2f(755 + i - 500, 50);
	glVertex2f(755 + i - 500, 175);
	glColor3f(0.443137, 0.443137, 0.776471);
	glVertex2f(727 + i - 500, 275);
	glVertex2f(350 + i - 500, 275);
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(650 + i - 500, 175);
	glVertex2f(650 + i - 500, 260);
	glColor3f(0.4, 0.4, 0.4);
	glVertex2f(720 + i - 500, 260);
	glVertex2f(745 + i - 500, 175);
	glEnd();



	glBegin(GL_POLYGON);
	glColor3f(0.4, 0.4, 0.4);
	glVertex2f(550 + i - 500, 175);
	glVertex2f(550 + i - 500, 260);
	glColor3f(0, 0, 0);
	glVertex2f(625 + i - 500, 260);
	glVertex2f(625 + i - 500, 175);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(450 + i - 500, 175);
	glVertex2f(450 + i - 500, 260);
	glColor3f(0.4, 0.4, 0.4);
	glVertex2f(525 + i - 500, 260);
	glVertex2f(525 + i - 500, 175);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.4, 0.4, 0.4);
	glVertex2f(375 + i - 500, 175);
	glVertex2f(375 + i - 500, 260);
	glColor3f(0, 0, 0);
	glVertex2f(425 + i - 500, 260);
	glVertex2f(425 + i - 500, 175);
	glEnd();

	for (l = 0; l<35; l++)
	{
		glColor3f(0.0, 0.0, 0.0);
		draw_circle(450 + i - 500, 50, l);
		draw_circle(625 + i - 500, 50, l);
	}




	glFlush();
}





void traffic_light()
{
	int l;
	if (light == 1)
	{
		for (l = 0; l <= 20; l++)
		{

			glColor3f(0.0, 0.0, 0.0);
			draw_circle(1065, 475, l);

			//glColor3f(1.0,1.0,0.0);
			//draw_circle(1065,425,l);

			glColor3f(0.0, 0.7, 0.0);
			draw_circle(1065, 375, l);
		}
	}

	else
	{

		for (l = 0; l <= 20; l++)
		{
			glColor3f(1.0, 0.0, 0.0);
			draw_circle(1065, 475, l);

			//glColor3f(0.0,0.0,0.0);
			//draw_circle(1065,425,l);

			glColor3f(0.0, 0.0, 0.0);
			draw_circle(1065, 375, l);
		}
	}
}


void idle()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	if (light == 0 && (i >= 330 && i <= 750)) //value of i when first vehicle is near the traffic-signal
	{
		i += SPEED / 10;
		++m;
		n -= 2;
		o += 0.2;
		c += 2;
	}

	if (light == 0 && (i >= 830 && i <= 1100)) //value of i when second vehicle is near the traffic-signal
	{
		i += SPEED / 10;
		++m;
		n -= 2;
		o += 0.2;
		c += 2;
	}

	if (light == 0 && (i >= 1200 && i <= 1620))// value of i when third vehicle is near the traffic signal
	{
		i += SPEED / 10;
		++m;
		n -= 2;
		o += 0.2;
		c += 2;
	}

	if (light == 0)
	{
		i = i;
		++m;
		n -= 2;
		o += 0.2;
		c += 2;
	}

	else
	{
		i += SPEED / 10;
		++m;
		n -= 2;
		o += 0.2;
		c += 2;
	}
	if (i>2200)
		i = 0.0;
	if (m>1200)
		m = 0.0;
	if (o>75)
	{
		plane = 0;
	}
	if (c>900)
	{
		comet = 0;
	}
	glutPostRedisplay();

}



void mouse(int btn, int state, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		exit(0);
}

void keyboardFunc(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'g':
		light = 1;
		break;

	case 'r':
		light = 0;
		break;

	case 'd':
		day = 1;
		break;

	case 'n':
		day = 0;
		break;
	case 'c':
		comet = 1;
		c = 0.0;
		break;
	case 'p':
		plane = 1;
		o = n = 0.0;
		break;
	case 27:
		exit(1);
		break;

	};

}

void main_menu(int index)
{
	switch (index)
	{
	case 1:
		if (index == 1)
		{
			plane = 1;
			o = n = 0.0;
		}
		break;

	case 2:
		if (index == 2)
		{
			comet = 1;
			c = 0.0;
		}
		break;

	case 3:
		if (index == 3)
		{
			exit(0);
		}
		break;
	}

}

void myinit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 1.0);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1100.0, 0.0, 700.0);
}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	draw_object();
	traffic_light();
	glFlush();
}


int main(int argc, char** argv)
{
	int c_menu;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1100.0, 700.0);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("Traffic Control Scenary");
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboardFunc);
	glutMouseFunc(mouse);
	myinit();


	c_menu = glutCreateMenu(main_menu);
	glutAddMenuEntry("Aeroplane", 1);
	glutAddMenuEntry("Comet", 2);
	glutAddMenuEntry("Exit", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);


	glutMainLoop();
	return 0;
}
