using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

public class Vector3 { 
    public int h;
    public int w;
    public int d;
    public Vector3(int _x, int _y, int _z) {
        h = _x;
        w = _y;
        d = _z;
    } 
}

public class Solution {
    public static void Main() {
        var rand = new Random();
        int n = 4;

        List<Vector3> boxes = new List<Vector3>();
        boxes.Add(new Vector3(9,4,8));
        boxes.Add(new Vector3(7,3,2));
        boxes.Add(new Vector3(6,5,7));
        boxes.Add(new Vector3(17,1,1));

        foreach(var v in boxes) {
            Console.WriteLine("({0},{1},{2})",v.h,v.w,v.d);
        }

        for (int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if (boxes[i].h < boxes[j].h) {
                    var tmp = boxes[i];
                    boxes[i] = boxes[j];
                    boxes[j] = tmp;
                }
            }
        }

        Console.WriteLine("===========");
        foreach(var v in boxes) {
            Console.WriteLine("({0},{1},{2})",v.h, v.w, v.d);
        }

        List<int> DP = new List<int>(Enumerable.Repeat(0, n));
        // List<int> DP = new List<int>(0, n);

        for (int i = 0; i < n; i++) {
            DP[i] += boxes[i].h;
            for(int j = i; j < n; j++) {
                if (boxes[j].w < boxes[i].w && boxes[j].d < boxes[i].d && boxes[j].h < boxes[i].h) {
                    DP[j] += boxes[i].h;
                }
            }
        }

        int maxvalue = DP.Max();
        Console.WriteLine("maxvalue : {0}", maxvalue);
    }
}


