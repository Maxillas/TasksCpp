# TasksCpp

## 1.2 step 4
Вам дана следующая иерархия классов:

``` C++
struct Base { ... };

struct D1 : Base { ... };

struct D2 : Base { ... };

struct D3 : D1, D2 { ... };
```

Напишите функцию D1BaseToD2Basejj, которая преобразует указатель типа Base на объект типа D3, который ссылается на экземпляр Base, соответствующий D1, в указатель, ссылающийся на экземпляр Base соответствующий D2.
___

## 1.2 step 10
Предположим, что при разработке игры вам потребовался юнит "Челмедведосвин" (ManBearPig).
Завершите разработку иерархии классов и реализуйте необходимые конструкторы.
PS: В данном игровом контексте предполагается, что человек — не животное.
___

## 1.4 step 4
Вам требуется реализовать функцию, которая принимает на вход два указателя на базовый класс Expression, и возвращает true, если оба указателя указывают на самом деле на объекты одного и того же класса, и false в противном случае (т.е. если оба указателя указывают на BinaryOperation, то возвращается true, а если один из них указывает на Number, а второй на BinaryOperation, то false).

Реализуйте её при помощи typeid.

Требования к реализации: Использовать dynamic_cast и вызывать методы по переданным указателям запрещено.

___
## 1.4 step 7
Предположим, что вам даётся два указателя на объект некоторого сложного полиморфного класса, который использует множественное наследование. Оба указателя имеют один и тот же тип, но могут ссылаться на разные однотипные базы внутри одного объекта.

Напишите шаблонную функцию, которая по двум однотипным указателям проверяет, указывают ли они на один объект.
___

## 1.6 step 10
Напишите возвращающую bool шаблонную функцию compare, которая принимает
две константные ссылки на объекты одного типа и указатель на константный
метод этого типа без параметров, который в свою очередь возвращает значение
какого-то второго типа. Функция должна сравнивать объекты по значениям,
которые для них вернёт соответствующий метод, и возвращать true,
если значение для первого объекта оказалось меньше, чем для второго.
```C++
std::string s1("Elf");
std::string s2("Archer");
// сравнение строк по длине
bool r1 = compare(s1, s2, &std::string::size); // true
bool r2 = compare(s1, s1, &std::string::size); // false
```
___

## 2.1
 По аналогии с функцией printf с предыдущего степа напишите функцию print_values с переменным числом аргументов, которая для каждого аргумента выводит его тип и значение в поток std::ostream, который ей передан в качестве первого аргумента. Функция должна работать с произвольным числом аргументов.
Указание: для вывода имени типа нужно использовать std::type_info::name.
Например, вызов функции
```C++
print_values(std::cout, 0, 3.5, "Hello");
```
должен вывести на стандартный вывод примерно следующее (таким будет вывод на g++).

i: 0
d: 3.5
PKc: Hello
___

## 2.2
Дополните класс Array перемещающим конструктором и перемещающим оператором присваивания.

Замечание: все объявленные методы класса Array уже реализованы.
___

## 2.3 step 3
Напишите шаблонную функцию to_pair, которая принимает произвольный std::tuple и два индекса внутри и возвращает std::pair, содержащий элементы переданного std::tuple с соответствующими индексами.

Пример:
```C++
auto t = std::make_tuple(0, 3.5, "Hello");
std::pair<double, char const *> p = to_pair<1,2>(t);
// p содержит 3.5 и "Hello"
```
 
___
## 2.3 step 5
Напишите constexpr бинарные операторы +, - и * (скалярное произведение) для структуры Point.

Пример использования:
```C++
constexpr size_t size = static_cast<size_t>(Point(2,4) * Point(4,3));
int m[size]; // массив из 20 элементов */

// определение структуры Point уже подключено
```
___

## 2.3 step 11

Рассмотрим следующую функцию for_each.

Определите переменную square_fun, хранящую безымянную функцию, которая возводит переданное число в квадрат.

Пример:
```C++
int m[10] = {1,2,3,4,5,6,7,8,9,10};

for_each_int(m, m + 10, square_fun); // теперь m = {1,4,9,16,25,36,49,64,81,100};
```
___

## 2.3 step 13
Рассмотрим следующую функцию find_if:
```C++
template<class F>
int * find_if(int * p, int * q, F f)
{
    for ( ; p != q; ++p )
        if (f(*p))
            return p;
    return q;
}
```
Определите переменную gen_finder, хранящую безымянную функцию, которая принимает массив значений типа int через два указателя и
возвращает безымянную функцию, которая в свою очередь принимает значение типа int и проверяет, есть ли это значение в переданном массиве.

Пример:
```C++
int primes[5] = {2,3,5,7,11};

int m[10] = {0,0,1,1,4,6,7,8,9,10};

// first_prime будет указывать на число 7
int * first_prime = find_if(m, m + 10, gen_finder(primes, primes + 5));
```
___

## 2.4

Напишите функцию apply, которая принимает некоторую функцию / функциональный объект, а так же аргументы для вызова этого объекта, и вызывает его, используя perfect forwarding.

Пример:
```C++
auto fun = [](std::string a, std::string const& b) { return a += b; };

std::string s("world!");

// s передаётся по lvalue ссылке,
// а временный объект по rvalue ссылке
s = apply(fun, std::string("Hello, "), s);
```

Примечание: гарантируется, что количество аргументов, переданных в apply, совпадает с количеством аргументов у функции/функционального объекта. При этом у функции может быть произвольное число аргументов.

Hint: ﻿в данном задании нужно использовать новый синтаксис определения функций.
___

## 3.2

Для последовательности s1,s2,s3,…,sn−1,sns1​,s2​,s3​,…,sn−1​,sn​ будем называть подотрезком подпоследовательность вида si,si+1,si+2,…,sj−2,sj−1si​,si+1​,si+2​,…,sj−2​,sj−1​ для некоторых ii и jj, i≤ji≤j, т.е. подотрезок — это непрерывная подпоследовательность.

Напишите функцию max_increasing_len, которая принимает последовательность, хранящуюся в std::list, по двум итераторам, и вычисляет для неё длину самого длинного строго возрастающего подотрезка.

Пример:
```C++
std::list<int> const l1 = {7,8,9,4,5,6,1,2,3,4};
size_t len1 = max_increasing_len(l1.begin(), l1.end()); // 4, соответствует подотрезку 1,2,3,4

std::list<int> const l2 = {-3,-2,-1,0,0,1,2,3,4,5};
size_t len2 = max_increasing_len(l2.begin(), l2.end()); // 6, соответствует подотрезку 0,1,2,3,4,5
```
Ограничения: не используйте другие контейнеры, не копируйте элементы из списка.

На первой неделе мы познакомились с RTTI и понятием мультиметодов. В этой задаче предлагается реализовать шаблонный класс Multimethod2, реализующий мультиметод от двух аргументов, который позволяет динамически добавлять новые реализации мультиметода для различных пар классов.

Вам нужно будет реализовать три метода класса Multimethod2:

    addImpl — добавляет реализацию мультиметода для двух типов, которые заданы через std::type_info.
    hasImpl — принимает два указателя и проверяет, есть ли реализация мультиметода для соответствующих типов.
    call — принимает два указателя и вызывает для них соответствующую реализацию.

Реализация этих методов должна корректно обрабатывать ситуацию, когда мультиметод является коммутативным (т.е. если результат вызова мультиметода не зависит от порядка аргументов).

Пример использования:
```C++
// базовый класс фигуры (полиморфный)
struct Shape { ... };

// прямоугольник
struct Rectangle : Shape { ... };

// треугольник
struct Triangle : Shape { ... };

// функция для проверки пересечения двух прямоугольников
bool is_intersect_r_r(Shape * a, Shape * b);

// функция для проверки пересечения прямоугольника и треугольника
bool is_intersect_r_t(Shape * a, Shape * b);

int main() 
{
    // мультиметод для наследников Shape
    // возращающий bool и являющийся коммутативным 
    Multimethod2<Shape, bool, true> is_intersect;

    // добавляем реализацию мультиметода для двух прямоугольников
    is_intersect.addImpl(typeid(Rectangle), typeid(Rectangle), is_intersect_r_r);

    // добавляем реализацию мультиметода для прямоугольника и треугольника
    is_intersect.addImpl(typeid(Rectangle), typeid(Triangle), is_intersect_r_t);

    // создаём две фигуры    
    Shape * s1 = new Triangle();
    Shape * s2 = new Rectangle();

    // проверяем, что реализация для s1 и s2 есть
    if (is_intersect.hasImpl(s1, s2))
    {
         // вызывается функция is_intersect_r_t(s2, s1)
         bool res = is_intersect.call(s1, s2);

         // Замечание: is_intersect_r_t ожидает,
         // что первым аргументом будет прямоугольник
         // а вторым треугольник, а здесь аргументы
         // передаются в обратном порядке. 
         // ваша реализация должна самостоятельно 
         // об этом позаботиться
    }
}
```
Для реализации вам потребуется положить std::type_info в какой-то контейнер. Однако по стандарту std::type_info нельзя копировать, поэтому просто так его в контейнер не положить. Для решения этой проблемы в новом стандарте появился специальный класс-обёртка std::type_index, который можно хранить в контейнерах и даже использовать в качестве ключа в упорядоченных ассоциативных контейнерах. std::type_index определён в заголовочном файле <typeindex>.

Дополнительную информацию вы найдёте в шаблоне кода.
___

## 3.4
В этом задании вам нужно разработать итераторы для контейнера VectorList, который хранит данные в списке векторов. Для упрощения задачи от вас требуется реализовать только константные итераторы (прямой и обратный), а также реализовать методы begin, end, rbegin и rend. Для того, чтобы разобраться в устройстве контейнера, начните работу над задачей с реализации метода size. Заполнение контейнера будет происходить при помощи метода append, который уже реализован (реализация в комментариях дана для ознакомления). Метод append гарантирует, что в списке не будет пустых векторов.

Больше подробностей в коде.
___

## 3.5
Напишите алгоритм remove_nth, который удаляет элемент из последовательности по номеру этого элемента.

Пример:
``` C++
std::vector<int> v = {0,1,2,3,4,5,6,7,8,9,10};
v.erase(remove_nth(v.begin(), v.end(), 5), v.end());
// теперь в v = {0,1,2,3,4,6,7,8,9,10};
```
## 4.1
В стандартной библиотеке есть семейство функций to_string для преобразования чисел в строки. Однако обратное преобразование не такое удобное — для каждого числового типа есть своя функция (например, strtoi для int).
В данном задании вам предлагается написать шаблонную функцию from_string, которая умеет преобразовывать строку в разные типы. Для реализации from_string предлагается воспользоваться классом std::istringstream, который представляет собой поток ввода из строки, т.е. для преобразования строки в тип T предлагается прочитать значение типа T из потока при помощи оператора >>. В случае неудачного преобразования функция должна бросать исключение bad_from_string, класс которого вам нужно реализовать самостоятельно.

Пример использования from_string:
``` C++
string s1("123");
int    a1 = from_string<int>   (s1); // a1 = 123
double b1 = from_string<double>(s1); // b1 = 123.0
string c1 = from_string<string>(s1); // c1 = "123"

string s2("12.3");
int    a2 = from_string<int>   (s2); // исключение
double b2 = from_string<double>(s2); // b2 = 12.3
string c2 = from_string<string>(s2); // c2 = "12.3"

string s3("abc");
int    a3 = from_string<int>   (s3); // исключение
double b3 = from_string<double>(s3); // исключение
string c3 = from_string<string>(s3); // c3 = "abc"
```

Указания:

    Для того, чтобы учитывать пробельные символы, используйте std::noskipws (например, если строка с числом начинается с пробела или заканчивается пробелом, то это должно быть ошибкой).
    При переопределении метода what класса std::exception после сигнатуры метода нужно указывать ключевое слово noexcept (про него будет рассказано позже).
    Помните, что считывание std::string из потока означает считывание одного слова (т.е. без пробельных символов), а считывание char — одного символа.
    Флаг eof() у потоков устанавливается только, если не удалось прочитать символ: если при чтении из потока с 5-ю символами прочли 5 символов, но при этом 6-ой (отсутствующий) символ прочесть не пытались, то eof() будет выдавать false.
    Если Вы определили исключение с ключевым словом class, но не забудьте, что нужно унаследоваться от std::exception с ключевым словом public.
    Не забудьте определить конструктор bad_from_string от char const * или от std::string.

## 5.3.1

Напишите метафункцию Fib<N>, которая вычисляет N-ое число Фибоначчи.
Напоминаю, что последовательность Фибоначчи определяется следующим образом:
Fib(0)=0Fib(0)=0
Fib(1)=1Fib(1)=1
Fib(N)=Fib(N−1)+Fib(N−2)Fib(N)=Fib(N−1)+Fib(N−2)

Пример:﻿
``` C++
std::cout << Fib<10>::value;     // 55
``` 
## 5.3.2



По аналогии со списком типов определите список целых чисел (int) времени компиляции IntList.

Внутри списка должна быть константа Head, соответствующая числу в голове списка, и имя типа Tail, соответствующее хвосту списка.

Пример:
``` C++
using primes = IntList<2,3,5,7,11,13>;

constexpr int head = primes::Head;

using odd_primes = primes::Tail;
``` 

## 5.3.3

Напишите метафункцию Length для вычисления длины списка IntList.

Пример:
``` C++
using primes = IntList<2,3,5,7,11,13>;

constexpr size_t len = Length<primes>::value; // 6
```
## 5.3.6

Напишите метафункцию Zip (аналог std::transform), которая принимает два списка целых чисел одинаковой длины, а так же бинарную метафункцию,  и возвращает список, получившийся в результате поэлементного применения метафункции к соответствующим элементам исходных списков.

Пример:
``` C++
// бинарная метафункция
template<int a, int b>
struct Plus
{
    static int const value = a + b;    
};

// два списка одной длины
using L1 = IntList<1,2,3,4,5>;
using L2 = IntList<1,3,7,7,2>;

// результат применения — список с поэлементными суммами
using L3 = Zip<L1, L2, Plus>::type;  // IntList<2, 5, 10, 11, 7>
```