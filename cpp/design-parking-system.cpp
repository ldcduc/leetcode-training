/* Problem url: https://leetcode.com/problems/design-parking-system
 * Code by: ldcduc
 * */
/* Begin of Solution */
class ParkingSystem {
public:
    vector<int> slots;
    ParkingSystem(int big, int medium, int small) {
        slots.push_back(big);
        slots.push_back(medium);
        slots.push_back(small);
    }
    
    bool addCar(int carType) {
        return (-- slots[carType - 1]) >= 0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: array
 * 
 * */
