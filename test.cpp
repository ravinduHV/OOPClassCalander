#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> V;
    V.push_back(1);
    V.push_back(2);
    V.push_back(3);
    V.insert(V.begin(), 1);
}