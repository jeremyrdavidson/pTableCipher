/*
Custom Periodic Table Cipher Encoder
2/7/2021
Jeremy Davidson
*/

/*
This is a (psuedo?)polyalphabetic cipher which translates every character in the plain text
into a randomly picked element's atomic symbol whose atomic number modulo 26 is equal to
the plain text character's position in the alphabet.

To decrypt the ciphered text, take each atomic number of every element in the string. apply
26 to that number, and translate that number (1-26) to the corresponding alphabet character.

ie; The atomic nmber of Ni is 28. 28 % 26 = 2. B is the second letter of the alphabet,
therefore Ni (ciphered) = b (plain).
*/

#include <iostream>
#include <string>
#include <random>

using namespace std;

int main()
{
// Atomic symbols ordered by atomic number. 
   string p_table[118] = { 
   "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P",
   "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu",
   "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc",
   "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La",
   "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu",
   "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At",
   "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es",
   "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh",
   "Fl", "Mc", "Lv", "Ts", "Og"                  
   };   
   
// Defines arrays for each letter of the alphabet and their index.
   string alphabet_array[26][5] = {};
   
// Defines plaintext string,
   string plain_text;

// Sets the atomic symbols to their respective arrays.
   for (int i = 0; i <= 25; i++) {      
       alphabet_array[i][0] += p_table[i];      
   }

   for (int i = 26; i <= 51; i++) {
       alphabet_array[i % 26][1] += p_table[i];       
   }      

   for (int i = 52; i <= 77; i++) {
       alphabet_array[i % 26][2] += p_table[i];       
   }

   for (int i = 78; i <= 103; i++) {
       alphabet_array[i % 26][3] += p_table[i];       
   }

   for (int i = 104; i <= 117; i++) {
       alphabet_array[i % 26][4] += p_table[i];       
   }
   
// Random number generation.
   random_device dev;
   mt19937 rng(dev());
   uniform_int_distribution<mt19937::result_type> dist5(0,4); // distribution in range [0, 4]
   uniform_int_distribution<mt19937::result_type> dist4(0,3); // distribution in range [0, 3]

// Explains the tool and prompts user for input.    
   cout << "Periodic Table Cipher Encoder" << endl << endl 
        << "To use, enter any text (all lowercase, and no spaces) into the prompt to encode." << endl << endl
        << "Enter plaintext:" << endl;

// Gets input from user then picks a random element of the corresponding array to use as ciphered outout. 
   cin >> plain_text;
   int text_length = plain_text.length();
      
   for (int i = 0; i < text_length; i++) {
   
// Calculates the position of each character in the string's position in the alphabet by using ASCII values. A = 0, B = 1... Z = 25, etc.   
       int ord = int(plain_text[i]) - 97;       
                 if (ord <= 14) {
                    cout << alphabet_array[ord][dist5(rng)];
                 }
                 else {
                    cout << alphabet_array[ord][dist4(rng)];
                 }
   } 
   
   return 0;
}
