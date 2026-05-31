import re
import tkinter as tk
from tkinter import filedialog, messagebox
from collections import Counter

def process_file():
    file_path = filedialog.askopenfilename(filetypes=[("Text files", "*.txt")])
    if not file_path: return

    try:
        # Читаем файл (пробуем utf-8, если не выйдет - системную кодировку)
        try:
            with open(file_path, 'r', encoding='utf-8') as f:
                content = f.read()
        except:
            with open(file_path, 'r', encoding='cp1251') as f:
                content = f.read()
        
        output_text.delete('1.0', tk.END)

        # 1. Поиск EMAIL (любое слово, где есть @ и точка)
        emails = re.findall(r'[^\s]+@[^\s]+\.[^\s]{2,}', content)
        
        # 2. Поиск ТЕЛЕФОНОВ (ищем любые последовательности цифр со знаками)
        # Этот паттерн найдет всё, что начинается на +7 или 8 и содержит скобки/тире
        phones = re.findall(r'(?:\+7|8)[\d\s\(\)\-]{10,18}', content)
        # Очистка телефонов от лишнего мусора в конце (если захватил лишнее)
        phones = [p.strip() for p in phones]

        # 3. Частота слов
        words = re.findall(r'[a-zа-яё]{2,}', content.lower())
        word_freq = Counter(words)
        
        # 4. Словарь по буквам
        letter_dict = {}
        for word in sorted(set(words)):
            char = word[0]
            if char not in letter_dict: letter_dict[char] = []
            letter_dict[char].append(word)

        # ВЫВОД
        output_text.insert(tk.END, f"--- ТОП-5 СЛОВ ---\n")
        for word, count in word_freq.most_common(5):
            output_text.insert(tk.END, f"{word}: {count}\n")
            
        output_text.insert(tk.END, f"\n--- EMAIL ({len(emails)}) ---\n")
        output_text.insert(tk.END, "\n".join(emails) if emails else "Пусто\n")
        
        output_text.insert(tk.END, f"\n--- ТЕЛЕФОНЫ ({len(phones)}) ---\n")
        output_text.insert(tk.END, "\n".join(phones) if phones else "Пусто\n")
        
        output_text.insert(tk.END, f"\n--- СЛОВАРЬ (фрагмент) ---\n")
        for char in list(letter_dict.keys())[:5]:
            output_text.insert(tk.END, f"'{char}': {letter_dict[char][:3]}\n")

    except Exception as e:
        messagebox.showerror("Ошибка", f"Ошибка: {e}")

root = tk.Tk()
root.title("Анализатор")
root.geometry("400x500")

btn = tk.Button(root, text="ВЫБРАТЬ ФАЙЛ", command=process_file, bg="green", fg="white")
btn.pack(pady=10, fill=tk.X, padx=10)

output_text = tk.Text(root, font=('Arial', 10))
output_text.pack(expand=True, fill='both', padx=10, pady=10)

root.mainloop()