constexpr int dayM[13] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        bool dayA[366] = { false };
        bool *ptrAa = dayA + dayM[stoi(arriveAlice.substr(0, 2))] + stoi(arriveAlice.substr(3, 5));
        bool *ptrAb = dayA + dayM[stoi(leaveAlice.substr(0, 2))] + stoi(leaveAlice.substr(3, 5));
        bool *ptrBa = dayA + dayM[stoi(arriveBob.substr(0, 2))] + stoi(arriveBob.substr(3, 5));
        bool *ptrBb = dayA + dayM[stoi(leaveBob.substr(0, 2))] + stoi(leaveBob.substr(3, 5));
        return (ptrAb < ptrBa || ptrBb <ptrAa ? 0 : ((ptrAb <= ptrBb ? ptrAb : ptrBb) - (ptrAa > ptrBa ? ptrAa : ptrBa) + 1));
    }
};