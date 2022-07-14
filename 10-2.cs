using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Solution {
    public static void Main() {
        List<String> words = new List<String>() {
            "amazon","abc","cba","bac","zonama","google","amanoz"
        };
        List< Tuple<String,int> > ModifiedWords = new List<Tuple<String,int>>();

        for (int i = 0; i < words.Count; i++)
            ModifiedWords.Add( new Tuple<String,int>(String.Concat( words[i].OrderBy(ch => ch) ), i ));
        
        ModifiedWords.Sort((x, y) => x.Item1.CompareTo(y.Item1));

        for (int i = 0; i < ModifiedWords.Count; i++) 
            Console.WriteLine(words[ModifiedWords[i].Item2]);

    }
}




