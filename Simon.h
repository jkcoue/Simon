#pragma once

enum ACTION {
  Pmeter = 0,
  Button1 = 1,
  Button2 = 2,
  Switch1 = 3,
  Switch2 = 4,
  AccLeft = 5,
  AccRight = 6,
};

static struct Game
{
  int sequenceLength;
  enum ACTION sequence[50];
} Simon;

void GameUIInit();
void updateGameUI();
void gameInit();
