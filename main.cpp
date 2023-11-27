#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

const int save_history_maksimum = 100000;

double history[save_history_maksimum][2];
int indeks_history = -1;

double x = 0.0;
double y = 0.0;

void lokasi() {
    std::cout << "Lokasi Saat Ini: (" << std::fixed << std::setprecision(2) << x << ", " << y << ")\n";
}

void gerak(double deltaX, double deltaY) {
    x += deltaX;
    y += deltaY;

    // Record history
    indeks_history++;
    history[indeks_history][0] = x;
    history[indeks_history][1] = y;

    lokasi();
}

void gerak_2(double kecepatan, double waktu, double sudut) {
    double radians = sudut * 3.14159 / 180.0;
    double deltaX = kecepatan * waktu * cos(radians);
    double deltaY = kecepatan * waktu * sin(radians);
    gerak(deltaX, deltaY);
}

void undo() {
    if (indeks_history > 0) {
        indeks_history--;
        x = history[indeks_history][0];
        y = history[indeks_history][1];
        lokasi();
    } else {
        std::cout << "Tidak dapat undo!\n";
    }
}

void redo() {
    if (indeks_history < save_history_maksimum - 1 && indeks_history < save_history_maksimum - 1) {
        indeks_history++;
        x = history[indeks_history][0];
        y = history[indeks_history][1];
        lokasi();
    } else {
        std::cout << "Tidak dapat redo!\n";
    }
}

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

// ... (rest of the code remains the same)

void save() {
    std::ofstream outFile("/Users/arialexander/Downloads/save.txt"); // Change the path to a location where you have write permissions
    if (!outFile.is_open()) {
        std::cout << "Error membuka file untuk disave!\n";
        return;
    }

    for (int i = 0; i <= indeks_history; ++i) {
        outFile << std::fixed << std::setprecision(2) << history[i][0] << " " << history[i][1] << "\n";
    }

    outFile.close();
    std::cout << "Save berhasil!\n";
}

void load() {
    std::ifstream inFile("/Users/arialexander/Downloads/save.txt"); // Change the path to the saved location
    if (!inFile.is_open()) {
        std::cout << "Error membuka file untuk diload!\n";
        return;
    }

    indeks_history = -1;
    while (inFile >> history[++indeks_history][0] >> history[indeks_history][1]) {
        // Increment indeks_history only if both inputs are successful
        indeks_history++;
    }

    inFile.close();
    indeks_history--;

    x = history[indeks_history][0];
    y = history[indeks_history][1];
    lokasi();
    std::cout << "Load berhasil!\n";
}



int main() {
    while (true) {
        std::cout << "\nSIMULASI DRONE\n";
        std::cout << "1. Tunjukkan lokasi saat ini\n";
        std::cout << "2. Pindahkan Drone\n";
        std::cout << "3. Gerakkan Drone dengan kecepatan, waktu, dan arah!\n";
        std::cout << "4. Undo\n";
        std::cout << "5. Redo\n";
        std::cout << "6. Save ke File\n";
        std::cout << "7. Load dari File\n";
        std::cout << "8. Exit\n";
        std::cout << "Pilih opsi: ";

        int pilihan;
        std::cin >> pilihan;

        switch (pilihan) {
            case 1:
                lokasi();
                break;
            case 2:
                double gerakX, gerakY;
                std::cout << "Masukkan perpindahan x: ";
                std::cin >> gerakX;
                std::cout << "Masukkan perpindahan y: ";
                std::cin >> gerakY;
                gerak(gerakX, gerakY);
                break;
            case 3:
                double kecepatan, waktu, sudut;
                std::cout << "Masukkan kecepatan (kotak/s): ";
                std::cin >> kecepatan;
                std::cout << "Masukkan waktu (s): ";
                std::cin >> waktu;
                std::cout << "Masukkan sudut (theta): ";
                std::cin >> sudut;
                gerak_2(kecepatan, waktu, sudut);
                break;
            case 4:
                undo();
                break;
            case 5:
                redo();
                break;
            case 6:
                save();
                break;
            case 7:
                load();
                break;
            case 8:
                std::cout << "Keluar dari simulasi.\n";
                return 0;
            default:
                std::cout << "Opsi tidak valid.\n";
        }
    }

    return 0;
}
