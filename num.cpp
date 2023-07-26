#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream inputFile("data.in");
    ofstream outputFile("data.out");

    if (!inputFile || !outputFile) {
        cout << "Eroare la deschiderea fisierelor.\n";
        return 1;
    }

    vector<long long> numbers;

    long long num;
    while (inputFile >> num) {
    
        // Convertim numarul la un string pentru a inlocui secventele "123"
        string numAsString = to_string(num);
        size_t found = numAsString.find("123");

        // Daca gasim secvente "123" in numar, le inlocuim cu "321"
        
        while (found != string::npos) {
            numAsString.replace(found, 3, "321");
            found = numAsString.find("123", found + 3); // Continuam cautarea dupa pozitia curenta
        }

        // Convertim numarul modificat direct la long long si il adaugam in container
        
        try {
            long long modifiedNum = stoll(numAsString);
            numbers.push_back(modifiedNum);
        } catch (const std::out_of_range& e) {
            // Numarul rezultat depaseste limitele unui numar intreg, il ignoram
        }
    }

    // Ordonam numerele in container
    
    sort(numbers.begin(), numbers.end());

    // Scriem numerele in fisierul de iesire
    
    for (long long n : numbers) {
        outputFile << n << endl;
    }

    // Inchidem fisierele
    
    inputFile.close();
    outputFile.close();

    return 0;
}
