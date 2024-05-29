#include <typeinfo>
#include <typeindex>

// Base - базовый класс иерархии
// Result - тип возвращаемого значения мультиметода
// Commutative - флаг, который показывает, что
// мультиметод коммутативный (т.е. f(x,y) = f(y,x)).
template<class Base, class Result, bool Commutative>
struct Multimethod2
{
    // устанавливает реализацию мультиметода
    // для типов t1 и t2 заданных через typeid
    // f - это функция или функциональный объект
    // принимающий два указателя на Base
    // и возвращающий значение типа Result
    void addImpl( ... t1, ... t2, ... f )
    {

    }

    // проверяет, есть ли реализация мультиметода
    // для типов объектов a и b
    bool hasImpl(Base * a, Base * b) const
    {
        // возвращает true, если реализация есть
        // если операция коммутативная, то нужно
        // проверить есть ли реализация для b и а
        return ...;
    }

    // Применяет мультиметод к объектам
    // по указателям a и b
    Result call(Base * a, Base * b) const
    {
        // возвращает результат применения реализации
        // мультиметода к a и b
        return ...;
    }
};