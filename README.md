## [textAI.cpp](https://github.com/repinnick/antiplagiat/blob/main/textAI.cpp)

```bool isSeparator(char c);``` // ищет знаки препинания и прочую фигню

```string textWithoutSeparators(string text);``` // сюда передаётся первоначальный текст, на выходе получаем отформатированный. Без знаков препинания и в нижнем регистре.

```int findWords(string text, string textForFind);``` // для поиска части текста, условно user-a, в основном тексте. Сюда я передаю по три слова, которые программа ищет по основному тексту и возвращает 3, если нашла такой же участок и 0, если не нашла.

```int wordCounter(string userText);``` // здесь я считаю количество слов в тексте usera, и возвращаю число, чтобы на его основе задать размер массива

```void addWordsInArray(string userText, string words[]);``` // здесь забиваю массив словами

```int checkWordsInText(int size, string words[], string documentText);``` // здесь уже идёт разбивка массива на три элемента, соединение трёх слов в строку и проверка их функцией findWords()

```int plagiatDetector(int size, int coincidences);``` // тут выводится процент плагиата по той формуле, которую сегодня решили взять за основу.

```int sumOfNotSelection();``` // подсчёт слов, которые участвуют в выборке меньше всего. 