#include <iostream>
#include <cmath>
using namespace std;

typedef long long LL;

LL Answer;
LL *xpoint1, *ypoint1, *xpoint2, *ypoint2;
LL abso(LL num) {
    if (num < 0) return 0 - num;
    return num;
}

int main(int argc, char** argv)
{
    int T, test_case;

    cin >> T;
    for (test_case = 0; test_case < T; test_case++)
    {
        int numYears;
        bool isPossible = false;
        cin >> numYears;
        Answer = numYears;

        xpoint1 = new LL[numYears];
        ypoint1 = new LL[numYears];
        xpoint2 = new LL[numYears];
        ypoint2 = new LL[numYears];
        for (int i = 0; i < numYears; i++) {
            cin >> xpoint1[i] >> ypoint1[i] >> xpoint2[i] >> ypoint2[i];
        }

        for (int i = 0; i < numYears; i++) {
            if (Answer < i) break;
            LL currX = xpoint1[i], currY = ypoint1[i];
            for (int j = 0; j < numYears; j++) {
                LL xDiff = abso(currX - xpoint2[j]);
                if (xDiff > numYears) continue;
                LL yDiff = abso(currY - ypoint2[j]);
                if (yDiff > numYears) continue;
                LL arrival = i + xDiff + yDiff + 1;
                if (arrival <= numYears) {
                    if (arrival < j + 1) arrival = j + 1;
                    if (Answer > arrival) Answer = arrival;
                    if (!isPossible) isPossible = true;
                }
            }
        }

        if (!isPossible) Answer = -1;

        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
    }

    return 0;
}
