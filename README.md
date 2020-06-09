## Summer Exam [![Build Status](https://travis-ci.com/starquell/summer-exam-oop.svg?token=bj2Apz5ftRqtamBtJ9iD&branch=master)](https://travis-ci.com/starquell/summer-exam-oop)

Виконавці :
   - Яна Скирда
   - Даніїл Осока
   - Ілля Гайдученко
   
Імплементовано:
   - Сортування :
        - Quick 
        - Merge
        - Radix
        - Counting
        - Selection
        - Insertion
        - Bucket
        - Heap
        - Binary Search Tree Sort
   - Дерева пошуку:
        - Red Black
        - Splay
        - AVL
   - Зв'язні списки
        - Singly Linked
        - Double Linked
        - Cyclic Singly Linked
   - Хеш-таблиці :
        - Coalested Hashing (Stack-based implementation)
   - Сутності :
        - Посадові особи: міністерство, організація, підрозділ, співробітник
        
   - Рандомна генерація багатьох сутностей та будь-яких контейнерів (`exam::random`)
   - Тести для всього реалізованого функціоналу (використовуючи [doctest](https://github.com/onqtam/doctest))
   - Бенчмарки для алгоритмів сортування та контейнерів (використовуючи [Google Benchmark](https://github.com/google/benchmark))
   - Set - множина, що працює на основі всіх реалізованих контейнерів (`exam::Set`)
   - Map - обгортка над Set, з функціоналом для роботи з парами (ключ - значення) (`exam::Map`)
   - Sort - клас для зручного вибору алгоритму сортування (`exam::Sort`)
   - AnySet - поліморфна обгортка над Set, що дозволяє обирати реалізацію Set в рантаймі (використовуючи type-erasure) (`exam::AnySet`)
   - GUI з можливістю роботи з імплементованими контейнерами та сортуванням
  
Версія С++ проекту - **17**.

Репозиторій використовує git submodule, тому для клонування:
```
git clone --recurse https://github.com/starquell/summer-exam-oop.git
```

Сумарно всіма виконавцями за час виконання роботи було переглянуто чотири 10-годинних відео з [музикою з Skyrim](https://www.youtube.com/watch?v=wSYoT_ptT00&t=15331s)