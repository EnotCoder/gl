#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdlib>

using namespace std;

const int width = 12;
const int height = 8;

const char player_img = '+';

int position[2] = {1,1};

int story = 0;

char map[height][width] = {
    {'#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#','.','.','.','.','.','.','.','.','.','.','#'},
    {'#','.','.',' ',' ',' ','#','#','#','#','.','#'},
    {'#','.','.','.','.','.','.','.','.','.','.','#'},
    {'#','.','.','.','.','.','.','.','.','#','.','#'},
    {'#','#','.',' ',' ',' ',' ',' ','.','#','.','#'},
    {'#','#','.','.','.','.','.','.','.','#','.','#'},
    {'#','#','#','#','#','#','#','#','#','#','#','#'},
};


void draw_map() {

    map[position[1]][position[0]] = player_img;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            cout << map[y][x];
        }
        cout << endl;
    }
}

int main() {
    srand(time(nullptr));
    draw_map();
    cout << 0+rand()%(7-0+1) << endl;

    while (true)
    {   
        char key;
        cin >> key;

        system("clear");
        
        switch (key){
        case 'W':
        case 'w':
            while (map[position[1]-1][position[0]] != '#')
            {
                map[position[1]][position[0]] = ' ';
                position[1] -= 1;
            }
            story ++;
            break;
        case 'S':
        case 's':
            while (map[position[1]+1][position[0]] != '#')
            {
                map[position[1]][position[0]] = ' ';
                position[1] += 1;
            }
            story ++;
            break;
        case 'A':
        case 'a':
            while (map[position[1]][position[0]-1] != '#')
            {
                map[position[1]][position[0]] = ' ';
                position[0] -= 1;
            }
            story ++;
            break;
        case 'D':
        case 'd':
            while (map[position[1]][position[0]+1] != '#')
            {
                map[position[1]][position[0]] = ' ';
                position[0] += 1;
            }
            story ++;
            break;
        }
        draw_map();
        cout << story << endl;
    }
    

    return 0;
}
