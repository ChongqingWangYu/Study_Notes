# Java关键字

## this关键字

> 关键字this应用对象自身。它也可以在构造方法内部用于调用同一个类的其它构造方法。

关键字this是指向调用对象本身的引用名。可以用this关键字引用对象的实例成员，这时可以省略。在引用**隐藏数据域**以及调用一个**重载的构造方法**的时候，this不可省略。

什么是隐藏数据域？：如果一个局部变量和一个类变量具有相同的名字，那么局部变量优先，而同名的类变量将被隐藏（hidden），这个隐藏的类变量就是一个隐藏数据域。

下面是一个完整的例子：

```java
public class Circle {
    private double radius;
    private static String title = "一个圆";

    public Circle() {
        //使用this关键字调用另外一个构造方法
        this(1.0);
    }

    public Circle(double radius) {
        //this关键字用于引用所构建的对象的隐藏数据域radius
        this.radius = radius;
    }

    public void setRadius(double radius) {
        //这里也不可以省略this关键字，因为这里使用this引用隐藏数据域radius
        this.radius = radius;
    }

    public static void setTitle(String title){
        //隐藏的静态变量需要通过“类名.静态变量”的方式引用
        Circle.title = title;

    }

    public double getArea(){
        //这里可以省略this关键字
        //return this.radius * this.radius * Math.PI;
        return radius * radius * Math.PI;
    }

    @Override
    public String toString() {
        //这里可以省略this关键字
        //return "radius:" + this.radius +"area:"+this.getArea();
        return "radius:" + radius +"area:"+getArea();
    }
}
```

*注意：*在构造方法中使用this关键字时，this语句应该在任何其它可执行语句之前。

## super关键字

> 关键字super指代父类，可以用于调用父类中的普通方法和构造方法。

- 调用父类的构造方法

使用`super()`或者`super(parameters)`，前者调用父类的无参构造方法，后者调用与参数匹配的父类构造方法。**必须出现在子类构造方法的第一行**。

构造方法可以调用重载的构造方法或父类的构造方法。**如果它们都没有被显式地调用，编译器就会自动地将`super()`作为构造方法的第一句**。

- 调用父类的方法

使用语法`super.方法名（参数）;`引用父类的方法，但是一般情况下，由于子类继承了父类，可以省略super关键字（子类和父类具有相同名的方法除外）。

## this()和super()的区别

1. 调用super()必须写在子类构造方法的第一行，否则编译不通过。每个子类构造方法的第一条语句，都是隐含地调用super()，如果父类没有这种形式的构造函数，那么在编译的时候就会报错。
2. super()和this()类似，区别是，super从子类中调用父类的构造方法，this()在同一类内调用其它方法。
3. super()和this()均需放在构造方法内第一行。
4. 尽管可以用this调用一个构造器，但却不能调用两个。
5. this和super不能同时出现在一个构造函数里面，因为this必然会调用其它的构造函数，其它的构造函数必然也会有super语句的存在，所以在同一个构造函数里面有相同的语句，就失去了语句的意义，编译器也不会通过。
6. this()和super()都指的是对象，所以，均不可以在static环境中使用。包括：static变量，static方法，static语句块。
7. 从本质上讲，this是一个指向本对象的指针，然而super是一个Java关键字。

## instanceof关键字

