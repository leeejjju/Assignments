import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

class TestHashMap{

    public static void main(String[] args){
        Map<String, Integer> a = new HashMap<String, Integer>();

        a.put("Kim", 0);
        a.put("Lee", 1);
        a.put("Park", 20);
        a.put("Choi", 3);


        /*
        System.out.println(a);
        for(String name : a.keySet()){ //????û•?êú keyÍ∞? ?ôï?ù∏
            System.out.println("[Key]:" + name + " [Value]:" + a.get(name));
        }
        */

        //Map<String, Integer> result = sortMapByValue(a);
        a = sortMapByKey(a);
        for (Map.Entry<String, Integer> entry : a.entrySet()) {
            System.out.println("Key: " + entry.getKey() + ", "
                    + "Value: " + entry.getValue());
        }


    }

    public static LinkedHashMap<String, Integer> sortMapByKey(Map<String, Integer> a) {
        List<Map.Entry<String, Integer>> entries = new LinkedList<>(a.entrySet());
        Collections.sort(entries, (o1, o2) -> o1.getKey().compareTo(o2.getKey()));

        LinkedHashMap<String, Integer> result = new LinkedHashMap<>();
        for (Map.Entry<String, Integer> entry : entries) {
            result.put(entry.getKey(), entry.getValue());
        }
        return result;
    }

    public static LinkedHashMap<String, Integer> sortMapByValue(Map<String, Integer> a) {
        List<Map.Entry<String, Integer>> entries = new LinkedList<>(a.entrySet());
        Collections.sort(entries, (o1, o2) -> o1.getValue().compareTo(o2.getValue()));

        LinkedHashMap<String, Integer> result = new LinkedHashMap<>();
        for (Map.Entry<String, Integer> entry : entries) {
            result.put(entry.getKey(), entry.getValue());
        }
        return result;
    }


}

