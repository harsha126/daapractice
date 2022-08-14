import java.util.*;

class LRUCache {

    Set<Integer> cache;
    int capacity;

    public LRUCache(int capacity) {
        this.cache = new LinkedHashSet<Integer>(capacity);
        this.capacity = capacity;
    }

    public boolean get(int key) {
        if (!cache.contains(key))
            return false;
        cache.remove(key);
        cache.add(key);
        return true;
    }

    public void refer(int key) {
        if (get(key) == false)
            put(key);
    }

    public void display() {
        LinkedList<Integer> list = new LinkedList<>(cache);

        Iterator<Integer> itr = list.descendingIterator();

        while (itr.hasNext())
            System.out.print(itr.next() + " ");
    }

    public void put(int key) {

        if (cache.size() == capacity) {
            int firstKey = cache.iterator().next();
            cache.remove(firstKey);
        }

        cache.add(key);
    }

    public static void main(String[] args) {
        LRUCache ca = new LRUCache(3);
        int[] arr = {1,2,3,4,1,2,5,1,2,3,4,5};
        for(int i = 0;i<arr.length;i++){
            ca.refer(arr[i]);
            ca.display();
            System.out.println();
        }
        // ca.display();
    }
}
