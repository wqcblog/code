package com.test;

import com.test.bean.Student;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class Main {
    public static void main(String[] args) {
        ClassPathXmlApplicationContext context=new ClassPathXmlApplicationContext("test.xml");
        Student student=context.getBean(Student.class); //通过类去获取
        // Student student=(Student) context.getBean("student"); 通过name/id获取，字符串名称传递
        Student student2=(Student) context.getBean("student");
        System.out.println(student);
        System.out.println(student2);
        System.out.println(student==student2); //Bean默认的属性是单例模式，获取相同的对象
        context.close();//容器关闭后才会调用destroy
    }
}
