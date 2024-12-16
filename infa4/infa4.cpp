#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

char charInput()       //проверка корректного ввода символов
{
    char input;
    while (!(std::cin >> input) || std::cin.peek() != '\n')
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Uncorrect input. " << std::endl;
    }
    return input;
}

class LetterCounter {
private:
    string filename; 
    int vowelCount;  
    int consonantCount; 
    const string vowels = "AEIOUYaeiouy"; 

public:
    //конструктор 
    LetterCounter(const string& file) : filename(file), vowelCount(0), consonantCount(0) {}

    void countLetters() {
        ifstream inputFile(filename);
        if (!inputFile) {
            cerr << "We can't find " << filename << " file." << endl;
            exit(0);
        }

        char ch;
        while (inputFile.get(ch)) { 
            if (isalpha(ch)) { 
                char lowerCh = tolower(ch); 
                if (vowels.find(lowerCh) != string::npos) {
                    vowelCount++; // Увеличиваем счетчик гласных
                }
                else {
                    consonantCount++; // Увеличиваем счетчик согласных
                }
            }
        }

        inputFile.close(); // Закрываем файл
    }

    bool hasTxtExtension(const string& filename) {      
        if (filename.find(".txt") != string::npos) {
            return true;
        }
        else return false;
    }
    void input() {
        string filename;   //enter thing  
        int uhHuhs = 0;
        bool normalAnswer = false;   
        while (!normalAnswer) {  

            cout << "Input a filename> ";
            getline(cin, filename);
            if (!filename.empty()) {
                if (hasTxtExtension(filename)){
                    this->filename = filename; //сохраняем имя файла в объекте
                    normalAnswer = true;
                }
                else {
                    filename.append(".txt");
                    this->filename = filename;
                    normalAnswer = true;
                }
            }
            else {
                cout << "uh-huh." << endl;    
                uhHuhs++;
            }
            if (uhHuhs == 3) {
                cout << endl << "Please, enter your file name more carefully. Thank you. " << endl << endl;
            }
            if (uhHuhs > 5) {
                cout << endl << "don't play with me." << endl;
                exit(1);
            }
        }

    }
    // Метод для вывода результатов
    void outputResult() const {
        cout << endl << "Vowels: " << vowelCount << endl;
        cout << "Consonants: " << consonantCount << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    system("chcp 1251 > nul");
    cout << "Yo! This program will calculates the number of vowels and consonants! SO excing and fun!" << endl;
    bool is_need_next_run = true; //создание флага для повторного запуска программы

    while (is_need_next_run) {
        LetterCounter counter("");
        counter.input();
        counter.countLetters();
        counter.outputResult();
        bool is_need_processed = false;
        do {
            std::cout << endl << "Wanna contiune? (Y/N):  ";
            char answer = charInput();
            if (answer == 'N') {
                std::cout << "Bye!" << std::endl;
                is_need_next_run = false;
                is_need_processed = true;
            }
            else if (answer == 'Y') {
                std::cout << "Contuine? ofc!" << std::endl << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                is_need_processed = true;
            }

        } while (!is_need_processed);
    }
    return 0;
}
