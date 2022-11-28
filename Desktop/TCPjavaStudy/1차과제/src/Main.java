public class Main {
    public static void main(String[] args) {

        //생성자가 없는 경우
        Student jun = new Student("jun", 10000);

        jun.byBus(301, 10, 1200);
        System.out.println(jun.money);

        jun.bySubway(7, 100, 1500);
        System.out.println(jun.money);

        jun.byTaxi(5, 1, 5000);
        System.out.println(jun.money);
    }
}
