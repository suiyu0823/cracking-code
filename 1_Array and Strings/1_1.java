/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author DanielX
 * This System will check user's status either student or teacher
 * Return Student (Or Teacher) Number and Corresponding Courses
 */
import java.io.*;
import java.util.Scanner;

    public boolean isUnique(String str)
        {
            if (str.length() > 128) return false;

            boolean[]char_set = new boolean[256];

            for (int i = 0; i < s.size(); i++)
        {

            int val = str.charAt(i);
            if (char_set[val]){
                return false;
            }
            char_set[val] = true;
        }
        return true;
    }
        }
    public static void main(String[] args) {
    String s = "Test string" ;
    boolean test = isUnique(s);
    System.out.println(test);
       
}
