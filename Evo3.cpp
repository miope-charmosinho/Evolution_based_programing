#include <iomanip>
#include <iostream>
#include <time.h>
#include <cmath>

using namespace std;

// f(x) = x^3 - 3x

// f(x) = x^5 + 2x^4 -3x^3 -5x^2 + x + 3

// f(x) = sin(x) + 0.5sin(2x)   [<--]

#define size 4
#define gens 80
#define mut 0.1
#define range 5
#define INT_MAX 2147483647
#define LOW_FLOAT -2147483647.0
#define dream_number 100

float population[size];
float grade[size];
float goat[2];
float dream_team[dream_number];
float average[1];
float trigger[3] = {LOW_FLOAT, LOW_FLOAT, LOW_FLOAT};
int contador[1] = {0};

void init_pop(float pop[size]) {
    srand(time(0));
    for(int i = 0; i < size; i++){
        pop[i] = rand()%range;
    }
}

void evaluation(float pop[size], float grade[size], float average[1]) {
    float sum = 0;
    for(int i = 0; i < size; i++){
        grade[i] = sin(pop[i]) + sin(2*pop[i])/2;
        sum = sum + pop[i];
    }
    average[0] = sum/size;
}

void the_best(float goat[2], float grade[size], float pop[size]) {
    goat[1] = LOW_FLOAT;
    for(int i = 0; i < size; i++){
        if (grade[i] >= goat[1]) {
            goat[0] = pop[i];
            goat[1] = grade[i];
        }
    }
}

void dst(float goat[2], float pop[size]) {
    for(int i = 0; i < size; i++){
        if (pop[i] == goat[0]) {
            continue;
        }
        pop[i] = (pop[i] + goat[0])/2;
    }
}

void mutation(float pop[size], float coef, float jump) {
    for(int i = 0; i < size; i++){
        if ((pop[i] == goat[0]) && (jump == 0)) {
            continue;
        }
        if(rand()%2 == 0) {
            pop[i] = pop[i] + range*mut*coef + jump;
        }
        else {
            pop[i] = pop[i] - range*mut*coef + jump;
        }
    }
}

bool mutation_trigger(float trigger[3]) {
    // shift left
    trigger[0] = trigger[1];
    trigger[1] = trigger[2];
    trigger[2] = goat[0];

    float average = (trigger[0] + trigger[1] + trigger[2]) / 3.0f;
    float tolerance = 0.005f;

    if (abs(average - goat[0]) < tolerance) {
        printf("\nStagnation detected\n");
        trigger[0] = LOW_FLOAT;
        trigger[1] = LOW_FLOAT;
        trigger[2] = LOW_FLOAT;
        return true;
    }
    return false;
}

void the_dream(float dream_team[dream_number]) {
    for (int i = 0; i < dream_number; i++) {
        if (dream_team[i] == 0) {
            dream_team[i] = goat[0];
            break;
        }
    }
}

void alternating_mutation(float pop[size], int contador[1], float dream_team[dream_number]) {
    if (contador[0] == 2) {
        the_dream(dream_team);
        mutation(pop, 1, 9);
        cout << "\nJumping...\n";
        contador[0] = 0;
    }
    else if (mutation_trigger(trigger) == true) {
        mutation(pop, 0.3, 0);
        contador[0] = contador[0] + 1;
    }
    else {
        mutation(pop, 1, 0);
    }
}

void see_pop() {
    cout << "\nPopulation: ";
    for(int i = 0; i < size; i++){
        cout << population[i] << ' ';
    }
    cout << "\nGoat) number:" << goat[0] << " grade:" << goat[1] << 
    "\nAverage) " << average[0] << endl;
}

void see_the_dream() {
    cout << "\nThese are the highest numbers we found: { ";
    for (int i = 0; i < dream_number; i++) {
        if (dream_team[i] == 0) {
            break;
        }
        cout << dream_team[i] << " ";
    }
    cout << "}" << endl;
}

int main() {
    init_pop(population);
    for(int i = 0; i < gens; i++){
        evaluation(population, grade, average);
        the_best(goat, grade, population);
        cout << "\nGeração " << i + 1;
        see_pop();
        alternating_mutation(population, contador, dream_team);
        dst(goat, population);
    }
    see_the_dream();
}