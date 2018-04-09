/*
 * =====================================================================================
 *
 *       Filename:  sequence.cpp
 *
 *    Description:  Find the campus that is not on any shortest path
 *
 *        Version:  1.0
 *        Created:  04/06/18 14:14:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Junghyun Kim
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <iostream>
using namespace std;

unsigned long long Answer;

unsigned long long divisors(unsigned long long D) {
    unsigned long long count = 0;
    
    for(unsigned long long i = 1; i*i <= D; i++) {
        if(i*i == D) count ++;
        else if(D % i == 0) count += 2;
    }

    return count;
}

int main(int argc, char** argv)
{
    int T, test_case;
    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        Answer = 0;
        int num;
        cin >> num;

        unsigned long long D[num-1];
        unsigned long long minD = ~0;
        unsigned long long maxD = 0L;
        unsigned long long before;

        for(int i = 0; i < num; i++) {
            unsigned long long input;
            cin >> input;
            if(i == 0) {
                before = input;
                continue;
            }
            else {
                unsigned long long diff = input - before;
                if(diff < minD)
                    minD = diff;

                if(diff > maxD)
                    maxD = diff;

                D[i-1] = diff;
            }

            before = input;
        }

        if(maxD == 0) 
            Answer = 1;
        else {
            bool flag = false;
            for(int i = 0; i < num-1; i++) {
                if((D[i] != 0) && (maxD % D[i] != 0)) {
                    flag = true;
                    break;
                }
            }

            if(!flag)
                Answer = divisors(minD);
        }

        printf("[DEBUG] %ul, %ul\n",minD, maxD);
        cout << "Case #" << test_case+1 << endl;
        cout << Answer << endl;
    }

    return 0;
}
