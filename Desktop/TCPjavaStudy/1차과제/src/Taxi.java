public class Taxi {
    int number;
    int people;
    int income = 2000;
    int fee;

    Taxi (int _number, int _people, int _fee) {
        number = _number;
        people = _people;
        fee = _fee;
    }

    public void ride() {
        people += 1;
        income += fee;
    }

    public void printTaxi() {
        System.out.println("Taxi");
        System.out.println("income" + income);
    }
}
