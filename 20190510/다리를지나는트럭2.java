import java.util.LinkedList;
import java.util.Queue;
import java.util.List;
import java.util.ArrayList;

//무게, 남은 이동거리에 대한 정보를 가진 Truck Class
public class Truck {
    int weight;
    int distance;
    
    public Truck(int weight, int distance) {
        this.weight = weight;
        this.distance = distance;
    }
}
 
class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        //총 수행시간, 다리가 견딜 수 있는 남은 무게
        int time = 0;
        int weightLeft = weight;
        Truck truck = null;
        
        //Queue는 LinkedList를 상속받는다.
        //다리 밖 대기 중인 트럭 (LinkedList로 연결된 Queue)
        Queue<Truck> outside = new LinkedList<Truck>();

        //ArrayList, LinkedList는 List(인터페이스)에 상속된 클래스이다. 
        //다리 위 트럭 (배열 형식의 List)
        //남은 거리를 for문으로 감소시켜주어야 함
        List<Truck> inside = new ArrayList<Truck>();
 
        for (int t : truck_weights) {
            outside.add(new Truck(t, bridge_length));
        }

        //다리 위나 다리 밖에 트럭이 하나라도 있다면 while문 반복
        while (!(inside.isEmpty()&&outside.isEmpty())) {
            time++;
            
            //다리 위 제일 앞 트럭의 남은거리<=0 (다리를 건넌 상황)
            if (!inside.isEmpty() && inside.get(0).distance <= 0) {
                //다리가 견딜 수 있는 남은 무게 증가
                weightLeft += inside.get(0).weight;
                //트럭 제거
                inside.remove(0);
            }
            
            //Queue의 최상단값이 남은 무게보다 가벼운 트럭이라면 inside로 넣어준다.
            if (!outside.isEmpty() && weightLeft >= outside.peek().weight ) {
                weightLeft -= outside.peek().weight;
                //poll()함수: fifo, 최상단값 반환+제거
                inside.add(outside.poll());
            }
            
            //다리 위 트럭의 distance(남은 거리)--;
            for (int i = 0; i < inside.size(); i++) {
                truck = inside.get(i);
                truck.distance--;
            }
        }
        //다리 위, 다리 밖 대기 중인 트럭이 모두 비어있을 때 return time;
        return time;
    }
}
