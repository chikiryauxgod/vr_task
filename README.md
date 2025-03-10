# vr_task

1. Создать простое консольное приложение C++, которое сортирует один и тот же массив объектов с помощью нескольких потоков и соответствует следующим требованиям:
•	В разных потоках разные алгоритмы сортировки;
•	После каждой сортировки выводится результат в консоль;
•	Реализованы автотесты с разными тестовыми данными, демонстрирующими работу приложения при различных граничных условиях задачи;

**Реализованы сортировка слиянием, быстрая сортировка и сортировка пузырьком**
- Сортировка слиянием реализует многопоточную сортировку, посредством создания новых потоков для рекурсивных вызовов функции;
- Количество используемых в сортировке потоков можно изменять значением глубины рекурсии (depth);

**Реализована рекурсивная быстрая сортировка**
- Разделяет массив на две части вокруг опорного элемента
- Для ускорения сортировки используется рекурсия, которая разделяет массив на меньшие части, сортируя их;
Алгоритм работает в одном потоке;

**Реализована сортировка пузырьком** 
- Сравнивает соседние элементы массива и меняет их местами, если они идут в неправильном порядке;
- Алгоритмы работает в одном потоке;

**Все алгоритмы были покрыты тестами** 
- В том числе тест одновременной сортировки в параллельных потоках
- Чтобы избежать гонки данных, вывод в терминал блокирован мьютексом;

```bash
git clone https://github.com/chikiryauxgod/vr_task
cd sort/
g++  main.cpp sorts.cpp -lgtest -o test
./test
```

2. Создать простое консольное приложение C++, которое реализует классы геометрических объектов (круг, треугольник, прямоугольник), наследуемых от абстрактного класса. Приложение должно соответствовать следующим требованиям:
•	В каждом классе должен быть реализован метод расчета площади
•	Должна быть реализована сортировка массива геометрических фигур по площади
•	Реализованы автотесты (желательно Gtest) с разными тестовыми данными, демонстрирующими работу приложения при различных граничных условиях задачи

**Определен абстрактный класс "Figure"**, 
- От него были унаследованы классы "Circle", "Triangle", "Rectangle";
Переопределены методы базового класса;

**Определен класс-интерфейс "AbstractFigureFactory"**
- От класса-интерфейса "AbstractFigureFactory" был унаследован класс "FigureFactory", включающий его реализацию;
- Таким образом, фабрика "FigureFactory" инкапсулирует создание фигур;
- Создание фигур было реализовано паттерном Абстрактная фабрика.

```cpp
cd ..
cd figure/
g++  main.cpp figure.cpp -lgtest -o test
./test
```
