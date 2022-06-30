#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SLEN 19

typedef struct {
  int id;
  char lastName[SLEN];
  char firstName[SLEN];
  int stage;
  int hitNum;
  int baseNum;
  int rbi;
  double hitRate;
} TEAM;

int read_datas(TEAM players[], int n, FILE* fp);
void count_hit_rate(TEAM players[], int n);
void show_messages(TEAM players[], int n);

static TEAM players[SLEN];

int main(void) {
  int len;
  FILE* fp;

  if ((fp = fopen("datas.txt", "r")) == NULL) {
    fprintf(stderr, "Can't open file datas.txt.\n");
    exit(EXIT_FAILURE);
  }
  len = read_datas(players, SLEN, fp);
  count_hit_rate(players, len);
  show_messages(players, len);
  if (fclose(fp) != 0)
    fprintf(stderr, "Can't close file datas.txt.\n");

  return 0;
}

int read_datas(TEAM players[], int n, FILE* fp) {
  int count = 0;
  float hitRate;
  char firstName[SLEN], lastName[SLEN];
  int id, stage, hitNum, baseNum, rbi;

  while (7 == fscanf(fp, "%d %18s %18s %d %d %d %d",
    &id, firstName, lastName, &stage, &hitNum, &baseNum, &rbi) &&
    !feof(fp) && count < n) {
    if (players[id].stage == 0) {
      ++count;
    }
    strcpy(players[id].lastName, lastName);
    strcpy(players[id].firstName, firstName);
    players[id].id = id;
    players[id].stage += stage;
    players[id].hitNum += hitNum;
    players[id].baseNum += baseNum;
    players[id].rbi += rbi;
  }
  return count;
}

void count_hit_rate(TEAM players[], int n) {
  int i;

  if (n > 0) {
    for (i = 0; i < n; i++) {
      players[i].hitRate = (double)players[i].hitNum / (double)players[i].stage;
      printf("%.2f\n", players[i].hitRate);
    }
  }
}

void show_messages(TEAM players[], int n) {
  int i;

  if (0 == n) {
    printf("No datas!\n");
  }
  else {
    printf("Datas for all players:\n");
    printf("ID  First_name Last_name       Stage  Hit_rate  Base_num   RBI  Hit_rate\n");
    for (i = 0; i < n; i++) {
      printf("%-4d %-12s %-10s %5d %7d %11d %8d %8.2f\n",
        players[i].id, players[i].firstName, players[i].lastName, players[i].stage, players[i].hitNum, players[i].baseNum, players[i].rbi, players[i].hitRate);
    }
  }
}