package com.example.test;

import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;

@RequestMapping("/api/")
@RestController
public class TestController {

    @GetMapping("name")
    //@ResponseBody
    public String hello() {
        Student student;
        return "Hyojeong Jun";
    }

   // @ResponseBody
    @GetMapping("major")
    public String major() {
       // throw new IllegalArgumentException();
        return "컴공";
    }

    @GetMapping("{number}")
    public Integer number(@PathVariable Integer number) {
        return number;
    }

    @GetMapping("result")
    public String search(@RequestParam String result) {
        return result + "의 검색 결과";
    }

    @GetMapping("student")
    public Student student() {
        return student;
    }

    private int id;
    private Student student;

    @PostMapping("student")
    public ResponseEntity<Void> newStudent(@RequestBody StudentRequest request) {
        id++;
        Student student = new Student(request.getName(), request.getMajor());
        return student;
    }

}

