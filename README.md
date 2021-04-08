# CMC-term-4-tests
That prac again

------------------------------------------------------------------------------------------------------
intPairTask:

Опишите абстрактный класс IntPair, представлящий пару целых чисел и имеющий чисто виртуальную функцию
  
virtual int Measure() const;  
  
Унаследуйте от IntPair класс intRectangle, задающий понятие прямоугольника с целочисленными сторонами.
Функцию Measure() определите как площадь прямоугольника. Введите в класс операцию сложения, которая по
двум прямоугольникам, имеющим хотя бы одну общую сторону, строит новый прямоугольник, образованный 
"склеиванием" двух исходных. В случае, если совпадают обе стороны, производите "склеивание" по длинной
стороне. В результирующем объекте первым числом должна быть длина совпавшей стороны исходных прямоугольников,
вторым числом - сумма остальных сторон. Если совпадающих сторон не найдено, выбрасывайте исключение класса
badAdditionб в объекте которого должны содержаться длины сторон прямоугольников, сложение которых не 
удалось.

В результате следующая функция main () :  
  
<code>
int main() { <br> 
    try{  <br>
        intRectangle a(3, 5), b(5, 7), c(11, 4), d(6, 11);  <br>
        intRectangle p, q;  <br>
        p = a + b;  <br>
        q = c + d;  <br>
        printf("%d\n", (p+q).measure());  <br>
        printf("%d\n", (q+a).measure());  <br>
    }  <br>
    catch(const badAddition & bad){  <br>
        printf("Bad addition: (%d*%d) + (%d*%d)\n",  <br>
            bad.getX1(), bad.getY1(), bad.getX2(), bad.getY2()); <br> 
    }  <br>
    return 0;  <br>
}  <br>
<code>

должна откомпилироваться без ошибок, предупреждений, отработать и выдать :  
  
160  <br>
Bad addition: (11х10)+(3х5)  
  
<strong>Все поля должны быть в закрытой (private) части базового класса, открытыми и защищёнными могут быть только
функции-члены класса, использование директивы friend запрещено. Для инициализации объектов используются
конструкторы. Никакие методы не должны изменять внутренние поля объектов, допускаются только функции,
возвращающие значения полей, но не меняющие их.<strong>
------------------------------------------------------------------------------------------------------

floatPairTask:  
  
Опишите абстрактный класс FloatPair, представлящий пару float чисел и имеющий
чисто виртуальную функцию
  
virtual int Measure() const;    
    
для вычисления некоторой (неизвестной на момент создания класса) меры.
    
Унаследуйте от FloatPair класс Segment, задающий понятие отрезка числовой прямой.
При попытке сконструировать отрезок, начальная точка которого правее конечной,
выбрасывайте исключение типа badSegment. Функцию Меasure() определите как длину
отрезка.
  
Введите в классе операцию сложения, которая по двум отрезкам, полностью или
частично перекрывающимся, строит новый отрезок, содержащий все точки исходных
отрезков (объединение). Если отрезки не имеют общих точек, их объединение
не будет отрезком; в этом случае выбрасывайте исключение класса BadAddition, в
объекте которого должны содержаться границы обоих отрезков, которые не удалось
сложить.
  
В результате следующая функция main():  

<code>
int main()  <br>
{  <br>
    try{  <br>
        segment f(1, 2), g(0.5, 5), h(2.5, 6.5); <br> 
        printf("%3.3f, %3.3f, %3.3f\n",  <br>
            (f+g).measure(), (g+h).measure(), (f+g+h).measure());  <br>
        printf("%3.3f\n", (f+h).measure());  <br>
    }  <br>
    catch(const badAddition & bad){  <br>
        printf("Bad addition: [%3.3f; %3.3f] + [%3.3f; %3.3f]\n", <br> 
            bad.getA1(), bad.getB1(), bad.getA2(), bad.getB2()); <br> 
    }  <br>
    catch(badSegment b){  <br>
        printf("Bad segment\n");  <br>
    }  <br>
    return 0;  <br>
}  <br>
<code>

должна откомпилироваться без ошибок и предупреждений, отработать и выдать  
  
4.500, 6.000, 6.000  <br>
BadAddition: [1.000; 2.000]+[2.500; 6.500]  
  
<strong> Все поля должны быть в закрытой (private) части базового класса, открытыми и защищёнными 
могут быть только функции-члены класса, использование директивы friend запрещено. Для
инициализации объектов используются конструкторы. Никакие методы не должны изменять
внутренние поля объектов, допускаются только функции, возвращающие значения полей, но не
меняющие их. <strong>