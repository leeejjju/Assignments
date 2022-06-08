#ifndef MENULIST_H
#define MENULIST_H



class menuList{
    vector<string> m;
    int x;

    public:
    menuList(){
        m.clear();
    }
    void printInfo();
    void run();
    void showMenu();
    int addMenu(string newMenu);
    int deleteMenu(string x);
    string getRandomMenu();

};

#endif