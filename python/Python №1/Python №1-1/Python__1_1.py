#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys

# ANSI escape-последовательности для цветов фона
RED = '\u001b[41m'
GREEN = '\u001b[42m'
YELLOW = '\u001b[43m'
BLUE = '\u001b[44m'
WHITE = '\u001b[47m'
RESET = '\u001b[0m'

# ---------- Флаг Франции (вертикальные полосы: синий, белый, красный) ----------
def france_flag():
    width = 21          # ширина флага (должна делиться на 3)
    height = 9
    block = '  '        # два пробела – один "пиксель"
    for _ in range(height):
        line = (BLUE + block * (width // 3) +
                WHITE + block * (width // 3) +
                RED + block * (width // 3) + RESET)
        print(line)

# ---------- Флаг Бангладеш (зелёный фон, красный круг в центре) ----------
def bangladesh_flag():
    width = 20
    height = 10
    center_x, center_y = width // 2, height // 2
    radius = 4
    for y in range(height):
        line_chars = []
        for x in range(width):
            if (x - center_x) ** 2 + (y - center_y) ** 2 <= radius ** 2:
                line_chars.append(RED + ' ' + RESET)
            else:
                line_chars.append(GREEN + ' ' + RESET)
        print(''.join(line_chars))

# ---------- Флаг Нидерландов (горизонтальные полосы: красный, белый, синий) ----------
def netherlands_flag():
    height = 9
    width = 20
    block = '  '
    for _ in range(height // 3):
        print(RED + block * (width // 2) + RESET)
    for _ in range(height // 3):
        print(WHITE + block * (width // 2) + RESET)
    for _ in range(height // 3):
        print(BLUE + block * (width // 2) + RESET)

# ---------- Флаг Польши (горизонтальные полосы: белый сверху, красный снизу) ----------
def poland_flag():
    height = 8
    width = 20
    block = '  '
    for _ in range(height // 2):
        print(WHITE + block * (width // 2) + RESET)
    for _ in range(height // 2):
        print(RED + block * (width // 2) + RESET)

# ---------- Флаг Литвы (горизонтальные полосы: жёлтый, зелёный, красный) ----------
def lithuania_flag():
    height = 9
    width = 20
    block = '  '
    for _ in range(height // 3):
        print(YELLOW + block * (width // 2) + RESET)
    for _ in range(height // 3):
        print(GREEN + block * (width // 2) + RESET)
    for _ in range(height // 3):
        print(RED + block * (width // 2) + RESET)

# ------------------- Главная функция -------------------
def main():
    if len(sys.argv) > 1:
        choice = sys.argv[1]
        if choice == '1':
            print("\nФлаг Франции:\n")
            france_flag()
        elif choice == '2':
            print("\nФлаг Бангладеш:\n")
            bangladesh_flag()
        elif choice == '3':
            print("\nФлаг Нидерландов:\n")
            netherlands_flag()
        elif choice == '4':
            print("\nФлаг Польши:\n")
            poland_flag()
        elif choice == '5':
            print("\nФлаг Литвы:\n")
            lithuania_flag()
        else:
            print("Использование: python flags.py [1-5]\n"
                  "1 – Франция, 2 – Бангладеш, 3 – Нидерланды, 4 – Польша, 5 – Литва")
    else:
        # Выводим все флаги по порядку
        print("\n=== Флаг Франции ===\n")
        france_flag()
        print("\n=== Флаг Бангладеш ===\n")
        bangladesh_flag()
        print("\n=== Флаг Нидерландов ===\n")
        netherlands_flag()
        print("\n=== Флаг Польши ===\n")
        poland_flag()
        print("\n=== Флаг Литвы ===\n")
        lithuania_flag()

if __name__ == "__main__":
    main()