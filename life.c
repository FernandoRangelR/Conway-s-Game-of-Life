#define _XOPEN_SOURCE 600

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define ROWS 82
#define COLUMNS 62
#define ITERATIONS 10000

char randm();
char game_of_life (char a[ROWS][COLUMNS],int i, int j);
int life_integers (char b[ROWS][COLUMNS], int i, int j);
char rules(char c[ROWS][COLUMNS], int a, int i, int j);
char swap(char d[ROWS][COLUMNS], char e[ROWS][COLUMNS], int b, int c);

int main(void)
{
char life[ROWS][COLUMNS];
char life_2[ROWS][COLUMNS];

int i, j, k;


for(i = 0; i < ROWS; i++){
 for(j = 0; j < COLUMNS; j++){
  if(i == 0 || j == 0 || i == ROWS-1 || j == COLUMNS-1){
   life[i][j] = '#';
   life_2[i][j] = '#';
  }
  else{
   life[i][j] = randm();
   printf("%c", life[i][j]);
  }
 }
 printf("\n");
}
printf("\033[2H");
printf("\033[J");
usleep(1000*1000/10);

for(k = 0; k < ITERATIONS; k++){
 for(i = 1; i < ROWS-1; i++){
  for(j = 1; j < COLUMNS-1; j++){
   life_2[i][j] = game_of_life(life, i, j);
   printf("%c", life_2[i][j]);
  }
  printf("\n");
 }
 printf("\033[2H");
 printf("\033[J");
 usleep(1000*1000/10);
 for(i = 1; i < ROWS-1; i++){
  for(j = 1; j < COLUMNS-1; j++){
   swap(life, life_2, i, j);
  }
 }
}
return 0;
}

char randm()
{
int a;
char b;

a = (rand() % (1 + 1 - 0) + 0);

if (a == 1){
 b = ' ';
}
else{
 b = '#';
}
return b;
}

char game_of_life (char a[ROWS][COLUMNS], int i, int j)
{
char b;
int n;

n = life_integers(a, i-1, j-1) + life_integers(a, i-1, j) + life_integers(a, i-1, j+1) + life_integers(a, i, j-1) + life_integers(a, i, j+1) + life_integers(a, i+1, j-1) + life_integers(a, i+1, j) + life_integers(a, i+1, j+1);

b = rules(a, n, i, j);

return b;
}

int life_integers (char b[ROWS][COLUMNS], int i, int j)
{
int n;

if(b[i][j] == ' '){
 n = 1;
}
else{
 n = 0;
}
return n;
}

char rules(char c[ROWS][COLUMNS], int a, int i, int j)
{
char n;

if(c[i][j] == ' '){
 if(a == 2 || a == 3){ 
  n = ' ';
 }
 else{
  n = '#';
 }
}
else{
 if(a == 3){
  n = ' ';
 }
 else{
  n = '#' ;
 }
}
return n;
}

char swap(char d[ROWS][COLUMNS], char e[ROWS][COLUMNS], int b, int c)
{
char tmp[ROWS][COLUMNS];

tmp[b][c] = d[b][c];
d[b][c] = e[b][c];
e[b][c] = tmp[b][c];

return 0;
}


