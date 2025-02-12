#ifndef STAPLER_H
#define STAPLER_H

#define MAX_MAG 3
#define MAX_STAPLES 5

typedef struct stapleMag {
    float size;
    int staples;
} STAPLEMAG;

typedef struct stapler {
    STAPLEMAG magazine[MAX_MAG];
    int top;
} STAPLER;

void clearInputBuffer();
void displayMenu();

void loadModule(STAPLER *stapler);
int loadMag(STAPLER *stapler, float size);
void unloadModule(STAPLER *stapler);
int unloadMag(STAPLER *stapler);
void useStapler(STAPLER *stapler);
void displayStaplerStatus(STAPLER *stapler);


#endif 