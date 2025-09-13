#include <iomanip>
#include <iostream>
#include <time.h>
#include <cmath>

using namespace std;

// f(x) = x^3 - 3x

// f(x) = x^5 + 2x^4 -3x^3 -5x^2 + x + 3

#define size 3
#define gens 20
#define mut 0.05
#define range 100
#define INT_MAX 2147483647

int population[size];
int grade[size];
int goat[2];
int dream_team[2] = {INT_MAX, INT_MAX};

void init_pop(int pop[size]) {
    srand(time(0));
    for(int i = 0; i < size; i++){
        pop[i] = rand()%(2*range + 1) -range;
    }
}

void evaluation(int pop[size], int grade[size]) {
    for(int i = 0; i < size; i++){
        grade[i] = pop[i]*pop[i]*pop[i] - 3*pop[i];
    }
}

void the_best(int goat[2], int grade[size], int pop[size]) {
    goat[1] = INT_MAX;
    for(int i = 0; i < size; i++){
        if (abs(grade[i]) < abs(goat[1])) {
            goat[0] = pop[i];
            goat[1] = grade[i];
        }
    }
}

void dst(int goat[2], int pop[size]) {
    for(int i = 0; i < size; i++){
        if (pop[i] == goat[0]) {
            continue;
        }
        pop[i] = int((pop[i] + goat[0])/2);
    }
}

void mutation(int pop[size]) {
    for(int i = 0; i < size; i++){
        if(rand()%2 == 0) {
            pop[i] = pop[i] + range*mut;
        }
        else {
            pop[i] = pop[i] - range*mut;
        }
    }
}

void the_dream(int goat[2], int dream[2]) {
    if(goat[1] == 0) {
        for(int i = 0; i < 2; i++){
            if((dream[i] < INT_MAX-1) || (goat[0] == dream[i-1])) {
                continue;
            }
            dream[i] = goat[0];
        }
    }
}

void see_pop(int pop[size], int goat[2]) {
    cout << "\nPopulation: ";
    for(int i = 0; i < size; i++){
        cout << pop[i] << ' ';
    }
    cout << "\nGoat) number:" << goat[0] << " grade:" << goat[1] << endl; 
}

int main() {
    init_pop(population);
    for(int i = 0; i < gens; i++){
        evaluation(population, grade);
        the_best(goat, grade, population);
        the_dream(goat, dream_team);
        cout << "\nGeração " << i + 1;
        see_pop(population, goat);
        mutation(population);
        dst(goat, population);
    }
    cout << "\nThis are the best results for this function: [" << dream_team[0] << " " << dream_team[1] << "] " << endl;
}