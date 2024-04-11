#include <iostream>
#include <string>

using namespace std;

/**
 * The suffix function that checks if a prefix has been found
 * which is also a string suffix. Start from the most
 * large value, k, and stops when found
 * the prefix.
 * template - template P (string)
 * k - number of characters that match up to state q
 * q - state
 * a - letter from the alphabet (which is added to what has been matched up to q)
 */
bool sufix(string sablon, int k, int q, char a)
{
    string prefix = sablon.substr(0, k) + a;
    int m = prefix.size();

    int i = 0, j = m - 1;

    while (i < k && j >= 0)
    {
        if (prefix[i] == sablon[j])
        {
            i++;
            j--;
        }
        else
        {
            i = 0;
            k--;
            prefix = sablon.substr(0, k) + a;
            m = prefix.size();
            j = m - 1;
        }
    }

    return i == k;
}

/**
 * Function that calculates the transition function
 * template - the P template
 * table - traction function (AF tabular representation)
 * dim - the size of the alphabet
 */
void calcul_functie_de_tranzitie(string sablon, int **tabel, int dim)
{
    int m = sablon.length();
    for (int q = 0; q < m; ++q)
    {
        for (int a = 0; a < dim; ++a)
        {
            int k = min(m, q + 1);
            while (!sufix(sablon, k - 1, q, 'a' + a))
            {
                cout << "aici";
                k--;
            }
            tabel[q][a] = k;
        }
    }
}

/**
 * Template matching function in text
 * T - the text
 * table - transition function (AF) for P
 * m - the number of characters in P
 */
void potrivire_AF(string T, int **tabel, int m)
{
    int n = T.size();
    int q = 0;

    for (int i = 0; i < n; i++)
    {
        q = tabel[q][T[i] - 'a'];
        if (q == m)
            cout << "The template appears from the position " << i + 1 - m << endl;
    }
}