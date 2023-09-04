#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING_ARRAY grid
 */

void printGrid(vector<string> grid) {
    cout << "______________________" << endl;
    for(string s : grid) cout << s << endl;
    cout << "______________________" << endl;
}

vector<string> bomberManAlt(int n, vector<string> grid) {
    int turn = 0;
    vector<string> postExplosionGrid;
    while(n > 0) {
        if (turn == 1) {
            postExplosionGrid = grid;
            grid = vector<string> (grid.size(), string(grid[0].size(), 'O'));
        } else if (turn == 2) {
            // Bombs explode
            turn++;
            for(int i = 0; i < postExplosionGrid.size(); i++) {
                for(int j = 0; j < postExplosionGrid[i].size(); j++) {
                    if(postExplosionGrid[i][j] == 'O') { // There is a bomb here!
                        if(i > 0) grid[i-1][j] = '.';
                        if(j > 0) grid[i][j-1] = '.';
                        grid[i][j] = '.';
                        if(j < postExplosionGrid[i].size() - 1) grid[i][j+1] = '.';
                        if(i < postExplosionGrid.size() - 1) grid[i+1][j] = '.';
                    }
                }
            }
            turn = 0;
        }
        printGrid(grid);
        turn++;
        n--;
    }
    return grid;
}

vector<string> complementaryGrid(vector<string> grid) {
    int rows = grid.size();
    int columns = grid[0].size();
    vector<string> bombGrid(rows, string(columns, 'O'));
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            if(grid[i][j] == 'O') { // There is a bomb here!
                if(i > 0) bombGrid[i-1][j] = '.';
                if(j > 0) bombGrid[i][j-1] = '.';
                bombGrid[i][j] = '.';
                if(j < columns - 1) bombGrid[i][j+1] = '.';
                if(i < rows - 1) bombGrid[i+1][j] = '.';
            }
        }
    }
    return bombGrid;
}

vector<string> bomberMan(int n, vector<string> grid) {
    // n -> 1 : res = grid
    // n -> 2 : res = all bombs
    // n -> 3 : res = complementary grid
    // n -> 4 : res = all bombs
    if(n == 1) return grid;

    switch (n % 4) {
    case 1:
        return complementaryGrid(complementaryGrid(grid));
        break;
    case 3:
        return complementaryGrid(grid);
        break;
    default:
        return vector<string> (grid.size(), string(grid[0].size(), 'O'));
        break;
    }
    return grid;
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int r = stoi(first_multiple_input[0]);

    int c = stoi(first_multiple_input[1]);

    int n = stoi(first_multiple_input[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](unsigned char c) { return !ispunct(c); })
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char c) { return !ispunct(c); }).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
