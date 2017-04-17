//
//  dungeon.cc
//  CC3K
//
//

#include "dungeon.h"
#include "tile.h"
#include "potion.h"
#include "gold.h"
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "map.h"
#include <ctime>
#include <cstring>
#include <tgmath.h>
using namespace std;

bool isPlayer(Cell*); //declaration before use

//----------------------------Command related stuff goes under here

bool Dungeon::movePlayer(string direction) {
    actstr = "";
    
    bool win = false;			//set to false everytime we move
    
    int xtmp = pp->getX(); //temporarily stores the x and y coords for PC
    int ytmp = pp->getY();
    Gold *tmpgold;
    if (direction == "no") {
        ytmp = ytmp - 1;         //y-1 coordinate is now referred to as ytmp
        actstr = "PC moves North";
    }
    else if (direction == "so") {
        ytmp = ytmp + 1;
        actstr = "PC moves South";
    }
    else if (direction == "ea") {
        xtmp = xtmp + 1;
        actstr = "PC moves East";
    }
    else if (direction == "we") {
        xtmp = xtmp - 1;
        actstr = "PC moves West";
    }
    else if (direction == "ne") {
        ytmp = ytmp - 1;
        xtmp = xtmp + 1;
        actstr = "PC moves NorthEast";
    }
    else if (direction == "nw") {
        ytmp = ytmp - 1;
        xtmp = xtmp - 1;
        actstr = "PC moves NorthWest";
    }
    else if (direction == "se") {
        ytmp = ytmp + 1;
        xtmp = xtmp + 1;
        actstr = "PC moves SouthEast";
    }
    else if (direction == "sw") {
        ytmp = ytmp + 1;
        xtmp = xtmp - 1;
        actstr = "PC moves SouthWest";
    }
    //ytmp and xtmp set
    bool move = false;
    if (pos[ytmp][xtmp]->getIcon()=='\\'){          //case stairs
        if (floor == 8) {
            win=true;
            actstr = "You Win!";
        }
        else {
            nextLevel();
        }
    }
    if (map[ytmp][xtmp].getChar()!= '-' && map[ytmp][xtmp].getChar()!= '|' && map[ytmp][xtmp].getChar()!= ' ') {  //wall check
        move = true;
    }
    if (pos[ytmp][xtmp]->getIcon()=='G') {    //if its a gold
        tmpgold = static_cast<Gold*>(pos[ytmp][xtmp]);
        if (tmpgold->isAvailable()) {
            pp->addGold(tmpgold->getGold());
            delete tmpgold;                     //deletes gold and creates a new blank cell
            pos[ytmp][xtmp]= new Cell();
        }
        else {
            move = false;
        }
    }
    if (pos[ytmp][xtmp]->getIcon()==' '&&move) {  //check no enemy/potion
        pos[pp->getY()][pp->getX()] = new Cell();    //old pos*** points to new cell
        delete pos[ytmp][xtmp];                      //
        pos[ytmp][xtmp] = pp;
        pp->setCoords(xtmp, ytmp);
    }
    
    // ------- Checks if there are any potions around
    
	if (pos[ytmp][xtmp + 1]->getIcon() == 'P') {
        Potion *tmppot =static_cast<Potion*>(pos[ytmp][xtmp + 1]);
        actstr.append(" and sees an ");
		if (pp->isSeenPotion(tmppot->getType())) {
            actstr.append(tmppot->getType());
            actstr.append(" potion");
        } else {
            actstr.append("unknown potion");
        }
	}
	if (pos[ytmp][xtmp - 1]->getIcon() == 'P') {
        Potion *tmppot =static_cast<Potion*>(pos[ytmp][xtmp - 1]);
        actstr.append(" and sees an ");
		if (pp->isSeenPotion(tmppot->getType())) {
            actstr.append(tmppot->getType());
            actstr.append(" potion");
        } else {
            actstr.append("unknown potion");
        }
	}
	if (pos[ytmp + 1][xtmp]->getIcon() == 'P') {
        Potion *tmppot =static_cast<Potion*>(pos[ytmp + 1][xtmp]);
        actstr.append(" and sees an ");
		if (pp->isSeenPotion(tmppot->getType())) {
            actstr.append(tmppot->getType());
            actstr.append(" potion");
        } else {
            actstr.append("unknown potion");
        }
	}
	if (pos[ytmp - 1][xtmp]->getIcon() == 'P') {
        Potion *tmppot =static_cast<Potion*>(pos[ytmp - 1][xtmp]);
        actstr.append(" and sees an ");
		if (pp->isSeenPotion(tmppot->getType())) {
            actstr.append(tmppot->getType());
            actstr.append(" potion");
        } else {
            actstr.append("unknown potion");
        }
	}
	if (pos[ytmp + 1][xtmp + 1]->getIcon() == 'P') {
        Potion *tmppot =static_cast<Potion*>(pos[ytmp + 1][xtmp + 1]);
        actstr.append(" and sees an ");
		if (pp->isSeenPotion(tmppot->getType())) {
            actstr.append(tmppot->getType());
            actstr.append(" potion");
        } else {
            actstr.append("unknown potion");
        }
	}
	if (pos[ytmp - 1][xtmp + 1]->getIcon() == 'P') {
        Potion *tmppot =static_cast<Potion*>(pos[ytmp - 1][xtmp + 1]);
        actstr.append(" and sees an ");
		if (pp->isSeenPotion(tmppot->getType())) {
            actstr.append(tmppot->getType());
            actstr.append(" potion");
        } else {
            actstr.append("unknown potion");
        }
	}
	if (pos[ytmp + 1][xtmp - 1]->getIcon() == 'P') {
        Potion *tmppot =static_cast<Potion*>(pos[ytmp + 1][xtmp - 1]);
        actstr.append(" and sees an ");
		if (pp->isSeenPotion(tmppot->getType())) {
            actstr.append(tmppot->getType());
            actstr.append(" potion");
        } else {
            actstr.append("unknown potion");
        }
	}
	if (pos[ytmp - 1][xtmp - 1]->getIcon() == 'P') {
        Potion *tmppot =static_cast<Potion*>(pos[ytmp - 1][xtmp - 1]);
        actstr.append(" and sees an ");
		if (pp->isSeenPotion(tmppot->getType())) {
            actstr.append(tmppot->getType());
            actstr.append(" potion");
        } else {
            actstr.append("unknown potion");
        }
	}
    // at the very end
    if (pp->isDead()) {
        win = true;
        actstr= "You Died!";
    }
    return win;
}

bool Dungeon::attack(string direction) {
    actstr = "";
    
    bool win = false;
    int xtmp = pp->getX(); //temporarily stores the x and y coords for PC as well
    int ytmp = pp->getY();
    if (direction == "no") {
        ytmp = ytmp - 1;         //y-1 coordinate is now referred to as ytmp
    }
    else if (direction == "so") {
        ytmp = ytmp + 1;
    }
    else if (direction == "ea") {
        xtmp = xtmp + 1;
    }
    else if (direction == "we") {
        xtmp = xtmp - 1;
    }
    else if (direction == "ne") {
        ytmp = ytmp - 1;
        xtmp = xtmp + 1;
    }
    else if (direction == "nw") {
        ytmp = ytmp - 1;
        xtmp = xtmp - 1;
    }
    else if (direction == "se") {
        ytmp = ytmp + 1;
        xtmp = xtmp + 1;
    }
    else if (direction == "sw") {
        ytmp = ytmp + 1;
        xtmp = xtmp - 1;
    }

    
    if (pos[ytmp][xtmp]->getIcon()=='V'||pos[ytmp][xtmp]->getIcon()=='N'||pos[ytmp][xtmp]->getIcon()=='M'||pos[ytmp][xtmp]->getIcon()=='X'||pos[ytmp][xtmp]->getIcon()=='T'||pos[ytmp][xtmp]->getIcon()=='W'||pos[ytmp][xtmp]->getIcon()=='D') {
        Enemy *currenemy = static_cast<Enemy*>(pos[ytmp][xtmp]);
//        if (!currenemy->isDead()) {
        if (currenemy->getIcon()=='M') {
            mhos=true;
        }
            int damage = ceil(100/(100+static_cast<double>(currenemy->getDef())) * pp->getAtk());
            currenemy->setHP(-1*damage);
            actstr = "PC deals ";
            stringstream ss;
            ss<<damage;
            actstr.append(ss.str());
            stringstream ss1;
            actstr.append(" damage to ");
            ss1<<currenemy->getIcon();
            actstr.append(ss1.str());
            actstr.append(" (");
            stringstream ss2;
            ss2<<currenemy->getHP();
            actstr.append(ss2.str());
            actstr.append(" HP)");
            if (currenemy->isDead()) {
                if (currenemy->getIcon()=='M') {
                    pos[ytmp][xtmp] = new Gold('8');//merchant drops gold
                }
                else {
                    pos[ytmp][xtmp] = new Cell();
                }
                cout << pos[ytmp][xtmp]->getIcon() << endl;
                if (currenemy->getIcon()=='D'){
                    currenemy->setGoldAvailable();
                }
                delete currenemy;
                currenemy = NULL;
 //           }
        }
    }
    // at the very end
    if (pp->isDead()) {
        win = true;
        actstr= "You Died!";
    }
    return win;
}

bool Dungeon::use(string direction) {
    actstr = "";
    bool win=false;
    int xtmp = pp->getX(); //temporarily stores the x and y coords for PC as well
    int ytmp = pp->getY();
    if (direction == "no") {
        ytmp = ytmp - 1;         //y-1 coordinate is now referred to as ytmp
    }
    else if (direction == "so") {
        ytmp = ytmp + 1;
    }
    else if (direction == "ea") {
        xtmp = xtmp + 1;
    }
    else if (direction == "we") {
        xtmp = xtmp - 1;
    }
    else if (direction == "ne") {
        ytmp = ytmp - 1;
        xtmp = xtmp + 1;
    }
    else if (direction == "nw") {
        ytmp = ytmp - 1;
        xtmp = xtmp - 1;
    }
    else if (direction == "se") {
        ytmp = ytmp + 1;
        xtmp = xtmp + 1;
    }
    else if (direction == "sw") {
        ytmp = ytmp + 1;
        xtmp = xtmp - 1;
    }
    if (pos[ytmp][xtmp]->getIcon()=='P') {
        Item *itmpoint = static_cast<Item*>(pos[ytmp][xtmp]);
        Potion *potpoint = static_cast<Potion*>(pos[ytmp][xtmp]);
        actstr = "PC uses ";
        actstr.append(potpoint->getType());
        pp->usePotion(potpoint->getStat(),itmpoint->getAmount());
        pp->seenPotion(potpoint->getType());
        delete potpoint;
        pos[ytmp][xtmp] = new Cell();
        pos[ytmp][xtmp]->setCoords(xtmp, ytmp);
    }
    if (pp->isDead()) {
        win = true;
        actstr= "You Died!";
    }
    return win;
}

void Dungeon::print() {
    for (int i=0; i<25; i++) {
        for (int j=0; j<79; j++) {
            if (pos[i][j]->getIcon()!=' ') {
                cout<<pos[i][j]->getIcon();
            }
            else {
                cout<<map[i][j].getChar();
            }
        }
        cout<<endl;
    }
    
    //Time to print status under board!!!
    cout<<"Race ";
    if (pp->getRace()=='h') {
        cout<<"Human ";
    }
    else if (pp->getRace()=='e') {
        cout<<"Elf ";
    }
    else if (pp->getRace()=='o') {
        cout<<"Orc ";
    }
    else if (pp->getRace()=='d') {
        cout<<"Dwarf ";
    }
    cout<<"Gold: ";
    cout<<pp->getGold();
    cout<<"                                                     "; //ALOT OF SPACES!!
    cout<<"Floor "<< floor<<endl;           //TODO : Take care of the floor shit later
    cout<<"HP: "<<pp->getCurrentHP()<<endl;
    cout<<"Atk: "<<pp->getAtk()<<endl;
    cout<<"Def: "<<pp->getDef()<<endl;
    cout<<"Action: " << actstr << endl;
}

bool Dungeon::step() {

    //--------------moving enemies start here
    for (int i=0; i<HEIGHT; i++) {
        for (int j=0; j<WIDTH; j++) {
            if (pos[i][j]->getIcon()=='D') {
                Enemy *dragon = static_cast<Enemy*>(pos[i][j]);
                Gold *dG = dragon->getGold();
                int itmp = dG->getY();
                int jtmp = dG->getX();
                bool attack = false;
                if (pos[itmp-1][jtmp]->getIcon()=='@') {
                    attack=true;
                }
                else if (pos[itmp+1][jtmp]->getIcon()=='@'){
                    attack=true;
                }
                else if (pos[itmp][jtmp-1]->getIcon()=='@'){
                    attack=true;
                }
                else if (pos[itmp][jtmp+1]->getIcon()=='@'){
                    attack=true;
                }
                else if (pos[itmp-1][jtmp-1]->getIcon()=='@'){
                    attack=true;
                }
                else if (pos[itmp-1][jtmp+1]->getIcon()=='@'){
                    attack=true;
                }
                else if (pos[itmp+1][jtmp+1]->getIcon()=='@'){
                    attack=true;
                }
                else if (pos[itmp+1][jtmp-1]->getIcon()=='@'){
                    attack=true;
                }
                if (attack) {
                    int damage = dragon->attackMe(pp->getDef());
                    pp->setHP(-1*damage);
                    stringstream ss;
                    ss<<damage;
                    actstr.append(". D deals ");
                    actstr.append(ss.str());
                    actstr.append(" damage to PC");
                }
            }
            else if (pos[i][j]->getIcon()=='V'||pos[i][j]->getIcon()=='N'||pos[i][j]->getIcon()=='M'||pos[i][j]->getIcon()=='X'||pos[i][j]->getIcon()=='T'||pos[i][j]->getIcon()=='W') {
                Enemy *currenemy = static_cast<Enemy*>(pos[i][j]);
                int possible=0;
                bool directions[8] = {false};
                
                
                
                
                if (pos[i][j]->getIcon()!='M'||(pos[i][j]->getIcon() == 'M' && mhos)){
                    if (isPlayer(pos[i][j + 1])) {
                        int damage = currenemy->attackMe(pp->getDef());
                        actstr.append(". ");
                        stringstream ass1c;
                        ass1c<<currenemy->getIcon();
                        actstr.append(ass1c.str());
                        actstr.append(" deals ");
                        stringstream ass1d;
                        ass1d<<damage;
                        actstr.append(ass1d.str());
                        actstr.append(" damage to PC ");
                        pp->setHP(-1*damage);
                        currenemy->setMoved(true);
                    }
                    if (isPlayer(pos[i][j - 1])) {
                        
                        int damage = currenemy->attackMe(pp->getDef());
                        actstr.append(". ");
                        stringstream ass1c;
                        ass1c<<currenemy->getIcon();
                        actstr.append(ass1c.str());
                        actstr.append(" deals ");
                        stringstream ass1d;
                        ass1d<<damage;
                        actstr.append(ass1d.str());
                        actstr.append(" damage to PC ");
                        pp->setHP(-1*damage);
                        currenemy->setMoved(true);
                    }
                    if (isPlayer(pos[i + 1][j])) {
                        
                        int damage = currenemy->attackMe(pp->getDef());
                        actstr.append(". ");
                        stringstream ass1c;
                        ass1c<<currenemy->getIcon();
                        actstr.append(ass1c.str());
                        actstr.append(" deals ");
                        stringstream ass1d;
                        ass1d<<damage;
                        actstr.append(ass1d.str());
                        actstr.append(" damage to PC ");
                        pp->setHP(-1*damage);
                        currenemy->setMoved(true);
                    }
                    if (isPlayer(pos[i - 1][j])) {
                        
                        int damage = currenemy->attackMe(pp->getDef());
                        actstr.append(". ");
                        stringstream ass1c;
                        ass1c<<currenemy->getIcon();
                        actstr.append(ass1c.str());
                        actstr.append(" deals ");
                        stringstream ass1d;
                        ass1d<<damage;
                        actstr.append(ass1d.str());
                        actstr.append(" damage to PC ");
                        pp->setHP(-1*damage);
                        currenemy->setMoved(true);
                    }
                    if (isPlayer(pos[i + 1][j + 1])) {
                        
                        int damage = currenemy->attackMe(pp->getDef());
                        actstr.append(". ");
                        stringstream ass1c;
                        ass1c<<currenemy->getIcon();
                        actstr.append(ass1c.str());
                        actstr.append(" deals ");
                        stringstream ass1d;
                        ass1d<<damage;
                        actstr.append(ass1d.str());
                        actstr.append(" damage to PC ");
                        pp->setHP(-1*damage);
                        currenemy->setMoved(true);
                    }
                    if (isPlayer(pos[i - 1][j + 1])) {
                        
                        int damage = currenemy->attackMe(pp->getDef());
                        actstr.append(". ");
                        stringstream ass1c;
                        ass1c<<currenemy->getIcon();
                        actstr.append(ass1c.str());
                        actstr.append(" deals ");
                        stringstream ass1d;
                        ass1d<<damage;
                        actstr.append(ass1d.str());
                        actstr.append(" damage to PC ");
                        pp->setHP(-1*damage);
                        currenemy->setMoved(true);
                    }
                    if (isPlayer(pos[i + 1][j - 1])) {
                        
                        int damage = currenemy->attackMe(pp->getDef());
                        actstr.append(". ");
                        stringstream ass1c;
                        ass1c<<currenemy->getIcon();
                        actstr.append(ass1c.str());
                        actstr.append(" deals ");
                        stringstream ass1d;
                        ass1d<<damage;
                        actstr.append(ass1d.str());
                        actstr.append(" damage to PC ");
                        pp->setHP(-1*damage);
                        currenemy->setMoved(true);
                    }
                    if (isPlayer(pos[i - 1][j - 1])) {
                        
                        int damage = currenemy->attackMe(pp->getDef());
                        actstr.append(". ");
                        stringstream ass1c;
                        ass1c<<currenemy->getIcon();
                        actstr.append(ass1c.str());
                        actstr.append(" deals ");
                        stringstream ass1d;
                        ass1d<<damage;
                        actstr.append(ass1d.str());
                        actstr.append(" damage to PC ");
                        pp->setHP(-1*damage);
                        currenemy->setMoved(true);
                    }
                }
                
                
                
                
                
                
                
                
                
                
                
                
                
                if (!currenemy->isMoved()) {
                    if (pos[i][j+1]->getIcon()==' ' && map[i][j+1].getChar()=='.') {
                        possible++;
                        directions[0] = true;
                    }
                    if (pos[i][j-1]->getIcon()==' ' && map[i][j-1].getChar()=='.') {
                        possible++;
                        directions[1]= true;
                    }
                    if (pos[i+1][j]->getIcon()==' ' && map[i+1][j].getChar()=='.') {
                        possible++;
                        directions[2]= true;
                    }
                    if (pos[i-1][j]->getIcon()==' ' && map[i-1][j].getChar()=='.') {
                        possible++;
                        directions[3]= true;
                    }
                    if (pos[i+1][j+1]->getIcon()==' ' && map[i+1][j+1].getChar()=='.') {
                        possible++;
                        directions[4]= true;
                    }
                    if (pos[i-1][j+1]->getIcon()==' ' && map[i-1][j+1].getChar()=='.') {
                        possible++;
                        directions[5]= true;
                    }
                    if (pos[i+1][j-1]->getIcon()==' ' && map[i+1][j-1].getChar()=='.') {
                        possible++;
                        directions[6]= true;
                    }
                    if (pos[i-1][j-1]->getIcon()==' ' && map[i-1][j-1].getChar()=='.') {
                        possible++;
                        directions[7]= true;
                    }
                    if (possible != 0) {
                        int r= rand()%possible;
                        for (int k = 0; k < 8; k++) {
                            if (directions[k]) {
                                if (r == 0) {
                                    int itmp = i;
                                    int jtmp = j;
                                    pos[i][j] = new Cell();
                                    //set enemy position depending on the random num generated
                                    if (k == 0) {
                                        jtmp++;
                                    } else if (k == 1) {
                                        jtmp--;
                                    } else if (k == 2) {
                                        itmp++;
                                    } else if (k == 3) {
                                        itmp--;
                                    } else if (k == 4) {
                                        itmp++;
                                        jtmp++;
                                    } else if (k == 5) {
                                        itmp--;
                                        jtmp++;
                                    } else if (k == 6) {
                                        jtmp--;
                                        itmp++;
                                    } else if (k == 7) {
                                        itmp--;
                                        jtmp--;
                                    }
                                    
                                    delete pos[itmp][jtmp];
                                    pos[itmp][jtmp] = currenemy;
                                    currenemy->setCoords(jtmp, itmp);
                                    pos[i][j]= new Cell();
                                    break;
                                }
                                r--;
                            }
                        }
                    }
                    currenemy->setMoved(true);
                }
            }
        }
    }
    for (int i=0; i<HEIGHT; i++) {
        for (int j=0; j<WIDTH; j++) {
            if (pos[i][j]->getIcon()=='V'||pos[i][j]->getIcon()=='N'||pos[i][j]->getIcon()=='M'||pos[i][j]->getIcon()=='X'||pos[i][j]->getIcon()=='T'||pos[i][j]->getIcon()=='W'){
                static_cast<Enemy*>(pos[i][j])->setMoved(false);
            }
        }
    }
    
    if (pp->isDead()) {
        actstr = "You Died!";
        return true;
        
    }
    else {
        return false;
    }
}


//----------------------------Constructor/Initializer related stuff goes under here:

Dungeon::Dungeon(char race){
    //initialize map first
    pp = new Player(race); //needs args for race
    cusMap = false;
    srand(time(NULL));
    floor =1;
	actstr = "PC has spawned!";
    mhos = false;
}

void Dungeon::nextLevel(){
    for (int i=0; i<HEIGHT; i++) {       //deletes all the things and generates
        delete [] pos[i];
    }
    //TODO: Player might spawn in the same chamber as stairs
    delete [] pos;
    pos = new Cell**[HEIGHT];
    for (int i=0; i<HEIGHT; i++) {
        pos[i] = new Cell*[WIDTH];
    }
    for (int i=0; i<HEIGHT; i++) {
        for (int j=0; j<WIDTH; j++) {
            pos[i][j]= new Cell();
        }
    }
    generate();
    floor++;
    pp->clearPotion();
}

void Dungeon::readMap(string fname){
    istream *in = new ifstream(fname.c_str());
    map = new Tile*[HEIGHT];
    pos = new Cell**[HEIGHT];
    for (int i=0; i<HEIGHT; i++) {
        map[i] = new Tile[WIDTH];
        pos[i] = new Cell*[WIDTH];
        for (int j=0; j<WIDTH; j++) {
            char tmp;
            *in>>noskipws>>tmp;
            if (tmp == '\n') {
                *in>>noskipws>>tmp;     //gets rid of endl
            }
            if (tmp == 'V'||tmp == 'W'||tmp == 'N'||tmp == 'D'||tmp == 'X'|| tmp == 'M' || tmp == 'T') {
                map[i][j] = Tile('.');
                pos[i][j] = new Enemy(tmp);
                pos[i][j]->setCoords(j, i);
                cusMap = true;
            } else if (tmp == '0' || tmp == '1' || tmp == '2' || tmp == '3' || tmp == '4' || tmp == '5') {
                map[i][j] = Tile('.');
                pos[i][j] = new Potion(tmp);     // TODO: do this **** later
                pos[i][j]->setCoords(j, i);
                cusMap = true;
            }else if (tmp == '6' || tmp == '7' || tmp == '8' || tmp == '9') {
                map[i][j] = Tile('.');
                pos[i][j] = new Gold(tmp);
                pos[i][j]->setCoords(j, i);
                cusMap = true;
            }else if (tmp == '@') {
                pp->setCoords(j, i);
                map[i][j] = Tile('.');
                pos[i][j] = pp;         //make new cell ' '
                pos[i][j]->setCoords(j, i);
                cusMap = true;
            } else {
                map[i][j] = Tile(tmp);       //set map layer
                pos[i][j] = new Cell();         //make new cell ' '
                pos[i][j]->setCoords(j, i);
            }
        }
    }
    
    if (!cusMap){                  //case not custom map
        generate();
    }
}
void Dungeon::genHelper(Cell *cptr){
    int chamb = rand()%5;
    if (cptr->getIcon() == '\\') {
        while (chamb == staircb) {
            chamb = rand()%5;
        }
    }
    int xgen=-1;
    int ygen=-1;
    do {
        if (chamb == 0) {
            xgen = rand()%26+3;
            ygen = rand()%4+3;
        }
        else if (chamb ==1) {
            int r = rand()%201;
            xgen = dict2[r][0];
            ygen = dict2[r][1];
        }
        else if (chamb ==2) {
            xgen = rand()%12+38;
            ygen = rand()%3+10;
        }
        else if (chamb ==3) {
            xgen = rand()%21+4;
            ygen = rand()%7+15;
        }
        else if (chamb ==4) {
            int r = rand()%150;
            xgen = dict1[r][0];
            ygen = dict1[r][1];
        }
    }while (pos[ygen][xgen]->getIcon()!=' ');
    cptr->setCoords(xgen, ygen);
    delete pos[ygen][xgen];
    pos[ygen][xgen] = cptr;
    if (cptr->getIcon() == '@') {
        staircb = chamb;
    }
}

void Dungeon::generate(){
    
    //Generate character:
    genHelper(pp);
    
    //Generate stairs:
    Cell *stair = new Cell('\\');
    
    genHelper(stair);
    
    for (int i=0; i < MAXPOTION; i++) {
        int type = rand()%6;
        Cell *potion = new Potion(pot[type]);
        genHelper(potion);
    }
    
    int mgenerated=0;
    for (int i=0; i<MAXGOLD; i++) {            //gerates gold
        int type = rand()%8;
        if (type==7) {
            Cell *gened = new Gold(gold[type]);    //DRAGON GOLLLLD
            genHelper(gened);
            int dx = gened->getX();
            int dy = gened->getY();               //for the dragon
            int possible=0;
            bool directions[8] = {false};
            if (pos[dy][dx+1]->getIcon()==' ' && map[dy][dx+1].getChar()=='.') {
                possible++;
                directions[0] = true;
            }
            if (pos[dy][dx-1]->getIcon()==' ' && map[dy][dx-1].getChar()=='.') {
                possible++;
                directions[1]= true;
            }
            if (pos[dy+1][dx]->getIcon()==' ' && map[dy+1][dx].getChar()=='.') {
                possible++;
                directions[2]= true;
            }
            if (pos[dy-1][dx]->getIcon()==' ' && map[dy-1][dx].getChar()=='.') {
                possible++;
                directions[3]= true;
            }
            if (pos[dy+1][dx+1]->getIcon()==' ' && map[dy+1][dx+1].getChar()=='.') {
                possible++;
                directions[4]= true;
            }
            if (pos[dy-1][dx+1]->getIcon()==' ' && map[dy-1][dx+1].getChar()=='.') {
                possible++;
                directions[5]= true;
            }
            if (pos[dy+1][dx-1]->getIcon()==' ' && map[dy+1][dx-1].getChar()=='.') {
                possible++;
                directions[6]= true;
            }
            if (pos[dy-1][dx-1]->getIcon()==' ' && map[dy-1][dx-1].getChar()=='.') {
                possible++;
                directions[7]= true;
            }
            if (possible != 0) {
                int r= rand()%possible;
                for (int k = 0; k < 8; k++) {
                    if (directions[k]) {
                        if (r == 0) {
                            int jtmp = dx;
                            int itmp = dy;
                            if (k == 0) {
                                jtmp++;
                            } else if (k == 1) {
                                jtmp--;
                            } else if (k == 2) {
                                itmp++;
                            } else if (k == 3) {
                                itmp--;
                            } else if (k == 4) {
                                itmp++;
                                jtmp++;
                            } else if (k == 5) {
                                itmp--;
                                jtmp++;
                            } else if (k == 6) {
                                jtmp--;
                                itmp++;
                            } else if (k == 7) {
                                itmp--;
                                jtmp--;
                            }
                            
                            delete pos[itmp][jtmp];
                            pos[itmp][jtmp] = new Enemy('D');
                            pos[itmp][jtmp]->setCoords(jtmp, itmp);
                            Enemy *ndragon = static_cast<Enemy*>(pos[itmp][jtmp]);
                            ndragon->setGold(static_cast<Gold*>(gened)); //this goes the other way around
                            mgenerated++;
                            break;
                        }
                        r--;
                    }
                }
            }
        }
        else {
            Cell *gened = new Gold(gold[type]);
            genHelper(gened);
        }
    }
    for (;mgenerated<20; mgenerated++) {
        int type = rand()%18;
        Cell *gened = new Enemy(enemy[type]);
        genHelper(gened);                    //passes it to genHelper that sets its coords
    }
}

bool isPlayer(Cell* cptr){
    if (cptr->getIcon()=='@') {
        return true;
    }
    else {
        return false;
    }
}


Dungeon::~Dungeon(){
    deleteDungeon();               //yup, its that simple!
}

void Dungeon::deleteDungeon() {
    for (int i=0; i <HEIGHT; i++) {          //delete probably works
        delete [] map[i];
    }
    delete [] map;
    for (int i=0; i<HEIGHT; i++) {
        for (int j=0; j<WIDTH; j++) {
            delete pos[i][j];
        }
        delete [] pos[i];
    }
    delete [] pos;                           //i think that's how it works
}