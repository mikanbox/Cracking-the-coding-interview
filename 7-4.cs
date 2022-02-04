using System;


public class Vehicle {
    public int id;
    public int type;
    public int size;
    private ParkingLot lot;

    public Vehicle(int id, int type, int size) {
        this.id = id;
        this.type = type;
        this.size = size;
    }

    public void ParkAt(ParkingLot lot) {
        try{
            lot.In(this);
            this.lot = lot;
        }catch (System.Exception) {
            throw;
        }
    }

    public void DepartFrom() {
        if (this.lot != null)
            this.lot.Out(this);
    }
}


public class ParkingLot {
    public int leftspaces = 100;

    public void In(Vehicle v) {
        if (leftspaces < v.size) 
            throw new System.Exception("ParkingLot is full");
        leftspaces -= v.size;
    }

    public void Out(Vehicle v) {
        leftspaces += v.size;
    }
}


public class Test {
    static public void Main() {
        ParkingLot lota = new ParkingLot();
        Vehicle car1 = new Vehicle(0, 0, 5);
        Vehicle car2 = new Vehicle(1, 0, 5);
        Vehicle bike = new Vehicle(2, 0, 5);

        car1.ParkAt(lota);
        car2.ParkAt(lota);

        Console.WriteLine("lota left size = " + lota.leftspaces);
    }
}

