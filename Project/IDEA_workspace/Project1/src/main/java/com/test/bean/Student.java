package com.test.bean;

import lombok.ToString;

import java.util.List;
import java.util.Map;

@ToString
//此方法可以重写ToString方法，普通数据类型显示值，引用类型显示地址
public class Student {
    String name;
    int age;
    Card card;
    List<String> list;
    Map<String,Double> map;
    public void setName(String name){
        this.name=name;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public void setCard(Card card) {
        this.card = card;
    }
    public void setList(List<String> list) {
    this.list = list;
}

    public void setMap(Map<String, Double> map) {
        this.map = map;
    }
    public void say(){
        System.out.println("我的成绩："+map);
    }
    public Student(String name){
        this.name=name;
    }
    public Student(String name,int age){
        this.name=name;
        this.age=age;
    }
    private void init(){
        System.out.println("初始化方法");
    }
    private void destroy(){
        System.out.println("销毁方法");
    }
    public Student(){
        System.out.println("我是Student");
    }
    //单例模式下构造只进行一次
}
