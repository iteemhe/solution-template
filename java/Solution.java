import java.util.*;

class Solution {
    public static void main(String args[]) {
        var foo = new Foo();
        var str = foo.<String>foo();
    }
}

class Foo {
    @SuppressWarnings("unchecked")
    public <T> T foo() {
        Class<T> clazz = T.class;
        return (T)clazz;
    }
}
