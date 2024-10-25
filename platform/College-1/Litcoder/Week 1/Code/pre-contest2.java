import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;
import java.util.TreeMap;

public class Main {
    public static void main(String[] args) {
        TimeTravelersArchive archive = new TimeTravelersArchive();
        Scanner input = new Scanner(System.in);

        while (input.hasNextLine()) {
            String str[] = input.nextLine().split(" ");
            String funcName = str[0];
            String key = str[1];
            String value;
            int timeStamp;

            if (funcName.equals("Store")) {
                value = str[2];
                timeStamp = Integer.parseInt(str[3]);
                archive.Store(key, value, timeStamp);
            } else if (funcName.equals("Retrieve")) {
                timeStamp = Integer.parseInt(str[2]);
                System.out.println(archive.Retrieve(key, timeStamp));
            } else {
                archive.wrongMethod();
            }
        }
        input.close();
    }
}

class TimeTravelersArchive {
    private Map<String, TreeMap<Integer, String>> archive;

    public TimeTravelersArchive() {
        archive = new HashMap<>();
    }

    public void Store(String key, String value, int timestamp) {
        archive.computeIfAbsent(key, k -> new TreeMap<>()).put(timestamp, value);
    }

    public String Retrieve(String key, int timestamp) {
        if (!archive.containsKey(key)) {
            return "";
        }
        TreeMap<Integer, String> values = archive.get(key);
        Integer floorKey = values.floorKey(timestamp);
        return floorKey == null ? "empty" : values.get(floorKey);
    }

    public void wrongMethod() {
        System.out.println("Wrong method called, please call Store or Retrieve method");
    }
}
