import java.util.*;

public class Probl{
    public static void main(String[] args){
        List<Integer> l = new ArrayList<>();
        l.add(1);
        l.add(1);
        l.add(1);
        l.add(1);
        l.add(2);
        System.out.println(droppedRequests(l));

    }
    public static int droppedRequests(List<Integer> requestTime) {

        int[] requestTimeArr = requestTime.stream().mapToInt(i->i).toArray();
        System.out.println(requestTimeArr);

        int dropped = 0;

        for (int i = 0 ; i < requestTimeArr.length ; i++) {

            if (i > 2 && requestTimeArr[i] == requestTimeArr[i-3]) {
                ++dropped;
            } else if (i > 19 && (requestTimeArr[i] - requestTimeArr[i-20]) < 10) {
                ++dropped;
            } else if (i > 59 && (requestTimeArr[i] - requestTimeArr[i-60]) < 60) {
                ++dropped;
            }
        }

        return dropped;
    }
}
