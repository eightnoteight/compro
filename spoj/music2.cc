#include <bits/stdc++.h>
using namespace std;
#define endl            '\n'
#define i32inf
#define i64inf
#define ui32inf
#define ui64inf                     __gcd
#define bitcounti32                 __builtin_popcount
#define bitcounti64                 __builtin_popcountll
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    string note, tonality;
    int test = 1;
    map<string, string> answers = {
        {"Aminor", "UNIQUE"}, {"Amajor", "UNIQUE"},
        {"Bminor", "UNIQUE"}, {"Bmajor", "UNIQUE"},
        {"Cminor", "UNIQUE"}, {"Cmajor", "UNIQUE"},
        {"Dminor", "UNIQUE"}, {"Dmajor", "UNIQUE"},
        {"Eminor", "UNIQUE"}, {"Emajor", "UNIQUE"},
        {"Fminor", "UNIQUE"}, {"Fmajor", "UNIQUE"},
        {"Gminor", "UNIQUE"}, {"Gmajor", "UNIQUE"},
        {"A#minor", "Bb minor"}, {"Bbminor", "A# minor"},
        {"A#major", "Bb major"}, {"Bbmajor", "A# major"},
        {"D#minor", "Eb minor"}, {"Ebminor", "D# minor"},
        {"D#major", "Eb major"}, {"Ebmajor", "D# major"},
        {"F#minor", "Gb minor"}, {"Gbminor", "F# minor"},
        {"F#major", "Gb major"}, {"Gbmajor", "F# major"},
        {"C#minor", "Db minor"}, {"Dbminor", "C# minor"},
        {"C#major", "Db major"}, {"Dbmajor", "C# major"},
        {"G#minor", "Ab minor"}, {"Abminor", "G# minor"},
        {"G#major", "Ab major"}, {"Abmajor", "G# major"},
    };
    while(cin >> note >> tonality)
        cout << "Case " << test++ << ": " << answers[note+tonality] << endl;
    return 0;
}
