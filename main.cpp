#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

extern bool gameOver;
extern const int width;
extern const int height;
extern int x, y;
extern int appleX, appleY, bananaX, bananaY, orangeX, orangeY, chocoX, chocoY, icecreamX, icecreamY;
extern int score;
extern int *tailX;
extern int *tailY;
extern int nTail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
extern eDirection dir;

void Setup();
void Draw();

#endif
