#include <iomanip>
#include <iostream>
#include <time.h>
#include <cmath>
#include <vector>
#include <random>

using namespace std;

#define map_lines 8
#define map_coluns 8
#define size_pop 10
#define gens 10
#define mutatation 0.01

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dist_weight(1, 100);
uniform_int_distribution<int> dist(0, 5);

vector<float> grade;
vector<vector<int>> numerical_map;
vector<vector<char>> visual_map;
int inicial_position = (10*map_lines/2 + map_coluns/2);

class Frog {
    public:
        vector<int> movement;
        int position;

        //Constructor
        Frog(vector<int> mov, int pos) {
            movement = mov;
            position = pos;
        }

        void change_position() {
            discrete_distribution<> dist_choice(movement.begin(), movement.end());
            int chosen_movement = dist_choice(gen);     // should return a number between 0 and 7 taking their weights in to account

            switch (chosen_movement) {
                case 0: position += (map_coluns - 1); break;
                case 1: position += map_coluns; break;
                case 2: position += (map_coluns + 1); break;
                case 3: position -= 1; break;
                case 4: position += 1; break;
                case 5: position -= (map_coluns - 1); break;
                case 6: position -= (map_coluns); break;
                case 7: position -= (map_coluns + 1); break;
            }
        }

        // operador de impressão
        friend ostream& operator<<(ostream& os, const Frog& f) {
            os << "Position: " << f.position << "\n Movements: ";
            for (int m : f.movement) os << m << " ";
            os << endl;
            return os;
        }
};

vector<Frog> population;

void create_num_map() {
    // chose the starting number
    int num = 0;
    vector<int> line;

    for (int i = 0; i < map_lines; i++) {
        for (int j = 0; j < map_coluns; j++) {
            line.push_back(num);
            num++;
        }
        numerical_map.push_back(line);
        line.clear();
    }
}

void create_active_map() {
    visual_map.assign(map_lines, vector<char>(map_coluns, ' '));
    int num = 0;

    for(int i = 0; i < map_lines; i++) {
        for(int j = 0; j < map_coluns; j++) {
            int entidade = dist(gen);
            if(num == inicial_position) {visual_map[i][j]='S';}
            else {
                switch(entidade) {
                    case 0:
                        visual_map[i][j] = 'M';
                        break;
                    case 1:
                        visual_map[i][j] = 'B';
                        break;
                    default:
                        visual_map[i][j] = ' ';
                        break;
                }
            }
            num++;
        }
    }
}

void see_map(vector<vector<char>> board) {
    int n = 4;
    for (int z = 0; z < n * 3/2 * map_coluns; z++) { cout << "-"; }
    cout << endl;
    for (int i = 0; i < map_lines; i++) {
        cout << "|";
        for (int j = 0; j < map_coluns; j++) {
            cout << setw(n) << board[i][j] << " |";
        }
        cout << endl;
        for (int k = 0; k < n * 3/2 * map_coluns; k++) { cout << "-"; }
        cout << endl;
    }
}

vector<int> create_mov() {
    vector<int> mov;
    for (int i = 0; i < 8; i++) {    
        mov.push_back(dist_weight(gen));
        //cout << mov[i] << " ";
        }
    //cout << endl;
    return mov;

/*
    Ordem de movimento)
        {5, 6, 7,
         3, _, 4,
         0, 1, 2}
*/


}

vector<Frog> create_pop() {
    vector<Frog> pop;
    for (int i = 0; i < size_pop; i++) {
        Frog frogie (create_mov(),inicial_position);
        pop.push_back(frogie);
    }
    return pop;
}

void see_pop(vector<Frog> pop) {
    for (int i = 0; i < size_pop; i++) {
        cout << pop[i];
    }
}

int main() {
    create_num_map();
    create_active_map();
    see_map(visual_map);
    population = create_pop();
    //see_pop(population);
    return 0;
}