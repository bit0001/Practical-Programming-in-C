#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

#define NUMBER_OF_ELEMENTS 5

extern int queue_buffer[NUMBER_OF_ELEMENTS];
extern int i_front;
extern int i_count;

void enqueue(double element);
int dequeue();
void print_queue();

#endif
