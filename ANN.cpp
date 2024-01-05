#include <iostream>
#include <fstream>
#include <vector>

// Struktur zur Speicherung der Vektoren
struct Data {
    double* vector1;
    double* vector2;
    int vectorLength;
};

// Funktion zum Lesen der Daten aus der Datei
Data readDataFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Fehler beim Öffnen der Datei!" << std::endl;
        // Rückgabewerte mit Null-Pointern im Fehlerfall
        return { nullptr, nullptr, 0 };
    }

    // Vektoren initialisieren
    std::vector<double> tempVector1;
    std::vector<double> tempVector2;

    // Daten einlesen
    int vectorLength = 0;
    while (file >> vectorLength) {
        tempVector1.resize(vectorLength);
        tempVector2.resize(vectorLength);

        // Vektor 1 einlesen
        for (int i = 0; i < vectorLength; ++i) {
            file >> tempVector1[i];
        }

        // Vektor 2 einlesen
        for (int i = 0; i < vectorLength; ++i) {
            file >> tempVector2[i];
        }
    }

    // Vektoren in dynamischem Speicher allozieren
    double* vector1 = new double[tempVector1.size()];
    double* vector2 = new double[tempVector2.size()];

    // Daten in die dynamischen Vektoren kopieren
    std::copy(tempVector1.begin(), tempVector1.end(), vector1);
    std::copy(tempVector2.begin(), tempVector2.end(), vector2);

    // Datei schließen
    file.close();

    // Rückgabe der Struktur mit den beiden Zeigern und der Vektorlänge
    return { vector1, vector2, vectorLength };
}

// Funktion zum Erstellen einer Testdatei
void createTestFile(const std::string& filename) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Fehler beim Erstellen der Testdatei!" << std::endl;
        return;
    }

    // Beispielinhalt der Testdatei
    file << "3 1.1 2.2 3.3 4.4 5.5 6.6\n";
    file << "2 7.7 8.8 9.9 10.10\n";
    file << "4 11.11 12.12 13.13 14.14 15.15\n";

    // Datei schließen
    file.close();
}

int main() {
    const std::string filename = "test_input.txt"; // Beispiel: Dateiname

    // Testdatei erstellen
    createTestFile(filename);

    // Daten aus der Testdatei lesen
    Data result = readDataFromFile(filename);

    // Überprüfen, ob die Daten erfolgreich eingelesen wurden
    if (result.vector1 && result.vector2) {
        // Beispiel: Ausgabe der ersten Werte der Vektoren
        std::cout << "Erster Wert in Vector1: " << result.vector1[0] << std::endl;
        std::cout << "Erster Wert in Vector2: " << result.vector2[0] << std::endl;

        // TODO: Weitere Verarbeitung der Daten hier

        // Speicher freigeben
        delete[] result.vector1;
        delete[] result.vector2;
    } else {
        std::cerr << "Fehler beim Lesen der Daten!" << std::endl;
    }

    return 0;
}