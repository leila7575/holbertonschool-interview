#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define SLIDE_LEFT -1
#define SLIDE_RIGHT 1

int slide_line(int *line, size_t size, int direction);

#endif
