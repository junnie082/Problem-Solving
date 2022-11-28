public class Bus {
    int number;
    int people;
    int income = 9000;
    int fee;

    public void ride() {
        people += 1;
        income += fee;
    }

    public void printBus() {
        System.out.println("Bus");
        System.out.println("income: " + income);
    }



    Bus() {
        number = 5;
        people = 10;
        income = 100;
    }

    Bus(int _number, int _people, int _fee) {
        number = _number;
        people = _people;
        fee = _fee;
    }
}
