#include <iostream>
#include <vector>

// Funktion zur Multiplikation eines Vektors mit einer Matrix
std::vector<double> multiplyVectorMatrix(const std::vector<double>& vector, const std::vector<std::vector<double>>& matrix) {
    // Überprüfen, ob die Multiplikation möglich ist
    if (vector.size() != matrix.size()) {
        std::cerr << "Fehler: Vektorlänge stimmt nicht mit der Anzahl der Matrixzeilen überein." << std::endl;
        return {};
    }

    // Anzahl der Zeilen und Spalten der Matrix
    int numRows = matrix.size();
    int numCols = matrix[0].size();

    // Ergebnisvektor initialisieren
    std::vector<double> result(numCols, 0.0);

    // Matrix-Vektor-Multiplikation
    for (int i = 0; i < numCols; ++i) {
        for (int j = 0; j < numRows; ++j) {
            result[i] += matrix[j][i] * vector[j];
        }
    }

    return result;
}

// Funktion zum Ausgeben eines Vektors
void printVector(const std::vector<double>& vector) {
    for (double value : vector) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Beispiel-Vektor und -Matrix
    std::vector<double> inputVector = {1.0, 2.0, 3.0};
    std::vector<std::vector<double>> inputMatrix = {{4.0, 5.0, 6.0},
                                                   {7.0, 8.0, 9.0},
                                                   {10.0, 11.0, 12.0}};

    // Vektor-Matrix-Multiplikation aufrufen
    std::vector<double> resultVector = multiplyVectorMatrix(inputVector, inputMatrix);

    // Überprüfen, ob die Multiplikation erfolgreich war
    if (!resultVector.empty()) {
        // Ausgabe des Eingabevektors und der Matrix
        std::cout << "Eingabevektor: ";
        printVector(inputVector);

        std::cout << "Eingabematrix:" << std::endl;
        for (const auto& row : inputMatrix) {
            printVector(row);
        }

        // Ausgabe des Ergebnisvektors
        std::cout << "Ergebnisvektor: ";
        printVector(resultVector);
    }

    return 0;
}