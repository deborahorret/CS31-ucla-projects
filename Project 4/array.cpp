//
//  main.cpp
//  Project 4
//
//  Created by Deborah Orret on 5/10/17.
//  Copyright © 2017 Deborah Orret. All rights reserved.
//

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int enumerate(const string a[], int n, string target) { //FUNCTION ONE WORKS
    
    // for loop that runs through all the things of the array until size n
    // check if each index == "target"
    // modify counter
    //return counter
    
    if (n < 0) {
        return -1;
    }
    
    int counter = 0;
    for (int i=0; i < n; i++) {
        if (a[i] == target) {
            counter++;
        }
    }
    return counter;
}


int locate(const string a[], int n, string target) { //FUNCTION TWO WORKS
    
    //for loop that runs through all the positions
    //once it finds a match, immediately return the value so that its the first match
    //outside of the for loop, if it goes through and never finds a match, return -1
    
    if (n < 0) {
        return -1;
    }
    
    for (int i=0; i < n; i++) {
        if (a[i] == target) {
            return i;
        }
    }
    return -1;
}


bool locateSequence(const string a[], int n, string target, int& begin, int& end){ //FUNCTION THREE WORKS

    if (n < 0) {
        return -1;
    }
    
    for (int i=0; i < n; i++) {
        if (a[i] == target) {
            begin = i;
            break;
        }
        else
            begin = 0;
    }
    if (begin != 0) {
        end = begin;
        while (a[end+1] == target) {
            end++;
        }
    }
    
    if (begin == 0) {
        return false;
    }
    else
        return true;
}


int locationOfMin(const string a[], int n) { //FUNCTION FOUR WORKS
    
    if (n < 0) {
        return -1;
    }
    
    int pos= 0;
    
    for (int i=0; i < n; i++) {
        if (a[i] < a[pos]) {
            pos = i;
        }
    }
    
    return pos;
}


int moveToEnd(string a[], int n, int pos) { // n is the size not the position,
                                            // FUNCTION FIVE WORKS
    if (n < 0 || pos < 0) {
        return -1;
    }
    if (pos > n) {
        return -1;
    }
    
    string temp = a[pos];
    string temp_2 = a[n-1];
    for (int i = pos; i < n - 2; i++) {
        a[i]  = a[i+1]; }
    a[n-2] = temp_2;
    a[n-1] = temp;
    return pos;
}


int moveToBeginning(string a[], int n, int pos) { //FUNCTION SIX WORKS
    
    if (n < 0 || pos < 0) {
        return -1;
    }
    
    if (pos > n) {
        return -1;
    }

    string temp = a[pos];
    for (int i = pos; i >= 1; i--) {
        a[i] = a[i-1];
    }
    a[0] = temp;
    return pos;
}



int locateDifference(const string a1[], int n1, const string a2[], int n2){ //FUNCTION SEVEN WORKS
    
    if (n1 < 0) {
        return -1;
    }
    
    if (n2 < 0) {
        return -1;
    }
    
    int mismatch = 0;
    
    if (n1 <= n2) {
        for (int i =0; i < n1; i++) {
            if (a1[i] != a2[i])
                mismatch++;
        }
        if (mismatch != 0)
            return mismatch;
        else
            return n2;
    }
    
    else {
        for (int i =0; i < n2; i++) {
            if (a1[i] != a2[i])
                mismatch++;
        }
        if (mismatch != 0)
            return mismatch;
        else
            return n2;
    }
}

int eliminateDups(string a[], int n) { //FUNCTION EIGHT WORKS
    //for loop running through all the elements, until size-1 because thats the last u can compare to
    // if a[i] and a[i+1] are identical, move a[i+1] to back
    // modify counter, return counter
    
    if (n < 0) {
        return -1;
    }
    
    int duplicate = n;
    for (int i=0; i < n-1; i++) {
        if (a[i] == a[i+1]) {
            duplicate --;
        }
    }
    
    int j = 0;
    while (j < n-1) {
        if (a[j] == a[j+1]) {
            //move i+1 to end
            string temp = a[j+1];
            string temp_2 = a[n-1];
            for (int k = j+1; k < n - 2; k++) {
                a[k]  = a[k+1]; }
            a[n-2] = temp_2;
            a[n-1] = temp;
        }
        else j++;
    }
    
    return duplicate;
}


bool subsequence(const string a1[], int n1, const string a2[], int n2) { //FUNCTION NINE IN PROGRESS
    
    if (n1 < 0) {
        return -1;
    }
    
    if (n2 < 0) {
        return -1;
    }
    
    int last_match = 0;
    int matches = 0;
    
    if (n1 < n2) { //n1 is the smaller one
        return false;
    }
    
    else { //n2 is the smaller one, or they are equal
        for (int i= 0; i < n2; i++) {
            for (int j= last_match; j < n1; j++ && j > last_match) {
                if (a2[i] == a1[j]) {
                    matches++;
                    last_match = j+1;
                    break;
                }// if statement
            }//inside for loop
        }
    } //else statement
 
    if (matches == n2) {
        return true;
    }
    else
        return false;
    
} //function brackets

int makeMerger(const string a1[], int n1, const string a2[], int n2, string result[], int max) { //FUNCTION TEN WORKS, something was off
    //check if in decreasing order
    //put them together in big string
    //sort them using same shit u were using before
    
    if (n1 < 0) {
        return -1;
    }
    
    if (n2 < 0) {
        return -1;
    }
    
    if (n1 + n2 > max) {
        return -1;
    }
    
    int check = 0;
    for (int a=0; a < n1-1; a++) {
        if (a1[a] <= a1[a+1]) {
            check = 1;
        }
        else return -1;
    }
    
    int check2 =0;
    for (int b=0; b < n2-1; b++) {
        if (a2[b] <= a2[b+1]) {
            check2 = 1;
        }
        else return -1;
    }
    
    if (check == 1 && check2 == 1) {
    
    for (int i=0; i < n1; i++) {
        result[i] = a1[i];
        }
    
    int x=0;
    for (int j= n1; j < n1+ n2; j++) {
        result[j] =a2[x];
        x++;
        }
    }
    
    string temp; //to sort the final result
    for (int y=0; y < n1+n2; y++) {
        if (result[y] < result[y-1]) {
            temp = result[y];
            result[y] = result[y-1];
            result[y-1] = temp;
        }
    }
    
    return n1+n2;
}



int divide(string a[], int n, string divider) { //FUNTION ELEVEN WORKS
    //if < divider, move to beggining if > divider move to end
    //for loop that tests if less than divider, once greater return nonsense
    
    if (n < 0) {
        return -1;
    }
    
    string t[10000];
    
    int pos = 0;
    
    for (int i=0; i < n; i++) {
        if (a[i] < divider) {
            t[pos] = a[i];
            pos++;
        }
    }
    
    for (int d=0; d < n; d++) {
        if (a[d] == divider) {
            t[pos] = a[d];
            pos++;
        }
    }
    
    for (int j=0; j < n; j++) {
        if (a[j] > divider) {
            t[pos] = a[j];
            pos++;
        }
    }
    
    for (int k=0; k < n; k++) {
        a[k] = t[k];
    }
    
    for (int f=0; f < n; f++) {
        if (a[f] >= divider) {
            return f;
        }
    }
    
    return n;
    
}



string c[6] = {
    "alpha", "beta", "beta", "delta", "gamma", "gamma"
};

string d[11] = {
    "alpha", "beta", "beta", "beta", "alpha",
    "alpha", "",     "delta", "beta", "beta",
    ""
};

string e[5] = {
    "alpha", "beta", "gamma", "gamma", "a"
};

string f[5] = {
    "azaz", "beta", "gamma", "mu", "a"
};

string g[100];

bool makeMergerCheck(const string a[], int n1, const string b[], int n2, const string c[])
{
    string z[100];
    merge(a,a+n1,b,b+n2,z);
    return equal(z,z+n1+n2,c);
}

bool divideCheck(const string a[], int n, int p, string divider)
{
    for (int k = 0; k < p; k++)
        if (a[k] >= divider)
            return false;
    for ( ; p < n  &&  a[p] == divider; p++)
        ;
    for (int k = p; k < n; k++)
        if (a[k] <= divider)
            return false;
    string b[100];
    copy(a,a+n,b);
    sort(b,b+n);
    return equal(b,b+n,c);
}

void testone(int n)
{
    const int N = 6;
    
    // Act as if  a  were declared:
    //   string a[6] = {
    //       "alpha", "beta", "gamma", "gamma", "beta", "delta"
    //   };
    // This is done in a way that will probably cause a crash if
    // a[-1] or a[6] is accessed:  We place garbage in those positions.
    string aa[1+N+1] = {
        "", "alpha", "beta", "gamma", "gamma", "beta", "delta", ""
    };
    string* a = &aa[1];
    string* z = aa;
    a[-1].string::~basic_string();
    a[N].string::~basic_string();
    fill_n(reinterpret_cast<char*>(&a[-1]), sizeof(a[-1]), 0xEF);
    fill_n(reinterpret_cast<char*>(&a[N]), sizeof(a[N]), 0xEF);
    
    string b[N] = {
        "alpha", "beta", "gamma", "delta", "beta", "delta"
    };
    
    switch (n)
    {
        case  1: {
            assert(enumerate(z, -1, "alpha") == -1);
        } break; case  2: {
            assert(enumerate(z, 0, "alpha") == 0);
        } break; case  3: {
            assert(enumerate(a, 6, "beta") == 2);
        } break; case  4: {
            assert(enumerate(a, 6, "delta") == 1);
        } break; case  5: {
            assert(enumerate(a, 6, "bet") == 0);
        } break; case  6: {
            assert(locate(z, -1, "alpha") == -1);
        } break; case  7: {
            assert(locate(z, 0, "alpha") == -1);
        } break; case  8: {
            assert(locate(a, 1, "alpha") == 0);
        } break; case  9: {
            assert(locate(a, 6, "alpha") == 0);
        } break; case 10: {
            assert(locate(a, 6, "gamma") == 2);
        } break; case 11: {
            assert(locate(a, 6, "zeta") == -1);
        } break; case 12: {
            int b = 999;
            int e = 999;
            assert(!locateSequence(z, -1, "alpha", b, e));
        } break; case 13: {
            int b = 999;
            int e = 999;
            assert(!locateSequence(z, 0, "alpha", b, e)  &&
                   b == 999  &&  e == 999);
        } break; case 14: {
            int b = 999;
            int e = 999;
            assert(locateSequence(d, 1, "alpha", b, e)  &&
                   b == 0  &&  e == 0);
        } break; case 15: {
            int b = 999;
            int e = 999;
            assert(!locateSequence(d, 1, "beta", b, e)  &&
                   b == 999  &&  e == 999);
        } break; case 16: {
            int b = 999;
            int e = 999;
            assert(locateSequence(d, 10, "alpha", b, e)  &&
                   b == 0  &&  e == 0);
        } break; case 17: {
            int b = 999;
            int e = 999;
            assert(locateSequence(d, 10, "beta", b, e)  &&
                   b == 1  &&  e == 3);
        } break; case 18: {
            int b = 999;
            int e = 999;
            assert(locateSequence(c, 6, "gamma", b, e)  &&
                   b == 4  &&  e == 5);
        } break; case 19: {
            assert(locationOfMin(z, -1) == -1);
        } break; case 20: {
            assert(locationOfMin(z, 0) == -1);
        } break; case 21: {
            assert(locationOfMin(a, 6) == 0);
        } break; case 22: {
            assert(locationOfMin(a+1, 5) == 0);
        } break; case 23: {
            assert(locationOfMin(a+2, 3) == 2);
        } break; case 24: {
            a[0] = "~~~~~~~~~~~";
            a[1] = "~~~~~~";
            a[2] = a[0];
            assert(locationOfMin(a, 3) == 1);
        } break; case 25: {
            assert(moveToEnd(z, -1, 0) == -1 &&
                   a[0] == "alpha" && a[1] == "beta");
        } break; case 26: {
            assert(moveToEnd(a, 6, -1) == -1 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 27: {
            assert(moveToEnd(a, 6, 6) == -1 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 28: {
            assert(moveToEnd(z, 0, 0) == -1 &&
                   a[0] == "alpha" && a[1] == "beta");
        } break; case 29: {
            assert(moveToEnd(a, 1, 0) == 0 &&
                   a[0] == "alpha" && a[1] == "beta");
        } break; case 30: {
            assert(moveToEnd(a, 6, 0) == 0 &&
                   a[0] == "beta" && a[1] == "gamma" && a[2] == "gamma" &&
                   a[3] == "beta" && a[4] == "delta" && a[5] == "alpha");
        } break; case 31: {
            assert(moveToEnd(a, 6, 5) == 5 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 32: {
            assert(moveToEnd(a, 6, 3) == 3 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "beta" && a[4] == "delta" && a[5] == "gamma");
        } break; case 33: {
            assert(moveToEnd(a, 5, 3) == 3 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "beta" && a[4] == "gamma" && a[5] == "delta");
        } break; case 34: {
            assert(moveToBeginning(z, -1, 0) == -1 &&
                   a[0] == "alpha" && a[1] == "beta");
        } break; case 35: {
            assert(moveToBeginning(a, 6, -1) == -1 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 36: {
            assert(moveToBeginning(a, 6, 6) == -1 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 37: {
            assert(moveToBeginning(z, 0, 0) == -1 &&
                   a[0] == "alpha" && a[1] == "beta");
        } break; case 38: {
            assert(moveToBeginning(a, 1, 0) == 0 &&
                   a[0] == "alpha" && a[1] == "beta");
        } break; case 39: {
            assert(moveToBeginning(a, 6, 0) == 0 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 40: {
            assert(moveToBeginning(a, 6, 5) == 5 &&
                   a[0] == "delta" && a[1] == "alpha" && a[2] == "beta" &&
                   a[3] == "gamma" && a[4] == "gamma" && a[5] == "beta");
        } break; case 41: {
            assert(moveToBeginning(a, 5, 3) == 3 &&
                   a[0] == "gamma" && a[1] == "alpha" && a[2] == "beta" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 42: {
            assert(locateDifference(z, -1, b, 6) == -1);
        } break; case 43: {
            assert(locateDifference(a, 6, z, -1) == -1);
        } break; case 44: {
            assert(locateDifference(z, 0, z, 0) == 0);
        } break; case 45: {
            assert(locateDifference(a, 3, b, 3) == 3);
        } break; case 46: {
            assert(locateDifference(a, 3, b, 2) == 2);
        } break; case 47: {
            assert(locateDifference(a, 2, b, 3) == 2);
        } break; case 48: {
            assert(locateDifference(a, 6, b, 6) == 3);
        } break; case 49: {
            assert(eliminateDups(d,10) == 6 && d[0] == "alpha"  &&
                   d[1] == "beta"  &&  d[2] == "alpha"  &&
                   d[3] == ""  &&  d[4] == "delta"  &&  d[5] == "beta");
        } break; case 50: {
            d[3] = "alpha";
            d[4] = "beta";
            assert(eliminateDups(d+3,6) == 6 && d[3] == "alpha"  &&
                   d[4] == "beta"  &&  d[5] == "alpha"  &&
                   d[6] == ""  &&  d[7] == "delta"  &&  d[8] == "beta");
        } break; case 51: {
            assert(eliminateDups(d,1) == 1  &&  d[0] == "alpha"  &&
                   d[1] == "beta");
        } break; case 52: {
            assert(eliminateDups(z,0) == 0  &&  a[0] == "alpha");
        } break; case 53: {
            assert(eliminateDups(z,-1) == -1  &&  a[0] == "alpha");
        } break; case 54: {
            assert(!subsequence(z, -1, b, 6));
        } break; case 55: {
            assert(!subsequence(a, 6, z, -1));
        } break; case 56: {
            assert(!subsequence(z, 0, b, 6));
        } break; case 57: {
            assert(subsequence(a, 6, z, 0));
        } break; case 58: {
            assert(subsequence(a, 6, b, 1));
        } break; case 59: {
            assert(subsequence(a, 6, b+1, 2));
        } break; case 60: {
            assert(subsequence(a, 6, b+1, 3));
        } break; case 61: {
            assert(!subsequence(a, 6, b+3, 2));
        } break; case 62: {
            assert(!subsequence(b, 6, a+2, 3));
        } break; case 63: {
            b[0] = "beta";
            assert(!subsequence(a, 3, b, 2));
        } break; case 64: {
            assert(subsequence(a, 6, a, 6));
        } break; case 65: {
            assert(makeMerger(e,1,f,1,g,10) == 2  &&  makeMergerCheck(e,1,f,1,g));
        } break; case 66: {
            assert(makeMerger(e+1,1,f+1,1,g,10) == 2  &&
                   makeMergerCheck(e+1,1,f+1,1,g));
        } break; case 67: {
            assert(makeMerger(e,4,f,4,g,10) == 8  &&  makeMergerCheck(e,4,f,4,g));
        } break; case 68: {
            assert(makeMerger(e,4,f,4,g,7) == -1);
        } break; case 69: {
            assert(makeMerger(z,0,f,4,g,7) == 4  &&  makeMergerCheck(z,0,f,4,g));
        } break; case 70: {
            e[2] = "mu";
            assert(makeMerger(e,4,f,4,g,10) == -1);
        } break; case 71: {
            assert(makeMerger(e,4,z,-1,g,7) == -1);
        } break; case 72: {
            assert(divide(z, -1, "beta") == -1 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 73: {
            assert(divide(z, 0, "beta") == 0 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 74: {
            assert(divide(a, 1, "aaa") == 0 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 75: {
            assert(divide(a, 1, "alpha") == 0 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 76: {
            assert(divide(a, 1, "zeta") == 1 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 77: {
            assert(divide(a, 2, "aaa") == 0 &&
                   divideCheck(a, 2, 0, "aaa") && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 78: {
            assert(divide(a, 2, "alpha") == 0 &&
                   divideCheck(a, 2, 0, "alpha") && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 79: {
            assert(divide(a, 2, "beta") == 1 &&
                   divideCheck(a, 2, 1, "beta") && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 80: {
            assert(divide(a, 2, "zeta") == 2 &&
                   divideCheck(a, 2, 2, "zeta") && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 81: {
            assert(divide(a, 6, "aaa") == 0 && divideCheck(a, 6, 0, "aaa"));
        } break; case 82: {
            assert(divide(a, 6, "alpha") == 0 &&
                   divideCheck(a, 6, 0, "alpha"));
        } break; case 83: {
            assert(divide(a, 6, "beta") == 1 &&
                   divideCheck(a, 6, 1, "beta"));
        } break; case 84: {
            assert(divide(a, 6, "delta") == 3 &&
                   divideCheck(a, 6, 3, "delta"));
        } break; case 85: {
            assert(divide(a, 6, "gamma") == 4 &&
                   divideCheck(a, 6, 4, "gamma"));
        } break; case 86: {
            assert(divide(a, 6, "zeta") == 6 &&
                   divideCheck(a, 6, 6, "zeta"));
        } break; case 87: {
            a[2] = "mu";
            c[5] = "mu";
            assert(divide(a, 6, "mu") == 5 && divideCheck(a, 6, 5, "mu"));
        } break; case 88: {
            assert(divide(a, 6, "chi") == 3 && divideCheck(a, 6, 3, "chi"));
        } break; case 89: {
            // This case tested whether moveToEnd used an extra array.
        } break; case 90: {
            // This case tested whether moveToBeginning used an extra array.
        } break; case 91: {
            // This case tested whether eliminateDups used an extra array.
        } break; case 92: {
            // This case tested whether makeMerger used an extra array.
        } break; case 93: {
            // This case tested whether divide used an extra array.
        } break;
    }
    
    new (&a[-1]) string;
    new (&a[N]) string;
}

int main()
{
    cout << "Enter a test number (1 to 93): ";
    int n;
    cin >> n;
    if (n < 1  ||  n > 93)
    {
        cout << "Bad test number" << endl;
        return 1;
    }
    testone(n);
    cout << "Passed test " << n << endl;
}

