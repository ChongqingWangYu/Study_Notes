# Java基础

## 什么是OO,OOA,OOD,OOP？

> 参考：[https://www.jianshu.com/p/41b3d7e1c624](https://www.jianshu.com/p/41b3d7e1c624)

- OO :**Object - Oriented** ,面向对象,基于对象概念,以对象为中心,以类和继承为构造机制,来认识,理解,刻画客观世界和设计,构建相应的软件系统的一门方法;本意-- 模拟人类的思维方式,使开发,维护,修改更加容易。
- OOA:**Object - Oriented Analysis**, 面向对象分析,强调的是在系统调查资料的基础上,针对OO方法所需要的素材进行的归类分析和整理,而不是对管理业务现状和方法的分析---其实就是进一步对OO进行细化,初步得出OO的方法(或者简单的理解:在得出的文档中对接口粗略定义)。
- OOD:**Object - Oriented Design**,面向对象设计,OO方法中一个中间过渡环节,其主要作用是对OOA分析的结果进一步的规范和整理,以便能够被OOP直接接受---整理和定义OO的属性和方法。
- OOP:**Object - Oriented Programming**,把组件的实现和接口分开,并且让组件具有多态性---(抽象,封装,继承,多态)面向接口编程。

## 抽象和封装、继承、多态

> 封装、继承、多态称为Java面向对象的三大特性。

### 抽象和封装

- 类的抽象：将类的实现和类的使用分开。

- 类的封装：实现的细节被封装并且对用户隐藏。

类的创建者描述类的功能，让使用者明白如何才能使用类。从类外可以访问的方法和数据域的集合以及预期这些成员如何行为的描述。类的使用者不需要知道类是如何实现的。

### 继承

继承是使用已存在的类的定义作为基础建立新类的技术，新类的定义可以增加新的数据或新的功能，也可以用父类的功能，但不能选择性地继承父类。通过使用继承我们能够非常方便地复用以前的代码。

1. 子类拥有父类非 private 的属性（数据域）和方法。
2. 子类可以拥有自己属性和方法，即子类可以对父类进行扩展。
3. 子类可以用自己的方式实现父类的方法（重写）。

### 多态

## 自动装箱与拆箱

### 装箱

> 将基本类型值转换为包装类对象的过程称为装箱（boxing）；

### 拆箱

> 装箱的相反转换过程，将包装类对象转换为基本数据类型的过程称为装箱（unboxing）；

Java允许基本类型和包装类类型之间进行**自动转换**。

## BigInteger和BigDecimal类

> BigInteger和BigDecimal类可以用于表示任意大小和精度的整数或者十进制数。他们位于`java.math`包中。

使用`new BigInteger();`和`new BigDecimal();`创建BigInteger和BigDecimal的实例。

使用`add`,`substract`,`multipe`,`divide`,`remainder`方法完成算术运算（加、减、乘、除、取余），例如下面是一个取余的例子：

```java
BigInteger num1 = new BigInteger("123123");
BigInteger num2 = new BigInteger("10");
BigInteger result = num1.remainder(num2);//123123 % 10
System.out.println(result);
```

## String 、StringBuffer和StringBuilder

### 可变性

String 类中使用 final 关键字字符数组保存字符串，`private　final　char　value[]`，所以 String 对象是**不可变**的。如下，源码中String类的定义：

```java
public final class String
	implements java.io.Serializable, Comparable<String>, CharSequence {
		/** The value is used for character storage. */
    	private final char value[];
    	...
    	...
    
}
```

StringBuilder 与 StringBuffer 都继承自 AbstractStringBuilder 类，在 AbstractStringBuilder 中也是使用字符数组保存字符串`char[]value` 但是没有用 final 关键字修饰，所以这两种对象都是**可变**的。

### 线程安全性

**String** 中的对象是不可变的，也就可以理解为常量，**线程安全**。AbstractStringBuilder 是 StringBuilder 与 StringBuffer 的公共父类，定义了一些字符串的基本操作，如 expandCapacity、append、insert、indexOf 等公共方法。**StringBuffer** 对方法加了同步锁或者对调用的方法加了同步锁（在源码中可以看到每个方法都加了`synchronized`关键字），所以是**线程安全**的。**StringBuilder** 并没有对方法进行加同步锁，所以是**非线程安全**的。 　　

### 性能

每次对 String 类型进行改变的时候，都会生成一个新的 String 对象，然后将指针指向新的 String 对象。

StringBuffer 每次都会对 StringBuffer 对象本身进行操作，而不是生成新的对象并改变对象引用。

相同情况下使用 StringBuilder 相比使用 StringBuffer 仅能获得 10%~15% 左右的性能提升，但却要冒多线程不安全的风险。

如果是多任务并发访问，使用StringBuffer；如果是单任务访问，使用StringBuilder会更有效。

## 方法重写和重载

### 方法重写

是指子类从父类中继承方法。使用场景一般是子类需要修改父类中定义的方法的实现。

- 仅当实例方法是可访问的，才能被覆盖。如果子类中定义的方法在父类中是私有的，那么这两个方法完全没有关系。
- 重写的方法必须使用相同的签名和相同的返回值类型在子类中定义。
- 静态方法也**能被继承但不能被覆盖**。

### 方法重载

重载方法使得你可以使用相同的名字来定义不同的方法，只要它们的签名是不同的。也就是说，一个类中有多个方法，具有相同的名字，但有不同的参数列表。Java编译器根据方法签名决定使用哪个方法。

### 重写和重载的区别

- 方法重写放生在通过继承而相关的不同类中；方法重载可以发生在同一个类中，也可以发生在由于继承而相关的不同类中。
- 方法重写具有相同的签名和返回值类型；方法重载具有相同的名字，但是不同的参数列表。

## Java关键字

### this关键字

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

### super关键字

> 关键字super指代父类，可以用于调用父类中的普通方法和构造方法。

- 调用父类的构造方法

使用`super()`或者`super(parameters)`，前者调用父类的无参构造方法，后者调用与参数匹配的父类构造方法。**必须出现在子类构造方法的第一行**。

构造方法可以调用重载的构造方法或父类的构造方法。**如果它们都没有被显式地调用，编译器就会自动地将`super()`作为构造方法的第一句**。

- 调用父类的方法

使用语法`super.方法名（参数）;`引用父类的方法，但是一般情况下，由于子类继承了父类，可以省略super关键字（子类和父类具有相同名的方法除外）。

### this()和super()的区别

1. 调用super()必须写在子类构造方法的第一行，否则编译不通过。每个子类构造方法的第一条语句，都是隐含地调用super()，如果父类没有这种形式的构造函数，那么在编译的时候就会报错。
2. super()和this()类似，区别是，super从子类中调用父类的构造方法，this()在同一类内调用其它方法。
3. super()和this()均需放在构造方法内第一行。
4. 尽管可以用this调用一个构造器，但却不能调用两个。
5. this和super不能同时出现在一个构造函数里面，因为this必然会调用其它的构造函数，其它的构造函数必然也会有super语句的存在，所以在同一个构造函数里面有相同的语句，就失去了语句的意义，编译器也不会通过。
6. this()和super()都指的是对象，所以，均不可以在static环境中使用。包括：static变量，static方法，static语句块。
7. 从本质上讲，this是一个指向本对象的指针，然而super是一个Java关键字。​                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                