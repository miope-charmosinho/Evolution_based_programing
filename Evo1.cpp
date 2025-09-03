#include <iomanip>
#include <iostream>
#include <time.h>

using namespace std;

#define size 3
#define gens 10
#define mutation_rate 1

int population[size];
int grade[size];

// Function that atributes random numbers from 0 to 20 to the population[] array
void init_pop(int pop[size]) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        pop[i] = rand() % 21;
    }
}

// Function that grades each value of the population array in relation to how close they are to 10
void grading(int pop[size], int grade[size]) {
    for (int i = 0; i < size; i++) {
        if (pop[i] <= 10)
            grade[i] = 10 - pop[i];
        else
            grade[i] = pop[i] - 10;
    }
}

// Function that, thru a pointer, gives the index of the best graded population[] member
void best(int grade[size], int &goat) {
    int the_best = grade[0];
    goat = 0;
    for (int i = 0; i < size; i++) {
        if (grade[i] <= the_best) {
            the_best = grade[i];
            goat = i;
        }
    }
}

// Creating a new generation by taking the average of each pop with the best
void sex(int pop[size], int goat) {
    for (int i = 0; i < size; i++) {
        if (i == goat) continue; 
        pop[i] = int((pop[i] + pop[goat]) / 2);
    }
}

void see_pop(int pop[size]) {
    for (int i = 0; i < size; i++) {
        cout << pop[i] << " ";
    }
}

void mutatiopn(int pop[size]) {
    for(int i = 0; i < size; i++){
        if (rand()%2 == 0) {
            pop[i] = pop[i] + mutation_rate;
            continue;
        }
        pop[i] = pop[i] - mutation_rate;
    }  
}

int main() {
    int goat;
    init_pop(population);

    for (int i = 0; i < gens; i++) {
        cout << "\nGeração " << i + 1 << ": ";
        see_pop(population);
        cout << endl;

        grading(population, grade);
        best(grade, goat);
        cout << "O melhor é " << population[goat] << endl;

        sex(population, goat);
        //if ((goat > 2) || (goat < 19)) {
        //    mutatiopn(population);
        //}
    }
    
    cout << "\nPopulação final: ";
    see_pop(population);
    cout << endl;

    return 0;
}
