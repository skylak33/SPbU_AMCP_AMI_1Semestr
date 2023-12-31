Если кириллица нормально не выводится

в начале int main() напишите setlocale(LC_ALL, "");
вместо cout << "..."; напишите wcout << L"...";



int main() {
  setlocale(LC_ALL, "");
  // Код
  wcout << some_data << L"Текст на русском"; 
}
