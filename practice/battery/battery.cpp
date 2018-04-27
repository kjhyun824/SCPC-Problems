/*
 * =====================================================================================
 *
 *       Filename:  battery.cpp
 *
 *    Description:  Find out minimum 'maximum power distance' and location for that
 *
 *        Version:  1.0
 *        Created:  04/24/18 11:25:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Junghyun Kim
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;

int min(int a, int b) {
    return (a < b) ? a : b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int abs(int x) {
    return (x > 0) ? x : (-x);
}

struct wire {
    unsigned int x[2];
    unsigned int y[2];
};

int distX(wire w, int _x) {
    return (abs(w.x[0] - _x) >= abs(w.x[1] - _x)) ? w.x[1] : w.x[0];
}

int distY(wire w, int _y) {
    return (abs(w.y[0] - _y) >= abs(w.y[1] - _y)) ? w.y[1] : w.y[0];
}

int dist(wire w, int _x, int _y) {
    return min(max(abs(w.x[0] - _x), abs(w.y[0] - _y)), max(abs(w.x[1] - _x), abs(w.y[1] - _y)));
}

int Answer;
wire wires[100];

int main(int argc, char** argv)
{
    int T, test_case;
    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        int numWire;
        cin >> numWire;

        for(int i = 0; i < numWire; i++) {
            cin >> wires[i].x[0] >> wires[i].y[0] >> wires[i].x[1] >> wires[i].y[1];

            wires[i].x[0] *= 2;
            wires[i].x[1] *= 2;
            wires[i].y[0] *= 2;
            wires[i].y[1] *= 2;
        }

        int batteryX = 0, batteryY = 0;

        while(true) {
            int leftX = 2e9, rightX = 0;

            for(int i = 0; i < numWire; i++) {
                int minX = distX(wires[i], batteryX);

                if(leftX > minX) leftX = minX;
                if(rightX < minX) rightX = minX;
            }

            int mid = (leftX + rightX) / 2;

            if(batteryX != mid)
                batteryX = mid;
            else
                break;
        }

        while(true) {
            int downY = 2e9, upY = 0;

            for(int i = 0; i < numWire; i++) {
                int minY = distY(wires[i], batteryY);

                if(downY > minY) downY = minY;
                if(upY < minY) upY = minY;
            }

            int mid = (downY + upY) / 2;

            if(batteryY != mid)
                batteryY = mid;
            else
                break;
        }

        int batteryX_ = 2e9, batteryY_ = 2e9;

        while(true) {
            int leftX = 2e9, rightX = 0;

            for(int i = 0; i < numWire; i++) {
                int minX = distX(wires[i], batteryX_);

                if(leftX > minX) leftX = minX;
                if(rightX < minX) rightX = minX;
            }

            int mid = (leftX + rightX) / 2;

            if(batteryX_ != mid)
                batteryX_ = mid;
            else
                break;
        }

        while(true) {
            int downY = 2e9, upY = 0;

            for(int i = 0; i < numWire; i++) {
                int minY = distY(wires[i], batteryY_);

                if(downY > minY) downY = minY;
                if(upY < minY) upY = minY;
            }

            int mid = (downY + upY) / 2;

            if(batteryY_ != mid)
                batteryY_ = mid;
            else
                break;
        }

        Answer = 0;
        for(int i = 0; i < numWire; i++) {
            int _dist = min(dist(wires[i], batteryX, batteryY), dist(wires[i], batteryX_, batteryY_));
            if(Answer < _dist) Answer = _dist;
        }

        cout << "Case #" << test_case+1 << endl;
        if(Answer % 2 == 0)
            cout << (Answer >> 1) << endl;
        else
            cout << (Answer >> 1) << ".5" << endl;
    }

    return 0;
}
