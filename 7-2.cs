using System;


class CallCenter {
    private string value = "init";
    public CallCenter dispatchCall(string text) {
        Console.WriteLine(value);
        value = text;
        return this;
    }
}

public class Text {
    static public void Main() {
        CallCenter test = new CallCenter();
        test.dispatchCall("test1").dispatchCall("test2");
    }
}