// Benjamin Y.
// CSCI 304 ('24 01)
// 4/20 != 24
// Section 1 (TR 2-3.5)
// Assignment IX


# include <stdio.h>
# include <stdlib.h>
# include <math.h>


/**
Synopsis:

Main checks if the abs(number) is odd or not.
    (i) Odd: Square it using mult, and return the product
    (ii) Even: returns the value of rf(n) **(further details in assembly comments)**

If the next numer in the input is not 0, keep doing this. Otherwise, halt.

*/


int mult (int x, int y) {   // Multiplies x and y

    int sum = 0;            // read: product

    while (x) {             // if x > 0, we need to add y more

        sum += y;
        x += -1;            // so x --> 0
        
    }

    return sum;             // x = 0 which means "sum" is the full product

}


int rf (int n) {            // recursive function?

    if (n==0) {             // base case 1
        return 1;           // "multipllies" by 1
    }

    if (n==1) {             // base case 2
        return 2;           // "multipllies" by 2
    }

    return mult(rf (n-1), rf (n-2));

}


int ab (int n) {            // absolute value function

    if (!(n > 0)) {         // as in assembly: if not positive, just return. Else, make it positive@
        n = 0 - n;
    }

    return n;               // returns the now (or already) positive n

}


int main () {               // Major Difference!!: we can directly print instead of using an output array

    int arr[] = {-6,4,5,-7,8,0};
    int i = 0;

    while (arr[i]) {        // while the current input is not 0

        int num = arr[i];   // print it out

        printf("%8d   0x%08x\n", num, num);

        num = ab (num);     // absolute value n no matter what

        if (num & 1) {      // if odd (then & 1 is 1)
            printf("%8d   0x%08x\n", mult (num, num), mult (num, num));
        }

        else {              // or throw it into rf
            printf("%8d   0x%08x\n", rf (num), rf (num));
        }

        i++;                // moves the input array pointer

    }

    return EXIT_SUCCESS;    // fin.

}