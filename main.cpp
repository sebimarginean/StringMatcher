#include <iostream>
#include <string>

#include "AF.h"
#include "KMP.h"

using namespace std;

int main()
{
    string T = "abbcabbabbcabbcab"; // text
    string P = "abbcab";            // template

    // AF ************************
    const int dim = 3; // dim alphabet
    int m = P.size();  // dim P template
    int S = m + 1;     // no. states
    int **delta;       // transition function

    delta = new int *[S];
    for (int i = 0; i < S; i++)
        delta[i] = new int[dim];

    calcul_functie_de_tranzitie(P, delta, dim);

    potrivire_AF(T, delta, m);

    KMPMatcher(T, P);

    return 0;
}
