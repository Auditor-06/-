#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>
#include <numeric>

// Класс для работы с файлами
class FileManager {
private:
    std::string filename;

public:
    FileManager(std::string fname) : filename(std::move(fname)) {}

    // Метод для записи массива в бинарный файл
    void writeBinary(const std::vector<int>& data) {
        std::ofstream out(filename, std::ios::binary);
        if (!out) {
            throw std::runtime_error("Ошибка открытия файла для записи: " + filename);
        }
        // Записываем размер вектора, а затем сами данные
        size_t size = data.size();
        out.write(reinterpret_cast<const char*>(&size), sizeof(size));
        out.write(reinterpret_cast<const char*>(data.data()), sizeof(int) * size);
        out.close();
    }

    // Метод для чтения массива из бинарного файла
    std::vector<int> readBinary() {
        std::ifstream in(filename, std::ios::binary);
        if (!in) {
            throw std::runtime_error("Ошибка открытия файла для чтения: " + filename);
        }
        size_t size = 0;
        in.read(reinterpret_cast<char*>(&size), sizeof(size));
        std::vector<int> data(size);
        in.read(reinterpret_cast<char*>(data.data()), sizeof(int) * size);
        in.close();
        return data;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    const std::string FILE_NAME = "array_data.bin";
    const int ARRAY_SIZE = 100;
    const int MIN_VAL = -100; // Исправлено: в задании указан диапазон, для примера взят [-100, 100]
    const int MAX_VAL = 100;

    // 1. Генерация массива случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(MIN_VAL, MAX_VAL);

    std::vector<int> numbers(ARRAY_SIZE);
    for (int& num : numbers) {
        num = distrib(gen);
    }

    // 2 и 3. Запись в файл и чтение из него с обработкой ошибок
    FileManager fileManager(FILE_NAME);
    try {
        fileManager.writeBinary(numbers);
        std::vector<int> read_numbers = fileManager.readBinary();

        // Проверка на целостность данных
        if (read_numbers.size() != ARRAY_SIZE) {
            std::cerr << "Предупреждение: размер считанных данных отличается от исходного!" << std::endl;
        }

        // 4. Анализ данных
        // Сортировка (применение алгоритмов)
        std::sort(read_numbers.begin(), read_numbers.end());

        // Поиск минимума и максимума (они теперь на краях вектора после сортировки)
        int min_val = read_numbers.front();
        int max_val = read_numbers.back();

        // Подсчет среднего арифметического
        double sum = std::accumulate(read_numbers.begin(), read_numbers.end(), 0.0);
        double average = sum / read_numbers.size();

        // Подсчет количества положительных и отрицательных чисел
        int positive_count = 0;
        int negative_count = 0;
        for (int val : read_numbers) {
            if (val > 0) positive_count++;
            else if (val < 0) negative_count++;
        }

        // Вывод результатов
        std::cout << "--- Результаты анализа ---" << std::endl;
        std::cout << "Минимальное значение: " << min_val << std::endl;
        std::cout << "Максимальное значение: " << max_val << std::endl;
        std::cout << "Среднее арифметическое: " << average << std::endl;
        std::cout << "Количество положительных чисел: " << positive_count << std::endl;
        std::cout << "Количество отрицательных чисел: " << negative_count << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Исключение: " << e.what() << std::endl;
    }

    return 0;
}