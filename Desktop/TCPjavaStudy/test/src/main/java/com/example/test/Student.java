package com.example.test;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.ToString;

@Getter
@ToString
@AllArgsConstructor
public class Student {

    private String name;
    private String major;
    private static int id;

    public Student() {
        this.name = "name";
        this.major = "major";
    }
}
