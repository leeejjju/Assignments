#ifndef MEMBERLIST_H
#define MEMBERLIST_H


class member{

    public:
    string name;
    int cost;
    member(string newName){
        name = newName;
        cost = 0;
    }
    member(string newName, int initCost){
        name = newName;
        cost = initCost;
    }
};

class memberList{
    vector<member> m;
    int x;

    public:
    memberList(){
        m.clear();
    }
    void printInfo();
    void run();
    void showMember();
    int addMember(string newName);
    int deleteMember(string x);
    int addCostToSelectedMember(string name, int cost);
    int addCostToAllMember(int cost);
};

#endif