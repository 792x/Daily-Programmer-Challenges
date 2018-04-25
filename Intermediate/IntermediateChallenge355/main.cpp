/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: css
 *
 * Created on April 24, 2018, 6:55 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/*
 * 
 * It's Thanksgiving eve and you're expecting guests over for dinner tomorrow. 
 * You find some spare ingredients, and make do with what you have. You know only two pie recipes, and they are down below.
 * Your guests have no preference of one pie over another, and you want to make the maximum number of (any kind) of pies possible with what you have. 
 * You cannot bake fractions of a pie, and cannot use fractions of an ingredient (So no 1/2 cup of sugar or anything like that) 
 * given recipes:
 * 
 * Pumpkin Pie
 *
 *    1 scoop of synthetic pumpkin flavouring (Hey you're a programmer not a cook)
 *    3 eggs
 *    4 cups of milk
 *    3 cups of sugar
 *
 * Apple Pie
 *
 *    1 apple
 *    4 eggs
 *    3 cups of milk
 *    2 cups of sugar
 *
 * 
 * https://www.reddit.com/r/dailyprogrammer/comments/87rz8c/20180328_challenge_355_intermediate_possible/
 * 
 */


int minValue(int a, int e, int m, int s) {
    int max = a, min = a;
    if (e > max) {
        max = e;
    } else if (e < min) {
        min = e;
    }
    if (m > max) {
        max = m;
    } else if (m < min) {
        min = m;
    }
    if (s > max) {
        max = s;
    } else if (s < min) {
        min = s;
    }
    return min;
}

int maxApplePies(int a, int e, int m, int s) {
    a = a;
    e = e / 4;
    m = m / 3;
    s = s / 2;

    return minValue(a, e, m, s);
}

int maxPumpkinPies(int c, int e, int m, int s) {
    c = c;
    e = e / 3;
    m = m / 4;
    s = s / 3;

    return minValue(c, e, m, s);
}

void howManyPies(int c, int a, int e, int m, int s) {

    int maxPies;
    int applePies = maxApplePies(a, e, m, s);
    int pumpkinPies = maxPumpkinPies(c, e, m, s);
    int finalApplePies;
    int finalPumpkinPies;
    int ee = e;
    int mm = m;
    int ss = s;

    if (applePies > pumpkinPies) {
        maxPies = applePies;
    } else {
        maxPies = pumpkinPies;
    }
    if (applePies > 0) {
        for (int i = 1; i < applePies; i++) {
            ee = ee - 4;
            mm = mm - 3;
            ss = ss - 2;
            if (i + maxPumpkinPies(c, ee, mm, ss) >= maxPies) {
                maxPies = i + maxPumpkinPies(c, ee, mm, ss);
                finalApplePies = i;
                finalPumpkinPies = maxPumpkinPies(c, ee, mm, ss);
            }
        }
    }

    ee = e;
    mm = m;
    ss = s;

    if (pumpkinPies > 0) {
        for (int i = 1; i < pumpkinPies; i++) {
            ee = ee - 3;
            mm = mm - 4;
            ss = ss - 3;
            if (i + maxApplePies(a, ee, mm, ss) >= maxPies) {
                maxPies = i + maxApplePies(a, ee, mm, ss);
                finalApplePies = maxApplePies(a, ee, mm, ss);
                finalPumpkinPies = i;
            }
        }
    }

    cout << finalApplePies << " apple pies and " << finalPumpkinPies << " pumpkin pies" << endl;
}

int main(int argc, char** argv) {

    howManyPies(10, 14, 10, 42, 24);
    howManyPies(12, 4, 40, 30, 40);
    howManyPies(12, 14, 20, 42, 24);
    return 0;
}

