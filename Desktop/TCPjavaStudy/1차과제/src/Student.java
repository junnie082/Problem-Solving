public class Student {
    // 학생 클래스.
    String name;
    int money;

    Student(String _name, int _money) {
        name = _name;
        money = _money;
    }

    public void byBus(int _number, int _people, int _fee) {
        Bus bus = new Bus(_number, _people, _fee);
        bus.ride();
        bus.printBus();
        money -= bus.fee;
    }

    public void bySubway(int _line, int _people, int _fee) {
        Subway subway = new Subway(_line, _people, _fee);
        subway.ride();
        subway.printSubway();
        money -= subway.fee;
    }

    public void byTaxi(int _number, int _people, int _fee) {
        Taxi taxi = new Taxi(_number, _people, _fee);
        taxi.ride();
        taxi.printTaxi();
        money -= taxi.fee;
    }


}

