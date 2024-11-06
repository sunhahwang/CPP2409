#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Movie {
public:
    string movie_name;
    float score;

    Movie(string s, float f) {
        movie_name = s;
        score = f;
    }

    void Print() {
        cout << movie_name << ": " << score << endl;; 
    }
};

int main(void) {
    vector<Movie> m;

    m.push_back(Movie("titinic", 9.9));
    m.push_back(Movie("gone with wind", 9.6));
    m.push_back(Movie("terminator", 9.7));
    
    for(auto& e : m) {
        e.Print();
    }
    return 0;
}