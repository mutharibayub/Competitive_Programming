

class Amphipod
{
public:
    char tag;
    int loc; //current location
    bool done; //whether it has reached final location
    bool lockedOut; //whether it is locked out(another amphipod moved after this one)
    bool canMove(const bool*& currLocs, int newLoc)
    {
        if (newLoc == loc || 
        done || 
        (loc == 1 && currLocs[5]) || 
        (loc == 2 && currLocs[6]) || 
        (loc == 3 && currLocs[7]) || 
        (loc == 4 && currLocs[8]) || 
        
        )

        {return false;}
        else
        {
            if()
            /* code */
        }
        
    }

};

int main()
{


    return 0;
}