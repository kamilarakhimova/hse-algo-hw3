# hse-algo-hw3
---
# КДЗ №3 по АиСД, 2 курс ПИ, ФКН, НИУ ВШЭ
---

## *1. АиСД-2, 2023*
## *2. Рахимова Камила Мухаммадовна (это я), БПИ214*
## *3. Clion, PyCharm, Google Colab*
---
### Реализованы 3/3 + 1/1 алгоритмов поиска кратчайшего пути в неориентированном графе, есть генератор тестовых данных (неориентированных графов) 3-ёх типов, присутствует измерение времени выполнения, а ещё в коде оставила комментарии. На этот раз получилось не слишком много (но всё равно много) графиков и табличек. Результаты работы проанализировала и интерпретировала в отчёте. В общем, сделала всё.
Ещё и стакан воды принесла к хлебушку (если вдруг потеряли/забыли хлебушку, то ищите его [тут](https://github.com/kamilarakhimova/hse-algo-hw2)):

![IMAGE 2023-06-11 22:28:59](https://github.com/kamilarakhimova/hse-algo-hw3/assets/58568615/4baf40f6-02fd-47e0-b7ac-6be1793e37ab)



---

### Не реализовано: такого нет.
---

Когда что где?:
- [Эть](https://github.com/kamilarakhimova/hse-algo-hw3/blob/main/Условие%20КДЗ%20№3.pdf) - тут находится описание условия задания.

- В файле [algorithms.cpp](https://github.com/kamilarakhimova/hse-algo-hw3/blob/main/algorithms.cpp) располагается код следующих 4-ёх алгоритмов поиска кратчайшего пути в неориентированном графе. Всё написано на языке C++.

```
1.    алгоритм Дейкстры    ✔ 
2.    алгоритм Флойда-Уоршела    ✔ 
3.    алгоритм Форда-Беллмана    ✔ 
4.    алгоритм поиска A*    ✔
```

- В файле [utils.cpp](https://github.com/kamilarakhimova/hse-algo-hw3/blob/main/utils.cpp) располагаются вспомогательные функции, такие, как функции генерации графов различных типов и функции, возвращающие названия алгоритмов/графов по их порядковому номеру.

- Немного о генерации графов: в полных графах получалось число рёбер всегда _m = n * (n - 1) // 2_. Связные графы генерировались с коэффициентом плотности 0.5, отсюда число рёбер в них _m = n * (n - 1) // 4_. В качестве разреженных графов были выбраны деревья, называемые "бамбук", соответственно число рёбер в них оказывается _m = n - 1_.

- Стартовой вершиной для любого алгоритма всегда берётся первая вершина (по индексу 0):

```
const int startVertex = 0;
```

- Конечной вершиной везде одинаково берётся последняя вершина (по индексу n - 1):

```
int finishVertex; // = n - 1
finishVertex = n - 1;
```

- В главном файле [main.cpp](https://github.com/kamilarakhimova/hse-algo-hw3/blob/main/main.cpp) находится (неожиданно!) всё самое основное. Программа начинает и заканчивает свою работу именно здесь. Суммарно по времени отработка программы занимает почти час, поэтому рекомендую запастись терпением. В ходе выполнения в консоль будет выводиться информация о стадии работы программы:

```
Программа начинает работу.
Все графы всех видов и размеров сгенерированы. Подготовительная работа выполнена.
Обработано 25%...
Обработано 50%...
Обработано 75%...
Обработано 100%!
Программа завершает работу. Конец.
```

- В папке [TablesForGraphs](https://github.com/kamilarakhimova/hse-algo-hw3/blob/main/TablesForGraphs) можно увидеть результаты работы [main.cpp](https://github.com/kamilarakhimova/hse-algo-hw3/blob/main/main.cpp). Тут в файлах формата ".csv" ждут своего звёздного часа все таблицы, необходимые для дальнейшего построения графиков. Таких файлов всего 4 + (4 * 3) + 3 + 3 = 22.

- Всё вышеописанное было реализовано на языке программирования C++. Далее использовался Python.

- В файлах [drawGraphs.py](https://github.com/kamilarakhimova/hse-algo-hw3/blob/main/drawGraphs.py) и [drawAlgoGraphs.py](https://github.com/kamilarakhimova/hse-algo-hw3/blob/main/drawAlgoGraphs.py) имеется код программы, превращавшей ".csv" файлы из [TablesForGraphs](https://github.com/kamilarakhimova/hse-algo-hw3/blob/main/TablesForGraphs) в красивые графики.

- Все графики можно найти в [Graphs](https://github.com/kamilarakhimova/hse-algo-hw3/blob/main/Graphs).

- И последнее: [хобаа!](https://github.com/kamilarakhimova/hse-algo-hw3/blob/main/Отчёт.md) - здесь беззаботно и бессовестно отдыхает готовый отчётик.

---

### Спасибо за внимание!!!
