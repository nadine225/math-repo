#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

void showOpeningPage() {
    cout << "==============================" << endl;
    cout << "    Selamat Datang di Game    " << endl;
    cout << "       Matematika SMAN 2      " << endl;
    cout << "          MEJAYAN             " << endl;
    cout << "==============================" << endl;
}

string getUsername() {
    string username;
    cout << "Masukkan Username: ";
    cin >> username;
    return username;
}

void showClosingPage(int score, const vector<string>& history) {
    cout << "==============================" << endl;
    cout << "         Terima Kasih!        " << endl;
    cout << "Skor Anda: " << score << endl;
    cout << "Riwayat Permainan:" << endl;
    for (const string& entry : history) {
        cout << entry << endl;
    }
    cout << "==============================" << endl;
}

int generateQuestion(int level, int& correctAnswer) {
    int num1, num2;
    char operators[] = {'+', '-', '*', '/'};
    char op = operators[rand() % 4];

    // Mengatur rentang angka berdasarkan level
    if (level == 1) { // Mudah
        num1 = rand() % 10; // 0-9
        num2 = rand() % 10; // 0-9
    } else if (level == 2) { // Sedang
        num1 = rand() % 50; // 0-49
        num2 = rand() % 50; // 0-49
    } else { // Sulit
        num1 = rand() % 100; // 0-99
        num2 = rand() % 100; // 0-99
    }

    // Menghindari pembagian dengan nol
    if (op == '/' && num2 == 0) {
        num2 = 1; // Jika num2 0, ubah menjadi 1
    }

    cout << "Pertanyaan: " << num1 << " " << op << " " << num2 << " = ?" << endl;

    switch (op) {
        case '+':
            correctAnswer = num1 + num2;
            break;
        case '-':
            correctAnswer = num1 - num2;
            break;
        case '*':
            correctAnswer = num1 * num2;
            break;
        case '/':
            correctAnswer = num1 / num2;
            break;
    }

    return op; // Mengembalikan operator untuk referensi jika diperlukan
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed untuk random number generation
    int score = 0;
    vector<string> history;
    const int totalQuestions = 25; // Limit permainan 25 nomor
    int level;

    showOpeningPage();

    // Memasukkan username
    string username = getUsername();
    cout << "Selamat datang, " << username << "!" << endl;

    // Memilih level kesulitan
    cout << "Pilih Level Kesulitan:" << endl;
    cout << "1. Mudah" << endl;
    cout << "2. Sedang" << endl;
    cout << "3. Sulit" << endl;
    cout << "Masukkan pilihan (1-3): ";
    cin >> level;

    for (int i = 0; i < totalQuestions; i++) {
        int correctAnswer;
        generateQuestion(level, correctAnswer);

        int userAnswer;
        cout << "Jawaban Anda: ";
        cin >> userAnswer;

        if (userAnswer == correctAnswer) {
            cout << "Jawaban Anda Benar!" << endl;
            score++;
            history.push_back("Pertanyaan " + to_string(i + 1) + ": Benar");
        } else {
            cout << "Jawaban Anda Salah. Jawaban yang benar adalah: " << correctAnswer << endl;
            history.push_back("Pertanyaan " + to_string(i + 1) + ": Salah (Jawaban: " + to_string(correctAnswer) + ")");
        }
    }

    showClosingPage(score, history);
    return 0;
}