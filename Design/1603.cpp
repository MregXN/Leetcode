class ParkingSystem {
private:
    int v[3];
public:
    ParkingSystem(int big, int medium, int small) {
        v[0] = big;
        v[1] = medium;
        v[2] = small;
    }
    
    bool addCar(int carType) {
        return ((--v[carType-1]) >= 0);
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */