#include <iomanip>
#include <iostream>
#include <time.h>
#include <cmath>
#include <vector>

using namespace std;

float frog_movement[9] = {1.0, 1.0, 1.0,
                          1.0, 0.0, 1.0,
                          1.0, 1.0, 1.0};
#define map_lines 10
#define map_coluns 10
#define size_pop 5
#define gens 20
#define mutatation 0.01

vector<int> population;
vector<float> grade;
vector<vector<int>> map;

void create_map(vector<vector<int>> map) {
    int contador = 1;
    vector<int> linha;
    for (int i = 0; i < map_lines; i++) {
        for (int j = 0; j < map_coluns; j++) {
            linha.push_back(contador);
            contador++;
        }
        map.push_back(linha);
        linha.clear();
    }
}

void see_map(vector<vector<int>> map) {
    cout << "entrou";
    for (int i = 0; i < map_lines; i++) {
        for (int j = 0; j < map_coluns; j++) {
            cout << map[i][j];
        }
    }
}

int main() {
    cout << "aaaa";
    create_map(map);
    cout << "entrou";
    see_map(map);
    return 0;
}